#include <stdio.h>

int main() {
    char c[20]="",intro[20]="c=";//此时c里存的是c字符数组的起始地址
//    gets(c);
    fgets(c,sizeof(c),stdin);//等价上面的gets(c),微软要求fgets()。fgets会读取'\n'

    puts(intro);puts(c);
    return 0;
}
