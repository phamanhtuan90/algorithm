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
    freopen("labiec40.inp","r",stdin);
    int n, h , countSideSpace,countInsideSpace, flag;
    scanf("%d %d", &n, &h);
    countSideSpace  = h/2;
    countInsideSpace  = 0;
    flag = 1;
    for(int i = 0; i < h; i++){
        if(i == h/2){
            printF(1,'*');
            flag = 0;
            countSideSpace = 0;
        }
        for(int j = 0; j < n; j++){
           if(i == 0 || i+1 == h){
             printF(countSideSpace,' ');
             printF(1,'*');
             printF(countSideSpace - 1,' ');
             countInsideSpace = -1;
           }else if (i == h/2){
                printF(countInsideSpace,' ');
                printF(1,'*');
            }else{
                printF(countSideSpace,' ');
                printF(1,'*');
                printF(countInsideSpace,' ');
                printF(1,'*');
                printF(countSideSpace - 1,' ');
            }
        }
        if(flag == 1){
            countSideSpace--;
            countInsideSpace+=2;
        }else{
            countSideSpace++;
            countInsideSpace-=2;
        }

        printF(1,'\n');
    }

    return 0;
}
