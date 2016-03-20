#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>

using namespace std;

int arr[100];
int num;

void printF(int num, char character){
    for(int i = 0; i<num; i++){
        printf("%c",character);
    }
}

void printFNumber(int num, int character){
    for(int i = 0; i<num; i++){
        printf("%d",character);
    }
}

int main(){
    freopen("labiec29.inp","r",stdin);
    int h, range, n, countNumber, countSpace;
    scanf("%d",&h);
    scanf("%d",&range);
    countNumber = (h * 2) - 1;
    countSpace = 0;
    n = 1;
    for(int i = 0;i < h;i++){
        printF(countSpace,' ');
        printFNumber(countNumber,n);
        countNumber -= 2;
        countSpace++;
        n += range;
        printF(1,'\n');
    }
    return 0;
}
