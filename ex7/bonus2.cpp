#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

int n,minBonus,maxBonus;

struct nInfo {
   int index,value;
};
nInfo arr[100];



void input(){
	scanf("%d %d %d",&n,&minBonus,&maxBonus);
	for (int i=0;i<n;i++){
        scanf("%d",&arr[i].value);
        arr[i].index = i;
	}
}


void solve(){
    int countNV = 0;
    for (int i=0;i<n;i++){
        if(arr[i].value >= minBonus &&  arr[i].value <= maxBonus){
            printf("%d  ",arr[i].index + 1);
            countNV++;
        }
    }
    if(countNV == 0){
         printf("-1");
    }
    printf("\n");
}


int main()
{
	freopen("bonus.inp","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int i = 0; i < ntest; i++){
        input();
        solve();
    }


	return 0;
}


