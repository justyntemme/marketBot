#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

void dlist_node_foreach(struct dlist_list *list,
			void *(*action)(void *carry, void *data, void *param),
			void *param)
{
	if ( !list || !list->head || !action )
		return;

	struct dlist_node *iter = NULL;
	void *carry = NULL;

	for(iter = list->head; NULL != iter; iter = iter->next)
		carry = action(carry, iter->data, param);

	return;
}/* dlist_node_foreach */

struct dlist_list *dlist_init(struct dlist_list *list,
			      void *(*node_alloc)(size_t),
			      void (*node_dalloc)(void *))
{
	list->count = 0;
	list->node_alloc = (node_alloc ? node_alloc : DLIST_DEF_ALLOC);
	list->node_dalloc = (node_dalloc ? node_dalloc : DLIST_DEF_DALLOC);

	list->head = NULL;
	list->tail = NULL;
	return list;
}/* dlist_init */

void *checkString(int *carry, void *data, void *param)
{
	int locationInArray = 0;
	int sizeOfArray = 0;	
	while (locationInArray < sizeOfArray)
		{
			switch(locationInArray)
			{
				case 0:
					printf("TODO Add reference words\n");
					//TODO add array of reference words as 3rd param
					
					break;
			}	
			locationInArray++;
		}	
	return 0;


}

inline size_t dlist_get_size(struct dlist_list *list)
{
	return list->count;
}/* dlist_get_size */

struct dlist_node *dlist_node_new(struct dlist_list *list,
				  void *data, void (*dalloc)(void *))
{
	struct dlist_node *node = NULL;

	if ( NULL == (node = list->node_alloc(sizeof( struct dlist_node))) ) {
		//FIXME: add support for custom error loggin and msg
		fprintf(stderr,"%s[%d]:%s alloc failed\n", __FILE__,
			__LINE__,__func__);

		return NULL;
	}

	node->data = data;
	node->data_dalloc = dalloc;
	node->next = NULL;
	node->prev = NULL;

	return node;
}/* dlist_node_new */
void populateLists(struct dlist_list *list, int size)
{
	struct dlist_node *node = NULL;
	for (int i = 0; i < size; i++)
	{
		node =dlist_node_new(list,NULL,NULL);
	}
}
int main(int argc, char *argv[])
{
	struct dlist_list *master_list = malloc(sizeof(struct dlist_list));
	master_list = dlist_init(master_list,NULL,NULL);
	populateLists(master_list,3);
	struct dlist_node *node = master_list->head;
	int listSize = dlist_get_size(master_list);
	printf("%d\n",listSize);
	void *carry = NULL;
	void *param = NULL;
	dlist_node_foreach(master_list,(void *)(checkString(carry,node->data,param)),param);


	return 0;
}
