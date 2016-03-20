#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>

using namespace std;
int numberChar = 0;

void printF(int num, char character){
    for(int i = 0; i<num; i++){
        printf("%c",character);
    }
}

void printFNumber(int num){
    for(int i = 0; i<num; i++){
        if(numberChar == 10){
            numberChar = 0;
        }
        printf("%d",numberChar);
        numberChar++;
    }
}

int main(){
    freopen("labiec38.inp","r",stdin);
    int h, n, w, countSpace;
    scanf("%d %d", &n, &w);
    h = (n * w) - (n -1);
    countSpace = 0;
    numberChar = 0;
    for(int i = 0; i < h; i++){
        if(countSpace == 0){
            printFNumber(w);
            countSpace = w - 1;
        }else{
            printF(countSpace,' ');
            printFNumber(1);
        }
        countSpace--;
        printF(1,'\n');
    }
    return 0;
}
