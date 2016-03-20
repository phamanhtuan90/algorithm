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
    freopen("labiec7.inp","r",stdin);
    int h, countSpace, countSpecial;
    scanf("%d", &h);
    countSpace = h - 1;
    countSpecial = 1;
    for(int i = 1; i <= h; i++){
       printF(countSpace,' ');
       printF(countSpecial,'*');
       printF(1,'\n');
       countSpace--;
       countSpecial += 2;
    }


    return 0;
}
