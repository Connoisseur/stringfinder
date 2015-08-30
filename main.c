/* File main.c */

#include "ternarysearchtree.h"

int main(int argc, void* argv[])
{
	if (argc != 2) {
		printf("Usage: stringfinder [path to file]\n");
		return 1;
	}

	/* Read string from file to tree
	*/
	struct node *head = fillTree(argv[1]);
	if (head == NULL) {
		printf("Error fillTree: %s\n", strerror(errno));
		return 1;
	}
	
	/* Read string from stdin and search it in tree
	*/
	char *buffer = malloc(BUFFER_SIZE);
	while (fgets(buffer, BUFFER_SIZE, stdin)) {
		if (strncmp("exit", buffer, 4) == 0) break;
		search(head, buffer) ? printf("YES\n") : printf("NO\n");
	}

	return 0;
}

