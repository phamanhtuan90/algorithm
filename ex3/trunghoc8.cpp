#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>

using namespace std;

int number1;
int number2;

void input(){
    scanf("%d",&number1);
    scanf("%d",&number2);
}
int getN(int n){
    if(n%2 == 0){
        n = n/2;
    }else{
        n = (3 * n) + 1;
    }
    return n;
}

int getCycle(int number){
    int cycle = 1;
    if(number == 1){
        return cycle;
    }
    for(int i = 0;i < 99999;i++){
        number = getN(number);
        cycle++;
        if(number == 1){
            break;
        }
    }
    return cycle;
}

void handle(){
    int result = 0;
    for(int i = number1;i <= number2;i++){
         int cycle = getCycle(i);
         if(cycle > result){
            result = cycle;
         }
    }
    printf("%d %d %d \n",number1,number2,result);
}

int main(){
    freopen("trunghoc8.inp","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int x = 0;x<ntest;x++){
        input();
        handle();
    }

    return 0;
}
