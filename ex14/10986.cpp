//123123123
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

int n, m, bd, kt;
int arr[111][111];
bool d[111];
int b[111];
int parent[111];
struct toado{
    int h,c;
};
toado huong[5] = {
    -1,0,
    0,1,
    1,0,
    0,-1
};
void input(){
    memset(arr,0,sizeof(arr));
     memset(b,0,sizeof(b));
     memset(d,0,sizeof(d));
     memset(parent,0,sizeof(parent));
    scanf("%d %d %d %d",&n, &m, &bd, &kt);
    for (int i=0;i<n;i++){
        b[i] = inf;
        d[i] = 0;
        parent[i] = -1;
    }
   
    for(int i = 0; i < m; i++){
        int x1,x2,range;
        scanf("%d %d %d",&x1, &x2, &range);
        arr[x1][x2] = range;
        arr[x2][x1] = range;
    }
    
}

int findMin(){
    int result = -1;
    int tmp = inf;
    for(int i = 0; i < n; i++){
        if(d[i] == 1){
            continue;
        }
        if(tmp > b[i]){
            tmp = b[i];
            result = i;
        }
    }
    return result;
}


void editLabel(int index){
    for(int i = 0; i < n; i++){
        if(arr[index][i] != 0){
            int tmp = b[index] + arr[index][i];
            
            if (b[i] > tmp){
                b[i] = tmp;
                d[i] = 0;
                parent[i] = index;
            }
        }
    }
}

void output(){
    printf("%d\n",b[kt]);
    printf("\n");
}

void solve(){
    b[bd] = 0;
    while(d[kt] == 0){
        int minIndex = findMin();
        if(minIndex == -1){
            break;
        }
        d[minIndex] = 1;
        editLabel(minIndex);
    }
}

int main()
{
    freopen("10986.txt","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int i = 0; i < ntest; i++){
        input();
        solve();
        output();
    }
    
    return 0;
}