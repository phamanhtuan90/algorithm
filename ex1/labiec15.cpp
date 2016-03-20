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
    freopen("labiec15.inp","r",stdin);
    int h, countStartSpace, countInsideSpace, canhday;
    scanf("%d", &h);
    countStartSpace = h - 1;
    countInsideSpace = 1;
    canhday = (h * 2) - 1;
    for(int i = 1; i <= h; i++){
       if(i == h){
          printF(canhday,'*');
       }else{
            printF(countStartSpace,' ');
            printF(1,'*');
            if(i > 1 && countInsideSpace > 0){
                printF(countInsideSpace,' ');
                printF(1,'*');
                countInsideSpace += 2;
            }
       }


       printF(1,'\n');
       countStartSpace--;

    }


    return 0;
}
