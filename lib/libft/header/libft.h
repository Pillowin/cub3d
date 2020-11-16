/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:15:19 by agautier          #+#    #+#             */
/*   Updated: 2020/11/11 15:01:00 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef	struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/*
**	printing
*/
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar(char c);
void				ft_putstr_non_printable(char *str);
void				ft_putstr(char *str);
void				ft_putnbr(int nb);
void				ft_putnbr_base(int nbr, char *base);
void				ft_putlstr(const char *str, size_t n);
void				ft_putulnbr_base(unsigned long n, char *base,
int *printed, int fd);
void				ft_putunbr_base(unsigned int n, char *base,
int *printed, int fd);
void				ft_putlnbr(long nb);
int					ft_printf(const char *format, ...);

/*
**	char
*/
int					ft_isalpha(int c);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
**	str
*/
size_t				ft_strlen(const char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strnstr(const char *haystack, const char *needle,
size_t len);
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strcpy(char *dest, char *src);
char				*ft_strncpy(char *dest, char *src, unsigned int n);
int					ft_str_is_alpha(char *str);
int					ft_str_is_numeric(char *str);
int					ft_str_is_lowercase(char *str);
int					ft_str_is_uppercase(char *str);
int					ft_str_is_printable(char *str);
char				*ft_strupcase(char *str);
char				*ft_strlowcase(char *str);
char				*ft_strcapitalize(char *str);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strcat(char *dest, char *src);
char				*ft_strncat(char *dest, char *src, unsigned int nb);
char				*ft_strstr(char *str, char *to_find);
char				*ft_strlchr(const char *s, int c, size_t size);
char				*ft_itoa(int n);
char				**ft_split(char const *s, char c);
char				**ft_split_charset(char *str, char *charset);
char				*ft_get_whitespaces();
int					get_next_line(int fd, char **line);

/*
**	mem
*/
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_calloc(size_t count, size_t size);
int					ft_free(void *ptr);
void				ft_swap(int *a, int *b);

/*
**	lst
*/
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
void (*del)(void *));

/*
**	nbr
*/
int					ft_atoi(const char *str);
void				ft_div_mod(int a, int b, int *div, int *mod);
void				ft_ultimate_div_mod(int *a, int *b);
int					ft_atoi_base(char *str, char *base);
int					ft_recursive_factorial(int nb);
int					ft_recursive_power(int nb, int power);
int					ft_fibonacci(int index);
int					ft_sqrt(int nb);
int					ft_is_prime(int nb);
int					ft_find_next_prime(int nb);
int					*ft_range(int min, int max);
int					ft_ultimate_range(int **range, int min, int max);
int					ft_latoi(const char *str, int n);
int					ft_ilen(int n);
void				ft_rev_int_tab(int *tab, int size);
void				ft_sort_int_tab(int *tab, int size);
#endif
