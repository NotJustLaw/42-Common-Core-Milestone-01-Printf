/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justlaw <justlaw@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 23:07:07 by justlaw           #+#    #+#             */
/*   Updated: 2025/04/27 23:09:44 by justlaw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

void	print_result(int orig, int mine)
{
	if (orig == mine)
		printf("\033[0;32m[OK] ");
	else
		printf("\033[0;31m[KO] ");
	printf("Original: %d | Yours: %d\033[0m\n", orig, mine);
}

int	main(void)
{
	int		org;
	int		ft;
	char	*str;
	void	*ptr;

	str = "42 is amazing";
	ptr = &str;
	printf("\n--------- BASIC TESTS ---------\n\n");
	
	printf("Test 1: Simple string\n");
	org = printf("Original: Hello World\n");
	ft = ft_printf("Ft_print: Hello World\n");
	print_result(org, ft);
	
	printf("\nTest 2: Character (%%c)\n");
	org = printf("Original: %c\n", 'X');
	ft = ft_printf("Ft_print: %c\n", 'X');
	print_result(org, ft);
	
	printf("\nTest 3: String (%%s)\n");
	org = printf("Original: %s\n", str);
	ft = ft_printf("Ft_print: %s\n", str);
	print_result(org, ft);
	
	printf("\nTest 4: Pointer (%%p)\n");
	org = printf("Original: %p\n", ptr);
	ft = ft_printf("Ft_print: %p\n", ptr);
	print_result(org, ft);
	
	printf("\nTest 5: Integer (%%d)\n");
	org = printf("Original: %d\n", 42);
	ft = ft_printf("Ft_print: %d\n", 42);
	print_result(org, ft);
	
	printf("\nTest 6: Integer (%%i)\n");
	org = printf("Original: %i\n", -42);
	ft = ft_printf("Ft_print: %i\n", -42);
	print_result(org, ft);
	
	printf("\nTest 7: Unsigned (%%u)\n");
	org = printf("Original: %u\n", (unsigned int)42);
	ft = ft_printf("Ft_print: %u\n", (unsigned int)42);
	print_result(org, ft);
	
	printf("\nTest 8: Hex lowercase (%%x)\n");
	org = printf("Original: %x\n", 42);
	ft = ft_printf("Ft_print: %x\n", 42);
	print_result(org, ft);
	
	printf("\nTest 9: Hex uppercase (%%X)\n");
	org = printf("Original: %X\n", 42);
	ft = ft_printf("Ft_print: %X\n", 42);
	print_result(org, ft);
	
	printf("\nTest 10: Percent (%%%%)\n");
	org = printf("Original: %%\n");
	ft = ft_printf("Ft_print: %%\n");
	print_result(org, ft);

	printf("\n--------- EDGE CASES ---------\n\n");
	
	printf("Test 11: NULL pointer as string\n");
	org = printf("Original: %p\n", NULL);
	ft = ft_printf("Ft_print: %p\n", NULL);
	print_result(org, ft);
	
	printf("\nTest 12: INT_MIN\n");
	org = printf("Original: %d\n", INT_MIN);
	ft = ft_printf("Ft_print: %d\n", INT_MIN);
	print_result(org, ft);
	
	printf("\nTest 13: INT_MAX\n");
	org = printf("Original: %d\n", INT_MAX);
	ft = ft_printf("Ft_print: %d\n", INT_MAX);
	print_result(org, ft);
	
	printf("\nTest 14: Multiple conversions\n");
	org = printf("Original: %d %s %x %% %c\n", 42, "test", 42, 'Z');
	ft = ft_printf("Ft_print: %d %s %x %% %c\n", 42, "test", 42, 'Z');
	print_result(org, ft);
	
	printf("\nTest 15: Empty string\n");
	org = printf("Original: %s\n", "");
	ft = ft_printf("Ft_print: %s\n", "");
	print_result(org, ft);

	return (0);
}