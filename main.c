/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 20:23:20 by maissa-b          #+#    #+#             */
/*   Updated: 2015/05/28 17:16:17 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

/****************************** Fonctions Part_1 ******************************/

void	ft_bzero(void *s, size_t n);
char	*ft_strcat(char *s1, const char *s2);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_puts(char *str);

/****************************** Fonctions Part_2 ******************************/

size_t	ft_strlen(const char *s);
void	*ft_memset(void *mem, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);

/******************************* Fonction Part_3 ******************************/

void	ft_cat(int fd);

/****************************** Fonctions Bonus *******************************/

int		ft_isupper(int c);
int		ft_islower(int c);
int		ft_isxdigit(int c);
int		ft_isspace(int c);
int		ft_isblank(int c);
char	*ft_strcpy(char *restrict dst, const char *restrict src);
char	*ft_strncpy(char *restrict dst, const char *restrict src, size_t n);
void	ft_putstring(char *str);
void	*ft_memalloc(size_t size);
char	*ft_strnew(size_t size);

/*********************** Fonctions Tools **************************************/

void	ft_putstr(char *str)
{
	int i = -1;

	if (str == NULL)
		write(1, "(null)", 6);
	else
	{
		while (str[++i])
		{
			write(1, &str[i], 1);
		}
	}
}

