#include <ctype.h>
#include <string.h>
#include "strops.h"

char	*str_reverse(char *str)
{
	char *string = NULL;
	strcpy(str, string);
	size_t length = strlen(string);
	char *start = &string[0];
	char *end = &string[length - 1];
	char *temp;
	for (size_t i = 0; i < length/2; i++)
	{
		temp = start;
		start = end;
		end = temp;
		start++;
		end--;
	}
	return string;
}

char	*str_upper(char *str)
{
	char *string = NULL;
	strcpy(str, string);
	for (char *point = &string[0]; *point != '\0'; point++)
	{
		if (islower(*point)) {
			*point = toupper(*point);
		}
	}
	return string;
}

char	*str_lower(char *str)
{
	char *string = NULL;
	strcpy(str, string);
	for (char *point = &string[0]; *point != '\0'; point++)
	{
		if (isupper(*point)) {
			*point = tolower(*point);
		}
	}
	return string;
}

bool	str_equal(char *str1, char *str2)
{
	size_t count = 0;
	char *point = str1;
	char *point_two = str2;
	for(; *point != '\0'; point++) {
		if (*point == *point_two) {
			point_two++;
			count++;
		}
	}
	if (count == strlen(str1)) {
		return true;
	}
	return false;
}

bool	str_startswith(char *str, char comparison)
{
	if (str[0] == comparison)
	{
		return true;
	}
	return false;
}

bool	str_endswith(char *str, char comparison)
{
	if (str[strlen(str) - 1] == comparison)
	{
		return true;
	}
	return false;
}

// WARNING: Does not work
char 	*str_replace(char *str, char *target, char *replacement)
{
	bool str_flag;
	size_t split_location = 0;
	for (char *point = &str[0]; *point != '\0'; point++)
	{
		split_location++;
		str_flag = str_equal(target, str);
		if (str_flag) {
			break;
		}
	}
	if (str_flag) {
		// Goal is to split the string up and then rebuild it with the replacement data
		// Will do this a bit later
		char *begin = NULL, *end;
		strncpy(begin, str, split_location);
		end = &str[split_location + strlen(target)];
		strcat(begin, replacement);
		strcat(begin, end);
		return begin;
	}
	return str;
}
