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
int arr[111][111];

struct toado{
    int h,c;
};
int d[111][111];
int range[111];
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
    memset(range,0,sizeof(range));
    maxSum = 0;
    scanf("%d %d",&h,&c);
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= c; j++){
            scanf("%d",&arr[i][j]);
        }
    }
}

int isOut(int hang,int cot){
    int result = 0;
    if(hang <= 0 || hang > h){
        result = 1;
    }
    if(cot <= 0 || cot > c){
        result = 1;
    }
    return result;
}

int dfs(int hang, int cot){
   	if ( best[hang][cot] != 0 )
        return best[hang][cot];
    best[hang][cot] = 1;
    d[hang][cot] = 1;
    for(int i = 0;i < 4; i++){
        int newHang = hang + huong[i].h;
        int newCot = cot + huong[i].c;
        if(isOut(newHang, newCot) == 0 && arr[newHang][newCot] > arr[hang][cot] ){
            int range = 1 + dfs(newHang,newCot);
            if(range > best[hang][cot]){
                best[hang][cot] = range;
                toado tmp;
                tmp.h = newHang;
                tmp.c = newCot;
                tick[hang][cot] = tmp;
            }
        }
    }
    
    return best[hang][cot];
}

void solve(){
    toado pointStart;
    toado tickResult[111][111];
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= c; j++){
            memset(tick,0,sizeof(tick));
            int range = dfs(i,j);
            if(range > maxSum){
                maxSum = range;
                pointStart.h = i;
                pointStart.c = j;
                for(int a = 1; a <= h; a++){
                    for(int b = 1; b <= c; b++){
                        tickResult[a][b] = tick[a][b];
                    }
                }
            }
        }
    }
    
    printf("%d\n",maxSum);
    int x = 1;
    while(x <= maxSum){
        printf("%d %d %d\n",pointStart.h,pointStart.c,arr[pointStart.h][pointStart.c]);
        if ( pointStart.h == h )
            break;
        pointStart = tickResult[pointStart.h][pointStart.c];
        x++;
    }
}

int main()
{
    freopen("longest2.txt","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int i = 0; i < ntest; i++){
        input();
        solve();
    }
    
    return 0;
}