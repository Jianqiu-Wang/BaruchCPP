/* author: Jianqiu Wang
Read text input from keyboard, and output amount of characters, words, and new lines 
Use do-while loop */
#include <stdio.h>

int main()
{
    int next_ch; // next charcter from input
    int last_ch = '\n'; // last charcter, to test if there are consectutive spaces
    
    int num_char = 0; // number of characters
    int num_word = 0; // number of words
    int num_line = 0; // number of lines
    int num_space = 0;// number of spaces
    
    do
    {
        next_ch = getchar();        

        if (next_ch == '\n') 
        {
            num_line = num_line + 1;
            /* if last char is not a space or next line, and next one is a space, count as a word */
            if (last_ch != ' ' & last_ch != '\n')
            {
                num_word = num_word + 1;
            }    
        }
        
        if (next_ch == ' ')
        {
            num_space =  num_space + 1;    
            /* if last char is a non-space and next one is a space, count as a word */
            if (last_ch != ' ' & last_ch != '\n')
            {
                num_word = num_word + 1;
            }        
        }

        /* update last character and number of chars*/
        if (next_ch != EOF)
        {
            num_char = num_char + 1;
            last_ch = next_ch;
        }
        
    } while (next_ch!= EOF);

    /* handle EOF, if no space before ctrl-d, should test if there is a word at end of input */
    if (next_ch == EOF & last_ch != ' ' & last_ch != '\n') 
    {
        num_word = num_word + 1;
    }

    printf("number of characters: %d\n", num_char);
    printf("number of words: %d\n", num_word);
    printf("number of lines: %d\n", num_line);
    printf("number of sapces: %d\n", num_space);

    return 0; 
}