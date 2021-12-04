#ifndef CSTRING_H
#define CSTRING_H

#define LOCKED 1
#define UNLOCKED 0

typedef struct CString CString;

CString *cstring_new(const char* str);

int length(CString *str);

char get_char(CString *str, int pos);

void replace(CString *str, int pos, char sub);

char *to_char_ptr(CString *str);

#endif
