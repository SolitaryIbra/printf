#include "main.h"

/**
 * is_printable - aabbcc
 * @character: aabbcc
 *
 * Return: aabbcc
 */
int is_printable(char character)
{
	if (character >= 32 && character < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - aabbcc
 * @mybuff: aabbcc
 * @utfcode: aabbcc
 * @i: aabbcc
 * Return: aabbcc
 */
int append_hexa_code(char utfcode, char mybuff[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	
	if (utfcode < 0)
		utfcode *= -1;

	mybuff[i++] = '\\';
	mybuff[i++] = 'x';

	mybuff[i++] = map_to[utfcode / 16];
	mybuff[i] = map_to[utfcode % 16];

	return (3);
}

/**
 * is_digit - aabbcc
 * @character: aabbcc
 *
 * Return: aabbcc
 */
int is_digit(char character)
{
	if (character >= '0' && character <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - aabbcc
 * @mynum: aabbcc
 * @area: aabbcc
 *
 * Return: aabbcc
 */
long int convert_size_number(long int mynum, int area)
{
	if (area == S_LONG)
		return (mynum);
	else if (area == S_SHORT)
		return ((short)mynum);

	return ((int)mynum);
}

/**
 * convert_size_unsgnd - aabbcc
 * @mynum: aabbcc
 * @area: aabbcc
 *
 * Return: Casted value of mynum
 */
long int convert_size_unsgnd(unsigned long int mynum, int area)
{
	if (area == S_LONG)
		return (mynum);
	else if (area == S_SHORT)
		return ((unsigned short)mynum);

	return ((unsigned int)mynum);
}
