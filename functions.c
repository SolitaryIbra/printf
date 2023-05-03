#include "main.h"


/**
 * print_char - aabbcc
 * @mytypoes: aabbcc
 * @mybuff: aabbcc
 * @clicks:  aabbcc
 * @wid: aabbcc
 * @exact: aabbcc
 * @area: aabbcc
 * Return: aabbcc
 */
int print_char(va_list mytypoes, char mybuff[],
	int clicks, int wid, int exact, int area)
{
	char c = va_arg(mytypoes, int);

	return (handle_write_char(c, mybuff, clicks, wid, exact, area));
}

/**
 * print_string - aabbcc
 * @mytypoes: aabbcc
 * @mybuff: aabbcc
 * @clicks:  aabbcc
 * @wid: aabbcc
 * @exact: aabbcc
 * @area: aabbcc
 * Return: aabbcc
 */
int print_string(va_list mytypoes, char mybuff[],
	int clicks, int wid, int exact, int area)
{
	int length = 0, i;
	char *s = va_arg(mytypoes, char *);

	UNUSED(mybuff);
	UNUSED(clicks);
	UNUSED(wid);
	UNUSED(exact);
	UNUSED(area);
	if (s == NULL)
	{
		s = "(null)";
		if (exact >= 6)
			s = "      ";
	}

	while (s[length] != '\0')
		length++;

	if (exact >= 0 && exact < length)
		length = exact;

	if (wid > length)
	{
		if (clicks & F_MINUS)
		{
			write(1, &s[0], length);
			for (i = wid - length; i > 0; i--)
				write(1, " ", 1);
			return (wid);
		}
		else
		{
			for (i = wid - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &s[0], length);
			return (wid);
		}
	}

	return (write(1, s, length));
}

/**
 * print_percent - aabbcc
 * @mytypoes: aabbcc
 * @mybuff: aabbcc
 * @clicks:  aabbcc
 * @wid: aabbcc
 * @exact: aabbcc
 * @area: aabbcc
 * Return: aabbcc
 */
int print_percent(va_list mytypoes, char mybuff[],
	int clicks, int wid, int exact, int area)
{
	UNUSED(mytypoes);
	UNUSED(mybuff);
	UNUSED(clicks);
	UNUSED(wid);
	UNUSED(exact);
	UNUSED(area);
	return (write(1, "%%", 1));
}

/**
 * print_int - aabbcc
 * @mytypoes: aabbcc
 * @mybuff: aabbcc
 * @clicks:  aabbcc
 * @wid: aabbcc
 * @exact: aabbcc
 * @area: aabbcc
 * Return: aabbcc
 */
int print_int(va_list mytypoes, char mybuff[],
	int clicks, int wid, int exact, int area)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(mytypoes, long int);
	unsigned long int num;

	n = convert_size_number(n, area);

	if (n == 0)
		mybuff[i--] = '0';

	mybuff[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		mybuff[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, mybuff, clicks, wid, exact, area));
}

/**
 * print_binary - aabbcc
 * @mytypoes: aabbcc
 * @mybuff: aabbcc
 * @clicks:  aabbcc
 * @wid: aabbcc
 * @exact: aabbcc
 * @area: aabbcc
 * Return: aabbcc
 */
int print_binary(va_list mytypoes, char mybuff[],
	int clicks, int wid, int exact, int area)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(mybuff);
	UNUSED(clicks);
	UNUSED(wid);
	UNUSED(exact);
	UNUSED(area);

	n = va_arg(mytypoes, unsigned int);
	m = 2147483648;
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
