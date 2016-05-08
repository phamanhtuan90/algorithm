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
char expressions [3] = {'*','+','-'};
int result = 0;
int best[111][111];
void input(){
    memset(arr,0,sizeof(arr));
    for(int i = 0; i < 5; i++){
        scanf("%d",&arr[i]);
    }
}

void dfs(int key, int sum){
    if(result == 1){
        return ;
    }
    int currentNumber = arr[key];
    d[key] = 1;
    for(int x = 0; x < 5; x++){
        if(x != key && d[x] == 0){
            for(int i = 0; i < 3;i++){
                if(i == 0){
                    dfs(x,sum * currentNumber);
                }else if(i == 1){
                    dfs(x,sum + currentNumber);
                }else {
                    dfs(x,sum  - currentNumber);
                }
                
            }
        }
    }
    if( sum == 23){
        result = 1;
    }
    
}

void solve(){
    for(int x = 0; x < 5; x++){
         memset(d,0,sizeof(d));
         if(result == 0){
            dfs(x,arr[x]);
         }
    }
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