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

struct toado{
    int h,c;
};
int d[111];
int range[111];
int maxSum;

toado huong[4] = {
    1,-1
    ,1,0
    ,1,1
};
int n;
int best[111][111];
int dp[111];
int sum;
void input(){
    memset(d,0,sizeof(d));
    memset(arr,0,sizeof(arr));
    memset(range,0,sizeof(range));
    memset(dp, 0, sizeof(dp));
    sum = 0;
    int a;
    n = 0;
    while (scanf("%d", &a) > 0) {
        if(a == 0) break;
        arr[n] = a;
        n++;
        sum += a;
    }
    
    
}
int x;
int result;

void solve(){
    dp[0] = 1;
    for(int i = 0; i < n ; i++){
        for(int j = 0; j <= sum; j++){
            if( dp[j - arr[i]] == 1){
                dp[j] = 1;
                //printf("%d %d \n", j, arr[i]);
            }
        }
    }
    while (scanf("%d", &x) > 0) {
        if(x == 0) break;
        if(x > sum){
            x = x%sum;
        }
        printf("%d ", dp[x]);
    }
    printf("\n");
    
}

int main()
{
    freopen("dp2.txt","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int i = 0; i < ntest; i++){
        input();
        solve();
    }
    
    return 0;
}