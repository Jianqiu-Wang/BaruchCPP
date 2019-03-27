/* author: Jianqiu Wang
 * Read characters from keyboard and write to file
 */
#include <stdio.h>
#include <stdlib.h>
#define MAXINPUT 80   // assume no more than 80 chars per line

int main()
{
    printf("Type filename:\n");
    char filename[80];
    scanf("%s\n", filename);  
    
    /* create file handler */
    FILE* fp;
    fp = fopen(filename, "w+");
    if (fp == NULL)
    {
        printf("Create file error!");
        exit(1);
    }

    char* p;
    p = (char*)malloc(MAXINPUT*sizeof(char)); // allocate memory for one line of input
    
    int c;
    int count = 0; // char counter for one line
    while (p!=NULL)
    {
        c = getchar();
        if (c==1)
        {
            fprintf(fp, "CTRL + A is a correct ending.\n");
            break;
        }
        else if (c!='\n')
        {
            p[count] = c;
            count++;
        }
        else
        {   
            /* write line to file, reallocate meory, reset counter */
            fprintf(fp, "%s\n", p);
            p = (char*)malloc(MAXINPUT*sizeof(char));
            count = 0;
        }
    }
        
    free(p);
    fclose(fp); // close file handler
    return 0;
}
