/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/
#include<stdio.h>
#include<stddef.h>
char removeSpaces(char *str) {
	int i = 0, j, k;
	if (str == NULL)
		return '\0';
	if (str == "")
		return NULL;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
		{
			k = i;
			j = i + 1;
			while (str[j] != '\0')
			{
				str[i] = str[j];
				i++;
				j++;
				while (str[j] == ' ')
					j++;
			}
			str[i] = '\0';
			i = k;
		}
		i++;
	}
	return *str;
}