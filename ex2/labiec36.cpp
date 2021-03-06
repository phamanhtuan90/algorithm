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
    freopen("labiec36.inp","r",stdin);
    freopen("labiec36.out","w",stdout);
    int h, n, w, countSpace;
    scanf("%d %d", &n, &w);
    h = (n * w) - (n -1);
    countSpace = 0;

    for(int i = 0; i < h; i++){
        if(countSpace == 0){
            printF(w,'*');
            countSpace = w - 1;
        }else{
            printF(countSpace,' ');
            printF(1,'*');
        }
        countSpace--;
        printF(1,'\n');
    }
    return 0;
}
