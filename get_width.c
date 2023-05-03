#include "main.h"

/**
 * get_width - aabbcc
 * @ormation: aabbcc
 * @myinti: aabbcc
 * @vector: aabbcc
 *
 * Return: aabbcc
 */
int get_width(const char *ormation, int *myinti, va_list vector)
{
	int flag_i;
	int mywid = 0;

	for (flag_i = *myinti + 1; ormation[flag_i] != '\0'; flag_i++)
	{
		if (is_digit(ormation[flag_i]))
		{
			mywid *= 10;
			mywid += ormation[flag_i] - '0';
		}
		else if (ormation[flag_i] == '*')
		{
			flag_i++;
			mywid = va_arg(vector, int);
			break;
		}
		else
			break;
	}

	*myinti = flag_i - 1;

	return (mywid);
}
