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

void handle(){
    int sum1 = 0;
    int sum2 = 0;
    int min1 = 0;
    int min2 = 0;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            int num = arr[i][j];
            if(i == j){
                sum1 += num;
                if(i == 0){
                    min1 = num;
                }
                if(min1 > num){
                    min1 = num;
                }
            }
            if(i + j == n - 1){
                sum2 += num;
                if(i == 0){
                    min2 = num;
                }
                if(min2 > num){
                    min2 = num;
                }
            }
        }
    }
    printf("%d %d %d %d\n",sum1, min1, sum2, min2);
}
int main(){
    freopen("trunghoc4.inp","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int x = 0;x<ntest;x++){
        input();
        handle();
    }

    return 0;
}
