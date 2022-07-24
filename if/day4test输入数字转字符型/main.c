#include<stdio.h>

int main(){
    int i;
    scanf("%d",&i);
    if(i<65||i>122) return 0;
    else{
        printf("%c",i);
    }
  return 0;
}