#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>

using namespace std;
int n;
int arr[10];

int main(){
    freopen("tieuhoc3.inp","r",stdin);
    int n;
    int moneys[5] = {50,20,10,5,1};
    int quantity[5];
    scanf("%d",&n);
    for(int i = 0;i<5;i++){
        if(n> 0 && n > moneys[i]){
            quantity[i] = n/moneys[i];
            n = n%moneys[i];
        }else{
            quantity[i] = 0;
        }
         printf("(%d)",moneys[i]);
         printf("%d\n",quantity[i]);
    }

    return 0;
}
