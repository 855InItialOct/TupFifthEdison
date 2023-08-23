#include <stdio.h>
#include <string.h>

int main()
{
	char c;
	int word = 0,num = 0;

	printf("Please enter a string of sentence:");

	while ((c =getchar())!='\n')
	{
		if (c!=' ')
		{
			if(word == 0)
			{
				word = 1;
				num++;
			}
		}
		else
		{
			word = 0;
		}
	}

	printf("There are %d words in this line.",num);
	
	return 0;
}
