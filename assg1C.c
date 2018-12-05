/*
 * Assg1C_new.c
 *
 *  Created on: Sep 12, 2018
 *      Author: SUNIL
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"functions.h"

int main()
{
	PrioQ *queue_instance = PQ_create();//Create priority queue instance

	if(queue_instance!=NULL)//Checking for successful creation of priority queue
	{

	/*
	 * Creating 20 data elements for testing.
	 * Array x contains data of type int pointed to by the 'void pointer' member in the node structure
	 * Array key contains the data that will be assigned to 'priority_key' member of the node structure
	 */
	int x[]={20,12,43,345,1445,8,595,573,651,794,9,21,289,9002,7898,340,200,908,12039,847};//20 data elements
	double key[20]={0};//20 priority key elements

	srand(time(NULL));//seeding 'rand()' with time such that randomly generated numbers are different every time

	printf("\tOrder of element entry into Queue:\n");
	printf("\t----------------------------------\n");
	printf("\tEntry Number \tPriority of Node       Data Stored in Node\n");
	//Please note that Entry number here merely means its numerical order of insertion, not its priority in the queue
	printf("\t------------ \t----------------       -------------------\n");

	// Here, we print out the priority key and data for each of the 20 elements before inserting to the queue
	for(int i=0;i<20;i++)
	{
		//The next 12 lines of code generate randomly generated numbers that could be large, small, negative or decimal
		if(i%6==5)
			key[i]=(double)rand();				//randomly generated priority key values
		if(i%6==4)
			key[i]=(double)rand()/(int)(rand());//randomly generated priority key values, that are relatively small
		if(i%6==3)
			key[i]=(double)rand()/13;			//randomly generated priority key values, that hold decimal points
		if(i%6==2)
			key[i]=-(double)rand();				//randomly generated priority key values, that are negative
		if(i%6==1)
			key[i]=-(double)rand()/(int)(rand());//randomly generated priority key values, that are negative and small
		if(i%6==0)
			key[i]=-(double)rand()/17;			//randomly generated priority key values, that are negative and hold decimal points


		printf("\t%10d\t%16lf\t\t%10d\n",i+1, key[i], x[i]);// Printing data and key for verification later
		PQ_insert(queue_instance, key[i], &x[i]);//Calling the PQ_insert function to insert x[i] into the queue A with key[i]
	}

	//Checking Validity of PQ_count() function
	int len_of_PQ = PQ_count(queue_instance);
	printf("\n\tNo. of elements in Queue = %d\n", len_of_PQ);
	printf("\t-------------------------------\n");

	//Checking order of elements in priority Queue
	PQ_print(queue_instance);

	//Checking Validity of PQ_delete() function
	double priority_key = 0;//variable to store the priority key of deleted node
	printf("\n\tPriority Key values of deleted items in order of deletion:");
	printf("\n\t----------------------------------------------------------\n");

	for(int i=0;i<len_of_PQ;i++)//loop through all elements of the queue
		{
			void *deleted_item=NULL;
			deleted_item = PQ_delete(queue_instance, &priority_key);
			//we do not necessarily need to check for condition of 'deleted_item == NULL' because we are looping through the number of elements in the queue as returned by PQ_count()
			printf("\tPriority value = %lf for deleted item %d\n", priority_key, i+1 );
		}

			 //Optional Block
			{//adding elements to the queue to check validity of PQ_free()

			/*
			 * Creating 5 data elements for testing.
			 * Array x contains data of type int pointed to by the 'void pointer' member in the node structure
			 * Array key contains the data that will be assigned to 'priority_key' member of the node structure
			 */
			int x[]={209,312,443,3345,13445};//5 data elements
			double key[5]={0};//5 priority key elements

			printf("\n\tChecking Functionality of PQ_free():\n");
			printf("\n\tOrder of element entry into Queue:\n");
			printf("\t----------------------------------\n");
			printf("\tEntry Number \tPriority of Node       Data Stored in Node\n");
			//Please note that Entry number here merely means its numerical order of insertion, not its priority in the queue
			printf("\t------------ \t----------------       -------------------\n");

			// Here, we print out the priority key and data for each of the 5 elements before inserting to the queue
			for(int i=0;i<5;i++)
			{
				key[i]=(double)rand();				//randomly generated priority key values

				printf("\t%10d\t%16lf\t\t%10d\n",i+1, key[i], x[i]);// Printing data and key for verification later
				PQ_insert(queue_instance, key[i], &x[i]);//Calling the PQ_insert function to insert x[i] into the queue A with key[i]
			}

			//Checking Validity of PQ_free() function
			PQ_free(queue_instance);//calling function to free all nodes in the priority queue and the queue itself


			}

	return 0;
	}

	return 1;
}


