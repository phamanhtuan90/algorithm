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

int n, m ,indexResult;
char arrStr[111][111];
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
int caseNum = 0;
void input(){
    memset(arr,0,sizeof(arr));
    memset(b,0,sizeof(b));
    memset(d,0,sizeof(d));
    memset(parent,0,sizeof(parent));
    memset(arrStr,0,sizeof(arrStr));
    caseNum++;

    for(int i = 1; i <= n ; i++){
        scanf("%s",arrStr[i]);
    }
 
    for(int j = 1; j <= m; j++){
        int x1,x2,range;
        scanf("%d %d %d",&x1,&x2,&range);
        arr[x1][x2] = range;
        arr[x2][x1] = range;
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
        if( b[i] <  tmp ){
            tmp = b[i];
            result = i;
        }
    }
    return result;
}


void editLabel(int index){
    for(int i = 1; i <= n; i++){
        if(arr[index][i] != 0){
            int tmp =  b[index] + arr[index][i];
            
            if (tmp <b[i]){
                b[i] = tmp;
                d[i] = 0;
                parent[i] = index;
            }
        }
    }
}


void output(){
    printf("Case #%d : %s\n",caseNum,arrStr[indexResult]);
}
void solve(){
    int resultRange = inf;
    for(int i = 1; i <= n; i++){
        resetParams();
        b[i] = 0;
        while(true){
            int bestIndex = findBest();
            if(bestIndex == -1){
                break;
            }
            d[bestIndex] = 1;
            editLabel(bestIndex);
        }
        int maxRange = 0;
        for(int j = 1; j <= n; j++){
            if(b[j] > maxRange){
                maxRange = b[j];
            }
        }
        
        if(resultRange > maxRange){
            resultRange = maxRange;
            indexResult = i;
        }
    }
   
    
    
}

int main()
{
    freopen("11015.txt","r",stdin);
    while(true){
        scanf("%d %d",&n,&m);
        if(n == 0 || m == 0){
            break;
        }
        input();
        solve();
        output();
    }
    return 0;
}