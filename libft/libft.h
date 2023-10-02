/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:05:53 by analba-sa         #+#    #+#             */
/*   Updated: 2023/09/29 13:21:39 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

void	ft_bzero(void *s, size_t n); /*Set the first n bytes of s to 0*/
int		ft_isalnum(int c); /*Check if c is alphanumeric character*/
int		ft_isalpha(int c); /*Check if c is a alphabet character*/
int		ft_isascii(int a); /*Check if a is an ascii character*/
int		ft_isdigit(int a); /*Check if a is a digit*/
int		ft_isprint(int a); /*Check if a is a printable character*/
void	*ft_memcpy(void *dst, const void *src, size_t n); /*Copies n bytes of memory from src to dst*/
void	*ft_memset(void *b, int c, size_t len); /*Write len bytes of value c to the memory b*/
size_t	ft_strlen(const char *str); /*Return the len of a string*/
void	*ft_memmove(void *dst, const void *src, size_t len); /*Copies n bytes from src to dst even if they overlap*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize); /*Copies n characters from src to dst*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize); /*Concatenate characters from src into dst ensuring nul-termination*/
int		ft_toupper(int c); /*Converts c into uppercase if its a lowercase letter*/
int		ft_tolower(int c); /*Converts c into lowercase if is an uppercase letter*/
char	*ft_strchr(const char *s, int c); /*Find the first occurrence of c in the string s*/
int		ft_strncmp(char *s1, char *s2, size_t n); /*Compare the first n characters of s1 and s2*/
void	*ft_memchr(const void *s, int c, size_t n); /*Locate the first occurrence of c in the string s*/
int		ft_memcmp(const void *s1, const void *s2, size_t n); /*Compare the first n bytes of memory areas s1 and s2*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len); /*Search the first occurrence of the string needle in the first len characters of haystack*/
char	*ft_strrchr(const char *s, int c); /*Find the last occurrence of c in the string s*/
int		ft_atoi(const char *str); /*Convert string str to an integer*/
char	*ft_strdup(const char *s1); /*Duplicate the string s1*/
void	*ft_calloc(size_t count, size_t size); /*Allocate the memory for a block of count elements of size size initialized to 0*/
char	*ft_substr(const char *s, unsigned int start, size_t len); /*Return a substring of s starting on start with len size*/
char	*ft_strjoin(const char *s1, const char *s2); /*Concatenate the strings s1 and s2 into a new string*/
char	*ft_strtrim(const char *s1, const char *set); /*Remove characters from set from the beginning and end of s*/
char	**ft_split(const char *s, char c); /*Split the string using delimiter c and return an array of strings*/
char	*ft_itoa(int n); /*Convert an integer n to a string of characters*/
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char)); /*Apply the function f to each character of s and return a new string*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *)); /*Apply the function f to each character of s with its index as argument*/
void	ft_putchar_fd(char c, int fd); /*Write the character c to the fd*/
void	ft_putstr_fd(char *s, int fd); /*Write string s to the fd*/
void	ft_putendl_fd(char *s, int fd); /*Write the string s followed by a newline to the fd*/
void	ft_putnbr_fd(int n, int fd); /*Write the number n to the fd*/
typedef struct s_list /*Struct of a node for a linked list*/
{
	void			*content;
	struct s_list	*next;
}				t_list;
t_list	*ft_lstnew(void *content); /*Create a new list node with the given content*/
void	ft_lstadd_front(t_list **lst, t_list *new); /*Add a new node to the front of the list*/
int		ft_lstsize(t_list *lst); /*Return the size of the list*/
t_list	*ft_lstlast(t_list *lst); /*Return the last node of the list*/
void	ft_lstadd_back(t_list **lst, t_list *new); /*Add a new node to the end of the list*/
void	ft_lstdelone(t_list *lst, void (*del)(void *)); /*Delete a node form the list and apply del to free the memory*/
void	ft_lstclear(t_list **lst, void (*del)(void *)); /*Clear all nodes from the list and apply del to free the memory*/
void	ft_lstiter(t_list *lst, void (*f)(void *)); /*Apply f to each node of the list*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *)); /*Create a new list by applying f to each node os the list*/

#endif
