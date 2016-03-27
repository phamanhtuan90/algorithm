#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <map>

using namespace std;

int nhang, ncot;
int arr[100][100];

void input(){
    scanf("%d %d",&nhang,&ncot);
    for(int i = 0;i< nhang;i++){
        char sHang[100];
        scanf("%s",&sHang);
       for(int j = 0;j< ncot;j++){
            arr[i][j] = sHang[j];
       }
    }

}
int dembom(int h, int c){
     int sum = 0;
     for(int i = 0;i< nhang;i++){
       for(int j = 0;j< ncot;j++){
            if( (i >= (h-1) && i <= (h+1)) && (j >= (c-1) && j <= (c+1)) ){
                if(arr[i][j] == '*'){
                    sum++;
                }
            }
       }
    }
    return sum;
}

void handle(){
    int result[100][100];

    for(int i = 0;i< nhang;i++){
       for(int j = 0;j< ncot;j++){
            if(arr[i][j] == '*'){
               result[i][j] = arr[i][j];
            }else{
                result[i][j] = dembom(i,j);
            }
       }
    }

    for(int i = 0;i< nhang;i++){
       for(int j = 0;j< ncot;j++){
           if(arr[i][j] == '*'){
             printf("*");
           }else{
             printf("%d", result[i][j] );
           }

       }
       printf("\n");
    }
    printf("\n");

}

int main()
{
	int ntest;
	freopen("minesweeper.inp","r",stdin);

	scanf("%d",&ntest);
	for (int i=0;i<ntest;i++){
		input();
		handle();

	}

	return 0;
}

