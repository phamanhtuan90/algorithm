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
struct dt {
    int a, b;
    double s;
};

toado listPoint[4];
double dist[111][111];
vector<dt> vect;


int findRoot(int num)
{
    if ( parent[num] == num )
        return num;
    return parent[num] = findRoot(parent[num]);
}
double calDist(int i,int j){
    toado tmpI = listPoint[i];
    toado tmpJ = listPoint[j];
    return sqrt(
                ((tmpJ.h - tmpI.h)*(tmpJ.h - tmpI.h))
                + ((tmpJ.c - tmpI.c)*(tmpJ.c - tmpI.c))
                );
    
}
bool cmp(dt d1,dt d2){
    if (d1.s < d2.s )
        return 1;
    return 0;
}

void solve(){
    memset(parent,0,sizeof(parent));
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%lf %lf", &listPoint[i].h, &listPoint[i].c);
        
    }
    
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            double range = calDist(i, j);
            dist[i][j] = range;
            dist[j][i] = range;
            dt tmp;
            tmp.a = i;
            tmp.b = j;
            tmp.s = range;
            vect.push_back(tmp);
        }
    }
    sort(vect.begin(),vect.end(),cmp);
    for (int i=0;i<n;i++){
        parent[i] = i;
    }
    double ans = 0;
    int dem = 0;
    for (int i=0;i<vect.size();i++){
        int a = vect[i].a;
        int b = vect[i].b;
        double s = vect[i].s;
        
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
    printf("%lf\n", ans);
    
    
    
    
}

int main()
{
    freopen("10034.txt","r",stdin);
    int ntest;
    scanf("%d", &ntest);
    for(int i = 0; i < ntest; i++){
        solve();
    }
    
    
    return 0;
}