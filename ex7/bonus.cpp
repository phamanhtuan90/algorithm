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


int binary_search(int number,nInfo arr[],int length){
	int l = 0;
	int r = length - 1;
	int i;

	while ( l <= r ){
		i = ( l+r )/2;

		if ( number == arr[i].value )
			return i;

		if ( number > arr[i].value )
			l = i+1;
		else
			r = i-1;
	}
	return -1;
}

bool cmp (nInfo s1, nInfo s2)
{
    if(s1.value < s2.value){
        return 1;
    }

    return 0;
}

void input(){
	scanf("%d %d %d",&n,&minBonus,&maxBonus);
	for (int i=0;i<n;i++){
        scanf("%d",&arr[i].value);
        arr[i].index = i;
	}
}


void solve(){
    int minBonuxIndex,maxBonusIndex;
    nInfo originArr[100];
    sort(arr, arr+n,cmp);
    minBonuxIndex = binary_search(minBonus,arr, n);
    maxBonusIndex = binary_search(maxBonus,arr, n);
    printf("%d \n",minBonuxIndex);
    printf("%d \n",maxBonusIndex);
    for(int i = minBonuxIndex; i <= maxBonusIndex; i++){
         printf("%d ",arr[i].index);
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


