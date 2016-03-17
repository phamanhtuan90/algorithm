#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>
using namespace std;
void handle(int num){
    if(num < 0){
         printf("%d la so am\n\n",num);
    }else if (num % 2 == 0){
        printf("%d la so chan\n\n",num);
    }else{
        printf("%d la so le\n\n",num);
    }

}
int main(){
    freopen("choinon9.inp","r",stdin);
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
