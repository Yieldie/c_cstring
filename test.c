#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include "cstring.h"

#define MAX_LEN 	100
#define TEST_BASIC	10
#define TEST_LEN	100
#define TEST_GET	100
#define TEST_REPLACE	100

void initialize(void);
void test_basic(void);
void test_length(void);
void test_getchar(void);
void test_replace(void);
void test_immutable(void);
char *random_str(int length);

void initialize(void)
{
	srand(time(NULL));
}

void test_basic(void) 
{
	char *tmp, *res;
	CString *str;
	for(int i = 0; i < TEST_BASIC; i++) {
		tmp = random_str(MAX_LEN);
		str = cstring_new(tmp);
		res = to_char_ptr(str);
		for(int j = 0; j < MAX_LEN; j++) {
			assert(*(res + j) == *(tmp + j));
		}
		free(tmp);
		free(res);
		cstring_delete(str);
	}
}

void test_length(void) 
{
	int n;
	char *tmp;
	CString *str;
	for(int i = 0; i < TEST_LEN; i++) {
		n = rand() % MAX_LEN + 1;
		tmp = random_str(n);
		str = cstring_new(tmp);
		assert(length(str) == n);
		free(tmp);
		cstring_delete(str);
	}
}

void test_getchar(void)
{
	char *tmp;
	CString *str;
	for(int i = 0; i < TEST_GET; i++) {
		tmp = random_str(MAX_LEN);
		str = cstring_new(tmp);
		for(int j = 0; j < MAX_LEN; j++) {
			assert(get_char(str, j) == *(tmp + j));
		}
		assert(get_char(str, MAX_LEN + rand() % 10) == '\0');
		free(tmp);
		cstring_delete(str);
	}
}

void test_replace() 
{
	char c;
	char *tmp, *res;
	CString *str;
	for(int i = 0; i < TEST_REPLACE; i++) {
		tmp = random_str(MAX_LEN);
		str = cstring_new(tmp);
		for(int j = 0; j < MAX_LEN; j++) {
			if(rand() % 2 == 0) {
				c = (char)(*(tmp + j) + 1 + rand() % ('z' - 'a' - 1));
				*(tmp + j) = c;
				replace(str, j, c);
			}
		}
		res = to_char_ptr(str);
		for(int j = 0; j < MAX_LEN; j++) {
			assert(*(tmp + j) == *(res + j));
		}
		free(tmp);
		free(res);
		cstring_delete(str);
	}
}

void test_immutable() 
{
	CString *str = cstring_new(random_str(MAX_LEN));
	char *tmp = to_char_ptr(str);
	for(int i = 0; i < MAX_LEN; i++) {
		*(tmp + i) += 1 + rand() % ('z' - 'a' - 1);
		assert(get_char(str, i) != *(tmp + i));
	}
	free(tmp);
	cstring_delete(str);
}

char *random_str(int length)
{
	char *str = (char *)malloc((length + 1) * sizeof(char));
	for(int i = 0; i < length; i++) {
		*(str + i) = (char)('a' + rand() % ('z' - 'a' + 1));
	}
	*(str + length) = '\0';
	return str;
}

int main(void) 
{
	initialize();
	test_basic();
	test_length();
	test_getchar();
	test_replace();
	test_immutable();
	return 0;
}
