#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>

using namespace std;

bool isTriangle(int num1, int num2,int num3){
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
    return result;

}
int main(){
    freopen("choinon7.inp","r",stdin);
    int num1, num2, num3;
    scanf("%d %d %d", &num1, &num2, &num3);
    if(isTriangle(num1,num2,num3)){
        printf("Ba canh %d %d %d la tam giac\n",num1,num2,num3);
        printf("Dien tich la %d \n",(num1+num2+num3)/2);
    }else{
        printf("Ba canh %d %d %d k phai la tam giac\n",num1,num2,num3);
    }
    return 0;
}
