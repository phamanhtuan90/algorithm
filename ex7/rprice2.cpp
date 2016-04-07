#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

int n,m,k;
int arrN[100];
int arrM[100];
struct nInfo {
   int index,value;
};


void input(){
	scanf("%d",&n);
	scanf("%d",&k);
	for (int i=0;i<n;i++){
        scanf("%d",&arrN[i]);
	}

	scanf("%d",&m);
	for (int i=0;i<m;i++){
        scanf("%d",&arrM[i]);
	}



}
int binary_search(int number,int arr[],int length){
	int l = 0;
	int r = length - 1;
	int i;
    int result = -1;
	while ( l <= r ){
		i = ( l+r )/2;
		if( arr[i] == number){
            return i;
		}
		if ( number > arr[i] ){
            l = i+1;
            if(arr[i] + k >=  number){
                result = i;
            }
		}
		else{
			r = i-1;
		}

	}
	return result;
}


void solve(){
    for (int i=0;i<m;i++){
        int index = binary_search(arrM[i],arrN, n);
        if(index >= 0){
            index++;
        }
        printf(" %d ",index);
    }
    printf("\n");
}


int main()
{
	freopen("rprice2.inp","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int i = 0; i < ntest; i++){
        input();
        solve();
    }


	return 0;
}


