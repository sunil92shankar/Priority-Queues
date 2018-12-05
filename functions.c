/*
 * functions.c
 *
 *  Created on: Sep 12, 2018
 *      Author: SUNIL
 */

#include<stdio.h>
#include<stdlib.h>
#include"functions.h"

//Define type of Node
typedef struct Node Node;
//Declaration and Definition of Node
struct Node {
		void *data_pointer; 	//pointer to data to be stored in node
		double priority_key;	//key of node in queue
		Node *next;				//pointer to next node in the queue
};

//Declaration and Definition of  PrioQ
struct PrioQ{
	Node *head;		//pointer to head node of the queue
	Node *tail;		//pointer to tail node of the queue
};

/*
 * Definition of the function PQ_create.
 * The function declares a pointer to a PrioQ structure and allocates memory for it.
 * A check is then performed to see if memory allocation is successful, if NO, then the function terminates and returns NULL
 * If memory allocation is successful, then 'head' and 'tail' of the Priority Queue are initialized to 'NULL' indicating an empty Queue
 * Then, the function returns the pointer to the Priority queue created
 */
PrioQ *PQ_create()
{
	//Declaring and initializing a pointer to the priority queue. Memory allocation also occurs in this step.
	PrioQ *PQ_pointer = (PrioQ*) malloc(sizeof(PrioQ));

	if (PQ_pointer==NULL)//Check if memory allocation for priority queue pointer failed
	{
		printf("\nMemory Allocation for new pointer failed\n");
		return NULL;//returning NULL indicates failure in allocating memory for Priority Queue
	}
	else
	{
		PQ_pointer->head = NULL;//pointers to head and tail of PQ initialized to NULL to indicate empty queue
		PQ_pointer->tail = NULL;//for newly created PrioQ pointer
		printf("\n\tPointer to PQ returned\n\n");
		return PQ_pointer;//Return address of memory location created for priority queue
	}
}



/*
 * Definition of function PQ_insert
 * The function accepts as arguments pointer to a priority queue, a key indicating priority of data to be inserted,
 * and a pointer to the data to be inserted.The function then determines the position for insertion of the data
 * based on it's key value.
 */
int PQ_insert(PrioQ *PQ, double key, void *data)
{
	if(data==NULL) //check for existence of data
	{
		printf("\n\tData for insertion does not exist, Insertion failed\n");
		//return 0 if data for insertion does not exist, so insertion was unsuccessful
		return 0;
	}
	if(PQ==NULL) //Check for existence of PQ
	{
		printf("\n\tPriority Queue does not exist, Insertion failed\n");
		//return 0 if PQ does not exist, so insertion was unsuccessful
		return 0;
	}
	//Creating a new node for the priority queue by declaring a pointer to a node of the priority queue
	//and allocating memory for the node
	Node *new_node = (Node*) malloc(sizeof(Node));
	if(new_node==NULL) //Checking if node creation is unsuccessful
	{
		printf("\n\tMemory allocation for queue node failed, therefore Insertion failed\n");
		return 0; //indicating to call that node creation for insertion into the Queue was unsuccessful
	}

	//Initializing values for members of node created
	new_node->data_pointer = data;//initializing data_pointer member
	new_node->priority_key = key;//initializing key value of node
	new_node->next = NULL;//At this point, 'next' member does not point to any other node. This is handled in the following steps

	if(PQ->head == NULL) //Checking if Priority Queue is empty
	{
		PQ->head = new_node;//An element/node inserted into an empty queue is both the head and tail of the queue
		PQ->tail = new_node;
	}
	else if((new_node->priority_key) < (PQ->head->priority_key))//checking if priority of node created is less than priority of head
		{
			/*
			 * Here, we ensure that the element with higher priority (lower key value) than
		     * the existing head becomes the new head,
			 * and the new head points to the previous head
			 */
			new_node->next = PQ->head;
			PQ->head = new_node;
		}
	else if((new_node->priority_key) >= (PQ->tail->priority_key))//Checking if new node has lower priority than the tail (which currently has the lowest priority)
			{
				/*
				 * Here, we ensure that the element with lower priority (higher key value) than
				 * the existing tail becomes the new tail,
				 * and the previous tail points to the new tail (newly created node being inserted)
				 */
				PQ->tail->next = new_node;
				PQ->tail = new_node;
			}
	else //This block considers the cases where the new node created has lower priority (greater key) than the head, but greater priority (lower key value) than the tail
	{
		Node *check = PQ->head;//create a local pointer to the head for iterating through the queue
		do
		{
			if ((new_node->priority_key >= check->priority_key) && //In this if condition, we try to find the nodes in the queue between which
					(new_node->priority_key < (check->next)->priority_key))//to insert the new created node
			{
				/*
				 * In the following lines, we ensure that a node is inserted into the queue based on priority previously checked
				 * check is the node with priority just higher than the newly created node.
				 * check is made to point to the new node; and
				 * the new node inserted is made to point to the node previously pointed to by check
				 */
				Node *temp=check->next;
				check->next = new_node;
				new_node->next = temp;
				break;
			}

			check=check->next;//updating local node pointer to the next node in the queue

		}while(check!=NULL);//Loop runs until it reaches the 'tail' of the queue
	}

	return 1;//indicating to call that node creation for insertion into the Queue was successful
}



