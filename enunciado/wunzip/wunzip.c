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
        printf("wzip: cannot open file\n");
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

    //FILE *fp;
    //char c;
    //int n;

    //n = 0;
    //while (--argc > 0) {
    //if ((fp = fopen(*++argv, "r")) == NULL)
    //return 1;
    //while (fread(&n, INTLEN, 1, fp)) {
    //fread(&c, ASCLEN, 1, fp);
    //while (n-- > 0)
    //printf("%c", c);
    //}
    //fclose(fp);
    //}
    fclose(currentFile);
    }
    return 0;
}