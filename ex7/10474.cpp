#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

int  itest, n, q;

int nArr[100];
int qArr[100];


int binary_search(int number,int arr[],int length){
	int l = 0;
	int r = length - 1;
	int i;

	while ( l <= r ){
		i = ( l+r )/2;

		if ( number == arr[i] )
			return i;

		if ( number > arr[i] )
			l = i+1;
		else
			r = i-1;
	}

	return -1;
}
bool cmp (int s1, int s2)
{
    if(s1 < s2){
        return 1;
    }

    return 0;
}

void input(){
	for (int i=0;i<n;i++){
        scanf("%d",&nArr[i]);
	}
	for (int i=0;i<q;i++){
        scanf("%d",&qArr[i]);
	}
}


void solve(){
    sort(nArr,nArr+n,cmp);
    printf("CASE #%d",itest);
    printf("\n");
}


int main()
{
	freopen("10474.inp","r",stdin);
    itest = 1;
    while(true){
        scanf("%d %d",&n,&q);
        if(n == 0 || q == 0){
            break;
        }
        input();
        solve();
        itest++;
    }


	return 0;
}


