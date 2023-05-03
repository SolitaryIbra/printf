#include <unistd.h>
/**
 * _putchar - aabbcc
 * @character: aabbcc
 * Return: aabbcc
 */
int _putchar(char character)
{
	return (write(1, &character, 1));
}
