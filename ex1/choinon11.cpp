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
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    handle(num1,num2);

    return 0;
}
