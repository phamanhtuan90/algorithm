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

int n, r, bd, kt, human;
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
    scanf("%d %d",&n, &r);
    for(int i = 0; i < r; i++){
        int x1,x2,p;
        scanf("%d %d %d", &x1,&x2,&p);
        arr[x1][x2] = p;
        arr[x2][x1] = p;
        
    }
    scanf("%d %d %d", &bd, &kt, &human);
    for (int i=1;i<=n;i++){
        b[i] = 0;
        d[i] = 0;
        parent[i] = -1;
    }
    
}

int findBest(){
    int result = -1;
    int tmp = 0;
    for(int i = 1; i <= n; i++){
        if(d[i] == 1){
            continue;
        }
        if(tmp < b[i]){
            tmp = b[i];
            result = i;
        }
    }
    return result;
}


void editLabel(int index){
    for(int i = 1; i <= n; i++){
        if(arr[index][i] != 0){
            int tmp =  min(arr[index][i],b[index]);
            if (tmp > b[i]){
                b[i] = tmp;
                d[i] = 0;
                parent[i] = index;
            }
        }
    }
}

void output(){

    int result = human/(b[kt] - 1);
//    if(human > (b[kt]-1)*result){
//        result++;
//    }
    if(human% (b[kt] - 1) > 0){
        result++;
    }
    printf("%d\n",result);
}

void solve(){
    b[bd] = inf;
    while(d[kt] == 0){
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
    freopen("10099.txt","r",stdin);
    input();
    solve();
    output();
    
    
    return 0;
}