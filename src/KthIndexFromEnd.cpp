/*
OVERVIEW: Given a string, return the letter at Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the letter at Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/

char KthIndexFromEnd(char *str, int K) {

	char *str1;
	int diff;
	if (K<0||str=='\0')
		return '\0';
	str1 = str;
	while (*str !='\0')
		str++;
	diff = str - str1;
	if (diff<K)
		return '\0';
	return*(str - K - 1);
}