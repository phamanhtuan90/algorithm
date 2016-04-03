#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

int n;
int s[111];

void input()
{
    scanf("%d",&n);
    for (int i=0; i<n; i++)
        scanf("%d",&s[i]);
}

void output()
{
    for (int i=0; i<n; i++)
        printf("%d ",s[i]);
    printf("\n");
}

bool cmp (int s1, int s2)
{
    if(s1 > s2)
        return 1;
    return 0;
}

void solve()
{
    sort(s, s+n,cmp);
}

int main()
{
    freopen("sorting1.inp","r",stdin);
    int ntest ;
    scanf("%d",&ntest);
    for(int i = 0; i < ntest; i++)
    {
        input();
        solve();
        output();
    }

    return 0;
}


