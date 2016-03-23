#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>

using namespace std;
int n;
int m[100][100];
void input(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
         for(int j = 0;j<n;j++){
            scanf("%d",&m[i][j]);
         }
    }
}

void handle(){
    int status = 1;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(i == j){
                if(m[i][j] != 0){
                    status = 0;
                }
            }
            if(j > i){
                 if(m[i][j] < 0){
                    status = 0;
                 }
            }
            if(j < i){
                 if(m[i][j] >= 0){
                    status = 0;
                 }
            }
        }
    }
    printf("%d \n",status);
}
int main(){
    freopen("trunghoc6.inp","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int x = 0;x<ntest;x++){
        input();
        handle();
    }

    return 0;
}
