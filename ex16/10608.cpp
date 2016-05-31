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
int quantity[111];
struct toado{
    int h,c;
};
toado huong[5] = {
    -1,0,
    0,1,
    1,0,
    0,-1
};
int sumResult ;

int findRoot(int num)
{
    if ( parent[num] == num )
        return num;
    return parent[num] = findRoot(parent[num]);
}


void solve(){
    scanf("%d %d", &n, &m);
    memset(parent,0,sizeof(parent));

    sumResult = 0;
    for(int j = 1; j <= n; j++){
        parent[j] = j;
        quantity[j] = 1;
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
        quantity[root1] += quantity[root2];
        quantity[root2] = 0;
    }
    for(int i = 1; i <= n; i++){
        if(quantity[i]  > sumResult){
            sumResult = quantity[i];
        }
    }
    printf("%d\n",sumResult);
    
}

int main()
{
    freopen("10608.txt","r",stdin);
    int ntest;
    scanf("%d", &ntest);
    for(int i = 0; i < ntest; i++){
        solve();
    }
    
    
    return 0;
}