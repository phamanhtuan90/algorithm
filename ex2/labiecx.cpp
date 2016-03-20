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

int main(){
    freopen("labiecx.inp","r",stdin);
    int h, countStart, insideSpace, flag;
    scanf("%d", &h);
    countStart = 1;
    insideSpace = h - 2;
    flag = 1;
    for(int i = 1; i <= h; i++){
       if(i == h/2 + 1){
            printF(h, '*');
            flag = 0;
            insideSpace = -1;
       }else{
            printF(countStart, '*');
            printF(insideSpace, ' ');
            printF(countStart, '*');
       }
       if(flag == 1){
            countStart++;
            insideSpace -= 2;
       }else{
            countStart--;
            insideSpace += 2;
       }
       printF(1,'\n');
    }
    return 0;
}
