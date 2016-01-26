#include "header.h"

Node *makeNode(char *newData) 
{
	Node *pMem = NULL;
	pMem = (Node *) malloc(sizeof (Node)); //grabbing memory from the heap 

	//initialize block - node
	pMem->pNext = NULL;

	//strncpy (safer - doesn't go out of the bounds)

	strcpy(pMem->data, newData);

	return pMem; //return a copy
}

//Quiz 2
Node *makeNode2(int newData)
{
	Node *pMem = NULL;
	pMem = (Node *)malloc(sizeof(Node)); //grabbing memory from the heap 

										 //initialize block - node
	pMem->pNext = NULL;

	//strncpy (safer - doesn't go out of the bounds)

	pMem->data = newData;

	return pMem; //return a copy
}

//the pHead refers to the pHead pointer in the main() (stores address)
void insertAtFront(Node **pHead, char *newData) 
{
	Node *pMem = NULL;

	pMem = makeNode(newData); //stores address to a block of memory that is from the heap

	if (pMem != NULL) //we allocated memory
	{
		//if (*pHead == NULL) //is the list empty? (contents of the pointer in the main)
		//{
		//	//make it point to the memory in the heap
		//	//motification will be retained because you changed the contents by dereferencing
		//	*pHead = pMem; //points to the next node
		//}

		//else //non-empy list
		//{
		//	//it could point to another node, memory leak if you break the link
		//	pMem->pNext = *pHead; //moving the rest of the nodes 
		//	*pHead = pMem; //inserting at front
		//}

		//refactored
		if (*pHead != NULL)
		{
			pMem->pNext = *pHead;
		}

		*pHead = pMem;
	}
}

void printList(Node *pHead) 
{
	//we are at the end of the list if pNext is NULL
	while (pHead != NULL) //if it points to pNext (that is NULL)
	{
		printf("--> %s ", pHead->data); //printing out the string that is the data inside of the nodes
		pHead = pHead->pNext; //nothing local is modified 
	}

	printf("-->\n");
}

// precondition: if list is not empty
//1-25-16
void deleteNodeAtFront(Node **pHead)
{
	Node *pTemp = NULL; //marker ...this is the node that I will free or delete
	//block that no longer exists or allocated (dangling pointer): pHead will store an address to a part of memory that is no longer accessible

	//We don't need a special case for one node or more than one node: Phead will point to NULL

	//1. Set pTemp to pHead - to start of list
	pTemp = *pHead; //phead is a pointer to a pointer, we want to change pHead in main!!! so *pHead
	//when we exit out, pHead's changes will not be retained (

	//2. Set pHead to pTemp's next pointer
	*pHead = (*pHead)->pNext; // = pTemp->pNexts

	//3. Free the block of memory
	free(pTemp); //pTemp is pointing to the first 
}

//insert in dictionary order a-z
int insertInOrder(Node **pHead, char *newData)
{
	Node *pMem = NULL, *pCur = NULL, *pPrev = NULL;
	int success = 0; //allocate memory successfully

	pMem = makeNode(newData); //pMem points to a block with newData that points to NULL

	if (pMem != NULL)
	{
		//we allocated a node
		success = 1;

		pCur = *pHead;

		while (pCur != NULL && strcmp(pMem->data, pCur->data) > 0) //order matters in this argument
		{
			//walk through list to find correct place to insert
			pPrev = pCur; //previous
			pCur = pCur->pNext; //next
		}

		//found the position to insert the node
		if (pPrev != NULL)
		{
			// we're not at the front of the list
			pMem->pNext = pCur;
			pPrev->pNext = pMem;
		}

		else
		{
			//inserting at front
			pMem->pNext = pCur;
			*pHead = pMem;
		}
	}

	return success;
}

int insertAtPositionN(struct node **pHead, int n, int newData)
{
	Node *pMem = NULL, *pCur = NULL, *pPrev = NULL;
	int success = 0, i = 0; //i is the index

	pMem = makeNode(newData);

	if (pMem != NULL)
	{
		success = 1;

		pCur = *pHead;

		if (n == 1)
		{
			if (*pHead != NULL)
			{
				*pHead = pMem;
			}

			else
			{
				*pHead = pMem;
				pMem->pNext = pCur;
			}
		}

		else 
		{
			for (i = 0; i < n; i++)
			{
				pPrev = pCur;
				pCur = pCur->pNext;
			}

			pPrev->pNext = pMem;
			pMem->pNext = pCur;
		}
	}

	success = 0;
}