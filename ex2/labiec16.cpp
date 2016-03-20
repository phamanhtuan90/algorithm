#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>

using namespace std;

int giaithua(int a){
    int result = a;
    for(int i = 1; i < a; i++){
        result *= (a - i);
    }
    return result;
}

int main(){
    freopen("labiec16.inp","r",stdin);
    int n, a, result;
    scanf("%d",&n);
    for(int i = 0; i < n;i++){
        scanf("%d",&a);
        result = giaithua(a);
        printf("%d! = %d\n", a, result);
    }
    return 0;
}
