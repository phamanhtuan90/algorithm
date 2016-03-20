#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>

using namespace std;

int main(){
    freopen("labiec3.inp","r",stdin);
    int num, sum;
    sum = 0;
    scanf("%d",&num);
    for(int i = 1; i <= num; i++){
       int inputNumber;
       scanf("%d", &inputNumber);
       sum +=inputNumber;
    }
    printf("%d \n", sum);

    return 0;
}
