#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>
using namespace std;
void handle(int num1, int num2,int num3){
    bool result;
    result = true;
    if(num1 > num2 + num3){
         result = false;
    }
    if(num2 > num1 + num3){
         result = false;
    }
    if(num3 > num1 + num2){
         result = false;
    }
    if(result == true){
        printf("Ba canh %d %d %d la tam giac\n",num1,num2,num3);
        printf("Dien tich la %d \n",(num1+num2+num3)/2);
    }else{
        printf("Ba canh %d %d %d k phai la tam giac\n",num1,num2,num3);
    }
}
int main(){
    freopen("choinon7.inp","r",stdin);
    int num1, num2, num3, num4 , num5, num6;
    scanf("%d %d %d %d %d %d", &num1, &num2, &num3, &num4, &num5, &num6);
    handle(num1,num2,num3);
    handle(num4,num5,num6);
    return 0;
}
