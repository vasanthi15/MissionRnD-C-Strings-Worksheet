/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>


void number_to_str(float number, char *str,int afterdecimal){
	long int num;
	int temp, i = 0, len = 0, flag = 0;
	temp = afterdecimal;
	while (temp--)
	{
		number *= 10;
	}
	num = number;
	temp = 1;
	while (num != 0)
	{
		num /= 10;
		temp *= 10;
		len++;
	}
	temp /= 10;
	num = number;
	if (num<0)
	{
		str[i++] = '-';
		flag = -1;
		num *= -1;
	}
	while (temp != 0)
	{
		if (afterdecimal == len - i - flag)
			str[i] = '.';
		else
		{
			str[i] = num / temp + 48;
			num %= temp;
			temp /= 10;
		}
		i++;
	}
	str[i] = '\0';
}
