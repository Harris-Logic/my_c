#include <stdio.h>
//int arrange(int n,int m){
//    int a=0;
//    if(n<m){a=n;n=m;m=a;}
//    if(n==m) return m;
//    return n*arrange(n-1,m);
//}

//int cnm(int n,int m){
//    int a=0;
//    if(n<m){ a=n;n=m;m=a;}
//    if(n==1) return n;
//    return m*cnm(n-1, m-1)/n;
//}
int multiplyNumbers(int n)
{
    if (n > 1)
        return n*multiplyNumbers(n-1);
    else
        return 1;
}
int cnm(int n,int m){
    int a,jieguo=0;
    if(n<m){ a=n;n=m;m=a;}

    if(n==1) return m;
    if(n==m)return 1;
    jieguo= multiplyNumbers(n)/ (multiplyNumbers(n-m)*multiplyNumbers(m));
    return jieguo;
}
int main() {
    int count=0,taijie,yijie,erjie,c_=1,i=0,j=0,erjiejiecheng=1,zuhe_nm=0;
//    int a;
//    a= cnm(5,3);

    scanf("%d",&taijie);
    for(yijie=0;yijie<=taijie;yijie++){//一阶数量不可能超过总台阶数
        for(erjie=0;erjie<=taijie/2;erjie++)//二阶数量不可能超过 总台阶数/2
            if(yijie*1+erjie*2<=taijie)//只有小于时，才有进入判断的价值。否则是浪费时间
                if(yijie*1+erjie*2==taijie){
//                    if(yijie*1==taijie) count++;
//                    else {
                        zuhe_nm=cnm(yijie+erjie,erjie);//有几种组合情况？两种球，其中一种选位置(如5个空选3个位置)
                        count+=zuhe_nm;//本轮组合情况数 计入总计
//                    }
//                        c_=1;//整个这一大段，是处理计算C4，2概率论里的那个玩意
//                        for(c_=1,i=yijie+erjie,j=1;j<=erjie;i--,j++) c_*=i;//
//                        for(j=erjie,erjiejiecheng=1;j>0;j--) erjiejiecheng*=j;
//                        c_/=erjiejiecheng;//erjie的阶乘
//                        count+=c_;}
            }



    }
    printf("%d",count);
//    printf("Hello, World!\n");
    return 0;
}
//Description
//   假如有n个台阶，一次只能上1个台阶或2个台阶，请问走到第n个台阶有几种走法？为便于读者理解题意，这里举例说明如下：
//   假如有3个台阶，那么总计就有3种走法：第一种为每次上1个台阶，上3次；第二种为先上2个台阶，再上1个台阶；第三种为先上1个台阶，再上2个台阶。输入为n，输出为走到第n个台阶有几种走法
//////        Input
//比如输入是3
//////        Output
//如果输入是3，走到第3个台阶的走法总计有3种，1,1,1 和  1,2 和2,1，输出为3


//以下是，手算排列组合的思路。贼复杂
//#include <stdio.h>
//
//int main() {
//    int count=0,taijie,yijie,erjie,c_=1,i=0,j=0,erjiejiecheng=1;
//
//    scanf("%d",&taijie);
//    for(yijie=0;yijie<=taijie;yijie++){
//        for(erjie=0;erjie<=taijie/2;erjie++)
//            if(yijie*1+erjie*2<=taijie)
//                if(yijie*1+erjie*2==taijie){
//                    if(yijie*1==taijie) count++;
//                    else {
////                        c_=1;
//                        for(c_=1,i=yijie+erjie,j=1;j<=erjie;i--,j++) c_*=i;//计算c4，2概率论里的那个玩意
//                        for(j=erjie,erjiejiecheng=1;j>0;j--) erjiejiecheng*=j;
//                        c_/=erjiejiecheng;//erjie的阶乘
//                        count+=c_;
//                    }
//                }
//
//
//
//    }
//    printf("%d",count);
////    printf("Hello, World!\n");
//    return 0;
//}
////Description
////   假如有n个台阶，一次只能上1个台阶或2个台阶，请问走到第n个台阶有几种走法？为便于读者理解题意，这里举例说明如下：
////   假如有3个台阶，那么总计就有3种走法：第一种为每次上1个台阶，上3次；第二种为先上2个台阶，再上1个台阶；第三种为先上1个台阶，再上2个台阶。输入为n，输出为走到第n个台阶有几种走法
////////        Input
////比如输入是3
////////        Output
////如果输入是3，走到第3个台阶的走法总计有3种，1,1,1 和  1,2 和2,1，输出为3