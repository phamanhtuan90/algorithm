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
    int result = arr[1] - arr[0];
    for(int i = 2; i < num;i++){
        if(arr[i] - arr[i - 1] != arr[i - 1] - arr[i - 2]){
            result = 0;
            break;
        }
    }
    return result;
}

void printF(int result){
    if(result == 0){
        printf("khong phai cap so cong \n");
    }else{
        printf("la day cap so cong %d\n",result);
    }
}

int main(){
    freopen("labiec25.inp","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        input();
        int result = check();
        printF(result);

    }
    return 0;
}
