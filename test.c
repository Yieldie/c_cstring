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
#define TEST_IMMUTABLE	100

void initialize(void);
void test_basic(void);
void test_length(void);
void test_getchar(void);
void test_replace(void);
void test_immutable(void);
char *random_str(int length);
void finalize(void);

void initialize(void)
{
	srand(time(NULL));
	printf("Running unit tests...\n");
}

// Test basic functionality - whether the content of CString does match the input or not.
void test_basic(void) 
{
	char *tmp; 
	const char *res;
	CString *str;
	for(int i = 0; i < TEST_BASIC; i++) {
		tmp = random_str(MAX_LEN);
		str = cstring_new(tmp);
		res = to_char_ptr(str);
		for(int j = 0; j < MAX_LEN; j++) {
			assert(res[j] == tmp[j]);
		}
		free(tmp);
		cstring_delete(str);
	}
}

// Test whether the length() function returns correct values.
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

// Test whether the get_char() function returns the correct values.
void test_getchar(void)
{
	char *tmp;
	CString *str;
	for(int i = 0; i < TEST_GET; i++) {
		tmp = random_str(MAX_LEN);
		str = cstring_new(tmp);
		for(int j = 0; j < MAX_LEN; j++) {
			assert(get_char(str, j) == tmp[j]);
		}
		assert(get_char(str, MAX_LEN + rand() % 10) == '\0'); // test the extreme case - position out of scope, the get_char() should return '\0' char
		free(tmp);
		cstring_delete(str);
	}
}

// Test whether the replace() procedure performs correct substitutions.
void test_replace(void) 
{
	char c;
	char *tmp; 
	const char *res;
	CString *str;
	for(int i = 0; i < TEST_REPLACE; i++) {
		tmp = random_str(MAX_LEN);
		str = cstring_new(tmp);
		for(int j = 0; j < MAX_LEN; j++) {
			if(rand() % 2 == 0) {
				c = (char)(tmp[j] + 1 + rand() % ('z' - 'a' - 1)); // it is guaranteed that the new char generated this way will be different than the old one
				tmp[j] = c;
				replace(str, j, c);
			}
		}
		res = to_char_ptr(str);
		for(int j = 0; j < MAX_LEN; j++) {
			assert(tmp[j] == res[j]);
		}
		free(tmp);
		cstring_delete(str);
	}
}

void finalize(void)
{
	printf("OK\n");
}

// Generate random string of given length, containing only small letters (for simplicity).
char *random_str(int length)
{
	char *str = (char *)malloc((length + 1) * sizeof(char));
	for(int i = 0; i < length; i++) {
		str[i] = (char)('a' + rand() % ('z' - 'a' + 1));
	}
	str[length] = '\0';
	return str;
}

int main(void)
{
	initialize();
	test_basic();
	test_length();
	test_getchar();
	test_replace();
	finalize();
	return 0;
}
