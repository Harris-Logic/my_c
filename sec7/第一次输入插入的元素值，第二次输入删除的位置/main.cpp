#include <iostream>

int main()
{
    int biao[30]={1,2,3};
    int charu;
    scanf("%d",&charu);
    for(int i=2;i!=0;i--) biao[i+1]=biao[i];//从biao[2]开始，往后挪一个位置。直至biao[0]，不挪biao[0]退出循环
    biao[1]=charu;
    for(int i=0;i<=3;i++) printf("%3.0d",biao[i]);//biao[i]!=NULL//std::cout << biao[i]<< std::endl;
    printf("\n");
    scanf("%d",&charu);
    if (charu>=5||charu<=0) printf("false");
    else{
        for(int i=charu-1;i<=3;i++) biao[i]=biao[i+1];
        biao[3]=0;
        for(int i=0;i<=2;i++) printf("%3d",biao[i]);
    }

//    std::cout << "Hello, World!" << std::endl;
    return 0;
}
//6 1
//Description
//        初始化顺序表（顺序表中元素为整型），里边的元素是1,2,3，然后通过scanf读取一个元素（假如插入的是6），插入到第2个位置，打印输出顺序表，每个元素占3个空格，格式为1  6  2  3，
//        然后scanf读取一个整型数，是删除的位置（假如输入为1），
//        然后输出顺序表  6  2  3，假如输入的位置不合法，输出false字符串。
//        提醒，Language一定要选为C++。
//
//
//Input
//        第一次输入插入的元素值，第二次输入删除的位置
//
//
//        Output
//假如插入的元素为6，那么输出为
//1  6  2  3
//
//假如删除的位置为1，那么输出为
//
//
//6  2  3