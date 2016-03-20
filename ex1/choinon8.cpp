#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>

using namespace std;

void handle(int num1, int num2,int num3){
    int one, two, three;
    if(num1 > num2 || num1 > num3){
         if(num1 > num2 && num1 > num3){
            one = num1;
            two = num2;
            three = num3;
            if(num2 < num3){
                three = num2;
                two = num3;
            }
         }else{
            two = num1;
            one = num2;
            three = num3;
            if(num2 < num3){
                three = num2;
                one = num3;
            }
         }
    }else{
         one = num2;
         two = num3;
         three = num1;
         if(num2 < num3){
            two = num2;
            one = num3;
        }
    }

    printf("Ba so %d %d %d \n\n",num1,num2,num3);
    printf("Sap xep %d %d %d \n\n",three,two,one);

}
int main(){
    freopen("choinon8.inp","r",stdin);
    int num1, num2, num3;
    scanf("%d %d %d", &num1, &num2, &num3);
    handle(num1,num2,num3);
    return 0;
}
