#include <stdio.h>
#include "cstring.h"

int main(void) 
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
	return 0;
}
