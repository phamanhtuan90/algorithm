#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>

using namespace std;

int main(){
    freopen("labiec14.inp","r",stdin);
    int numberInput, numberLarge, quantity;
    scanf("%d", &numberInput);
    quantity = numberInput/2;
    if(numberInput%2 == 0){
        quantity--;
    }
    printf("So luong cap %d \n",quantity);
    for(int i = 1; i <= quantity;i++){
        numberLarge = numberInput - i;
        if(numberLarge > i){
            printf("Cap so la %d %d \n",numberLarge,i);
        }
    }
    return 0;
}
