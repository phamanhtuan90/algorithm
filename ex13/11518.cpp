#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int n,m,l;
int arr[111][111];
int arrL[11];

struct toado{
    int h,c;
};
toado huong[5] = {
    -1,0,
    0,1,
    1,0,
    0,-1
};

int d[111][111];
int countResult;


void input(){
    memset(arr,0,sizeof(arr));
    memset(arr,0,sizeof(arrL));
    memset(d,0,sizeof(d));
    countResult = 0;
    
    scanf("%d %d %d",&n,&m,&l);
    for(int i = 0; i < m;i++){
        int n1,n2;
        scanf("%d %d",&n1,&n2);
        arr[n1][n2] = 1;
    }
    for(int j = 0; j < l; j++){
        
        scanf("%d",&arrL[j]);
    }
}

void dfs(int currentNumber){
    for(int number = 1; number <= n; number++){
        if(currentNumber != number && arr[currentNumber][number] == 1 && d[currentNumber][number] == 0){
            d[currentNumber][number]  = 1;
            countResult++;
            
        }
    }
}


void solve(){
    for(int j = 0; j < l; j++){
        dfs(arrL[j]);
    }
    printf("%d\n",countResult);
}

int main()
{
    freopen("11518.txt","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int i = 0; i < ntest; i++){
        input();
        solve();
    }
    
    return 0;
}