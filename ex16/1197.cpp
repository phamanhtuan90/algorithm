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
    memset(parent,0,sizeof(parent));

    for(int j = 0; j < n; j++){
        parent[j] = j;
    }
    int k, number, root;
    for(int i = 0; i < m; i++){
        scanf("%d", &k);
        root = 0;
        for(int j = 0; j < k; j++){
            scanf("%d", &number);
            int rootNumber = findRoot(number);
            if(rootNumber == 0){
                int currentRoot = findRoot(root);
                parent[currentRoot] = 0;
                root = 0;
                continue;
            }
            
            if(j == 0){
                root = number;
            }else{
                parent[number] = root;
            }
            
        }
    }
    sumResult = 0;
    for(int i = 0; i < n; i++){
        if(parent[i] == 0){
            sumResult++;
        }
    }
    printf("%d\n", sumResult);
}



int main()
{
    freopen("1197.txt","r",stdin);
    while(true){
        memset(parent,0,sizeof(parent));
        scanf("%d %d", &n, &m);

        if(n == 0 && m == 0){
            break;
        }
        solve();
    }
    return 0;
}