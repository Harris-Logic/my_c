//
// Created by Logic on 2023/1/10.
//
//输出：词典文件dict.txt（词典中的内容为每一行都是一个“单词 词频”）
//词典的存储格式如下。
//
//|   a 66          |
//|   abandon 77    |
//|   public 88     |
//|    ...........  |
//|_________________|
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "sstream"

using std::cin;
using std::ofstream;
using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;
using std::istringstream;

typedef struct Record//全是public的类
{
    Record(const string &word,int freqc)
    :_word(word)
    ,_frequency(freqc)
    {}
    string _word;
    int _frequency;
}Record,*pRecord;

class Dictionary{
public:
    Dictionary(int capac)
    {
        _dict.reserve(capac);//预留空间
    }
//    Dictionary(){
//    :_dict(new vector<Record>[sizeof(vector<Record>) +1 ]()){
//    _dict = new std::vector<Record>;
//    _dict[NULL]._word=new std::string ;
////        _dict._word.push_back();
////    :_dict(new vector<struct Record>){
////        _dict._word=NULL;
////        _dict._frequency=0;
//    }
    //......
    void read(const string &filename)
    {
        ifstream ifs(filename, std::ios::in | std::ios::app);//追加模式，输入 Holly Bible.txt
        if(!ifs.good())
        {
            cerr<<"open "<<filename<<" no good!"<<endl;//标准错误输出
            return;
        }
        //读文件，对每个单词做处理
        string line;
        while (getline(ifs ,line))
        {//读出一个单词，判断是不是英文单词
            //字符串io istringstream
            istringstream iss(line);//定义iss，他具有读的功能.
            // iss在内存里处理，比在磁盘里ifs>>word要快
            string word;
            while(iss >> word/*,!iss.eof*/)
            {//运算符重载，这个式子会变成真值表达式。具有true和false
                //word要判断是不是英文单词，对原始数据要进行处理。难点
                string newWord=dealword(word);//等会写 处理原始数据的函数
                insert(newWord);//将满足条件的词存入vector
                //一个函数，一个功能、职责
            }
        }

//            int i=0;
//            string tmp;
//            while(line[i]!=' '){
//                if((line[i]<='Z' && line[i]>='A' ) || line[i]=='-'
//                   ||  (line[i]>='a'&&line[i]<='z')){
//                    tmp+=line[i++];//累加
////            _dict->_word=line;
////            ++_dict->_frequency;
//                } else{
//                    break;
//                }//顺利判断出，是一个单词，继续执行下列操作
//                if(_dict._word == tmp) _dict[tmp]->_frequency++;
//                else{
//                    _dict._word = tmp;
//                    _dict[tmp]->_frequency++;
//                }
//            }//while
        ifs.close();

    }
    void store(const string &filename)
    {
        ofstream ofs(filename);
        if(!ofs.good())
        {
            cerr<<"open"<<filename<<"error"<<endl;
            return;
        }
        for(size_t i =0;i !=_dict.size();++i)
        {
            ofs<< _dict[i]._word<<"     "
            <<_dict[i]._frequency<<endl;
        }
        ofs.close();
//        ofstream ofs( filename, std::ios::out | std::ios::app);
//        //追加模式 输出到dic.txt
//        if(!ofs.good()){
//            cerr<< "ofstream no good!"<<endl;
//            return;
//        }
//        ofs << _dict->_word <<_dict->_frequency<<endl;
    }

public://shift+* 高亮某个单词vimplus 按n可以跳转
    string dealword(const string &word)//加&，性能更好，减少拷贝
    {
        for(size_t i=0;i != word.size();++i)
        {
            //word!
//            if((word[i]<='Z' && word[i]>='A' ) || word[i]=='-'||  (word [i]>='a'&&word[i]<='z') )
            if(!isalpha(word[i]))
            {
                return string();//返回空串,返回值不能加&，&无法引用空串及临时对象
            }
        }
        return word;
    }
    void insert(const string &word)//word是空串怎么办？
    {
        if(string() == word)
        {
            return;//边界条件处理,判断空串
        }
        size_t i=0;
        for(i=0;i != _dict.size();++i)//size==0时，一次都不执行
        {
            if(word== _dict[i]._word)
            {
                ++_dict[i]._frequency;
//                break;
                return;//错误的
            }
        }
        if(i == _dict.size())
        {
            _dict.push_back(Record(word,1));//Record，单词首次出现的代码
        }
    }
private:
    vector<Record> _dict;
};
//void Dictionary::read(const std::string &filename)
//void Dictionary::store(const std::string &filename)
void dit(const string &filename)
{
    Dictionary dic(13000);
//    cout<<filename;
//    string line;//用于操作行
    cout<<"beging..";
    dic.read(filename);

//    while (ifs >> line){
//        ofs << line;
//    }
    //    while (getline(ifs, line)){
////        ofs<<line<<std::endl;
//    }
//    ofstream ofs("dic.txt",std::ios::out | std::ios::app);
//    if(!ofs.good()){
//        cerr << "ofstream nogood"<<endl;
//        return;
//    }
    cout<<"end of reading..";
    dic.store("dic3.txt");
//    ofs << dic.store;
}

int main(int argc, char **argv)
{
    dit("The_Holy_Bible.txt");
    return 0;
}

