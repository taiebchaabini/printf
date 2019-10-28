#include <stdio.h>
#include <stdarg.h>
#include "holberton.h"
/**
* _printf - prints anything
* @format: pointer to string that contains specifiers
* Return: number of characters printed
**/
int _printf(const char *format, ...)
{
unsigned int count = 0, i = 0;
int (*f)(va_list);
va_list list;

if (format == '\0')
return (-1);
va_start(list, format);
while (format && format[i])
{
if (format[i] != '%')
{
_putchar(format[i]);
count++;
}
else if (format[i] == '%' && format[i + 1] == '\0')
return (-1);
else if (format[i] == '\0')
return (count);
else if (format[i] == '%')
{
f = getspecifier(format[i + 1]);
i += 1;
if (f == '\0')
{
if (format[i] != '%')
{
_putchar(format[i - 1]);
count += 1;
}
_putchar(format[i]);
count += 1;
}
else
count = count + f(list);
}
i++;
}
va_end(list);
return (count);
}
