#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>

using namespace std;

int main(){
    freopen("choinon6.inp","r",stdin);

    int h, rate, salary;
    scanf("%d", &h);
    scanf("%d", &rate);
    salary = h * rate;

    if(h >40){
        salary += (h - 40) * rate;
    }
    printf("So tien linh la : %d",salary);

    return 0;
}
