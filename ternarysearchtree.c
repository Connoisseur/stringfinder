/* File ternarysearchtree.c */

#include "ternarysearchtree.h"


struct node* insert (struct node *node, char *string)
{
	/* Create new node if needed
	*/
	if (node == 0) {
		node = malloc (sizeof(struct node));
		node->symbol = *string;
		node->lowKid = node->equelKid = node->highKid = 0;
	}

	/* Symbol less the node's symbol
	*/
	if (*string < node->symbol) {
		node->lowKid = insert (node->lowKid, string);
	}

	/* Symbol equel the node's symbol
	*/
	else if (*string == node->symbol) {
		if (*string != '\n')
			node->equelKid = insert (node->equelKid, ++string);
	}

	/* Symbol more the node's symbol
	*/
	else {
		node->highKid = insert (node->highKid, string);
	}

	return node;
}


char search (struct node *node, char* string)
{
	while (node) {

		/* Symbol less the node's symbol
		*/
		if (*string < node->symbol) {
			node = node->lowKid;
		}

		/* Symbol equel the node's symbol
		*/
		else if (*string == node->symbol) {

			/* Last symbol is found
			*/
			if (*string++ == '\n')
				return 1;

			node = node->equelKid;
		}

		/* Symbol more the node's symbol
		*/
		else {
			node = node->highKid;
		}
	}

	return 0;
}


struct node* fillTree (const char *filePath)
{
	FILE* fd = fopen (filePath, "r");
	if (fd == NULL) {
		return NULL;
	}

	char *buffer = malloc (BUFFER_SIZE);
	struct node* node = 0;

	while (fgets (buffer, BUFFER_SIZE, fd)) {
		node = insert (node, buffer);
	}

	fclose (fd);

	return node;
}

