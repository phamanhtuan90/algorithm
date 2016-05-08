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
int arr[111];
int d[111];
struct toado{
    int h,c;
};
int maxSum;
toado huong[5] = {
    -1,0,
    0,1,
    1,0,
    0,-1
};
int danhdau[111][111][111];
char expressions [3] = {'*','+','-'};
int result = 0;
int best[111][111];
void input(){
    memset(arr,0,sizeof(arr));
    result = 0;
    for(int i = 0; i < 5; i++){
        scanf("%d",&arr[i]);
    }
}

void dfs(int sum, int index){
    if(result == 1){
        return;
    }
    if(index == 5){
        if(sum == 23){
            result = 1;
        }
        return;
    }
    int num = arr[index];
    int newSum = 0;
    for(int i = 0; i < 3;i++){
        if(i == 0){
            newSum =  sum * num;
        }else if(i == 1){
            newSum = sum + num;
           
        }else {
            newSum = sum - num;
        }
        dfs(newSum,index + 1);
        
    }
}



void solve(){
    dfs(arr[0],0);
    if(result == 1){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
}

int main()
{
    freopen("dequy235.txt","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int i = 0; i < ntest; i++){
        input();
        solve();
    }
    
    return 0;
}