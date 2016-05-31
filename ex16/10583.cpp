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

int n, m;
int arr[111][111];
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
int sumResult = 0;

int findRoot(int num)
{
    if ( parent[num] == num )
        return num;
    return parent[num] = findRoot(parent[num]);
}


void solve(){
    sumResult = 0;
    for(int j = 1; j <= n; j++){
        parent[j] = j;
    }
    int num1, num2, root1, root2;
    for(int i = 1; i <= m; i++){
        scanf("%d %d", &num1, &num2);
        root1 = findRoot(num1);
        root2 = findRoot(num2);
        if(root1 == root2){
            continue;
        }
        parent[root2] = root1;
    }
    for(int i = 1; i <= n; i++){
        if(parent[i] == i){
            sumResult++;
        }
    }
    printf("%d\n",sumResult);
  
}

int main()
{
    freopen("10583.txt","r",stdin);
    while(true){
        memset(parent,0,sizeof(parent));
        scanf("%d %d", &n, &m);
        if(n == 0 || m == 0){
            break;
        }
        solve();
    }
    return 0;
}