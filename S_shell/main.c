#include "main.h"

int main(int jm, char **argv){
	char *prompt = "(JMshell) $ ";
	char *lineptr;
	size_t n = 0;

	/*void variables declared */
	(void)jm; (void)argv;

	printf("%s", prompt);
	getline(&lineptr, &n, stdin);
	printf("%s\n", lineptr);

	free(lineptr);
	return (0);
}
