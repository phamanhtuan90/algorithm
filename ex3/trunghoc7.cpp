#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>

using namespace std;
int w;
int h;
int ncanh;
int arr[100][100];
void input(){
    scanf("%d",&w);
    scanf("%d",&h);
    scanf("%d",&ncanh);

    for(int i = 0;i<w;i++){
         for(int j = 0;j<h;j++){
            scanf("%d",&arr[i][j]);
         }
    }
}
bool check(int a, int b, int ncanh){

     for(int i = a; i<a+ncanh; i++)
    {
        for(int j = b; j<b+ncanh; j++)
        {
            if(arr[i][j] == 0)
                    return false;

        }
    }
    return true;
}

void handle(){
    int sum = 0;
    for(int i = 0; i<w; i++)
    {
        for(int j = 0; j<h; j++)
        {
            if(i + ncanh - 1 < w && j + ncanh - 1 < h){
                if(check(i,j,ncanh)){
                    sum++;
                }
            }
        }
    }
    printf("%d \n",sum);
}

int main(){
    freopen("trunghoc7.inp","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int x = 0;x<ntest;x++){
        input();
        handle();
    }

    return 0;
}
