#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int h,c;
char arr[111][111];

struct toado{
    int h,c;
};
int d[111][111];
int range[111];
int maxSum;
toado tick[111][111];
toado huong[9] = {
    -1,0,
    -1,1,
    0,1,
    1,1,
    1,0,
    1,-1,
    0,-1,
    -1,-1
    
};

int best[111][111];
void input(){
    memset(arr,0,sizeof(arr));
    memset(d,0,sizeof(d));
    for(int i = 0; i < h; i++){
        scanf("%s",&arr[i]);
        
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

int checkS(int h, int c){
    int sum = 0;
    for(int i = 0;i< 8;i++){
        int newH = h+huong[i].h;
        int newC = c+huong[i].c;
        if(isOut(newH,newC) == 0 && arr[newH][newC] == '*'){
            sum++;
        }
    }
    return sum;
}


void solve(){
    int dem = 0;
    for(int i = 0; i < h; i++){
        for (int j = 0; j < c; j++) {
            if(arr[i][j] == '*'){
                int quantity = checkS(i,j);
                if(quantity == 0){
                    dem++;
                }
            }
        }
    }
    printf("%d\n",dem);
}

int main()
{
    freopen("11244.txt","r",stdin);
    while(scanf("%d %d",&h, &c) > 0){
        if(h > 0 && c > 0){
            input();
            solve();
        }
        
    }
    
    return 0;
}