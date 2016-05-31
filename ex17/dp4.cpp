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
void buildDp(){
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(int i = 0; i < n ; i++){
        if(d[i] == 1) continue;
        for(int j = sum; j >= arr[i]; j--){
            if( dp[j - arr[i]] == 1){
                dp[j] = 1;
            }
        }
    }
}
void calCount(int num){
    vector<int> vect;
    vect.clear();
    int tmpX = x;
    if(dp[num] == 1){
        result++;
        for(int i = n - 1; i >=0; i--){
            if(d[i] == 1) continue;
            if(dp[tmpX- arr[i]] == 1){
                vect.push_back(arr[i]);
                d[i] = 1;
                tmpX = tmpX- arr[i];
            }
        }
        if(tmpX == 0){
            buildDp();
            calCount(num);
        }
        
    }
    
    for(int i = 0; i < vect.size(); i++){
        calCount(vect[i]);
    }
}

void solve(){
    while (scanf("%d", &x) > 0) {
        memset(dp,0,sizeof(dp));
        memset(d,0,sizeof(d));
        result = 0;
        if(x == 0) break;
        buildDp();
        if(dp[x] == 1){
            calCount(x);
            printf("%d ", result);
        }else{
            printf("0 ");
        }
    }
    printf("\n");
    
}

int main()
{
    freopen("dp4.txt","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int i = 0; i < ntest; i++){
        input();
        solve();
    }
    
    return 0;
}