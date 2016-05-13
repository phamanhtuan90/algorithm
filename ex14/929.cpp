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
void input(){
    memset(arr,0,sizeof(arr));
    memset(b,0,sizeof(b));
    memset(d,0,sizeof(d));
    memset(parent,0,sizeof(parent));
    scanf("%d %d",&h, &c);
    for (int i=0;i<h;i++){
        for (int j=0;j<c;j++){
             scanf("%d", &arr[i][j]);
             b[i][j] = inf;
             d[i][j] = 0;
         }
    }
 
    
}

int isOut(int hang,int cot){
    int result  = 0;
    if(hang >= h || hang < 0){
        result  = 1;
    }
    if(cot >= c || cot < 0){
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
  
    for (int i=0; i<h; i++){
        for (int j=0; j<c; j++){
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


void editLabel(toado node){
    for(int i = 0; i < 4; i++){
        toado newNode = doMove(node,i);
        if(isOut(newNode.h,newNode.c) == false){
            int tmp = b[node.h][node.c] + arr[newNode.h][newNode.c];
            
            if (b[newNode.h][newNode.c] > tmp){
                b[newNode.h][newNode.c] = tmp;
                d[newNode.h][newNode.c] = 0;
                parent[newNode.h][newNode.c]  = node;
            }
        }
        
    }
}

void output(){
    printf("%d\n",b[h-1][c-1]);
}

void solve(){
    b[0][0] = 0;
    while(d[h-1][c-1] == 0){
        toado minTmp = findMin();
        d[minTmp.h][minTmp.c] = 1;
        editLabel(minTmp);
    }
}

int main()
{
    freopen("929.txt","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int i = 0; i < ntest; i++){
        input();
        solve();
        output();
    }
    
    return 0;
}