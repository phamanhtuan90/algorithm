#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

int n,m;
int arrN[111];
int arrM[111];

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
			return arr[i].index;

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
	scanf("%d",&n);
	for (int i=0;i<n;i++){
        scanf("%d",&arr[i].value);
        arr[i].index = i;
	}

	scanf("%d",&m);
	for (int i=0;i<m;i++){
        scanf("%d",&arrM[i]);
	}
}


void solve(){
    sort(arr, arr+n,cmp);
    for (int i=0;i<m;i++){
        int index = binary_search(arrM[i],arr, n);
        if(index >= 0){
            index++;
        }
        printf("%d  ",index);

    }
    printf("\n");
}


int main()
{
	freopen("searching2.inp","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int i = 0; i < ntest; i++){
        input();
        solve();
    }


	return 0;
}


