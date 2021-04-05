/*
** EPITECH PROJECT, 2019
** my_printf.c
** File description:
** pritnf
*/

#include <stdarg.h>
#include <stdio.h>
#include "include/my.h"
#include <criterion/criterion.h>

int my_printf_flags2(const char *format, ...)
{
    va_list ap;
    va_start (ap, format);
    int i = 1;

    switch (format[i]) {
    case 'b' :
        decimal_to_binary(va_arg(ap, int));
        break;
    case 'X' :
        decToHexa(va_arg(ap, int));
        my_putchar('\n');
        break;
    case 'x' :
        decToLittleHexa(va_arg(ap, int));
        my_putchar('\n');
        break;
        default:
            va_end(ap);
    }
}

int my_printf_othersflags(const char *format, ...)
{
    va_list ap;
    va_start (ap, format);
    int i = 1;
    int number;

    switch (format[i]) {
    case 'o' :
        decimal_to_octal(va_arg(ap, int));
            break;
    case 'u':
        number = va_arg(ap, int);
        if (number >= 0) {
            my_put_nbr(number);
            my_putchar('\n');
        }
        else {
        number = number * (-1);
        my_put_nbr(number);
        my_putchar('\n');
        }
        break;
    default:
        my_printf_flags2(format);
        va_end(ap);
    }
}

int my_printf(const char *format,...)
{
    va_list ap;
    va_list index;
    int i = 1;


    va_start(ap, format);

    switch (format[i]) {
    case 'd' : case 'i' :
        my_put_nbr(va_arg(ap, int));
        my_putchar('\n');
        break;
    case 'c':
        my_putchar(va_arg(ap, int));
        my_putchar('\n');
        break;
    case 's':
        my_putstr(va_arg(ap, char*));
        my_putchar('\n');
        break;
    default:
        my_printf_othersflags(format);
        va_end(ap);
    }
}