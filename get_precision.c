#include "main.h"

/**
 * get_precision - aabbcc
 * @ormation: aabbcc
 * @myinti: aabbcc
 * @vector: aabbcc
 *
 * Return: aabbcc
 */
int get_precision(const char *ormation, int *myinti, va_list vector)
{
	int flag_i = *myinti + 1;
	int exact = -1;

	if (ormation[flag_i] != '.')
		return (exact);

	exact = 0;

	for (flag_i += 1; ormation[flag_i] != '\0'; flag_i++)
	{
		if (is_digit(ormation[flag_i]))
		{
			exact *= 10;
			exact += ormation[flag_i] - '0';
		}
		else if (ormation[flag_i] == '*')
		{
			flag_i++;
			exact = va_arg(vector, int);
			break;
		}
		else
			break;
	}

	*myinti = flag_i - 1;

	return (exact);
}
