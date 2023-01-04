#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief This program finds all the possible combinations of 3 letters
 * 
 */
int main()
{	
    FILE * fp1;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    fp1 = fopen("output.txt", "w");
    if (fp1 == NULL )
        exit(EXIT_FAILURE);
    int ASCHIIOFFSET = 97;
        
    for (int i = 0; i <  26; i++){
        for (int j = 0; j <  26; j++){
            for (int k = 0; k <  26; k++){
                fprintf(fp1,"%c%c%c\n", i + ASCHIIOFFSET, j + ASCHIIOFFSET, k + ASCHIIOFFSET);
            }
        }
    }
        

    fclose(fp1);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}
