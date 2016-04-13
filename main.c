#include <stdio.h>
#include <stdlib.h>
typedef struct chat_node 
	{
	int (*next_function);
	void* current_level;
	char user_words[];
	} chat_node;

typedef struct person
	{
	char *credit_card_number;
	char *firstName;
	char *lastname;
	char *address;
	double balance;
	} person;
void add_item(int price, person *p)
	{
		p->balance+=price;
	}

//list of how tree should be structured, more for me than actuall documentation
//                                                  Intro node (cout suggestion words?)
//				[]					[]								[]
//                        {list items}                    {list cart(for each in card price+list)}            {checkout(cout << enter fake cc #)(sanitize etc)}
//             []           	[]            []
//   {apples(add to cart)}    {banana(add to cart)}      {milk(add to cart $price of milk)}	
//
//
//
//
//
//
//   users will always be able to quit by either saying exit, quit, leave 
//
//   users will always get a help message displaying working commands when saying help
//
//   users will always list items, thenn return to intro node
//
//   to get complicated requests the engine will search and store all reference words in a array of strings
//
//   engne will itterate and first look for top level reference word. it will then follow the reference word looking for the next step in the user path in the 
//   user string
//
//   	if secound level is not found in user string it will prompt user for 2nd string			


int main(int argc, char *argv[])
	{
		char *wordDictionary[][];
		

	return 0;
	}

