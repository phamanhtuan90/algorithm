#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int n,start;
int arr[111][111];
bool d[111][111];
struct toado{
    int h,c;
};
int range[111];
int maxRange;
toado huong[5] = {-1,0
    ,0,1
    ,1,0
    ,0,-1};

void input(){
    memset(d,0,sizeof(d));
    memset(arr,0,sizeof(arr));
    memset(range,0,sizeof(range));
    maxRange = 0;
	scanf("%d %d",&n,&start);
	for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d",&arr[i][j]);
        }
	}
}

int dfs(int node){
    for(int i = 1; i <= n; i++){
        if(i != node && arr[node][i] != 0 && d[node][i] == 0 ){
            d[node][i] = 1;
            d[i][node] = 1;
            range[i] = range[node] + arr[node][i];
            maxRange = max(maxRange,range[i]);
            dfs(i);
        }
    }
    return 0;
}

void solve(){
     dfs(start);
     printf("%d \n",maxRange);
}

int main()
{
	freopen("dequy2.inp","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int i = 0; i < ntest; i++){
        input();
        solve();
    }


	return 0;
}


