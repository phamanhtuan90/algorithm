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
    freopen("labiec39.inp","r",stdin);
    int n, h , countSideSpace,countInsideSpace;
    scanf("%d %d", &n, &h);
    countSideSpace  = 0;
    countInsideSpace  = (h * 2) - 3;
    for(int i = 0; i < h; i++){
        if(i == 0){
            printF(1,'*');
        }
        for(int j = 0; j < n; j++){
           if(i == 0){
             printF(countInsideSpace,' ');
             printF(1,'*');
           }else if(i+1 == h){
                printF(countSideSpace,' ');
                printF(1,'*');
                printF(countSideSpace - 1,' ');
            }else{
                printF(countSideSpace,' ');
                printF(1,'*');
                printF(countInsideSpace,' ');
                printF(1,'*');
                printF(countSideSpace - 1,' ');
            }
        }
        countSideSpace++;
        countInsideSpace-=2;
        printF(1,'\n');
    }

    return 0;
}
