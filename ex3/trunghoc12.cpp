#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>

using namespace std;

int n;
int arr[100][100];

void input(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
         for(int j = 0;j<n;j++){
            scanf("%d",&arr[i][j]);
         }
    }
}

int handle(){
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(j > i){
                 if(arr[i][j] != arr[j][i]){
                    return 0;
                 }
            }
        }
    }
    return 1;
}

int main(){
    freopen("trunghoc12.inp","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int x = 0;x<ntest;x++){
        input();
        int result = handle();
        printf("%d\n",result);
    }

    return 0;
}
