#include "main.h"

/**
 * get_flags - aabbcc
 * @ormation: aabbcc
 * @myinti: aabbcc
 * Return: aabbcc
 */
int get_flags(const char *ormation, int *myinti)
{
	int myintj, flag_i;
	int clicker = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (flag_i = *myinti + 1; ormation[flag_i] != '\0'; flag_i++)
	{
		for (myintj = 0; FLAGS_CH[myintj] != '\0'; myintj++)
			if (ormation[flag_i] == FLAGS_CH[myintj])
			{
				clicker |= FLAGS_ARR[myintj];
				break;
			}

		if (FLAGS_CH[myintj] == 0)
			break;
	}

	*myinti = flag_i - 1;

	return (clicker);
}
