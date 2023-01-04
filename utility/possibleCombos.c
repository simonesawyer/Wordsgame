#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replaceFirst(char * str, char oldChar, char newChar)
{
    int i=0;

    /* Run till end of string */
    while(str[i] != '\0')
    {
        /* If an occurrence of character is found */
        if(str[i] == oldChar)
        {
            str[i] = newChar;
            break;
        }

        i++;
    }
}
/**
 * @brief With a list of combinations and a list of words it finds if they are contained in the word list
 * 
 */
int main()
{	
    FILE * fp1;
    FILE * fp2;
    FILE * fp3;
    char * pch;
    char * line1 = NULL;
    size_t len1 = 0;
    ssize_t read1;
    char * line2 = NULL;
    size_t len2 = 0;
    ssize_t read2;
    fp1 = fopen("words.txt", "r");
    fp2 = fopen("combos.txt", "r");
    fp3 = fopen("output.txt", "w");

    if (fp1 == NULL )
        exit(EXIT_FAILURE);
    int ASCHIIOFFSET = 97;
    int test = 0;
    int a = 0;
    int b = 0;
    while ((read2 = getline(&line2, &len2, fp2)) != -1) {
        a++;
        while ((read1 = getline(&line1, &len1, fp1)) != -1) {
            b++;
            pch=strchr(line1,line2[0]);
            if(pch == NULL)continue;
            replaceFirst(line1, line2[0], '1');

            pch=strchr(line1,line2[1]);
            if(pch == NULL)continue;
            replaceFirst(line1, line2[1], '1');

            pch=strchr(line1,line2[2]);
            if(pch == NULL)continue;
            test = 1;
            break;
        }
        if(!test){
            fprintf(fp3,"%s", line2 );
            
        }
        test = 0;
        rewind(fp1);

    }
    printf("%d %d\n", a,b);

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    if (line1)
        free(line1);
    if (line2)
        free(line2);
    exit(EXIT_SUCCESS);
}
