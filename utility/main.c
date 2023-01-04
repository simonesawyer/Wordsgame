#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Filters words list in a dictonary to be 3 letters or greater
 *  
 */
int main()
{	
    FILE * fp1;
    FILE * fp2;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    fp1 = fopen("words.txt", "r");
    fp2 = fopen("output.txt", "w");
    if (fp1 == NULL || fp2 == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp1)) != -1) {
        if(strlen(line) > 4){
            fprintf(fp2,"%s", line );
        }
        
    }

    fclose(fp1);
    fclose(fp2);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}
