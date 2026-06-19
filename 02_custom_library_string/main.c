#include <stdio.h>
#include <stdlib.h>
#include "strutil.h"

int main(void) {
    char s[] = "ABCDEFG";
    char *dest = calloc(8, sizeof(char));

    printf("Length: %d\n", my_strlen(s));
    
    my_strcpy(dest, s);
    printf("Strcpy: %s\n", dest);

    char a = 'A';
    char b = 'B';

    printf("Strcmp: %d\n", my_strcmp(&a, &b));
    my_strrev(s);
    printf("Strrev: %s\n", s);
    
    printf("Strcount: %d\n", my_strcount(s, 'B'));

    return 0;
}

