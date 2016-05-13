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

int n,kt, maxTime, m;
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
int d[111];
int b[111];
int parent[111];
int countResult = 0;
void input(){
    memset(arr,0,sizeof(arr));
    scanf("%d %d %d %d",&n, &kt, &maxTime, &m);
    for(int i = 0; i < m; i ++){
        int b1, b2, s;
        scanf("%d %d %d", &b1, &b2, &s);
        arr[b1][b2] = s;
    }
    
}


void resetParams(){
    memset(b,0,sizeof(b));
    memset(d,0,sizeof(d));
    memset(parent,0,sizeof(parent));
    for(int i = 1 ; i <= n; i++){
        b[i] = inf;
        d[i] = 0;
    }
}


int findMin(){
    int result = -1;
    int flag = inf;
    for(int i = 1; i <= n; i++){
        if(d[i] == 1){
            continue;
        }
        if(flag > b[i]){
            result = i;
            flag = b[i];
        }
    }
    return result;
}


void editLabel(int node){
    for(int i = 1; i <= n; i++){
        if(arr[node][i] != 0){
            int flag = b[node] + arr[node][i];
            if(b[i] > flag){
                b[i] = flag;
                d[i] = 0;
                parent[i] = node;
                
            }
        }
    }
}



void solve(){
    for(int i = 1 ; i <= n; i++){
        if(i == kt){
            countResult++;
            continue;
        }
        resetParams();
        b[i] = 0;
        while (d[kt]  == 0) {
            int currentMin = findMin();
            if(currentMin == -1){
                break;
            }
            d[currentMin] = 1;
            editLabel(currentMin);
        }
        if(b[kt] <= maxTime){
            countResult++;
        }
    }
    printf("%d\n",countResult);
}

int main()
{
    freopen("1112.txt","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int i = 0; i < ntest; i++){
        input();
        solve();
    }
    
    return 0;
}