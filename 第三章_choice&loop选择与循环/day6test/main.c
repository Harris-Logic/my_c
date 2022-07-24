#include<stdio.h>

int main(){
    int a=0,i=0,tmp=0,b=0,k=0;

    scanf("%d",&a);i=a;

    k=0;
    while(i>0){
        tmp=i%10;
        b=b*10+tmp;
        i=i/10;
        k++;
    }
    // printf("a=%d,b=%d,i=%d,k=%d",a,b,i,k);
    if(a==b) printf("yes");
    else printf("no");    
    return 0;
}

//   Description
// 输入一个整型数，判断是否是对称数，如果是，输出yes，否则输出no，不用考虑这个整型数过大，int类型存不下，不用考虑负值；

// 例如 12321是对称数，输出yes，124421是对称数，输出yes，1231不是对称数，输出no


// Input
// 一个整型数


// Output
// 输出是yes，或者no




// int i,count,s_len;
    
//     scanf("%d",&i);

//     char s1[]="",s2[]="";
//     while(i!=NULL){// 处理整形数，使之变成字符串数组的形式
//         // s1[]=i/10;
//         s1=strcat(s1,"i%10");

//     }

//     s_len=strlen(s1);
//     count=0;
//     while(count<s_len)){
//         s2[s_len-count-1]=s1[count];
//         count++;
//     }//将s1逆置成s2
//     if(s1==s2) printf("yes");
//     else if(s1!=s2) printf("no");