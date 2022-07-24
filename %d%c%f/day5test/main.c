#include<stdio.h>

int main(){
    int i;
    char j;
    float ii,jj,k;

    
    scanf("%d %c %f",&i,&j,&k);
    jj=(float)j;ii=(float)i;
    // printf("%d %c %.2f\n",i,j,k);
    printf("%.2f",ii+jj+k);
  

  return 0;
}
//输入：
//10 a 98.3