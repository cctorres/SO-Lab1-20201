#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("wunzip: file1 [file2 ...]\n");
        return 1;
    }
    int unzipNumber;
    char unzipChar;
    
    for (int i = 1; i < argc; i++)
    {
    FILE *currentFile = fopen(argv[i], "r");
    if (currentFile == NULL)
    {
        printf("wunzip: cannot open file\n");
        return 1;
    }
    while (argc !=0)
    {
        while (fread(&unzipNumber, 4, 1, currentFile))
        {
            fread(&unzipChar, 1, 1, currentFile);
             while (unzipNumber != 0)
            {
                printf("%c", unzipChar);
                unzipNumber = unzipNumber - 1;
            }
        }
        argc = argc - 1;
    }
    fclose(currentFile);
    }
    return 0;
}