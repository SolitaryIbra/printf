#include "main.h"

/**
* handle_write_char - aabbcc
* @character: aabbcc
* @mybuff: aabbcc
* @clicker:  aabbcc
* @mywid: aabbcc
* @exact: aabbcc
* @area: aabbcc
*
* Return: aabbcc
*/
int handle_write_char(char character, char mybuff[],
int clicker, int mywid, int exact, int area)
{
int myinti = 0;
char extra_padd = ' ';

UNUSED(exact);
UNUSED(area);

if (clicker & F_ZERO)
extra_padd = '0';

mybuff[myinti++] = character;
mybuff[myinti] = '\0';

if (mywid > 1)
{
mybuff[BUFF_SIZE - 1] = '\0';
for (myinti = 0; myinti < mywid - 1; myinti++)
mybuff[BUFF_SIZE - myinti - 2] = extra_padd;

if (clicker & F_MINUS)
return (write(1, &mybuff[0], 1) +
write(1, &mybuff[BUFF_SIZE - myinti - 1], mywid - 1));
else
return (write(1, &mybuff[BUFF_SIZE - myinti - 1], mywid - 1) +
write(1, &mybuff[0], 1));
}

return (write(1, &mybuff[0], 1));
}

/**
* write_number - aabbcc
* @is_nve: aabbcc
* @myindent: aabbcc
* @mybuff: aabbcc
* @clicker: aabbcc
* @mywid: aabbcc
* @exact: aabbcc
* @area: aabbcc
*
* Return: aabbcc
*/
int write_number(int is_nve, int myindent, char mybuff[],
int clicker, int mywid, int exact, int area)
{
int mylen = BUFF_SIZE - myindent - 1;
char extra_padd = ' ', extra_ch = 0;

UNUSED(area);

if ((clicker & F_ZERO) && !(clicker & F_MINUS))
extra_padd = '0';
if (is_nve)
extra_ch = '-';
else if (clicker & F_PLUS)
extra_ch = '+';
else if (clicker & F_SPACE)
extra_ch = ' ';

return (write_num(myindent, mybuff, clicker, mywid, exact,
mylen, extra_padd, extra_ch));
}

/**
* write_num - aabbcc
* @myindent: aabbcc
* @mybuff: aabbcc
* @clicker: aabbcc
* @mywid: aabbcc
* @prec: aabbcc
* @mylen: aabbcc
* @extra_padd: aabbcc
* @extra_character: aabbcc
*
* Return: aabbcc
*/
int write_num(int myindent, char mybuff[],
int clicker, int mywid, int prec,
int mylen, char extra_padd, char extra_character)
{
int myinti, padd_start = 1;

if (prec == 0 && myindent == BUFF_SIZE - 2 && mybuff[myindent]
== '0' && mywid == 0)
return (0);
if (prec == 0 && myindent == BUFF_SIZE - 2 && mybuff[myindent] == '0')
mybuff[myindent] = extra_padd = ' ';
if (prec > 0 && prec < mylen)
extra_padd = ' ';
while (prec > mylen)
mybuff[--myindent] = '0', mylen++;
if (extra_character != 0)
mylen++;
if (mywid > mylen)
{
for (myinti = 1; myinti < mywid - mylen + 1; myinti++)
mybuff[myinti] = extra_padd;
mybuff[myinti] = '\0';
if (clicker & F_MINUS && extra_padd == ' ')
{
if (extra_character)
mybuff[--myindent] = extra_character;
return (write(1, &mybuff[myindent], mylen)
+ write(1, &mybuff[1], myinti - 1));
}
else if (!(clicker & F_MINUS) && extra_padd == ' ')
{
if (extra_character) 
mybuff[--myindent] = extra_character;
return (write(1, &mybuff[1], myinti - 1)
+ write(1, &mybuff[myindent], mylen));
}
else if (!(clicker & F_MINUS) && extra_padd == '0')
{
if (extra_character) 
mybuff[--padd_start] = extra_character;
return (write(1, &mybuff[padd_start], myinti - padd_start) +
write(1, &mybuff[myindent], mylen - (1 - padd_start)));
}
}
if (extra_character)
mybuff[--myindent] = extra_character;
return (write(1, &mybuff[myindent], mylen));
}

/**
* write_unsgnd - aabbcc
* @is_nve: aabbcc
* @myindent: aabbcc
* @mybuff: aabbcc
* @clicker: aabbcc
* @mywid: aabbcc
* @exact: aabbcc
* @area: aabbcc
*
* Return: aabbcc
*/
int write_unsgnd(int is_nve, int myindent,
char mybuff[],
int clicker, int mywid, int exact, int area)
{
int mylen = BUFF_SIZE - myindent - 1, myinti = 0;
char extra_padd = ' ';

UNUSED(is_nve);
UNUSED(area);

if (exact == 0 && myindent == BUFF_SIZE - 2 && mybuff[myindent] == '0')
return (0);

if (exact > 0 && exact < mylen)
extra_padd = ' ';

while (exact > mylen)
{
mybuff[--myindent] = '0';
mylen++;
}

if ((clicker & F_ZERO) && !(clicker & F_MINUS))
extra_padd = '0';

if (mywid > mylen)
{
for (myinti = 0; myinti < mywid - mylen; myinti++)
mybuff[myinti] = extra_padd;

mybuff[myinti] = '\0';

if (clicker & F_MINUS)
{
return (write(1, &mybuff[myindent], mylen) + write(1, &mybuff[0], myinti));
}
else
{
return (write(1, &mybuff[0], myinti) + write(1, &mybuff[myindent], mylen));
}
}

return (write(1, &mybuff[myindent], mylen));
}

/**
* write_pointer - aabbcc
* @mybuff: aabbcc
* @myindent: aabbcc
* @mylen: aabbcc
* @mywid: aabbcc
* @clicker: aabbcc
* @extra_padd: aabbcc
* @extra_character: aabbcc
* @padd_start: aabbcc
*
* Return: aabbcc
*/
int write_pointer(char mybuff[], int myindent, int mylen,
int mywid, int clicker, char extra_padd, char extra_character, int padd_start)
{
int myinti;

if (mywid > mylen)
{
for (myinti = 3; myinti < mywid - mylen + 3; myinti++)
mybuff[myinti] = extra_padd;
mybuff[myinti] = '\0';
if (clicker & F_MINUS && extra_padd == ' ')
{
mybuff[--myindent] = 'x';
mybuff[--myindent] = '0';
if (extra_character)
mybuff[--myindent] = extra_character;
return (write(1, &mybuff[myindent], mylen)
+ write(1, &mybuff[3], myinti - 3));
}
else if (!(clicker & F_MINUS) && extra_padd == ' ')
{
mybuff[--myindent] = 'x';
mybuff[--myindent] = '0';
if (extra_character)
mybuff[--myindent] = extra_character;
return (write(1, &mybuff[3], myinti - 3) +
write(1, &mybuff[myindent], mylen));
}
else if (!(clicker & F_MINUS) && extra_padd == '0')
{
if (extra_character)
mybuff[--padd_start] = extra_character;
mybuff[1] = '0';
mybuff[2] = 'x';
return (write(1, &mybuff[padd_start], myinti - padd_start) +
write(1, &mybuff[myindent], mylen - (1 - padd_start) - 2));
}
}
mybuff[--myindent] = 'x';
mybuff[--myindent] = '0';
if (extra_character)
mybuff[--myindent] = extra_character;
return (write(1, &mybuff[myindent], BUFF_SIZE - myindent - 1));
}
