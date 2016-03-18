#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>

using namespace std;

int main(){
    freopen("labiec4.inp","r",stdin);

    for(int i = 1; i  > 0; i++){
       int inputNumber;
       scanf("%d", &inputNumber);
       if(inputNumber % 10 == 0){
         break;
       }
       printf("%d \n", inputNumber);
    }

    return 0;
}