/*
 * Function PQ_delete takes a pointer to a Priority queue and pointer to a double variable as arguments
 * We return NULL if the queue PQ is empty. If not empty, we remove the current head of the queue as it has the
 * smallest key (highest priority). The void data pointer in the current head is returned explicitly by the function and the
 * key of the data to be deleted is 'returned' by passing the value of 'PQ->head->priority_key' to the memory location
 * pointed to by the pointer 'key' passed * to the function
 */
void *PQ_delete(PrioQ *PQ, double *key)
{
	if (key==NULL)//Check PQ exists or not
		{
			printf("\n\tkey does not exist. Deletion not executed.");
			return NULL;//key does not exist
		}
	if (PQ==NULL)//Check PQ exists or not
		{
			printf("\n\tPriority Queue does not exist. Deletion not executed.");
			return NULL;//Queue does not exist
		}
	if (PQ->head==NULL)//Check if queue is empty
		{
			printf("\n\tPriority Queue is empty. Deletion not executed.");
			return NULL;//Queue was empty
		}

	void *data_item = PQ->head->data_pointer;//store void data pointer from head in a void pointer for returning
	*key = (PQ->head->priority_key);//pass the value (it is effectively a return to the call) of the priority of the node to be deleted to the memory location pointed to by 'key'

	if (PQ->head==PQ->tail) //check if queue has only one element
		{
			free(PQ->head);//free up memory allocated for only node in the queue
			PQ->head = NULL;//Queue is now empty
			PQ->tail = NULL;//Queue is  now empty
			return data_item;//return void data pointer of node deleted from queue

		}
		else//Queue has more than one element
		{
			Node * cur = PQ->head;//store pointer to the head of the queue in cur. Head of the queue has highest priority (lowest key) and will be 'deleted'
			PQ->head = PQ->head->next;//New head of the queue is the node pointed to by the previous head
			free(cur);//release memory allocated to the node that is now being deleted (previous head)
			return data_item;//return void data pointer of node deleted from queue
		}

}



/*
 * PQ_count() takes a pointer to a priority queue as argument and counts the number of nodes in the queue
 * The function then returns the number of nodes counted
 */
unsigned int PQ_count(PrioQ *PQ)
{
	if(PQ==NULL)
	{
		printf("\n\tQueue does not exist. Counting function was not executed.");
		return 0;// return 0 when PQ does not exist
	}

	if (PQ->head == NULL)//check if queue is empty
	{
		return 0;//return 0 - the number of nodes in the queue
	}
	else if (PQ->head==PQ->tail)//Checking if head and tail point to the same memory location, this means there is only 1 node in the queue
		{
			return 1;//return the number of nodes (1) in the queue
		}
		else// this block considers the case when the number of nodes in the queue is more than 1
			{
				Node *temp = PQ->head; //Store address to head in node pointer 'temp'. 'temp' will be used for iterating through the queue
				unsigned int count = 1;//Since, we use a do...while loop, initialize count as 1

				do
				{
					count++;//update count
					temp = temp->next;//temp is updated to the location it was previously pointing to in the queue

				}while(temp->next != NULL);//loop until you reach the tail of the queue

				return count;//return count of number of nodes in the queue
			}
}



/*
 * Function PQ_free takes a pointer a queue as an argument, loops through each node
 * starting from node and ending at tail.
 *
 * In each loop, the head node pointed to by PQ is removed from the
 * queue and memory allocated for the head node is freed.
 *
 * Finally, memory allocated to PQ (the structure ) is also freed
 */
void *PQ_free( PrioQ *PQ)
{
	if(PQ==NULL)// Check if PQ is null
	{
		printf("\n\tPriority Queue is already empty. Memory release was not processed.\n");
		return NULL;// If PQ is null, do not attempt to release PQ as it is already empty. Return NULL.
	}

	printf("\n\tPriority Key values of deleted items in order of deletion using PQ_free():");
	printf("\n\t------------------------------------------------------------------------\n");

	Node *cur = PQ->head; //setting cur to the head of the queue
	int i=1;
	while(cur != NULL) //Looping until the end of the queue
	{
		Node *temp = cur;	//temp points to the effective head of the remaining nodes in the queue
		printf("\tPriority value = %lf for deleted item %d\n", temp->priority_key, i);
		cur = cur->next; 	//updating cur to the node pointed to by cur
		free(temp);			//freeing node pointed to by temp
		i++;
	}

	free(PQ);//free memory allocated to the PrioQ data structure associated with the queue
	return NULL;
}



/*
 * PQ_print() takes a pointer to a queue as an argument and prints the node keys in order from head to tail
 * In other words, it prints the key in nodes from higher priority to lower priority
 */

int PQ_print(PrioQ *PQ)
{
	if(PQ==NULL || !PQ)//check if PQ is empty
	{
		printf("\n\tPQ does not exist, Printing unsuccessful");
		return 1;//return 1 if PQ is empty
	}
	Node *temp=PQ->head;
	int len = PQ_count(PQ);//getting number of elements in queue

	printf("\n\tDisplaying Priority Queue elements in order\n\t--------------------------------------------");
	printf("\n\tS.No (starting at head) \tPriority Key value of queue element\n");
	printf("\t-----------------------  \t------------------------------------\n");

	for(int i=0; i<len; i++)//looping through each node of the queue
	{
		printf("\t\t%d\t\t\t\t%lf\n",i+1, temp->priority_key);//printing the key of each element of the queue from head to tail (higher priority to lower priority)
		temp = temp->next;
	}

	return 0;
}

