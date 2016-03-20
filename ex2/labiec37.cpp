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
    freopen("labiec37.inp","r",stdin);
    int  n, w, h, countStartSpace, countInsideSpace, flag;
    scanf("%d %d", &n, &w);
    h = (n * w) - (n -1);
    countStartSpace = w/2;
    countInsideSpace = 0;
    flag = 1;
    for(int i = 0; i < h; i++){
        if(countStartSpace == w/2 ){
            printF(countStartSpace,' ');
            printF(1,'*');
            flag = 1;
            countInsideSpace = -1;

        }else{
            printF(countStartSpace,' ');
            printF(1,'*');
            printF(countInsideSpace,' ');
            printF(1,'*');
        }
        if(countStartSpace == 0){
            flag = 0;
        }
        if(flag == 0){
            countStartSpace++;
            countInsideSpace -=2;
        }else{
            countStartSpace--;
            countInsideSpace +=2;
        }

        printF(1,'\n');
    }
    return 0;
}
