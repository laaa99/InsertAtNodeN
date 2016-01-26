#ifndef HEADER_H
#define HEADER_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <Windows.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

//1-20-16
typedef struct node
{
	char data[100]; //data in the node (bytes: 100)
	struct node *pNext; //points to the next node

}Node;

Node *makeNode(char *newData);
void insertAtFront(Node **pHead, char *newData);
void printList(Node *pHead); //single star because you're not modifying it
void deleteNodeAtFront(Node **pHead); //modifying again


#endif 