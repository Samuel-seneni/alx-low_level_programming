#include "hash_tables.h"

/**
 * hash_table_create - creating a hash table
 * @size: size of the array
 *
 * Return: pointer to the hash table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *table;
	unsigned long int x;

	table = malloc(sizeof(hash_table_t));
	if (table == NULL)
		return (NULL);
	table->size = size;
	table->array = malloc(size * sizeof(hash_node_t *));
	if (table->array == NULL)
	{
		free(table);
		return (NULL);
	}
	for (x = 0; x < size; x++)
		hash_table->array[x] = NULL;
	return (table);
}
