#include <stdio.h>
#include <ctype.h>

int main() 
{
    char article[3][80];
    int upper = 0, lower = 0, space = 0, number = 0, other = 0;
    for (int i = 0; i < 3; ++i) 
    {
        gets(article[i]);
        for (int j = 0; j < 80; ++j) 
        {
            if(isupper(article[i][j]))
                upper++;
            else if(islower(article[i][j]))
                lower++;
            else if(isspace(article[i][j]))
                space++;
            else if(isdigit(article[i][j]))
                number++;
            else
                other++;
        }
    }
    printf("Uppercase:%d\n", upper);
    printf("Lowercase:%d\n", lower);
    printf("Space:%d\n", space);
    printf("Number:%d\n", number);
    printf("Other:%d\n", other);

    return 0;
}