#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>

using namespace std;

bool checkPrime(int number){
    bool result = true;
    if(number % 2 == 0|| number % 3 == 0
       || number % 5 == 0 || number % 7 == 0 ){
        result = false;
    }
    if(number == 2 || number == 3 || number ==5 || number == 7){
        result = true;
    }
    return result;
}

int main(){
    freopen("labiec12.inp","r",stdin);

    for(int i = 0; i  < 4; i++){
        int number;
        scanf("%d", &number);
        if(checkPrime(number)){
            printf("%d la so nguyen to \n",number);
        }else{
          printf("%d k phai so nguyen to\n",number);
        }
    }
}
