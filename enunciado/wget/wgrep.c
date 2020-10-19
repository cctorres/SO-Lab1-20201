#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("wgrep: searchterm [file ...]\n");
        return 1;
    }
    char *stringWord = argv[1];

    for (int i = 2; i < argc; i++)
    {
        FILE *currentFile = fopen(argv[i], "r");
        if (currentFile == NULL)
        {
            printf("wgrep: cannot open file\n");
            return 1;
        }
        size_t numero_bytes = 0;
        //ssize_t y size_t son sinónimos de unsigned int
        char *cadena = NULL;
        ssize_t bytes_leidos = getline(&cadena, &numero_bytes, currentFile);
        while (bytes_leidos != -1)
        {
            if (strstr(cadena, stringWord) != NULL)
            {
                printf("%s", cadena);
            }
            bytes_leidos = getline(&cadena, &numero_bytes, currentFile);
        }
        fclose(currentFile);
    }
    return 0;
}