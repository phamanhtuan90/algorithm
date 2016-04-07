#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

int n,m;
int arrN[100];
int arrM[100];
struct nInfo {
   int index,value;
};


void input(){
	scanf("%d",&n);
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
		if ( number > arr[i] ){
            l = i+1;
		}
		else{
            if(number == arr[i]){
                return i;
            }
            result = i;
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
	freopen("rprice1.inp","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int i = 0; i < ntest; i++){
        input();
        solve();
    }


	return 0;
}


