#include "shell.h"

int main (int jm, char **argv){
  char *prompt = "(JMshell) #";
  char *lineptr = NULL, *lineptr_copy = NULL;
  size_t n = 0;
  int j , count_token = 0;
  ssize_t b_read;
  const char *delim = "\n ";
  char *token;
 

  void printDir();/* printing working directory*/

    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("\nDir: %s", cwd);

  /*(void)jm; (void)argv; */
  
 while(1) {
  printf("%s", prompt);
  b_read = getline(&lineptr, &n, stdin);
  if (b_read == -1){
  printf("Exiting shell....\n");
  return (-1);}
   lineptr_copy = malloc(sizeof(char)*b_read);
   
   if (lineptr_copy == NULL)
     {
            perror("tsh: memory allocation error");
            return (-1);
        }
   strcpy(lineptr_copy, lineptr);
    token = strtok (lineptr, delim);
   
while (token != NULL)
        {
            count_token++;
           token = strtok(NULL, delim);
        }
        count_token++;
   
  argv = malloc(sizeof(char *));
token = strtok(lineptr_copy, delim);
   for(j = 0; token != NULL; j++){
     argv [j] = malloc (sizeof(char)* strlen(token));
     strcpy(argv[j],token);
     token = strtok(NULL, delim); 
     
   }
   argv[j] = NULL;
   
   
   printf("%s\n", lineptr);
   
free(lineptr_copy);

/*free(lineptr);*/

}
  return(0);
}
}
