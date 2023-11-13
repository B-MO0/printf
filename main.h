#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int print_char(va_list arguments_list);
int print_str(va_list arguments_list);
int print_number(va_list arguments_list);
int print_number_recursive(int n);
#endif /** MAIN_H */
