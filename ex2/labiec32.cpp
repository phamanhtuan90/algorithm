#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>

using namespace std;

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
    freopen("labiec32.inp","r",stdin);
    int h, a, b, flag, numberChar;
    scanf("%d", &h);
    a = 0;
    b = h - 2;
    flag = 1;
    numberChar = h;
    for(int i = 1; i <= h; i++){
       if(i == h/2 + 1){
            printF(a, ' ');
            printFNumber(1, numberChar);
            flag = 0;
            b = -1;
       }else{
            printF(a, ' ');
            printFNumber(1, numberChar);
            printF(b, ' ');
            printFNumber(1, numberChar);
       }
       if(flag == 1){
            a++;
            b -= 2;
       }else{
            a--;
            b += 2;
       }
       numberChar--;
       printF(1,'\n');
    }
    return 0;
}
