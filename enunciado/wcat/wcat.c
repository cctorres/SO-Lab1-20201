#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("wcat: file1 [file2 ...]\n");
        return 0;
    }
    for (int i = 1; i < argc; i++)
    {
        FILE *currentFile = fopen(argv[i], "r");
        if (currentFile == NULL)
        {
            printf("wcat: cannot open file\n");
            return 1;
        }
        char character = fgetc(currentFile);
        while (character != EOF)
        {
            printf("%c",character);
            character = fgetc(currentFile);    
        }  
          
        fclose(currentFile);
    }
    return 0;
}