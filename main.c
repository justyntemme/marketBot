#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

/* All Functions ending with a comment are functions from the same project
 * as dlist.h and have only changed small amounts if any. all work on functions
 * are offered pushed upstream to the dutils project
 *
 *
 */

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
struct reference_list
{
	char *words[100];
	int points[100];
	char *goal[100];


};



void dlist_node_foreach(struct dlist_list *list,
			void *(*action)(void *carry, void *data, void *param),
			void *param)
{
	if ( !list || !list->head || !action ){	
		printf("error\n");
		
		
		
		return;
	}
	struct dlist_node *iter = NULL;
	void *carry = malloc(sizeof(int));
	*(int *)carry = 0;
	for(iter = list->head; NULL != iter; iter = iter->next)
	{
		carry = action(carry, &iter->data, param);

	}
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

void *fillString(int *carry,struct reference_list *rlist,int *param) //implament point system here. a for loop for the size of array might be a better option, then a case
						       // switch if the word is one of the reference words. with the last jjcase being nill
{	

			
	
	
	switch (*carry)
	{
		case 0:
			printf("At first node\n");
			rlist->words[0] = "abc\0";
			printf("char is %s \n",rlist->words[0]);
			break;
		case 1:
			printf("At 2nd node\n");
			rlist->words[0] = "123\0";
			break;
		case 3:
			printf("At 3rd node\n");
			rlist->words[0] = "cat\0";
			break;
	}
	*(int *)carry+=1;
	// TODO add DATA param with reference words. Fun stuff is about to begain	
	return (carry);
}
inline size_t dlist_get_size(struct dlist_list *list)
{
	return list->count;
}/* dlist_get_size */



void populateLists(struct dlist_list *list, int size) //TODO add data as an argument. the wordlist
{
	

	for (int i = 0; i < size; i++)
	{	struct reference_list *temp_rlist = malloc(sizeof(struct reference_list));
		struct reference_node *tempNode = dlist_node_new(list,temp_rlist,NULL);
		dlist_node_append(list,dlist_node_new(list,tempNode,NULL));
		printf("%i\n",i);
		
	}
	
}

struct dlist_node *dlist_node_append(struct dlist_list *list,
				     struct dlist_node *node)
{
	if ( !list || !node )
		return NULL;

	//check add @ head
	if ( !list->head ) {
		list->head = node;
		node->next = NULL;
		node->prev = NULL;
		list->tail = node;
		++list->count;
		return node;
	}

	list->tail->next = node;
	node->next = NULL;
	node->prev = list->tail;
	list->tail = node;
	++list->count;

	return node;
}/* dlist_node_append */

int main(int argc, char *argv[])
{
	struct dlist_list *master_list = malloc(sizeof(struct dlist_list)); //assign master list
	master_list = dlist_init(master_list,NULL,NULL); //initialize list
	populateLists(master_list,3); //populate 3 nodes on list
	void *(*fillStringPointer)(int *,int *, void *) = &fillString;
	//node = master node
	struct dlist_node *node = master_list->head;
	//get list size
	int listSize = dlist_get_size(master_list);
	struct reference_list *rlist = &(master_list->head->data);
	
	
	dlist_node_foreach(master_list,fillStringPointer,NULL);
	printf("Address of main rlist is %d\n",&rlist);
	printf("char is %s \n",rlist->words[0]);
	rlist = &(master_list->head->next->data);
	printf("char is %s \n",rlist->words[0]);
	rlist = &(master_list->head->next->next->data);
	printf("char is %s \n",rlist->words[0]);


	return 0;

}
/*	DATA struct info
 *	10 byte string [s,t,r,i,n,g,0,0,\0]
 *	array of strings that corrospond in position of array to value
 *	['apple''buy''checkout']
 *	['2' '3' '4']
 *			not sure weather to have function or chat_node be the value for the point 
 *			system.
 *	ways to implament
 *				point based system. Certain words attribute points to the next
 *				sentance. certain words are worth more. would be held in a stucture
 *				with two arrays. one containing word,theother containing point value
 */
