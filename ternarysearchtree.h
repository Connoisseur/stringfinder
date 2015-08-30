/* File ternarysearchtree.h */
#ifndef TERNARYSEARCHTREE_H
#define TERNARYSEARCHTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 64


struct node {
	char symbol;
	struct node *lowKid, *equelKid, *highKid;
};


/* Insert string into the tree
*/ 
struct node* insert (struct node *head, char *string);


/* Search string in the tree
*/
char search (struct node *node, char* string);


/* Fill tree with string from file 
*/
struct node* fillTree (const char *filePath);


#endif /* TERNARYSEARCHTREE_H */
