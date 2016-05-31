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

int n, s, q, bd, kt;
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
    scanf("%d %d %d",&n, &s, &q);
    for(int i = 0; i < s; i++){
        int x1,x2,d;
        scanf("%d %d %d", &x1,&x2,&d);
        arr[x1][x2] = d;
        arr[x2][x1] = d;
        
    }
    
}

void resetParams(){
    memset(b,0,sizeof(b));
    memset(d,0,sizeof(d));
    memset(parent,0,sizeof(parent));
    for (int i=1;i<=n;i++){
        b[i] = inf;
        d[i] = 0;
        parent[i] = -1;
    }
}

int findBest(){
    int result = -1;
    int tmp = inf;
    for(int i = 1; i <= n; i++){
        if(d[i] == 1){
            continue;
        }
        if(b[i] < tmp){
            tmp = b[i];
            result = i;
        }
    }
    return result;
}


void editLabel(int index){
    for(int i = 1; i <= n; i++){
        if(arr[index][i] != 0){
            int tmp =  max(arr[index][i],b[index]);
            if (tmp < b[i]){
                b[i] = tmp;
                d[i] = 0;
                parent[i] = index;
            }
        }
    }
}

void output(){
    if(b[kt] == inf){
        printf("no path\n");
    }else{
        printf("%d\n", b[kt]);
    }
}

void solve(){
    for(int i = 0 ; i < q; i++){
        resetParams();
        scanf("%d %d", &bd, &kt);
        b[bd] = 0;
        while(d[kt] == 0){
            int bestIndex = findBest();
            if(bestIndex == -1){
                break;
            }
            d[bestIndex] = 1;
            editLabel(bestIndex);
        }
        output();
       
    }
    printf("\n");
  
}

int main()
{
    freopen("10048.txt","r",stdin);
    int ntest;
    scanf("%d", &ntest);
    for(int i = 0; i < ntest; i++){
        input();
        solve();
        //output();
    }
    return 0;
}