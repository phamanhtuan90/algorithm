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
int arr[111][111];
bool d[111][111];
struct toado{
    int h,c;
};
int range[111];
int maxRange;
int sum,maxSum;
toado resultDetail[4];
toado tmpDetail[4];
toado huong[4] = {
     1,-1
    ,1,0
    ,1,1
};

void input(){
    memset(d,0,sizeof(d));
    memset(arr,0,sizeof(arr));
    memset(range,0,sizeof(range));
    maxSum = 0;
    sum = 0;
    scanf("%d %d",&h,&c);
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= c; j++){
            scanf("%d",&arr[i][j]);
        }
    }
}

int isOut(int hang,int cot){
    int result = 0;
    if(hang <= 0 || hang > h){
        result = 1;
    }
    if(cot <= 0 || cot > c){
        result = 1;
    }
    return result;
}


int dfs(int hang, int cot){
    //(i+1,j-1) , (i+1,j) hoặc (i+1,j+1).
    toado pointInfo ;
    sum += arr[hang][cot];
    pointInfo.h = hang;
    pointInfo.c = cot;
    tmpDetail[hang] = pointInfo;
    if(hang == h){
        if(maxSum < sum){
            maxSum = sum;
            for(int i = 1; i <= h; i++){
                resultDetail[i] = tmpDetail[i];
            }
            
        }
        return 0;
    }
    for(int i = 0;i < 3; i++){
        int newHang = hang + huong[i].h;
        int newCot = cot + huong[i].c;
        if(isOut(newHang, newCot) == 0){
            dfs(newHang,newCot);
        }
    }
    sum -= arr[hang][cot];
    return 0;
}

void solve(){
    for(int i = 1; i <= c; i++){
        dfs(1,i);
    }
    printf("%d \n", maxSum);
    for(int i = 1; i <= h; i++){
        int resultH =resultDetail[i].h;
        int resultC =resultDetail[i].c;
         printf("%d %d %d\n", resultH, resultC, arr[resultH][resultC]);
    }
    printf("\n");
    
    
}

int main()
{
    freopen("longest.txt","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int i = 0; i < ntest; i++){
        input();
        solve();
    }
    
    
    return 0;
}