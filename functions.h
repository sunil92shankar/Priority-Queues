/*
 * functions.h
 *
 *  Created on: Sep 12, 2018
 *      Author: SUNIL
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

//Define type of PrioQ
typedef struct PrioQ PrioQ;

/*
 * Create a Priority Queue which may have several dynamically allocated elements/nodes
 *
 * @return a pointer to the priority queue created, or NULL if operation fails
 */
PrioQ *PQ_create();


/*
 * Insert an element to the front, end or in between nodes in the queue based on the priority (using key)
 *
 * @param PQ, the priority queue to which a new node is to be added
 * @param key determining the priority in the queue, of the node to be inserted
 * @param data, the data that is to be inserted into the node
 * @return 0 if insertion fails, or 1 value if insertion operation succeeds
 */
int PQ_insert(PrioQ *PQ, double key, void *data);


/*
 * Remove/Delete a node, specifically the head from the priority queue
 *
 * @param PQ, the Priority Queue from which the deletion is to occur
 * @param key, the address of variable where the priority value of the deleted node is to be stored
 * @return pointer to the data item removed, or  NULL if the queue was empty (or if there is an issue with parameter checks)
 */
void *PQ_delete(PrioQ *PQ, double *key);


/*
 * Count the number of nodes in the queue
 *
 * @param PQ, the queue whose length is to be determined
 * @return a positive value corresponding to the number of elements in the queue, or NULL if PQ does not exist
 */
unsigned int PQ_count(PrioQ *PQ);


/*
 * Release all nodes from the priority queue as well as the priority queue from memory
 *
 * @param PQ the priority queue whose data is to be released
 * @return NULL if PQ is already free, or if operation to free all elements is successful
 */
void *PQ_free( PrioQ *PQ);

/*
 * Print all nodes (data and key) from the priority queue from head to tail
 *
 * @param PQ the priority queue which is to be printed
 * @return 0 if print is successful, 1 if PQ is NULL
 */
int PQ_print(PrioQ *PQ);

#endif /* FUNCTIONS_H_ */
