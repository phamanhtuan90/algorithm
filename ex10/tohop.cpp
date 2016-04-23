#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int n,k;
int s[111];
bool d[111];


void input(){
	scanf("%d %d",&k,&n);
}

void output(){
	for(int i = 1; i <= k; i++){
        printf("%d ",s[i]);
	}
	printf("\n");
}

void chinhhop(int lev, int x){
    if(lev > k){
        output();
        return;
    }
    for(int i = 1; i <= x; i++){
        if(d[i] == 0 && s[lev - 1] < i){
            d[i] = 1;
            s[lev] = i;
            chinhhop(lev + 1, x);
            d[i] = 0;
        }
    }
}

void solve(){
    chinhhop(1, n);
}

int main()
{
	freopen("tohop.inp","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int i = 0; i < ntest; i++){
        input();
        solve();
    }


	return 0;
}


