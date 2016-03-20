#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>

using namespace std;

int main(){
    freopen("labiec2.inp","r",stdin);
    int num, sum;
    sum = 0;
    scanf("%d",&num);
    for(int i = 0; i <= num; i++){
        if(i % 2 == 1){
            sum += i;
        }
    }
    printf("Tong %d", sum);
    return 0;
}
