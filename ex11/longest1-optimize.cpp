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
toado d[111][111];
int range[111];
int maxSum;

toado huong[4] = {
    1,-1
    ,1,0
    ,1,1
};
int best[111][111];
void input(){
    memset(d,0,sizeof(d));
    memset(arr,0,sizeof(arr));
    memset(range,0,sizeof(range));
    maxSum = 0;
    scanf("%d %d",&h,&c);
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= c; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for (int i=1;i<=h;i++){
        for (int j=1;j<=c;j++){
            best[i][j] = -1;
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
   	if ( best[hang][cot] != -1 )
        return best[hang][cot];
    best[hang][cot] = arr[hang][cot];
    
    for(int i = 0;i < 3; i++){
        int newHang = hang + huong[i].h;
        int newCot = cot + huong[i].c;
        if(isOut(newHang, newCot) == 0){
            int sum = arr[hang][cot] + dfs(newHang,newCot);
            if(sum > best[hang][cot]){
                best[hang][cot] = sum;
                toado tmp;
                tmp.h = newHang;
                tmp.c = newCot;
                d[hang][cot] = tmp;
            }
        }
    }
    
    return best[hang][cot];
}

void solve(){
    int cResult = 1;
    for(int i = 1; i <= c; i++){
        int sum = dfs(1,i);
        if(sum > maxSum){
            maxSum = sum;
            cResult = i;
        }
        
    }
    printf("%d\n",maxSum);
    toado temp;
    
    temp.h = 1;
    temp.c = cResult;
    
    while(true){
        printf("%d %d %d\n",temp.h,temp.c,arr[temp.h][temp.c]);
        if ( temp.h == h )
            break;
        temp = d[temp.h][temp.c];
    }
    
    
}

int main()
{
    freopen("longest.txt","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int i = 0; i < ntest; i++){
        input();
        solve();
    }
    
    return 0;
}