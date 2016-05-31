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

int n, s;
int h[111];
int r[111];
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
    caseNum++;
    scanf("%d", &s);
    while (true) {
        int x1, x2;
        scanf("%d %d", &x1, &x2);
        if(x1 ==0 || x2 == 0){
            break;
        }
        arr[x1][x2] = 1;
        //arr[x2][x1] = 1;
    }

    
}

void resetParams(){
    memset(b,0,sizeof(b));
    memset(d,0,sizeof(d));
    memset(parent,0,sizeof(parent));
    for (int i=1;i<=n;i++){
        b[i] = 0;
        d[i] = 0;
        parent[i] = -1;
    }
}

int findBest(){
    int result = -1;
    int tmp = -1;
    for(int i = 1; i <= n; i++){
        if(d[i] == 1){
            continue;
        }
        if( b[i] > tmp ){
            tmp = b[i];
            result = i;
        }
    }
    return result;
}


void editLabel(int index){
    for(int i = 1; i <= n; i++){
        if(arr[index][i] != 0){
            int tmp =  b[index] + 1;
            
            if (tmp > b[i] && i != s && parent[index] != i){
                b[i] = tmp;
                d[i] = 0;
                parent[i] = index;
            }
        }
    }
}


void output(){
    int maxIndex = 0;
    int maxNum = 0;
    for(int  i = 1; i <= n; i++){
        if(b[i] > maxNum){
            maxNum = b[i];
            maxIndex = i;
        }
    }
    printf("Case  %d: The longest path from %d has length %d, finishing at %d",
           caseNum,s,b[maxIndex],maxIndex);
    printf("\n");
}
void solve(){
   
    resetParams();
    b[s] = 0;
    while(true){
        int bestIndex = findBest();
        if(bestIndex == -1){
            break;
        }
        d[bestIndex] = 1;
        editLabel(bestIndex);
    }

    
}

int main()
{
    freopen("10000.txt","r",stdin);
    while(true){
        scanf("%d",&n);
        if(n == 0){
            break;
        }
        input();
        solve();
        output();
    }
    return 0;
}