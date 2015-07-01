#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define OPERATION_SUCCESS 0
#define OPERATION_TERMINATED 1
#define OPERATION_ERROR -1

void removeTrailingNewLine(char* s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '\n')
        {
            s[i] = '\0';
            return;
        }
    }
}

int hasTrailingSlash(char* s)
{
    return s[strlen(s)-1] == '/';
}

int runTest(char* binPath)
{
    
    
    char* fileName = (char*) calloc(BUFFER_SIZE, sizeof(char));
    if (fileName == NULL)
    {
        perror("malloc");
        exit(1);
    }
    
    // read executable name from stdin
    if (fgets(fileName, BUFFER_SIZE, stdin) == NULL)
    {
        goto exitTerminated;
    }
    
    removeTrailingNewLine(fileName);
    
    char* command = (char*) calloc(BUFFER_SIZE, sizeof(char));
    if (command == NULL)
    {
        perror("malloc");
        exit(1);
    }
    
    // delete gvki-0
    sprintf(command, "rm -rf gvki-0");
    printf("Running command %s\n", command);
    
    // generate command to be executed
    if (hasTrailingSlash(binPath))
    {
        sprintf(command, "%s%s", binPath, fileName);
    } else
    {
        sprintf(command, "%s/%s", binPath, fileName);
    }
    
    // run OpenCL program
//     printf("Running program %s\n", fileName);
    printf("Running command %s\n", command);
    int systemResult = system(command);
    
    // generate command for moving gvki
    if (systemResult == 0)
    {
        sprintf(command, "mv gvki-0 gvki-%s", fileName);
        printf("Running command %s\n", command);
        system(command);
    } else
    {
        printf("Program error\n");
    }
    
    
    exitSuccess:
    // delete gvki-0
    sprintf(command, "rm -rf gvki-0");
    printf("Running command %s\n", command);
    system(command);
    // free
    free(fileName);
    free(command);
    return OPERATION_SUCCESS;
    
    exitTerminated:
    // delete gvki-0
    sprintf(command, "rm -rf gvki-0");
    printf("Running command %s\n", command);
    system(command);
    // free
    free(fileName);
    free(command);
    return OPERATION_TERMINATED;
    

}

int main(int argc, char** argv)
{
    if (argc == 2)
    {
        system("rm -rf gvki-0");
        while (runTest(argv[1]) == OPERATION_SUCCESS);
    } else
    {
        printf("Usage: ./automate <binary path>\n");
    }
    
    return 0;
}