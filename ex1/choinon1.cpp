#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>

using namespace std;

int main(){
    freopen("choinon1.inp","r",stdin);
    int num1, num2, result;
    scanf("%d %d", &num1, &num2);
    result = num1;
    if(num2 > num1){
        result = num2;
    }
    printf("So lon nhat la: %d", result);
    return 0;
}
