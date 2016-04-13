#include <stdio.h>
#include <stdlib.h>
typedef struct chat_node 
	{
	int (*next_functions_addr)[];
	char *words[15];
	char user_words[];
	} chat_node;

//list of how tree should be structured, more for me than actuall documentation
//                                                  Intro node (cout suggestion words?)
//				[]					[]								[]
//                        {list items}                    {list cart(for each in card price+list)}            {checkout(cout << enter fake cc #)(sanitize etc)}
//             []           	[]            []
//   {apples(add to cart)}    {banana(add to cart)}      {milk(add to cart $price of milk)}									














typedef struct order_intro
	{
		//definition of order_intro... adding structures almost as class objects too be navigated. chat_node will crawl the tree with each branch being 
		//specified as a structure since instead of being generic,we want the customer to follow a path.
	

		char *reference_words[15]=NULL;
		reference_words[0]="apple";
		reference_words[1]="banana";
		reference_words[2]="exit";


	
	}  order_intro;



int main(int argc, char *argv[])
	{

	return 0;
	}


int *find_next_addr(chat_node  *current_chat_node)
	{
		int (*next_addr) = NULL;
		for (int i = 0; i < (sizeof(current_chat_node->words)/sizeof(current_chat_node->words[0]));i++)
			{
			}
		return next_addr;
	}
