#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        fprintf(stderr, "Invalid arguments!\n");
        return EXIT_FAILURE;
    }

    if (!strcmp(argv[3], "-TB"))
    {
        uint16_t num;
        FILE *fr = fopen(argv[1], "r");
        if (NULL == fr)
        {
            fprintf(stderr, "Reading problem!\n");
            return EXIT_FAILURE;
        }
        FILE *fw = fopen(argv[2], "wb");
        if (NULL == fw)
        {
            fprintf(stderr, "Writing problem!\n");
            return EXIT_FAILURE;
        }
        while (fscanf(fr, "%hd", &num) != EOF)
        {
            fwrite(&num, sizeof(num), 1, fw);
        }
        fclose(fw);
        fclose(fr);
        printf("Writing successfull!\n");
    }
    else if (!strcmp(argv[3], "-BT"))
    {
        uint16_t num;
        FILE *fr = fopen(argv[1], "rb");
        if (NULL == fr)
        {
            fprintf(stderr, "Reading problem!\n");
            return EXIT_FAILURE;
        }
        FILE *fw = fopen(argv[2], "w");
        if (NULL == fw)
        {
            fprintf(stderr, "Writing problem!\n");
            return EXIT_FAILURE;
        }
        while (fread(&num, sizeof(num), 1, fr))
        {
            fprintf(fw, "%hd\n", num);
        }
        fclose(fw);
        fclose(fr);
        printf("Writing successfull!\n");
    }
    else
    {
        fprintf(stderr, "Invalid option!\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}