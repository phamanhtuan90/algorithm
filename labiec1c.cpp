#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>

using namespace std;

int main(){
    freopen("labiec1c.inp","r",stdin);
    int num1, num2;
    scanf("%d %d",&num1,&num2);
    for(num1; num1 <= num2; num1++){
        if(num1 %2 == 0){
             printf("%d \n",num1);
        }
    }

    return 0;
}
