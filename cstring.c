#include <stdlib.h>
#include "cstring.h"

typedef struct CString
{
	int len;
	char *content;
} CString;

CString *cstring_new(const char* str)
{
	int l = 0;
	CString *ret = (CString *)malloc(sizeof(CString));
	while(*(str + l++) != '\0'); //find the length of the input string
	ret->len = l - 1;
	ret->content = (char *)malloc(l * sizeof(char));
	for(int i = 0; i < l; i++) {
		*(ret->content + i) = *(str + i);
	}
	return ret;
}

int length(CString *str)
{
	return str->len;
}

char get_char(CString *str, int pos)
{
	return (pos < str->len) ? *(str->content + pos) : '\0';
}

void replace(CString *str, int pos, char sub)
{
	if(pos < str->len) {
		*(str->content + pos) = sub;
	}
}

char *to_char_ptr(CString *str)
{
	char *ret = (char *)malloc((str->len + 1) * sizeof(char));
	for(int i = 0; i <= str->len; i++) {
		*(ret + i) = *(str->content + i);
	}
	return ret;
}

void cstring_delete(CString *str)
{
	free(str->content);
	free(str);
}
