#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>
using namespace std;
void handle(int a, int b){
    float x;
    if(a == 0 && b > 0){
        printf("Phuong trinh vo nghiem \n\n");
    }else if(a == 0 && b == 0){
        printf("Phuong trinh vo so nghiem \n\n");
    }else{
        x = (0-b)/a;
        printf("Phuong trinh co 1 nghiem x = %f\n\n",x);
    }


}
int main(){
    freopen("choinon11.inp","r",stdin);
    int num1, num2, num3, num4 , num5, num6;
    scanf("%d %d %d %d %d %d", &num1, &num2, &num3, &num4, &num5, &num6);
    handle(num1,num2);
    handle(num3,num4);
    handle(num5,num6);

    return 0;
}
