#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void check_elf(unsigned char *e_ident);
void close_elf(int elf);
/**
 * check_elf - identify if a file is an ELF file.
 * @e_ident: a pointer to an array containing the ELF magic numbers.
 * Description: if the file is not an ELF file - exit code 98.
 */
void check_elf(unsigned char *e_ident)
{
	int x;

	for (x = 0; x < 4; x++)
	{
		if (e_ident[x] != 127 &&
				e_ident[x] != 'E' &&
				e_ident[x] != 'L' &&
				e_ident[x] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}
/**
 * print_magic - prints magic numbers of an ELF header.
 * @e_ident:a pointer of array containing the ELF magic numbers.
 * Description: magic numbers are separated by spaces.
 */
void print_magic(unsigned char *e_ident)
{
	int x;

	printf(" magic: ");

	for (x = 0; x < EI_NIDENT; x++)
	{
		printf("%02x", e_ident[x]);

		if (x == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}
/**
 * print_class - prints the class of an ELF header.
 * @e_ident: an array containing the ELF class.
 */
void print_class(unsigned char *e_ident)
{
	printf(" class: ");

	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;

		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}
/**
 * print_data - the data of an ELF header.
 * @e_ident: a ponter of an array into the ELF class.
 */
void print_data(unsigned char *e_ident)
{
	printf(" Data: ");

	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's compliment, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's compliment, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}
/**
 * print_version - prints version of an ELF header.
 * @e_ident: an array containing the ELF version.
 */
void print_version(unsigned char *e_ident)
{
	printf(" version: %d", 
			e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}
/**
 * print_osabi - prints the OS/ABI of an ELF header.
 * @e_ident: an array containing the ELF version.
 */
void print_osabi(unsigned char *e_ident)
{
	printf(" OS/ABI: ");

	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}
/**
 * print_abi- the ABI version of an ELF header.
 * @e_ident: an array containing the ELF ABI version.
 */
void print_abi(unsigned char *e_ident)
{
	printf(" ABI Version: %d\n", 
			e_ident[EI_ABIVERSION]);
}
/**
 * print_type - prints type of an ELF header.
 * @e_type: The ELF type.
 * @e_ident: pointer to array containing the ELF class.
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf(" Type: ");

	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", e_type);
	}
}
/**
 * print_entry - entry point of an ELF header.
 * @e_entry: address of the ELF entry point.
 * @e_ident: an array containing the ELF class.
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf(" Entry point address:");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) | ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}
/**
 * close_elf - close an ELF life.
 * @elf: file descriptor of the ELF file.
 * Description: if the file cannot be closed - exit code 98.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't close fd %d\n", elf);
		exit(98);
	}
}
/**
 * main - information contained in the ELF header.
 * @argv: an array of pointers to the arguments.
 * @argc: the number of arguments
 * return: 0 (success)
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int x, y;

	x = open(argv[1], O_RDONLY);
	if (x == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(x);
		dprintf(STDERR_FILENO, "Error: can't read file %s\n", argv[1]);
		exit(98);
	}
	y = read(x, header, sizeof(Elf64_Ehdr));
	if (y == -1)
	{
		free(header);
		close_elf(x);
		dprintf(STDERR_FILENO, "Error: '%s : No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_version(header->e_ident);
	print_data(header->e_ident);
	print_osabi(header->e_ident);
	print_abi(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(x);
	return (0);
}
