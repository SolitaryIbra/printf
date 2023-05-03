#include "main.h"
/**
 * handle_print - aabbcc
 * @myform: aabbcc
 * @vector: aabbcc
 * @intedation: aabbcc
 * @mybuff: aabbcc
 * @clicker: aabbcc
 * @mywid: aabbcc
 * @exact: aabbcc
 * @area: aabbcc
 * Return: aabbcc
 */
int handle_print(const char *myform, int *intedation, va_list vector, char mybuff[],
	int clicker, int mywid, int exact, int area)
{
	int i, unknow_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].myform != '\0'; i++)
		if (myform[*intedation] == fmt_types[i].myform)
			return (fmt_types[i].fn(vector, mybuff, clicker, mywid, exact, area));

	if (fmt_types[i].myform == '\0')
	{
		if (myform[*intedation] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (myform[*intedation - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (mywid)
		{
			--(*intedation);
			while (myform[*intedation] != ' ' && myform[*intedation] != '%')
				--(*intedation);
			if (myform[*intedation] == ' ')
				--(*intedation);
			return (1);
		}
		unknow_len += write(1, &myform[*intedation], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
