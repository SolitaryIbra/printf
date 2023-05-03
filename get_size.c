#include "main.h"

/**
 * get_size - aabbcc
 * @ormation: aabbcc
 * @myinti: aabbcc
 *
 * Return: aabbcc
 */
int get_size(const char *ormation, int *myinti)
{
	int flag_i = *myinti + 1;
	int area = 0;

	if (ormation[flag_i] == 'l')
		area = S_LONG;
	else if (ormation[flag_i] == 'h')
		area = S_SHORT;

	if (area == 0)
		*myinti = flag_i - 1;
	else
		*myinti = flag_i;

	return (area);
}
