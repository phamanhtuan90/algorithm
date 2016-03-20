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
    freopen("labiec41.inp","r",stdin);
    int h, countStartSpecial, countEndSpecial, countInsideSpace, flag;

    scanf("%d", &h);
    countStartSpecial = 1;
    countEndSpecial = 1;
    countInsideSpace = h - 1;
    flag = 1;
    for(int i = 1; i <= h; i++){
       if(h/2 + 1 == i){
           printF(countStartSpecial,'*');
           printF(countEndSpecial,'*');
           flag = 0;
       }else{
           printF(countStartSpecial,'*');
           printF(countInsideSpace,' ');
           printF(countEndSpecial,'*');
       }
       printF(1,'\n');
       if(flag == 1 ){
         countStartSpecial++;
         countInsideSpace -=2;
         countEndSpecial += 2;
       }else{
         countStartSpecial--;
         countInsideSpace +=2;
         countEndSpecial -= 2;
       }
    }
    return 0;
}
