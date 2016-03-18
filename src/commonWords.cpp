/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".


INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>

#include <malloc.h>

#define SIZE 31
int isStringMatch(char *str1, char *str2, int m, int n)
{
	int i = 0, k = 0;
	char *temp;
	temp = (char *)malloc(sizeof(char)*(n - m));
	for (i = m; i<n; i++)
		temp[i - m] = str2[i];
	i = 0;
	while ((str1[i] == ' ') && (str1[i] != '\0'))
		i++;
	while((str1[i] != '\0'))
	{
		if ((str1[i] == temp[k]) && (str1[i]!=NULL))
		{
			i++;
			k++;
		}
		else if ((k == n - m) && (str1[i]==' '))
			return 1;
		else
		{
			i++;
			k = 0;
		}
	}
	return 0;
}
char ** commonWords(char *str1, char *str2) {
	char **retstr;
	int i = 0, j = 0, k, ind = 0, l, m, var, len;
	if (str1 == NULL || str2 == NULL)
		return NULL;
	retstr = (char **)malloc(sizeof(char*) *SIZE);
	while (str2[j] != '\0')
		j++;
	len = j;
	while (i<len)
	{
		j = i;
		while ((str2[j] != ' ') && (str2[j] != '\0'))
			j++;
		k = isStringMatch(str1, str2, i, j);
		if (k == 1)
		{
			var = j - i + 1;
			retstr[ind] = (char*)malloc(var*sizeof(char));
			for (m = i, l = 0; m < j; m++, l++)
				retstr[ind][l] = str2[m];
			retstr[ind][l] = '\0';
			ind++;
		}
		i = j + 1;
	}
	if (k == 0)
		return NULL;
	return retstr;
}