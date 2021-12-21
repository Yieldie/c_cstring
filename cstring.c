#include <stdlib.h>
#include <string.h>
#include "cstring.h"

struct CString
{
	unsigned int len;
	char *content;
};

/**
 * Funkcja zwraca nową strukturę CString z zawartością str.
 */
CString *cstring_new(const char* str)
{
	unsigned int l = 0;
	CString *ret = (CString *)malloc(sizeof(CString));
	if(ret != NULL) {
		l = strlen(str);
		ret->len = l;
		ret->content = (char *)malloc(l * sizeof(char));
		memcpy(ret->content, str, (size_t)l);
	}
	return ret;
}

/**
 *Funkcja zwraca długość stringa str.
 */
int length(CString *str)
{
	return str->len;
}

/**
 * Funkcja zwraca znak na pozycji pos w stringu str, o ile pos mieści się w zakresie.
 */
char get_char(CString *str, unsigned int pos)
{
	return (pos < str->len) ? str->content[pos] : '\0';
}

/**
 * Funkcja zmienia znak na pozycji pos w stringu str na znak sub, o ile pos mieści się w zakresie.
 */
void replace(CString *str, unsigned int pos, char sub)
{
	if(pos < str->len) {
		str->content[pos] = sub;
	}
}

/**
 * Funkcja zwraca reprezentację char* struktury str.
 */
const char *to_char_ptr(CString *str)
{
	return str->content;
}

/**
 * Dodatkowa funkcja do usuwania struktury wraz z dealokacją zawartości char *content.
 */
void cstring_delete(CString *str)
{
	free(str->content);
	free(str);
}
