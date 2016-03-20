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

int main(){
    freopen("labiec28.inp","r",stdin);
    int h, countStar, countSpace;
    scanf("%d",&h);
    countStar = (h * 2) - 1;
    countSpace = 0;
    for(int i = 0;i < h;i++){
        printF(countSpace,' ');
        printF(countStar,'*');
        countStar -= 2;
        countSpace++;
        printF(1,'\n');
    }
    return 0;
}
