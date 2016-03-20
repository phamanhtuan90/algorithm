#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>

using namespace std;

int cal(int num){
    int result, over;
    if(num <= 50){
         result = num * 230;
    }else{
        over = num - 50;
        result = 50 * 230;
        if(over <= 50){
             result += over * 480;
        }else if (over < 100){
             result += (50 * 480) + (over - 50) * 700;
        }else{
             result += (50 * 480) + (99 - 50) * 700 + (over - 99) * 900;
        }
    }
    return result;


}
int main(){
    freopen("choinon10.inp","r",stdin);
    int num1,result;
    scanf("%d", &num1);
    result = cal(num1);
    printf("Tong tien cho %d so dien la %d d\n\n", num1 , result);
    return 0;
}
