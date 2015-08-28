#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 64


struct node {
	char symbol;
	struct node *lowKid, *equelKid, *highKid;
};


struct node* insert (struct node *head, char *string);
char search (struct node *node, char* string);
struct node* fillTrie (const char *filePath);


int main(int argc, void* argv[]){

	if (argc != 2) {
		printf("Usage: \n");
		return 1;
	}

	char *buffer = malloc(BUFFER_SIZE);
	struct node *head = fillTrie(argv[1]);
	
	while (fgets(buffer, BUFFER_SIZE, stdin)) {
		if (strncmp("exit", buffer, 4) == 0) break;
		search(head, buffer) ? printf("YES\n") : printf("NO\n");
	}

	return 0;
}


struct node* insert (struct node *node, char *string)
{
	if (node == 0) {
		node = malloc (sizeof(struct node));
		node->symbol = *string;
		node->lowKid = node->equelKid = node->highKid = 0;
	}

	if (*string < node->symbol) {
		node->lowKid = insert(node->lowKid, string);
	}
	else if (*string == node->symbol) {
		if (*string != '\n')
			node->equelKid = insert(node->equelKid, ++string);
	}
	else {
		node->highKid = insert(node->highKid, string);
	}

	return node;
}


char search (struct node *node, char* string)
{
	while (node) {
		if (*string < node->symbol) {
			node = node->lowKid;
		}
		else if (*string == node->symbol) {
			if (*string++ == '\n')
				return 1;
			node = node->equelKid;
		}
		else {
			node = node->highKid;
		}
	}

	return 0;
}


struct node* fillTrie (const char *filePath)
{
	FILE* fd = fopen(filePath, "r");
	if (fd == NULL) {
		printf("Error fopen %s: %s\n", filePath, strerror(errno));
		return NULL;
	}

	char *buffer = malloc(BUFFER_SIZE);
	struct node* node = 0;

	while (fgets(buffer, BUFFER_SIZE, fd)) {
		node = insert(node, buffer);
	}

	fclose(fd);

	return node;
}
