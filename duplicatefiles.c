#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    // declaring a pointer to link the file to my code
    FILE *file;
    file = fopen("files.in", "r");

    // Program exits if the file pointer returns NULL
    if (file == NULL)
    {
        printf("Error! opening file");
        exit(1);
    }
    int folder;
    fscanf(file, "%d", &folder);
    for (int i = 0; i < folder; i++)
    {
        int no_of_file;
        fscanf(file, "%d", &no_of_file);
        char file_names[no_of_file][100];
        int file_id[no_of_file];

        for (int j = 0; j < no_of_file; j++)
        {
            int idCompare;
            char file_name[100];
            fscanf(file, "%s", file_name);
            int fileExist;

            for (int i = 0; i < no_of_file; i++)
            {
                // checking if the file exist in the main array i.e file_names
                if (!strcmp(file_names[i], file_name))
                {
                    fileExist = i;
                    break;
                }
                else
                {

                    fileExist = -1;
                }
            }

            fscanf(file, "%d", &idCompare);

            // if the file doesn't exist yet add it to the file array i.e file_names
            if (fileExist == -1)
            {
                strcpy(file_names[j], file_name);
                file_id[j] = idCompare;
            }
            else
            { // if the file exist compare the ID with the already existing file ID
                if (file_id[fileExist] <= idCompare)
                {
                    strcpy(file_names[j], file_name);
                }
                else
                {
                    strcpy(file_names[j], file_name);
                    file_id[fileExist] = idCompare;
                    file_id[j] = -1;
                }
            }
        }
        int sort;
        for(int i = 0; i < no_of_file; i++){
            for(int j = i + 1; j < no_of_file; j++){
                if(file_id[i]>file_id[j]){
                    sort = file_id[i];
                    file_id[i] = file_id[j];
                    file_id[j] = sort;
                }
            }
        }
        for(int a = 0; a < no_of_file; a++){
            if (file_id[a] != -1){
                printf("%d ", file_id[a]);
            }
        }        
        printf("\n");
    }
}