#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>

using namespace std;

int arr[100];
int num;

int input(){
    scanf("%d",&num);
    for(int i = 0;i < num;i++){
        scanf("%d",&arr[i]);
    }
}

int check(){
    int result = 1;
    for(int i = 1; i < num;i++){
        if(arr[i] * arr[i - 1] >= 0){
            result = 0;
            break;
        }
    }
    return result;
}

int main(){
    freopen("labiec26.inp","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        input();
        int result = check();
        printf("%d\n",result);

    }
    return 0;
}
