#include "main.h"

/**
 * print_unsigned - aabbcc
 * @mytypoes: aabbcc
 * @mybuff: aabbcc
 * @checker:  aabbcc
 * @wid: aabbcc
 * @exact: aabbcc
 * @area: aabbcc
 * Return: aabbcc
 */
int print_unsigned(va_list mytypoes, char mybuff[],
	int checker, int wid, int exact, int area)
{
	int myint = BUFF_SIZE - 2;
	unsigned long int num = va_arg(mytypoes, unsigned long int);

	num = convert_size_unsgnd(num, area);

	if (num == 0)
		mybuff[myint--] = '0';

	mybuff[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		mybuff[myint--] = (num % 10) + '0';
		num /= 10;
	}

	myint++;

	return (write_unsgnd(0, myint, mybuff, checker, wid, exact, area));
}

/**
 * print_octal - aabbcc
 * @mytypoes: aabbcc
 * @mybuff: aabbcc
 * @checker:  aabbcc
 * @wid: aabbcc
 * @exact: aabbcc
 * @area: aabbcc
 * Return: aabbcc
 */
int print_octal(va_list mytypoes, char mybuff[],
	int checker, int wid, int exact, int area)
{

	int myint = BUFF_SIZE - 2;
	unsigned long int num = va_arg(mytypoes, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(wid);

	num = convert_size_unsgnd(num, area);

	if (num == 0)
		mybuff[myint--] = '0';

	mybuff[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		mybuff[myint--] = (num % 8) + '0';
		num /= 8;
	}

	if (checker & F_HASH && init_num != 0)
		mybuff[myint--] = '0';

	myint++;

	return (write_unsgnd(0, myint, mybuff, checker, wid, exact, area));
}

/**
 * print_hexadecimal - aabbcc
 * @mytypoes: aabbcc
 * @mybuff: aabbcc
 * @checker: aabbcc
 * @wid: aabbcc
 * @exact: aabbcc
 * @area: aabbcc
 * Return: aabbcc
 */
int print_hexadecimal(va_list mytypoes, char mybuff[],
	int checker, int wid, int exact, int area)
{
	return (print_hexa(mytypoes, "0123456789abcdef", mybuff,
		checker, 'x', wid, exact, area));
}

/**
 * print_hexa_upper - aabbcc
 * @mytypoes: aabbcc
 * @mybuff: aabbcc
 * @checker:  aabbcc
 * @wid: aabbcc
 * @exact: aabbcc
 * @area: aabbcc
 * Return: aabbcc
 */
int print_hexa_upper(va_list mytypoes, char mybuff[],
	int checker, int wid, int exact, int area)
{
	return (print_hexa(mytypoes, "0123456789ABCDEF", mybuff,
		checker, 'X', wid, exact, area));
}

/**
 * print_hexa - aabbcc
 * @mytypoes: aabbcc
 * @map_to: aabbcc
 * @mybuff: aabbcc
 * @checker:  aabbcc
 * @flag_ch: aabbcc
 * @wid: aabbcc
 * @exact: aabbcc
 * @area: aabbcc
 * Return: aabbcc
 */
int print_hexa(va_list mytypoes, char map_to[], char mybuff[],
	int checker, char flag_ch, int wid, int exact, int area)
{
	int myint = BUFF_SIZE - 2;
	unsigned long int num = va_arg(mytypoes, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(wid);

	num = convert_size_unsgnd(num, area);

	if (num == 0)
		mybuff[myint--] = '0';

	mybuff[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		mybuff[myint--] = map_to[num % 16];
		num /= 16;
	}

	if (checker & F_HASH && init_num != 0)
	{
		mybuff[myint--] = flag_ch;
		mybuff[myint--] = '0';
	}

	myint++;

	return (write_unsgnd(0, myint, mybuff, checker, wid, exact, area));
}
