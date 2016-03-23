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
    for(int i = 0; i < n;i++ ){
        scanf("%d",&arr[i]);
    }
}
int getCount(int num){
    int c = 0;
    for(int i = 0; i < n;i++ ){
        if(num == arr[i]){
            c++;
        }
    }
    return c;
}
void handle(){
    int numberResult;
    int countResult;
    numberResult = 0;
    countResult = 0;
    for(int i = 0; i < n; i++ ){
        int num = arr[i];
        if(numberResult != num){
            int countNumber = getCount(num);
            if(countNumber > countResult || (countNumber == countResult && num > numberResult)){
                numberResult = num;
                countResult = countNumber;
            }
        }
    }

    printf("%d %d\n",numberResult,countResult);
}
int main(){

    freopen("tieuhoc6.inp","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int x = 0;x<ntest;x++){
        input();
        handle();
    }

    return 0;
}
