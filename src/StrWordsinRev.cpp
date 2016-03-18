/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
void findreverse(char *input, int beg, int end)
{
	char c;
	int i;
	for (i = 0; i<(end - beg) / 2 + 1; i++)
	{
		c = input[beg + i];
		input[beg + i] = input[end - i];
		input[end - i] = c;
	}
}
void str_words_in_rev(char *input, int len){
	int beg = 0, end = len - 1, i = 0, k = 0;
	findreverse(input, beg, end);
	while (1)
	{
		if ((input[i] == ' ') || (input[i] == '\0'))
		{
			findreverse(input + k, 0, i - k - 1);
			if (input[i] == '\0')
				break;
			k = i + 1;
		}
		i++;
	}
}