static size_t		ft_co_n(int n)
{
	size_t			i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char				*ft_itoa(int n)
{
	size_t			len;
	char			*s;
	unsigned int	nb;

	len = ft_co_n(n);
	nb = n;
	if (n < 0)
	{
		nb = -n;
		len++;
	}
	if (!(s = ft_strnew(len)))
		return (NULL);
	s[--len] = nb % 10 + '0';
	while (nb /= 10)
		s[--len] = nb % 10 + '0';
	if (n < 0)
		s[0] = '-';
	return (s);
}

void				ft_putnbr(int nb)
{
	ft_putstr(ft_itoa(nb));
}


/*********************** Fonctions Tests Part_1 *******************************/

void		test_ft_bzero(void)
{

	char *str1 = strdup("Les marins aiment le rhum");
	char *str2 = strdup("Les marins aiment le rhum");
	ft_putstr("bzero(\"");
	ft_putstr(str1);
	ft_putstr("\", 10) ->");
	ft_bzero(str1, 10);
	bzero(str2, 10);
	(memcmp(str1, str2, 10) == 0) ? ft_putstr("\033[32m OK \033[m") : ft_putstr("\033[31m FAIL \033[m");
	ft_putstr("\n");

	str1 = strdup("Les marins aiment le rhum");
	str2 = strdup("Les marins aiment le rhum");
	ft_putstr("bzero(\"");
	ft_putstr(str1);
	ft_putstr("\", strlen(str1)) ->");
	int a = strlen(str1);
	ft_bzero(str1, strlen(str1));
	bzero(str2, strlen(str2));
	(memcmp(str1, str2, a) == 0) ? ft_putstr("\033[32m OK \033[m") : ft_putstr("\033[31m FAIL \033[m");
	ft_putstr("\n");

	str1 = strdup("Les marins aiment le rhum");
	str2 = strdup("Les marins aiment le rhum");
	ft_putstr("bzero(\"");
	ft_putstr(str1);
	ft_putstr("\", 1) ->");
	ft_bzero(str1, 1);
	bzero(str2, 1);
	(memcmp(str1, str2, 1) == 0) ? ft_putstr("\033[32m OK \033[m") : ft_putstr("\033[31m FAIL \033[m");
	ft_putstr("\n");

	str1 = strdup("Les marins aiment le rhum");
	str2 = strdup("Les marins aiment le rhum");
	ft_putstr("bzero(\"");
	ft_putstr(str1);
	ft_putstr("\", 0) ->");
	ft_bzero(str1, 0);
	bzero(str2, 0);
	(memcmp(str1, str2, 0) == 0) ? ft_putstr("\033[32m OK \033[m") : ft_putstr("\033[31m FAIL \033[m");
	ft_putstr("\n");
}

void test_ft_strcat(void)
{
	char	*str1;
	char	*str2;


	str1 = (char *)malloc(sizeof(char) * 40);
	str2 = (char *)malloc(sizeof(char) * 40);
	ft_putstr("strcat(\"\", pasteque) -> ");
	ft_putstr("strcat : ");
	strcat(str2, "pasteque");
	ft_putstr(str2);
	ft_putstr(", ft_strcat: ");
	strcat(str1, "pasteque");
	ft_putstr(str1);
	(strcmp(str1, str2) == 0) ? ft_putstr("\033[32m OK \033[m") : ft_putstr("\033[31m FAIL \033[m");
	ft_putstr("\n");

	ft_putstr("strcat(pasteque, \\\\\\) -> ");
	ft_putstr("strcat : ");
	strcat(str2, "\\\\\\");
	ft_putstr(str2);
	ft_putstr(", ft_strcat: ");
	strcat(str1, "\\\\\\");
	ft_putstr(str1);
	(strcmp(str1, str2) == 0) ? ft_putstr("\033[32m OK \033[m") : ft_putstr("\033[31m FAIL \033[m");
	ft_putstr("\n");

	ft_putstr("strcat(hello, \" world\") -> ");
	ft_putstr("strcat : ");
	strcat(str2, " world");
	ft_putstr(str2);
	ft_putstr(", ft_strcat: ");
	strcat(str1, " world");
	ft_putstr(str1);
	(strcmp(str1, str2) == 0) ? ft_putstr("\033[32m OK \033[m") : ft_putstr("\033[31m FAIL \033[m");
	ft_putstr("\n");

	ft_putstr("strcat(hello world, po\\0mme) -> ");
	ft_putstr("strcat : ");
	strcat(str2, "po\0mme");
	ft_putstr(str2);
	ft_putstr(", ft_strcat: ");
	strcat(str1, "po\0mme");
	ft_putstr(str1);
	(strcmp(str1, str2) == 0) ? ft_putstr("\033[32m OK \033[m") : ft_putstr("\033[31m FAIL \033[m");
	ft_putstr("\n");

	ft_putstr("strcat(hello worldpo, \"\") -> ");
	ft_putstr("strcat : ");
	strcat(str2, "");
	ft_putstr(str2);
	ft_putstr(", ft_strcat: ");
	strcat(str1, "");
	ft_putstr(str1);
	(strcmp(str1, str2) == 0) ? ft_putstr("\033[32m OK \033[m") : ft_putstr("\033[31m FAIL \033[m");
	ft_putstr("\n");
}

void		test_ft_isalpha(void)
{
	int i = -1;
	int res;
	int ft_res;

	while (++i < 127)
	{
		res = isalpha(i);
		ft_res = ft_isalpha(i);
		if (res != ft_res)
			break;
	}
	if (i == 127)
		ft_putstr("\033[32mAll test OK \033[m");
	else
	{
		ft_putstr("\033[31mFAIL test ");
		ft_putnbr(i);
		ft_putstr("\n");
		ft_putstr("\033[m");
	}
	ft_putstr("\n");
}

void	test_ft_isdigit(void)
{
	int i = -1;
	int res;
	int ft_res;

	while (++i < 127)
	{
		res = isdigit(i);
		ft_res = ft_isdigit(i);
		if (res != ft_res)
			break;
	}
	if (i == 127)
		ft_putstr("\033[32mAll test OK \033[m");
	else
	{
		ft_putstr("\033[31mFAIL test ");
		ft_putnbr(i);
		ft_putstr("\n");
		ft_putstr("\033[m");
	}
	ft_putstr("\n");
}

void		test_ft_isalnum(void)
{
	int i = -1;
	int res;
	int ft_res;

	while (++i < 127)
	{
		res = isalnum(i);
		ft_res = ft_isalnum(i);
		if (res != ft_res)
			break;
	}
	if (i == 127)
		ft_putstr("\033[32mAll test OK \033[m");
	else
	{
		ft_putstr("\033[31mFAIL test ");
		ft_putnbr(i);
		ft_putstr("\n");
		ft_putstr("\033[m");
	}
	ft_putstr("\n");
}

void		test_ft_isascii(void)
{
	int i = -50;
	int res;
	int ft_res;

	while (++i < 200)
	{
		res = isascii(i);
		ft_res = ft_isascii(i);
		if (res != ft_res)
			break;
	}
	if (i == 200)
	{
		ft_putstr("\033[32mAll test OK \033[m");
		ft_putstr("\n");
	}
	else
	{
		ft_putstr("\033[31mFAIL test ");
		ft_putnbr(i);
		ft_putstr("\n");
		ft_putstr("\033[m");
	}
}

void		test_ft_isprint(void)
{
	int i = -1;
	int res;
	int ft_res;

	while (++i < 127)
	{
		res = isprint(i);
		ft_res = ft_isprint(i);
		if (res != ft_res)
			break;
	}
	if (i == 127)
	{
		ft_putstr("\033[32mAll test OK \033[m");
		ft_putstr("\n");
	}
	else
	{
		ft_putstr("\033[31mFAIL test ");
		ft_putnbr(i);
		ft_putstr("\n");
		ft_putstr("\033[m");
	}
}

void		test_ft_toupper(void)
{
	int i = -1;
	int res = 0;
	int ft_res = 0;

	while (++i < 127)
	{
		res += toupper(i);
		ft_res += ft_toupper(i);
		if (res != ft_res)
			break;
	}
	if (i == 127)
		ft_putstr("\033[32mAll test OK \033[m");
	else
	{
		ft_putstr("\033[31mFAIL test ");
		ft_putnbr(i);
		ft_putstr("\n");
		ft_putstr("\033[m");
	}
	ft_putstr("\n");
}

void	test_ft_tolower(void)
{
	int i = -1;
	int res = 0;
	int ft_res = 0;

	while (++i < 127)
	{
		res += tolower(i);
		ft_res += ft_tolower(i);
		if (res != ft_res)
			break;
	}
	if (i == 127)
		ft_putstr("\033[32mAll test OK \033[m");
	else
	{
		ft_putstr("\033[31mFAIL test ");
		ft_putnbr(i);
		ft_putstr("\n");
		ft_putstr("\033[m");
	}
}

void	test_ft_puts(void)
{
	ft_putstr("puts: ");
	puts(NULL);
	ft_putstr(", ft_puts: ");
	ft_puts(NULL);

	ft_putstr("puts: ");
	puts("Bonjour");
	ft_putstr(", ft_puts: ");
	ft_puts("Bonjour");

	ft_putstr("puts: ");
	puts("13, ");
	ft_putstr("ft_puts: ");
	ft_puts("13");

	ft_putstr("puts: ");
	puts("hello world, ");
	ft_putstr("ft_puts: ");
	ft_puts("hello world");

	ft_putstr("puts: ");
	puts("!@#$%^&*(), ");
	ft_putstr("ft_puts: ");
	ft_puts("!@#$%^&*()");

	close(1);
	ft_putstr("puts: ");
	puts("!@#$%^&*(), ");
	ft_putstr("ft_puts: ");
	ft_puts("!@#$%^&*()");
	dup2(0,1);
}

/*********************** Fonctions Tests Part_2 *******************************/

void		test_ft_strlen(void)
{
	char str1[] = "Ici, la taille compte";
	char str2[] = "Oui mais on dit quelle ne compte pas";
	char str3[] = "Seulement les rageux disent ça\n\n\n\n";
	char str4[] = "Moi je ne suis\0 pourtant pas un rageu";
	char str5[] = "T'en a pas marre de parler solo?";
	char str6[] = "Un peu, on arrête là";
	char str7[] = "Ok!";
	char str8[] = "\0";

	(ft_strlen(str1) == strlen(str1)) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr(str1);
	ft_putstr(" -> strlen: ");
	ft_putnbr(strlen(str1));
	ft_putstr(", ft_strlen: ");
	ft_putnbr(ft_strlen(str1));
	ft_putstr("\n");

	(ft_strlen(str2) == strlen(str2)) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr(str2);
	ft_putstr(" -> strlen: ");
	ft_putnbr(strlen(str2));
	ft_putstr(", ft_strlen: ");
	ft_putnbr(ft_strlen(str2));
	ft_putstr("\n");

	(ft_strlen(str3) == strlen(str3)) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr(str3);
	ft_putstr(" -> strlen: ");
	ft_putnbr(strlen(str3));
	ft_putstr(", ft_strlen: ");
	ft_putnbr(ft_strlen(str3));
	ft_putstr("\n");

	(ft_strlen(str4) == strlen(str4)) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr(str4);
	ft_putstr(" -> strlen: ");
	ft_putnbr(strlen(str4));
	ft_putstr(", ft_strlen: ");
	ft_putnbr(ft_strlen(str4));
	ft_putstr("\n");

	(ft_strlen(str5) == strlen(str5)) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr(str5);
	ft_putstr(" -> strlen: ");
	ft_putnbr(strlen(str5));
	ft_putstr(", ft_strlen: ");
	ft_putnbr(ft_strlen(str5));
	ft_putstr("\n");

	(ft_strlen(str6) == strlen(str6)) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr(str6);
	ft_putstr(" -> strlen: ");
	ft_putnbr(strlen(str6));
	ft_putstr(", ft_strlen: ");
	ft_putnbr(ft_strlen(str6));
	ft_putstr("\n");

	(ft_strlen(str7) == strlen(str7)) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr(str7);
	ft_putstr(" -> strlen: ");
	ft_putnbr(strlen(str7));
	ft_putstr(", ft_strlen: ");
	ft_putnbr(ft_strlen(str7));
	ft_putstr("\n");

	(ft_strlen(str8) == strlen(str8)) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr(str8);
	ft_putstr(" -> strlen: ");
	ft_putnbr(strlen(str8));
	ft_putstr(", ft_strlen: ");
	ft_putnbr(ft_strlen(str8));
	ft_putstr("\n");
}

void		test_ft_memcpy(void)
{
	char *str1 = strdup("Coucou toi!");
	char *str2 = strdup("Coucou toi!");
	((memcmp(ft_memcpy(str1, "aaaaaaaa", 0), memcpy(str2, "aaaaaaaa", 0), 11)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("memcpy(\"Coucou toi!\", \"aaaaaaa\", 0) ->"); 
	ft_putstr(" ft_memcpy: ");
	ft_putstr(str1);
	ft_putstr(", ");
	ft_putstr("memcpy: ");
	ft_putstr(str2);
	ft_putstr("\n");

	str1 = strdup("Coucou toi!");
	str2 = strdup("Coucou toi!");
	((memcmp(ft_memcpy(str1, "AAAAAAAA", 8), memcpy(str2, "AAAAAAAA", 8), 11)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");	
	ft_putstr("memcpy(\"Coucou toi!\", \"AAAAAAAA\", 8) ->"); 
	ft_putstr("ft_mempy: ");
	ft_putstr(str1);
	ft_putstr(", ");
	ft_putstr("memcpy: ");
	ft_putstr(str2);
	ft_putstr("\n");

	str1 = strdup("Coucou toi!");
	str2 = strdup("Coucou toi!");
	((memcmp(ft_memcpy(str1, "12345678", 8), memcpy(str2, "12345678", 8), 11)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("memcpy(\"Coucou toi!\", \"12345678\", 8) ->"); 
	ft_putstr("ft_memcpy: ");
	ft_putstr(str1);
	ft_putstr(", ");
	ft_putstr("memcpy: ");
	ft_putstr(str2);
	ft_putstr("\n");

	str1 = strdup("Coucou toi!");
	str2 = strdup("Coucou toi!");
	((memcmp(ft_memcpy(str1, "jIujIuH", 7), memcpy(str2, "jIujIuH", 7),11)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("memcpy(\"Coucou toi!\", \"jIujIuH\", 7) ->"); 
	ft_putstr("ft_memcpy: ");
	ft_putstr(str1);
	ft_putstr(", ");
	ft_putstr("memcpy: ");
	ft_putstr(str2);
	ft_putstr("\n");

	str1 = strdup("Coucou toi!");
	str2 = strdup("Coucou toi!");
	((memcmp(ft_memcpy(str1, "/>*<+|@-12345", 13), memcpy(str2, "/>*<+|@-12345", 13), 14)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("memcpy(\"Coucou toi!\", \"/>*<+|@-12345\", 13) ->"); 
	ft_putstr("ft_memcpy: ");
	ft_putstr(str1);
	ft_putstr(", ");
	ft_putstr("memcpy: ");
	ft_putstr(str2);
	ft_putstr("\n");

	str1 = strdup("Coucou toi!");
	str2 = strdup("Coucou toi!");
	((memcmp(ft_memcpy(str1, "yoloswag", 15), memcpy(str2, "yoloswag", 15), 11)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("memcpy(\"Coucou toi!\", \"yoloswag\", 15) ->"); 
	ft_putstr("ft_memcpy: ");
	ft_putstr(str1);
	ft_putstr(", ");
	ft_putstr("memcpy: ");
	ft_putstr(str2);
	ft_putstr("\n");

	str1 = strdup("Coucou toi!");
	str2 = strdup("Coucou toi!");
	((memcmp(ft_memcpy(str1, "\0", strlen(str1)), memcpy(str2, "\0", strlen(str2)), 11)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("memcpy(\"Coucou toi!\", \"\\0\", strlen(str1)) ->"); 
	ft_putstr("ft_memcpy: ");
	ft_putstr(str1);
	ft_putstr(", ");
	ft_putstr("memcpy: ");
	ft_putstr(str2);
	ft_putstr("\n");
}


void		test_ft_memset(void)
{

	char *str1 = strdup("Coucou toi!");
	char *str2 = strdup("Coucou toi!");
	((memcmp(ft_memset(str1, 'a', 4), memset(str2, 'a', 4), 11)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("memset(\"Coucou toi!\", \'a\', 4) -> "); 
	ft_putstr("memset: ");
	ft_putstr(str1);
	ft_putstr(", ");
	ft_putstr("ft_memset: ");
	ft_putstr(str2);
	ft_putstr("\n");

	str1 = strdup("Coucou toi!");
	str2 = strdup("Coucou toi!");
	((memcmp(ft_memset(str1, 'A', 14), memset(str2, 'A', 14), 14)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");	
	ft_putstr("memset(\"Coucou toi!\", \'A\', 14) -> "); 
	ft_putstr("memset: ");
	ft_putstr(str1);
	ft_putstr(", ");
	ft_putstr("ft_memset: ");
	ft_putstr(str2);
	ft_putstr("\n");

	str1 = strdup("Coucou toi!");
	str2 = strdup("Coucou toi!");
	((memcmp(ft_memset(str1, '1', strlen(str1)), memset(str2, '1', strlen(str2)), 11)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("memset(\"Coucou toi!\", \'1\', strlen(str1)) -> "); 
	ft_putstr("memset: ");
	ft_putstr(str1);
	ft_putstr(", ");
	ft_putstr("ft_memset: ");
	ft_putstr(str2);
	ft_putstr("\n");

	str1 = strdup("Coucou toi!");
	str2 = strdup("Coucou toi!");
	((memcmp(ft_memset(str1, '!', 0), memset(str2, '!', 0),11)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("memset(\"Coucou toi!\", \'!\', 0) -> "); 
	ft_putstr("memset: ");
	ft_putstr(str1);
	ft_putstr(", ");
	ft_putstr("ft_memset: ");
	ft_putstr(str2);
	ft_putstr("\n");

	str1 = strdup("Coucou toi!");
	str2 = strdup("Coucou toi!");
	((memcmp(ft_memset(str1, ' ', 4), memset(str2, ' ', 4), 11)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("memset(\"Coucou toi!\", \' \', 4) -> "); 
	ft_putstr("memset: ");
	ft_putstr(str1);
	ft_putstr(", ");
	ft_putstr("ft_memset: ");
	ft_putstr(str2);
	ft_putstr("\n");
}

void		test_ft_strdup(void)
{
	char str1[] = "Ici, la taille compte.";
	char str2[] = "Oui mais on dit qu'elle ne compte pas";
	char str3[] = "Seulement les rageux disent ça";
	char str4[] = "Moi je ne suis \0 pourtant pas un rageu.";
	char str5[] = "T'en as pas marre de parler solo?";
	char str6[] = "Un peu, on arrête là.";
	char str7[] = "Ok!\0";

	(strcmp(ft_strdup(str1), strdup(str1)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("strdup : ");
	ft_putstr(str1);
	ft_putstr("\n");

	(strcmp(ft_strdup(str2), strdup(str2)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("strdup : ");
	ft_putstr(str2);
	ft_putstr("\n");

	(strcmp(ft_strdup(str3), strdup(str3)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("strdup : ");
	ft_putstr(str3);
	ft_putstr("\n");

	(strcmp(ft_strdup(str4), strdup(str4)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("strdup : ");
	ft_putstr(str4);
	ft_putstr("\n");

	(strcmp(ft_strdup(str5), strdup(str5)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("strdup : ");
	ft_putstr(str5);
	ft_putstr("\n");

	(strcmp(ft_strdup(str6), strdup(str6)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("strdup : ");
	ft_putstr(str6);
	ft_putstr("\n");

	(strcmp(ft_strdup(str7), strdup(str7)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("strdup : ");
	ft_putstr(str7);
	ft_putstr("\n");
}

/*********************** Fonctions Tests Part_3 *******************************/

int	test_ft_cat(void)
{
	int fd;

	ft_putstr("\n");

	if ((fd = open("Makefile", O_RDONLY)) == (-1))
	{
		ft_putstr("ERROR !");
	}
	ft_cat(fd);
	//ft_cat(0);
	return (0);
}

/************************ Fonctions Tests Bonus *******************************/

void		test_ft_isupper(void)
{
	int i = -1;
	int res = 0;
	int ft_res = 0;

	while (++i < 127)
	{
		res += isupper(i);
		ft_res += ft_isupper(i);
		if (res != ft_res)
			break;
	}
	if (i == 127)
		ft_putstr("\033[32mAll test OK \033[m");
	else
	{
		ft_putstr("\033[31mFAIL test ");
		ft_putnbr(i);
		ft_putstr("\n\033[m");
	}
}

void		test_ft_islower(void)
{
	int i = -1;
	int res = 0;
	int ft_res = 0;

	while (++i < 127)
	{
		res += islower(i);
		ft_res += ft_islower(i);
		if (res != ft_res)
			break;
	}
	if (i == 127)
		ft_putstr("\033[32mAll test OK \033[m");
	else
	{
		ft_putstr("\033[31mFAIL test ");
		ft_putnbr(i);
		ft_putstr("\n\033[m");
	}
}

void		test_ft_isxdigit(void)
{
	int i = -1;
	int res = 0;
	int ft_res = 0;

	while (++i < 127)
	{
		res += isxdigit(i);
		ft_res += ft_isxdigit(i);
		if (res != ft_res)
			break;
	}
	if (i == 127)
		ft_putstr("\033[32mAll test OK \033[m");
	else
	{
		ft_putstr("\033[31mFAIL test ");
		ft_putnbr(i);
		ft_putstr("\n\033[m");
	}
}

void		test_ft_isspace(void)
{
	int i = -1;
	int res = 0;
	int ft_res = 0;

	while (++i < 127)
	{
		res += isspace(i);
		ft_res += ft_isspace(i);
		if (res != ft_res)
			break;
	}
	if (i == 127)
		ft_putstr("\033[32mAll test OK \033[m");
	else
	{
		ft_putstr("\033[31mFAIL test ");
		ft_putnbr(i);
		ft_putstr("\n\033[m");
	}
}

void		test_ft_isblank(void)
{
	int i = -1;
	int res = 0;
	int ft_res = 0;

	while (++i < 127)
	{
		res += isblank(i);
		ft_res += ft_isblank(i);
		if (res != ft_res)
			break;
	}
	if (i == 127)
		ft_putstr("\033[32mAll test OK \033[m");
	else
	{
		ft_putstr("\033[31mFAIL test ");
		ft_putnbr(i);
		ft_putstr("\n\033[m");
	}
}

void		test_ft_strcpy(void)
{
	char *str1;
	char *str2;
	char *str3;
	char *str4;

	str1 = strdup("COUCOU");
	str2 = strdup("COUCOU");
	str3 = strcpy(str1, "coucou");
	str4 = ft_strcpy(str2, "coucou");
	((strcmp(str3, str4)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("COUCOU");
	ft_putstr(" / ");
	ft_putstr("coucou");
	ft_putstr(" -> strcpy: ");
	ft_putstr(str3);
	ft_putstr(", ft_strcpy: ");
	ft_putstr(str4);
	ft_putstr("\n");

	str1 = strdup("COUCOU");
	str2 = strdup("COUCOU");
	str3 = strcpy(str1, "hello");
	str4 = ft_strcpy(str2, "hello");
	((strcmp(str3, str4)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("COUCOU");
	ft_putstr(" / ");
	ft_putstr("hello");
	ft_putstr(" -> strcpy: ");
	ft_putstr(str3);
	ft_putstr(", ft_strcpy: ");
	ft_putstr(str4);
	ft_putstr("\n");

	str1 = strdup("COUCOU");
	str2 = strdup("COUCOU");
	str3 = strcpy(str1, "qwertyuiop");
	str4 = ft_strcpy(str2, "qwertyuiop");
	((strcmp(str3, str4)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("COUCOU");
	ft_putstr(" / ");
	ft_putstr("qwertyuiop");
	ft_putstr(" -> strcpy: ");
	ft_putstr(str3);
	ft_putstr(", ft_strcpy: ");
	ft_putstr(str4);
	ft_putstr("\n");

	str1 = strdup("COUCOU");
	str2 = strdup("COUCOU");
	str3 = strcpy(str1, "");
	str4 = ft_strcpy(str2, "");
	((strcmp(str3, str4)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("COUCOU");
	ft_putstr(" / ");
	ft_putstr("\"\"");
	ft_putstr(" -> strcpy: ");
	ft_putstr(str3);
	ft_putstr(", ft_strcpy: ");
	ft_putstr(str4);
	ft_putstr("\n");
}

void		test_ft_strncpy(void)
{
	char *str1;
	char *str2;
	char *str3;
	char *str4;

	str1 = strdup("COUCOU");
	str2 = strdup("COUCOU");
	str3 = strncpy(str1, "coucou", 10);
	str4 = ft_strncpy(str2, "coucou", 10);
	((memcmp(str3, str4, 10)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("strncpy(COUCOU, coucou, 10) -> strncpy: ");
	ft_putstr(str3);
	ft_putstr(", ft_strncpy: ");
	ft_putstr(str4);
	ft_putstr("\n");

	str1 = strdup("COUCOU");
	str2 = strdup("COUCOU");
	str3 = strncpy(str1, "hello", 10);
	str4 = ft_strncpy(str2, "hello", 10);
	((memcmp(str3, str4, 10)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("strncpy(COUCOU, hello, 10) -> strncpy: ");
	ft_putstr(str3);
	ft_putstr(", ft_strncpy: ");
	ft_putstr(str4);
	ft_putstr("\n");

	str1 = strdup("COUCOU");
	str2 = strdup("COUCOU");
	str3 = strncpy(str1, "hello", 2);
	str4 = ft_strncpy(str2, "hello", 2);
	((memcmp(str3, str4, 10)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("strncpy(COUCOU, hello, 2) -> strncpy: ");
	ft_putstr(str3);
	ft_putstr(", ft_strncpy: ");
	ft_putstr(str4);
	ft_putstr("\n");

	str1 = strdup("COUCOU");
	str2 = strdup("COUCOU");
	str3 = strncpy(str1, "qwertyuiop", 8);
	str4 = ft_strncpy(str2, "qwertyuiop", 8);
	((memcmp(str3, str4, 10)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("strncpy(COUCOU, qwertyuiop, 8) -> strncpy: ");
	ft_putstr(str3);
	ft_putstr(", ft_strncpy: ");
	ft_putstr(str4);
	ft_putstr("\n");

	str1 = strdup("COUCOU");
	str2 = strdup("COUCOU");
	str3 = strncpy(str1, "qwertyuiop", 0);
	str4 = ft_strncpy(str2, "qwertyuiop", 0);
	((memcmp(str3, str4, 10)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("strncpy(COUCOU, qwertyuiop, 0) -> strncpy: ");
	ft_putstr(str3);
	ft_putstr(", ft_strncpy: ");
	ft_putstr(str4);
	ft_putstr("\n");
}

void	test_ft_putstring(void)
{
	ft_putstr("ft_putstr: ");
	ft_putstr(NULL);
	ft_putstr(", ft_putstring: ");
	ft_putstring(NULL);
	ft_putstr("\n");

	ft_putstr("ft_putstr: ");
	ft_putstr("Bonjour");
	ft_putstr(", ft_putstring: ");
	ft_putstring("Bonjour");
	ft_putstr("\n");

	ft_putstr("ft_putstr: ");
	ft_putstr("13, ");
	ft_putstr("ft_putstring: ");
	ft_putstring("13");
	ft_putstr("\n");

	ft_putstr("ft_putstr: ");
	ft_putstr("hello world, ");
	ft_putstr("ft_putstring: ");
	ft_putstring("hello world");
	ft_putstr("\n");

	ft_putstr("ft_putstr: ");
	ft_putstr("!@#$%^&*(), ");
	ft_putstr("ft_putstring: ");
	ft_putstring("!@#$%^&*()");
	ft_putstr("\n");
}

void test_ft_memalloc(void)
{
	char *s1;
	char *s2;

	s1 = malloc(0);
	bzero(s1, 0);
	s2 = ft_memalloc(0);
	ft_putstr("ft_memalloc(0) ->");
	memcmp(s1, s2, 0) == 0 ? ft_putstr("\033[32m OK\n\033[m") : ft_putstr("\033[31m FAIL\n\033[m");

	char *s3;
	char s4[] = "\0\0\0\0\0";
	ft_putstr("ft_memalloc(5) ->");
	s3 = ft_memalloc(5);
	memcmp(s3, s4, 5) == 0 ? ft_putstr("\033[32m OK\n\033[m") : ft_putstr("\033[31m FAIL\n\033[m");
	
	char *s5;
	char *s6;
	s5 = malloc(1000);
	bzero(s1, 1000);
	s6 = ft_memalloc(1000);
	ft_putstr("ft_memalloc(1000) ->");
	memcmp(s5, s6, 1000) == 0 ? ft_putstr("\033[32m OK\n\033[m") : ft_putstr("\033[31m FAIL\n\033[m");
}

void test_ft_strnew(void)
{
	char *s1;
	char s2[] = "\0";
	ft_putstr("ft_strnew(0) ->");
	s1 = ft_strnew(0);
	memcmp(s1, s2, 1) == 0 ? ft_putstr("\033[32m OK\n\033[m") : ft_putstr("\033[31m FAIL\n\033[m");

	char *s3;
	char s4[] = "\0\0\0\0\0\0";

	ft_putstr("ft_strnew(5) ->");
	s3 = ft_strnew(5);
	memcmp(s3, s4, 6) == 0 ? ft_putstr("\033[32m OK\n\033[m") : ft_putstr("\033[31m FAIL\n\033[m");

	char *s5;
	char *s6;

	s5 = malloc(1001);
	bzero(s5, 1001);
	s6 = ft_strnew(1001);
	ft_putstr("ft_strnew(1001) ->");
	memcmp(s5, s6, 1001) == 0 ? ft_putstr("\033[32m OK\n\033[m") : ft_putstr("\033[31m FAIL\n\033[m");
}

/****************************** Core test *************************************/

int main(void)
{
	ft_putstr("\033[33mPart_1:\n\033[m");

	ft_putstr("\nFT_BZERO:\n");
	test_ft_bzero();
	ft_putstr("\nFT_STRCAT:\n");
	test_ft_strcat();
	ft_putstr("\nFT_ISALPHA:\n");
	test_ft_isalpha();
	ft_putstr("\nFT_ISDIGIT:\n");
	test_ft_isdigit();
	ft_putstr("\nFT_ISALNUM:\n");
	test_ft_isalnum();
	ft_putstr("\nFT_SIASCII:\n");
	test_ft_isascii();
	ft_putstr("\nFT_ISPRINT:\n");
	test_ft_isprint();
	ft_putstr("\nFT_TOUPPER:\n");
	test_ft_toupper();
	ft_putstr("\nFT_TOLOWER:\n");
	test_ft_tolower();
	ft_putstr("\n\nFT_PUTS:\n");
	test_ft_puts();

	ft_putstr("\n\n\033[33mPart_2:\n\033[m");

	ft_putstr("\nFT_STRLEN:\n");
	test_ft_strlen();
	ft_putstr("\nFT_MEMCPY:\n");
	test_ft_memcpy();
	ft_putstr("\nFT_MEMSET:\n");
	test_ft_memset();
	ft_putstr("\nFT_STRDUP:\n");
	test_ft_strdup();

	ft_putstr("\n\033[33mPart_3:\n\033[m");

	ft_putstr("\nFT_CAT:\n");
	test_ft_cat();

	ft_putstr("\n\033[33mPart Bonus:\n\033[m");

	ft_putstr("\nFT_ISUPPER:\n");
	test_ft_isupper();
	ft_putstr("\n\nFT_ISLOWER:\n");
	test_ft_islower();
	ft_putstr("\n\nFT_ISXDIGIT:\n");
	test_ft_isxdigit();
	ft_putstr("\n\nFT_ISSPACE:\n");
	test_ft_isspace();
	ft_putstr("\n\nFT_ISBLANK:\n");
	test_ft_isblank();
	ft_putstr("\n\nFT_STRCPY:\n");
	test_ft_strcpy();
	ft_putstr("\nFT_STRNCPY:\n");
	test_ft_strncpy();
	ft_putstr("\n\nFT_PUTSTRING:\n");
	test_ft_putstring();
	ft_putstr("\nFT_MEMALLOC:\n");
	test_ft_memalloc();
	ft_putstr("\n\nFT_STRNEW:\n");
	test_ft_strnew();
}
