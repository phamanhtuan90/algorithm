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

int n,k, bd, kt;
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

void input(){
    memset(arr,0,sizeof(arr));
    memset(b,0,sizeof(b));
    memset(d,0,sizeof(d));
    memset(parent,0,sizeof(parent));
    scanf("%d %d %d %d",&n, &k, &bd, &kt);
    for (int j=0;j<k;j++){
        int l1, l2, s;
        scanf("%d %d %d", &l1, &l2, &s);
        arr[l1][l2] = s;
    }
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

void output(){
    int flag = kt;
    vector <int> result;
    while (flag > 0) {
        result.push_back(flag);
        flag = parent[flag];
    }
    sort(result.begin(), result.end() );
    for(int i = 0; i < result.size(); i++){
        printf("%d ", result[i]);
    }
    printf("\n");
}

void solve(){
    b[bd] = 0;
    while (d[kt]  == 0) {
        int currentMin = findMin();
        if(currentMin == -1){
            break;
        }
        d[currentMin] = 1;
        editLabel(currentMin);
    }
}

int main()
{
    freopen("dijkstra1.txt","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int i = 0; i < ntest; i++){
        input();
        solve();
        output();
    }
    
    return 0;
}