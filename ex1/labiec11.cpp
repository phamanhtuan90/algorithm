#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>

using namespace std;

int main(){
    freopen("labiec11.inp","r",stdin);

    int r,d;
    scanf("%d %d", &d, &r);
    for(int i = 0; i  < d; i++){
       for(int j = 0; j  < r; j++){
           if(i == 0 || i == d -1 || j == 0 || j == r-1){
                 printf("*");
           }else{
               printf(" ");
           }
       }
       printf("\n");

    }
}
