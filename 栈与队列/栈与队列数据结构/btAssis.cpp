//
// Created by Liang on 2022/7/23.
//

#include "function.h"

void initbtAssis(pbtAssis &bt){
    bt=(pbtAssis) calloc(1,sizeof (btAssis));
//    bt->btNode[]=NULL;
}
bool isbtAssisEmpty(pbtAssis bt){
    if(bt->length==0) return true;
    else return false;
}
bool inbtAssis(pbtAssis &bt,BiTree btx){
    if(bt->length==MAXSIZE) return false;//full judge
    else{
        bt->btNode[bt->rear]=btx;
        bt->rear=bt->rear+1%MAXSIZE;bt->length++;
        return true;
    }
}
bool outbtAssis(pbtAssis &bt,BiTree &btx){
    //empty judge
    if(isbtAssisEmpty(bt)){return false;}
    else{
        btx=bt->btNode[bt->front];
        bt->btNode[bt->front]=NULL;
        bt->front=bt->front+1%MAXSIZE;bt->length--;
        return true;
    }

}