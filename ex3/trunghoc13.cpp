#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>

using namespace std;

int n;
int arr[100];

void input(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}

int handle(){
    int sumResult = 0;
    int numberResult = 0;
    int sum = 0;
    int num = 0;
    for(int i = 1; i<n; i++)
    {
        if(arr[i] > arr[i - 1]){
            if(num == 0){
                sum = arr[i - 1] + arr[i];
                num = 2;
            }else{
                sum += arr[i];
                num++;
            }
            if(num > numberResult || (num == numberResult && sum > sumResult)){
                sumResult = sum;
                numberResult = num;
            }
        }else{
            sum = 0;
            num = 0;
        }
    }
    printf("%d %d \n",numberResult,sumResult);

}

int main(){
    freopen("trunghoc13.inp","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int x = 0;x<ntest;x++){
        input();
        handle();
    }

    return 0;
}
