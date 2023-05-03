#include "main.h"

void print_buffer(char mybuff[], int *buffing_indentation);

/**
 * _printf - aabbcc
 * @myformation: aabbcc
 * Return: aabbcc
 */
int _printf(const char *myformation, ...)
{
	int myint, outputed = 0, printed_chars = 0;
	int clicker, mywid, exact, area, buffing_indentation = 0;
	va_list list;
	char mybuff[BUFF_SIZE];

	if (myformation == NULL)
		return (-1);

	va_start(list, myformation);

	for (myint = 0; myformation && myformation[myint] != '\0'; myint++)
	{
		if (myformation[myint] != '%')
		{
			mybuff[buffing_indentation++] = myformation[myint];
			if (buffing_indentation == BUFF_SIZE)
				print_buffer(mybuff, &buffing_indentation);
			printed_chars++;
		}
		else
		{
			print_buffer(mybuff, &buffing_indentation);
			clicker = get_flags(myformation, &myint);
			mywid = get_width(myformation, &myint, list);
			exact = get_precision(myformation, &myint, list);
			area = get_size(myformation, &myint);
			++myint;
			outputed = handle_print(myformation, &myint, list, mybuff,
				clicker, mywid, exact, area);
			if (outputed == -1)
				return (-1);
			printed_chars += outputed;
		}
	}

	print_buffer(mybuff, &buffing_indentation);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer -aabbcc
 * @mybuff: aabbcc
 * @buffing_indentation: aabbcc
 */
void print_buffer(char mybuff[], int *buffing_indentation)
{
	if (*buffing_indentation > 0)
		write(1, &mybuff[0], *buffing_indentation);

	*buffing_indentation = 0;
}
