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
    freopen("labiec31.inp","r",stdin);
    int h, a, b, flag;
    char char1, char2;
    scanf("%d", &h);
    a = 0;
    b = h - 2;
    flag =1;
    char1 = '$';
    char2 = '*';
    for(int i = 1; i <= h; i++){
       if(i == h/2 + 1){
            printF(a, ' ');
            printF(1, char1);
            flag = 0;
            b = -1;
            char1 = '*';
            char2 = '$';
       }else{
            printF(a, ' ');
            printF(1, char1);
            printF(b, ' ');
            printF(1, char2);
       }
       if(flag == 1){
            a++;
            b -= 2;
       }else{
            a--;
            b += 2;
       }
       printF(1,'\n');
    }
    return 0;
}
