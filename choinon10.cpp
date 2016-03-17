#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>
using namespace std;
void handle(int num){
    int result, over;
    if(num <= 50){
         result = num * 230;
    }else{
        over = num - 50;
        if(over <= 50){
             result = num * 480;
        }else if (over < 100){
             result = num * 700;
        }else {
             result = num * 900;
        }
    }
     printf("Tong tien cho %d so dien la %d d\n\n",num , result);

}
int main(){
    freopen("choinon10.inp","r",stdin);
    int num1, num2, num3, num4 , num5, num6;
    scanf("%d %d %d %d %d %d", &num1, &num2, &num3, &num4, &num5, &num6);
    handle(num1);
    handle(num2);
    handle(num3);
    handle(num4);
    handle(num5);
    handle(num6);
    return 0;
}
