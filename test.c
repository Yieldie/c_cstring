#include <stdio.h>
#include <assert.h>
#include <random.h>
#include "cstring.h"

#define MAX_LEN 	100
#define TEST_LEN	100

void initialize()
{
	srand(time(NULL));
}

void test_basic(void) 
{
	const char *in = "foo bar baz";
	char *tmp;
	CString *str = cstring_new(in);
	printf("%s\n", to_char_ptr(str));
	replace(str, 6, 'z');
	tmp = to_char_ptr(str);
	*tmp = 'b';
	printf("%s\n", tmp);
	printf("%s\n", to_char_ptr(str));
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
		assert(length(cstring) == n);
		free(tmp);
		//cstring_delete(str), unimplemented
	}
}

char *random_str(int length)
{
	char *str = (char *)malloc((length + 1) * sizeof(char));
	for(int i = 0; i < length; i++) {
		*(str + i) = (char)(rand() % ('z' - 'a' + 1));
	}
	*(str + length) = '\0';
	return str;
}

int main(void) 
{
	initialize();
	test_basic();
	test_length();
	return 0;
}
