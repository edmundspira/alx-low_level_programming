#include "main.h"

int check_palindrome(char *s);

/**
 * is_palindrome - Returns if a string is palindrome
 * @s: the string value to be checked
 * Return: integer value
 */

int is_palindrome(char *s)
{
	if (*s == '0')
		return (1);

	return (check_palindrome(s));
}

/**
 * check_palindrome - Check if a string is palindrome
 * @s: the string value to be checked
 *
 * Return: integer value
 */

int check_palindrome(char *s)
{
	int l = _strlen_recursion(s) - 1;

	if (*s == s[l])
	{
		s++;
		l--;
	}
	else
	{
		return (0);
	}

	return (1);
}

/**
 * _strlen_recursion - Get the length of a string
 * @s: the string to get the length
 *
 * Return: the string length
 */

int _strlen_recursion(char *s)
{
	if (*s == '\0')
	{
		return (0);
	}

	s++;
	return (_strlen_recursion(s) + 1);
}

int is_palindrome(char *);

/**
 * main - check the code
 * Return: Always 0.
 */

int main(void)
{
	int r;

	r = is_palindrome("I guess I thought the dream-space would be all about the visual, but it's more about the feeling. My question is what happens when you start messing with the physics of it.ti fo scisyhp eht htiw gnissem trats uoy nehw sneppah tahw si noitseuq yM .gnileef eht tuoba erom s'ti tub ,lausiv eht tuoba lla eb dluow ecaps-maerd eht thguoht I sseug I");
	printf("%d\n", r);
	return (0);
}
