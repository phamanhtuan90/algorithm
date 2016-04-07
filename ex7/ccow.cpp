#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

int  n, c;

int nArr[100];


bool cmp (int n1, int n2)
{
    if(n1 < n2){
        return 1;
    }

    return 0;
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
            result = i;
			r = i-1;
		}

	}
	return result;
}

void input(){

    scanf("%d %d",&n,&c);
	for (int i=0;i<n;i++){
        scanf("%d",&nArr[i]);
	}
}


void solve(){
    sort(nArr,nArr + n, cmp);
    int startC = nArr[0];
    int endC = nArr[n - 1];
    int maxRange = (endC - startC)/ (c - 1);
    for(int range = maxRange;range > 0; range--){
        int currentC = startC;
        bool flag = false;
        for(int j = 1; j < c; j++){
            int nextNumber = currentC + range;
            int nextIndex = binary_search(nextNumber,nArr,n);

            if(nextIndex == -1){
                break;
            }else{
                currentC = nArr[nextIndex];
            }
            if(j == c-1){
                flag = true;
            }
        }
        if(flag == true){
            printf("%d\n",range);
            break;
        }
    }
}


int main()
{
	freopen("ccow.inp","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int i = 0; i < ntest; i++){
        input();
        solve();
    }
}


