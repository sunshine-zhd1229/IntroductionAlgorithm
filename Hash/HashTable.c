#include  <stdlib.h>
#include  <string.h>

#define     TABLE_FULL	 		-2
#define     HASH_INSERT_OK		 0
#define     table_meta_size		 1024
#define     NIL			  		 0
#define     DELETED		  		 1
#define     USED		  		 2
#define     NOT_IN_TABLE 		-1
#define     WRONG_ARG	 		-1
#define     DELETE_OK	  		 0

typedef struct {
	void *data;
	int flag;
} hash_value; 

typedef struct table_meta{
	hash_value table_list[table_meta_size];
	struct table_meta *next;
} Hash_Table;

Hash_Table* CreateHashTable() 
{
	Hash_Table *table = malloc(table_meta_size * sizeof(Hash_Table));
	memset(table, 0, sizeof(Hash_Table));
	return table;
}

int HashInsert(Hash_Table *table, int key)
{
	int hvalue1, hvalue2, hvalue, i;
	Hash_Table *p = table, *prev;
	hvalue1 = key % table_meta_size;
	hvalue2 = 1 + (key % (table_meta_size - 1));
	
	while(p != NULL) {
		for (i = 0; i < table_meta_size; i++) {
			hvalue = (hvalue1 + i * hvalue2) % table_meta_size;
			if (p->table_list[hvalue].flag != USED) {
				p->table_list[hvalue].data = &key;
				p->table_list[hvalue].flag = USED;
				return HASH_INSERT_OK;
			}
		}
		prev = p;
		p = p->next;
	}

	p = malloc(table_meta_size * sizeof(Hash_Table));
	if(p == NULL)
	  return TABLE_FULL;
	memset(p, 0, sizeof(Hash_Table));
	prev->next = p;
	table->table_list[hvalue1].data = &key;
	table->table_list[hvalue1].flag = USED;
	return HASH_INSERT_OK;
}

int HashSearch(Hash_Table *table, int key, int *table_index)
{
	int hvalue1, hvalue2, hvalue, count = 0, i;
	Hash_Table *p = table;
	hvalue1 = key % table_meta_size;
	hvalue2 = 1 + (key % (table_meta_size - 1));

	while(p != NULL) {
		for (i = 0; i < table_meta_size; i++) {
			hvalue = (hvalue1 + i * hvalue2) % table_meta_size;
			if (p->table_list[hvalue].flag == NIL)
			  return NOT_IN_TABLE;
			else if(p->table_list[hvalue].flag == DELETED)
			  continue;
			else if(*((int *)(p->table_list[hvalue].data)) == key) {
				*table_index = count;
				return hvalue;
			} 
		}
		p = p->next;
		count++;
	}
	return NOT_IN_TABLE;
}

int HashDelete(Hash_Table *table, int j, int table_index) 
{
	int i = table_index;
	Hash_Table *p = table;
	while(i--) {
		p = p->next;
		if (p == NULL)
		  return WRONG_ARG;
	}
	p->table_list[j].flag = DELETED;
	p->table_list[j].data = NULL;
	return DELETE_OK;
}
