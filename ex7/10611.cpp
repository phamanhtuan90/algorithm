#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

int  n, q;

int nArr[100];
int qArr[100];


int searchMin(int number,int arr[],int length){
	int l = 0;
	int r = length - 1;
	int i;
    int result = -1;
	while ( l <= r ){
		i = ( l+r )/2;
		if ( number > arr[i] ){
            l = i+1;
            result = arr[i];
		}
		else{
			r = i-1;
		}

	}
	return result;
}


int searchMax(int number,int arr[],int length){
	int l = 0;
	int r = length - 1;
	int i;
    int result = -1;
	while ( l <= r ){
		i = ( l+r )/2;
		if ( number >= arr[i] ){
            l = i+1;
		}
		else{
            result = arr[i];
			r = i-1;
		}

	}
	return result;
}
void input(){

    scanf("%d",&n);
	for (int i=0;i<n;i++){
        scanf("%d",&nArr[i]);
	}
	scanf("%d",&q);
	for (int i=0;i<q;i++){
        scanf("%d",&qArr[i]);
	}
}


void solve(){
    for (int i=0;i<q;i++){
        int numMin = searchMin(qArr[i],nArr,n);
        int numMax =  searchMax(qArr[i],nArr,n);
        if(i > 0){
            printf("\n");
        }
        if(numMin == -1){
            printf("X");
        }else{
            printf("%d",numMin);
        }

        if(numMax == -1){
            printf(" X");
        }else{
            printf(" %d",numMax);
        }
	}
}


int main()
{
	freopen("10611.inp","r",stdin);
    input();
    solve();
	return 0;
}


