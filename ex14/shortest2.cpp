#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#define inf 1000000000
using namespace std;

int h,c;
int arr[111][111];

struct toado{
    int h,c;
};
toado huong[5] = {
    -1,0,
    0,1,
    1,0,
    0,-1
};
int d[111][111];
int b[111][111];
toado parent[111][111];
toado flagResult;
vector<toado> listResult;
int sResult = inf;

void input(){
    memset(arr,0,sizeof(arr));
    scanf("%d %d",&h, &c);
    for (int i=1; i<=h; i++){
        for (int j=1 ; j<=c; j++){
            scanf("%d", &arr[i][j]);
        }
    }
}

void initParams(){
    for (int i=1; i<=h; i++){
        for (int j=1 ; j<=c; j++){
            b[i][j] = inf;
            d[i][j] = 0;
        }
    }
    memset(parent,0,sizeof(parent));
}

int isOut(int hang,int cot){
    int result  = 0;
    if(hang > h || hang <= 0){
        result  = 1;
    }
    if(cot > c || cot <= 0){
        result  = 1;
    }
    return result;
}

toado doMove(toado old,int huongNumber){
    toado newResult;
    newResult.h = old.h + huong[huongNumber].h;
    newResult.c = old.c + huong[huongNumber].c;
    return newResult;
}


toado findMin(){
    toado result;
    int tmp = inf;
    
    for (int i=1; i<=h; i++){
        for (int j=1; j<=c; j++){
            if(d[i][j] == 1){
                continue;
            }
            if(tmp > b[i][j]){
                tmp = b[i][j];
                result.h = i;
                result.c = j;
            }
        }
    }
    
    return result;
}

void buildListResult(){
    listResult.clear();
    toado flag = flagResult;
    while(arr[flag.h][flag.c] > 0){
        listResult.push_back(flag);
        flag = parent[flag.h][flag.c];
    }
}

void editLabel(toado node){
    for(int i = 0; i < 4; i++){
        toado newNode = doMove(node,i);
        if(isOut(newNode.h,newNode.c) ){
            continue;
        }
        int tmp = b[node.h][node.c] + arr[newNode.h][newNode.c];
        if(tmp > b[newNode.h][newNode.c]){
            continue;
        }
        b[newNode.h][newNode.c] = tmp;
        d[newNode.h][newNode.c] = 0;
        parent[newNode.h][newNode.c]  = node;
        if(newNode.h == h && sResult > b[newNode.h][newNode.c]){
            flagResult = newNode;
            sResult = b[newNode.h][newNode.c];
            buildListResult();
        }
        
        
        
    }
}
bool cmp (toado node1, toado node2)
{
    if(node1.h > node2.h){
        return 0;
    }
    if(node1.c > node2.c){
        return 0;
    }
    
    return 1;
}

void output(){
    printf("%d\n",b[flagResult.h][flagResult.c]);
    sort(listResult.begin(),listResult.end(),cmp);
    for(int i = 0; i < listResult.size(); i++){
        int tmpH = listResult[i].h;
        int tmpC = listResult[i].c;
        printf("%d %d %d\n", tmpH, tmpC, arr[tmpH][tmpC]);
    }
}

void solve(){
    for(int i = 1; i <= c; i++){
        initParams();
        b[1][i] = arr[1][i];
        while(d[h][c] == 0){
            toado minTmp = findMin();
            d[minTmp.h][minTmp.c] = 1;
            editLabel(minTmp);
        }
    }
    
}

int main()
{
    freopen("shortest2.txt","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int i = 0; i < ntest; i++){
        input();
        solve();
        output();
    }
    
    return 0;
}