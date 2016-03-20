#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>

using namespace std;

int main(){
    freopen("labiec1b.inp","r",stdin);
    int num1, sum;
    sum = 0;
    scanf("%d",&num1);
    for(int i = 1; i <= num1; i++){
        sum += i;
    }
    printf("Tong la %d",sum);
    return 0;
}
