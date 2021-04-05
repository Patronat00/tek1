/*
** EPITECH PROJECT, 2019
** test.c
** File description:
** tests
*/

Test(my_printf_simpleflags, simple_string)
{
    my_printf_simpleflags("bonjour");
    cr_assert("bonjour");
    my_printf_simpleflags("bonjour = %d" , 66);
    cr_assert("bonjour = 66\n");
}

Test(my_printf_simpleflags_octal, simplie_string)
{
    my_printf_simpleflags("10 = %o", 12);
    cr_assert("12\n");
}

Test(my_printf_simpleflags_octal, simplie_string)
{
    my_printf_simpleflags("10 = %o", 12);
    cr_assert("12\n");
}

Test(my_printf_c, simple_string)
{
    my_printf_simpleflags("A = %c");
    cr_assert("A\n");
}

Test(my_printf_S, simple_string)
{
    my_printf_simpleflags("bonjour = %S");
    cr_assert("bonjour\n");
}
