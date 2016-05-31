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
    double h,c;
};
struct dt{
    int a,b,s;
};
toado huong[5] = {
    -1,0,
    0,1,
    1,0,
    0,-1
};
toado listPoint[4];
vector<dt> vect;
int sumAll;
double dist[111][111];
int findRoot(int num)
{
    if ( parent[num] == num )
        return num;
    return parent[num] = findRoot(parent[num]);
}
bool cmp(dt d1,dt d2){
    if (d1.s < d2.s )
        return 1;
    return 0;
}

void input(){
    memset(parent,0,sizeof(parent));
    vect.clear();
    sumAll = 0;
    for(int i = 0; i < m; i++){
        dt temp;
        scanf("%d %d %d", &temp.a, &temp.b, &temp.s);
        sumAll += temp.s;
        vect.push_back(temp);
    }
    sort(vect.begin(),vect.end(),cmp);
    for (int i=0;i<n;i++){
        parent[i] = i;
    }
}

void solve(){

    int ans = 0;
    int dem = 0;
    for (int i=0;i<vect.size();i++){
        int a = vect[i].a;
        int b = vect[i].b;
        int s = vect[i].s;
        
        int g1 = findRoot(a);
        int g2 = findRoot(b);
        
        if ( g1 == g2 )
            continue;
        
        parent[g2] = g1;
        ans += s;
        dem++;
        if ( dem == n-1 )
            break;
    }
    
    printf("%d\n",sumAll - ans);
    
    
}

int main()
{
    freopen("11631.txt","r",stdin);
    while(true){
        scanf("%d %d", &n, &m);
        if(n == 0 || m == 0){
            break;
        }
        input();
        solve();
    }
    
    
    return 0;
}