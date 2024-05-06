/*
Files: ft_printf.c

Function 'ft_printf' that mimics the real printf
(managing only the following conversions: s,d and x)
*/

#include <stdarg.h>
#include <unistd.h>

/**
 * @param str String to iterate
 * @return Length of the str passed as argument
 */
int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

/**

 * @brief Writes the char passed as argument and increments the bytes 
	pointer variable on success and changes it to -1 on failure.
 * @param c Char to print
 * @param bytes Int pointer to bytes variable
 * @return None
 */
void	pf_putchar(char c, int *bytes)
{
	if (write(1, &c, 1) == -1)
		*bytes = -1;
	else
		*bytes += 1;
}

/**

 * @brief Checks that the string exists or changes its content to "(null)".
	Calls pf_putchar with each char of the str passed as argument checking
	that no previous write have failed.
 * @param str String to print
 * @param bytes Int pointer to bytes variable
 * @return None
 */
void	pf_putstr(char *str, int *bytes)
{
	int	i;

	if (!str)
		str = "(null)";
	i = -1;
	while (str[++i] && *bytes != -1)
		pf_putchar(str[i], bytes);
}

/**

 * @brief Recursive function that calls itself until it prints all its numbers.
	First it checks that no previous write have failed .
	If n is < 0, prints a '-' and converts it to positive before calling itself.
	When the number/character to print appears by itself on its base,
	it calls pf_putchar to print such number/character.
 * @param n Number to print
 * @param base Base in which to print the number (Base 10/Hexadecimal Base)
 * @param bytes Int pointer to bytes variable
 * @return None
 */
void	pf_putnbr_base(long long n, char *base, int *bytes)
{
	if (*bytes == -1)
		return ;
	if (n < 0)
	{
		n = -n;
		pf_putchar('-', bytes);
		pf_putnbr_base(n, base, bytes);
	}
	else if (n > ft_strlen(base) + 1)
	{
		pf_putnbr_base(n / ft_strlen(base), base, bytes);
		pf_putnbr_base(n % ft_strlen(base), base, bytes);
	}
	else
		pf_putchar(base[n], bytes);
}

/**

 * @brief Variadic function that mimics the behaviour of 'printf' with the
	following conversions: "%s" "%d" and "%x".
	Creates bytes to keep track of the number of bytes written and returns
	it at the end.
	Iterates through the string looking for conversions (%s || %d || %x),
	when finiding one, prints it according to its type. 
	On any other case it prints the actual character (str[i])
 * @param str Variable to print
 * @return bytes: Number of bytes written during the function or -1 on fail.
 */
int	ft_printf(const char *str, ...)
{
	int		bytes;
	int		i;
	va_list	arg;

	i = -1;
	bytes = 0;
	va_start(arg, str);
	while (str[++i] && bytes != -1)
	{
		if (str[i] == '%' && (str[i + 1] == 's' || str[i + 1] == 'd'
				|| str[i + 1] == 'x'))
		{
			i++;
			if (str[i] == 's')
				pf_putstr(va_arg(arg, char *), &bytes);
			else if (str[i] == 'd')
				pf_putnbr_base(va_arg(arg, int), "0123456789", &bytes);
			else
				pf_putnbr_base(va_arg(arg, unsigned int), "0123456789abcdef",
					&bytes);
		}
		else
			pf_putchar(str[i], &bytes);
	}
	return (va_end(arg), bytes);
}
