#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>

using namespace std;

void check(int num1, int num2,int num3){
    int result;
    result = num1;
    if(num2 > result){
        result = num2;
    }
    if(num3 > result){
        result = num3;
    }
     printf("So lon nhat la: %d\n", result);
}

int main(){
    freopen("choinon5.inp","r",stdin);
    int num1, num2, num3;
    scanf("%d %d %d", &num1, &num2, &num3);
    check(num1,num2,num3);
    return 0;
}
