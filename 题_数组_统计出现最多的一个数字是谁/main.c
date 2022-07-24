#include <stdio.h>

int main() {
    int b[1000]={0},a[1000]={0};
    int m=0,n=0,q=0; //用m记录当前最大的频次值。最后输出i为要找的最多出现的数字
    //初始化a
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    for(int i=0;i<n;i++) b[a[i]]++;//对a中的数字进行统计。数组b下标即数字，b记录的值即数字出现频次
    for(int i=0;i<1000;i++){//寻遍整个1000个b数组成员
        if(b[i]>m) {m=b[i];q=i;}//q记录当前频次值最多的数字是谁
    }
    if(m>n/2) printf("%d",q);
    else printf("-1");
//    printf("Hello, World!\n");
    return 0;
}
