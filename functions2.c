#include "main.h"
#include "unistd.h"

/**
 * print_pointer - aabbcc
 * @mytypes: aabbcc
 * @mybuff: aabbcc
 * @clicker:  aabbcc
 * @mywid: aabbcc
 * @exact: aabbcc
 * @area: aabbcc
 * Return: aabbcc
 */
int print_pointer(va_list mytypes, char mybuff[],
	int clicker, int mywid, int exact, int area)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(mytypes, void *);

	UNUSED(mywid);
	UNUSED(area);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	mybuff[BUFF_SIZE - 1] = '\0';
	UNUSED(exact);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		mybuff[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((clicker & F_ZERO) && !(clicker & F_MINUS))
		padd = '0';
	if (clicker & F_PLUS)
		extra_c = '+', length++;
	else if (clicker & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	return (write_pointer(mybuff, ind, length,
		mywid, clicker, padd, extra_c, padd_start));
}

/**
 * print_non_printable - aabbcc
 * @mytypes: aabbcc
 * @mybuff: aabbcc
 * @clicker:  aabbcc
 * @mywid: aabbcc
 * @exact: aabbcc
 * @area: aabbcc
 * Return: aabbcc
 */
int print_non_printable(va_list mytypes, char mybuff[],
	int clicker, int mywid, int exact, int area)
{
	int myint = 0, offset = 0;
	char *str = va_arg(mytypes, char *);

	UNUSED(clicker);
	UNUSED(mywid);
	UNUSED(exact);
	UNUSED(area);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[myint] != '\0')
	{
		if (is_printable(str[myint]))
			mybuff[myint + offset] = str[myint];
		else
			offset += append_hexa_code(str[myint], mybuff, myint + offset);

		myint++;
	}

	mybuff[myint + offset] = '\0';

	return (write(1, mybuff, myint + offset));
}

/**
 * print_reverse - aabbcc
 * @mytypes: aabbcc
 * @mybuff: aabbcc
 * @clicker:  aabbcc
 * @mywid: aabbcc
 * @exact: aabbcc
 * @area: aabbcc
 * Return: aabbcc
 */

int print_reverse(va_list mytypes, char mybuff[],
	int clicker, int mywid, int exact, int area)
{
	char *str;
	int myint, count = 0;

	UNUSED(mybuff);
	UNUSED(clicker);
	UNUSED(mywid);
	UNUSED(area);

	str = va_arg(mytypes, char *);

	if (str == NULL)
	{
		UNUSED(exact);

		str = ")Null(";
	}
	for (myint = 0; str[myint]; myint++)
		;

	for (myint = myint - 1; myint >= 0; myint--)
	{
		char z = str[myint];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/**
 * print_rot13string - aabbcc
 * @mytypes: aabbcc
 * @mybuff: aabbcc
 * @clicker:  aabbcc
 * @mywid: aabbcc
 * @exact: aabbcc
 * @area: aabbcc
 * Return: aabbcc
 */
int print_rot13string(va_list mytypes, char mybuff[],
	int clicker, int mywid, int exact, int area)
{
	char x;
	char *str;
	unsigned int myint, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(mytypes, char *);
	UNUSED(mybuff);
	UNUSED(clicker);
	UNUSED(mywid);
	UNUSED(exact);
	UNUSED(area);

	if (str == NULL)
		str = "(AHYY)";
	for (myint = 0; str[myint]; myint++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[myint])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[myint];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
