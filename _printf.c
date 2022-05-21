#include "main.h"
#include <stdarg.h>
#include <stddef.h>
int _printf (const char * const format, ...)
{
	va_list args;
	int i = 0, k = 0, num = 0;
	int n_displayed = 0;
	char *str = NULL;

	va_start (args, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			n_displayed++;
		}
		else
		{
		    if (format[i + 1] == 'c')
		    {
			_print_char(va_arg(args, int));
			n_displayed++;
			i++;
		}
		    else if (format[i + 1] == 's')
		    {
			    i++;
			    _print_str(args);
		    }
		    else if (format[i + 1] == '%')
		    {
			    i++;
			    _putchar('%');
			    n_displayed++;
		    }
		    else if (format[i + 1] == 'd')
		    {
			    i++;
			    _print_int (va_arg(args, int));
		    }
		}

		i++;
	}

	va_end (args);

	return (n_displayed);
}
