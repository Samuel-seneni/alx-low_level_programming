#include "hash_tables.h"

/**
 * hash_table_create - creating of of the hash table
 * @size: size of the array
 *
 * Return: a pointer to the hash table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *table;

	if (size == 0)
		return (NULL);
	table = malloc(sizeof(hash_table_t));
	if (table == NULL)
		return (NULL);
	table->size = size;
	table->array = malloc(sizeof(hash_table_t));
	if (table->array == NULL)
	{
		free(table);
		return (NULL);
	}
	return (table);
}
