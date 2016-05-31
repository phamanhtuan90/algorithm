#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
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
double dist[111][111];

map <string, int> listCity;
int listCityIndex;

void pushListCity(string city){
    if(listCity[city] == 0){
        listCity[city] = listCityIndex;
        listCityIndex++;
    }
}
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
    listCityIndex = 1;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        char city1[30], city2[30];
        dt temp;
        scanf("%s %s %d", &city1, &city2, &temp.s);
        pushListCity(city1);
        pushListCity(city2);
        temp.a = listCity[city1];
        temp.b = listCity[city2];
        vect.push_back(temp);
    }
    sort(vect.begin(),vect.end(),cmp);
    for (int i=1;i<=n;i++){
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
    
    printf("%d\n", ans);
    
    
}

int main()
{
    freopen("1174.txt","r",stdin);
    int ntest;
    scanf("%d", &ntest);
    for(int i = 0; i < ntest; i++){
        input();
        solve();
    }
    
    
    return 0;
}