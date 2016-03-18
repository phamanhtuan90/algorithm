#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>

using namespace std;

void handle(int num){
    if(num < 0){
         printf("%d la so am\n\n",num);
    }else if (num % 2 == 0){
        printf("%d la so chan\n\n",num);
    }else{
        printf("%d la so le\n\n",num);
    }

}
int main(){
    freopen("choinon9.inp","r",stdin);
    int num1;
    scanf("%d", &num1);
    handle(num1);
    return 0;
}
