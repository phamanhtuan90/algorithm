#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>
using namespace std;
void check(float num){
    if(num >= 9){
        printf("Xuat sac: %f\n", num);
    }else if(num >= 8 && num < 9){
        printf("Gioi: %f\n", num);
    }else if(num >= 7 && num < 8){
        printf("Kha: %f\n", num);
    }else if(num >= 6 && num < 7){
        printf("TB Kha: %f\n", num);
    }else if(num >= 5 && num < 6){
        printf("TB: %f\n", num);
    }else{
         printf("Yeu: %f\n", num);
    }
}
int main(){
    freopen("choinon4.inp","r",stdin);
    float num1, num2, num3, num4 , num5, num6;
    scanf("%f %f %f %f %f %f", &num1, &num2, &num3, &num4, &num5, &num6);
    check(num1);
    check(num2);
    check(num3);
    check(num4);
    check(num5);
    check(num6);
    return 0;
}
