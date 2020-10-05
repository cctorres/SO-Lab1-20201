#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("wzip: file1 [file2 ...]\n");
        return 1;
    }
    int contador = 1;
    char currentCharFile;
    for (int i = 1; i < argc; i++)
    {
        FILE *currentFile = fopen(argv[i], "r");
        if (currentFile == NULL)
        {
            printf("wzip: cannot open file\n");
            return 1;
        }
        char currentCharIterator = fgetc(currentFile);
        while ((currentCharFile = fgetc(currentFile)) != EOF)
        {
            if (currentCharFile == currentCharIterator)
            {
                contador++;
            }
            else
            {
                //printf("%i%c", contador, currentCharIterator);
                fwrite(&contador, sizeof(int), 1, stdout);
                fwrite(&currentCharIterator, sizeof(char), 1, stdout);
                currentCharIterator = currentCharFile;
                contador = 1;
            }
        }
        fwrite(&contador, sizeof(int), 1, stdout);
        fwrite(&currentCharIterator, sizeof(char), 1, stdout);
        //printf("%i%c", contador, currentCharIterator);
        fclose(currentFile);
    }
    return 0;
}