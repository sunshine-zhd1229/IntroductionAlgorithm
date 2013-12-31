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

Hash_Table* CreateHashTable();
int HashInsert(Hash_Table *table, int key);
int HashSearch(Hash_Table *table, int key, int *table_index);
int HashDelete(Hash_Table *table, int j, int table_index); 
