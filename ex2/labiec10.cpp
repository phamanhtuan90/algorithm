#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>

using namespace std;

int Ucln(int num1, int num2){
    int result, a;
    result = 1;
    a = num1;
    if(num1 > num2){
        a = num2;
    }
    for(int i = 2; i <= a; i++){
        if(num1 % i == 0 && num2 % i == 0){
            result = i;
        }
    }
    return result;
}

int Bcnn(int num1, int num2){
    int result, i;
    result = num1 * num2;
    i = num1;
    if(num1 > num2){
        i = num2;
    }
    for(i; i < result; i++){
        if(i % num1 == 0 && i % num2 == 0){
            result = i;
            break;
        }
    }
    return result;
}

int main(){
    freopen("labiec10.inp","r",stdin);
    int num1, num2, ucln, bcnn;
    scanf("%d %d",&num1,&num2);
    ucln = Ucln(num1, num2);
    bcnn = Bcnn(num1, num2);
    printf("%d %d",ucln, bcnn);
    return 0;
}
