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
    freopen("labiec34.inp","r",stdin);
    int h, w, range;
    scanf("%d %d %d", &h, &w, &range);
    for(int i = 0; i < h; i++){
        if(i == 1 || i % range == 1){
            printF(w,'*');
        }else{
            printF(1,'*');
            printF(w - 2,' ');
            printF(1,'*');
        }

        printF(1,'\n');
    }
    return 0;
}
