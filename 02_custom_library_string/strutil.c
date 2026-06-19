
int my_strlen(const char *s) {
    int index = 0;    
    while(s[index] != '\0') {
        index++;
    }

    return index;
}

void my_strcpy(char *dest, const char *src) {
    int src_len = my_strlen(src);
    for(int i = 0; i < src_len; i++) {
        dest[i] = src[i];
    }
}

int my_strcmp(const char *a, const char *b) {
    int a_len = my_strlen(a);
    int b_len = my_strlen(b);

    int end = 0;
    if(a_len < b_len) {
        end = a_len;
    } else {
        end = b_len;
    }

    for(int i = 0; i < end; i++) {
        if(a[i] < b[i]) {
            return -1;
        } else if(a[i] > b[i]) {
            return 1;
        }
    }

    return 0;
}

void my_strrev(char *s) {
    int s_len = my_strlen(s);
    for(int i = 0; i < s_len / 2; i++) {
        char tmp = s[i];
        s[i] = s[s_len - 1 - i];
        s[s_len - 1 - i] = tmp;
    }
}

int my_strcount(const char *s, char c) {
    int s_len = my_strlen(s);
    int counter = 0;
    for(int i = 0; i < s_len; i++) {
        if(s[i] == c) {
            counter++;
        }
    }

    return counter;
}

