#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int n,m;
int arrN[111];
int arrM[111];

int searchNgu(int number){
    for(int i = 0; i < n; i++){
        if(arrN[i] == number){
            return i;
        }
    }
    return -1;
}
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


void solve(){

    for (int i=0;i<m;i++){
        int index = binary_search(arrM[i],arrN, n);
        if(index >= 0){
            index++;
        }
        printf(" %d ",index);
    }
    printf("\n");

    for (int i=0;i<m;i++){
        int index = searchNgu(arrM[i]);
        if(index >= 0){
            index++;
        }
        printf(" %d ",index);
    }
    printf("\n");
}


int main()
{
	freopen("searching1.inp","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int i = 0; i < ntest; i++){
        input();
        solve();
    }


	return 0;
}


