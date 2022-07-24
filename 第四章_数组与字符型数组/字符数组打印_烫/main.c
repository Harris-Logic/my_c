#include <stdio.h>

int main() {
    char c[5]="hello";//{'h','e','l','l','o'};
    char d[4]="howrfdsf",o[]={'\0'};

    printf("%s----%s\n",o,d);
//    printf("Hello, World!\n");
    c[0]-=32;
//    printf();

    return 0;
}
