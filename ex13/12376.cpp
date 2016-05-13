#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int n,m;
int arr[111][111];
int arrN[11];

struct toado{
    int h,c;
};
int d[111];
int q[111];
int maxSum;
toado tick[111][111];
toado huong[5] = {
    -1,0,
    0,1,
    1,0,
    0,-1
};

int best[111][111];
void input(){
    memset(arr,0,sizeof(arr));
    memset(arrN,0,sizeof(arrN));

    memset(d,0,sizeof(d));
     scanf("%d %d",&n,&m);
    for(int i = 0;i < n; i++){
        scanf("%d",&arrN[i]);
    }
    
    for(int i = 0;i < m; i++){
        int x1,x2;
        scanf("%d %d",&x1,&x2);
        arr[x1][x2] = 1;
    }
    
    
}

int sum;
int lastIndex;
void dfs(int num){
    int tmp = 0;
    int tmpIndex = -1;
    for(int i  = 0 ; i < n; i++){
        if(num != i && arr[num][i] == 1 && d[i] == 0){
            if(arrN[i] > tmp){
                tmp = arrN[i];
                tmpIndex = i;
                
            }
        }
    }
    if(tmp > 0){
        sum += tmp;
        d[tmpIndex] = 1;
        lastIndex =tmpIndex;
        dfs(tmpIndex);
    }
}

void solve(){
    sum = arrN[0];
    dfs(0);
    printf("%d %d\n",sum,lastIndex);
}

int main()
{
    freopen("12376.txt","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    //print("%d",&ntest);
    for(int i = 0; i < ntest; i++){
      input();
      solve();
    }
    
    return 0;
}