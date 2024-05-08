/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconiau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 01:12:19 by lconiau           #+#    #+#             */
/*   Updated: 2024/03/04 21:39:48 by lconiau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_listlib
{
	void				*content;
	struct s_listlib	*next;
}		t_listlib;

int			ft_atoi(const char *string);
void		ft_bzero(void *s, size_t n);
int			ft_isalnum(int character);
int			ft_isalpha(int c);
int			ft_isascii(int character);
int			ft_isdigit(int c);
int			ft_isprint(int character);
void		*ft_memchr(const void *memoryBlock, int searchedChar, size_t size);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *pointer, int value, int count);
int			ft_memcmp(const void *p1, const void *p2, size_t size);
char		*ft_strchr(const char *string, int searchedChar);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *string);
int			ft_strncmp(const char *first, const char *secosnd, int lenght);
char		*ft_strnstr(const char *fullString, const char *substr, size_t len);
char		*ft_strrchr(const char *string, int searchedChar);
int			ft_tolower(int c);
int			ft_toupper(int c);
void		*ft_calloc(size_t elementCount, size_t elementSize);
char		*ft_strdup(const char *source);
char		*ft_substr(const char *s, unsigned int start, size_t len);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strtrim(const char *s1, const char *set);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		**ft_split(char *s, char c);
void		ft_lstadd_front(t_listlib **lst, t_listlib *new);
t_listlib	*ft_lstnew(void *content);
int			ft_lstsize(t_listlib *lst);
t_listlib	*ft_lstlast(t_listlib *lst);
void		ft_lstadd_back(t_listlib **lst, t_listlib *new);
void		ft_lstdelone(t_listlib *lst, void (*del)(void*));
void		ft_lstclear(t_listlib **lst, void (*del)(void*));
void		ft_lstiter(t_listlib *lst, void (*f)(void *));
t_listlib	*ft_lstmap(t_listlib *lst, void *(*f)(void *), void (*del)(void *));

#endif
