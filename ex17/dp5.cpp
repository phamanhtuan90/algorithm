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
int best[111];
int parent[111];
int sum;

int maxx = 0;
int ansidex = -1;
void input(){
    memset(d,0,sizeof(d));
    memset(arr,0,sizeof(arr));
    memset(best, 0, sizeof(best));
    memset(parent, 0, sizeof(parent));
    ansidex = -1;
    maxx = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    
    for(int i = 0; i < n; i++){
        parent[i] = i;
        best[i] = 1;
        
    }
}

void solve(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j] && best[i] < best[j] + 1){
                parent[i] = j;
                best[i] = best[j] + 1;
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(maxx < best[i]){
            maxx = best[i];
            ansidex = i;
        }
    }
    
    
}

void induong(int idx){
    if ( parent[idx] != idx )
        induong(parent[idx]);
    printf("%d ",arr[idx]);
}

void output(){
    printf("%d\n",best[ansidex]);
    induong(ansidex);
    printf("\n\n");
    
}

int main()
{
    freopen("dp5.txt","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int i = 0; i < ntest; i++){
        input();
        solve();
        output();
    }
    
    return 0;
}