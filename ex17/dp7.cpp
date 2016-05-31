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

struct info{
    int h1,h2,s;
};
int d[111];
int range[111];
int maxSum;

info arr[10];
int n;
int best[111];
int parent[111];
int sum;
int maxx = 0;
int ansidex = -1;

bool cmp(info d1,info d2){
    if (d1.h1 != d2.h1 )
        return d1.h1 < d2.h1;
    return d1.h2 < d2.h2;
}

void input(){
    memset(d,0,sizeof(d));
    memset(range,0,sizeof(range));
    memset(best, 0, sizeof(best));
    maxx = 0;
    ansidex  = -1;
    sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d %d",&arr[i].h1, &arr[i].h2, &arr[i].s);
    }
    sort(arr,arr + n,cmp);
    for(int i = 0; i < n; i++){
        parent[i] = i;
        best[i] = arr[i].s;
    }
    
    
}

void solve(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[i].h1 >= arr[j].h2 && best[i] < best[j] + arr[j].s){
                parent[i] = j;
                best[i] = best[j] + arr[i].s;
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
    printf("%d %d\n",arr[idx].h1,arr[idx].h2);
}

void output(){
    printf("%d\n",best[ansidex]);
    induong(ansidex);
    
}

int main()
{
    freopen("dp7.txt","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int i = 0; i < ntest; i++){
        input();
        solve();
        output();
    }
    
    return 0;
}