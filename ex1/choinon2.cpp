#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>

using namespace std;

void compare(int num1, int num2){
    if(num1 == num2){
        printf("%d bang %d \n", num1, num2);
    }else{
        printf("%d khac %d \n", num1, num2);
    }
}

int main(){
    freopen("choinon2.inp","r",stdin);
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    compare(num1,num2);
    return 0;
}
