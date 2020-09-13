#ifndef LIBMX_H
#define LIBMX_H

#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "stdbool.h"
#include "fcntl.h"
#include "wchar.h"
#include "string.h"
#include "limits.h"




//My pack:
void mx_copy_sqrtintarr(int **src, int ***dest);
void mx_print2d_sqrintarr(int **arr, char *title);
int mx_getindex_foundstr(char *what, char **where, unsigned int begin_with);
char *mx_copyfoundstr(char *what, char **where, unsigned int begin_with);
char **mx_copy_strarrchar(char **strarr, char stop);
char *mx_strget_numberstr(char *s);
void mx_print_error(const char *s);
void mx_print_chars(char character, int amount);
long long mx_strget_longlongnum(char *s);
char *GetSubstrInLines(char *substr, char **Lines, unsigned int StartLine);
void mx_delintarr(int ***IntArrArr);
void mx_intdel(int **int_array);
int **mx_intarrnew(unsigned int size);
int *mx_intnew(unsigned int size);
char **mx_delallstrdups(char **StrArr);
char **mx_strarrdup(char **StrArr);
char **mx_strsplitall(char **StrArr, char delim);
char **mx_shorten_strs_delim(char **StrArr, char delim, unsigned int StartStr, unsigned int DelimedPart);
char **mx_strarrnew(unsigned int StrAmnt);
int mx_strarrlen(char **StrArr);
long long mx_atoi(char *str);
bool mx_is_alphabet(char c);
bool mx_is_digit(char c);
bool mx_is_whitespace(char c);
int FindLeftLetterIndex(char *str);
int DefineCleanStrLength(char *TrimmedStr);
char *DelimWords(char *dest, char *TrimdStr, char delim);

//Utility pack:

void mx_printchar(char c);
void mx_print_unicode(wchar_t c);
void mx_printstr(const char *s);
void mx_print_strarr(char **arr, const char *delim);
void mx_printint(int n);
double mx_pow(double n, unsigned int pow);
int mx_sqrt(int x);
char *mx_nbr_to_hex(unsigned long nbr); //needs free;
unsigned long mx_hex_to_nbr(const char *hex);
char *mx_itoa(int number); //needs free; //+++
void mx_foreach(int *arr, int size, void (*f)(int));
int mx_binary_search(char **arr, int size, const char *s, int *count);
int mx_bubble_sort(char **arr, int size);

//String pack:

int mx_strlen(const char *s);
void mx_swap_char(char *s1, char *s2);
void mx_str_reverse(char *s); 
void mx_strdel(char **str);
void mx_del_strarr(char ***arr);
int mx_get_char_index(const char *str, char c); //+++
char *mx_strdup(const char *str);
char *mx_strcpy(char *dst, const char *src);
char *mx_strndup(const char *s1, size_t n);//+++
char *mx_strncpy(char *dst, const char *src, int len);//+++
int mx_strcmp(const char *s1, const char *s2); 
char *mx_strcat(char *restricts1, const char *restricts2); 
char*mx_strstr(const char *haystack, const char *needle);
int mx_get_substr_index(const char *str, const char *sub);
int mx_count_substr(const char *str, const char *sub);
int mx_count_words(const char *str, char c);
char *mx_strnew(const int size); //page 20
char *mx_strtrim(const char *str); // >20; needs free;
char *mx_del_extra_spaces(const char *str); //needs free;
char **mx_strsplit(const char *s, char c); // >20 needs free;
char *mx_strjoin(const char *s1, const char *s2); // needs free;//+++;
char *mx_file_to_str(const char *file); //needs free; +++
char *mx_replace_substr(const char *str, const char *sub, const char *replace);

//Memory pack:

void *mx_memset(void *b, int c, size_t len);//+++
void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n);//+++
void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n);//+++
int mx_memcmp(const void *s1, const void *s2, size_t n);
void *mx_memchr(const void *s, int c, size_t n);
void *mx_memrchr(const void *s, int c, size_t n);
void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len);
void *mx_memmove(void *dst, const void *src, size_t len);
void *mx_realloc(void *ptr, size_t size);

//List pack:

typedef struct s_list {
    void *data;
    struct s_list *next;
}              t_list;


void PrintListData(t_list *list);
t_list *mx_create_node(void *data);
void mx_push_front(t_list **list, void *data);//+++
void mx_push_back(t_list **list, void *data);//+++
void mx_pop_front(t_list **head);
void mx_pop_back(t_list **head);
int mx_list_size(t_list *list);//+++
t_list *mx_sort_list(t_list *lst, bool(*cmp)(void*, void*));//+++

#endif
