#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>

using namespace std;


int main(){
    freopen("labiec12.inp","r",stdin);

    int a, b, c, delta;
    scanf("%d %d %d", &a, &b, &c);

    delta = (b * b) - (4 * a * c);
    if(delta < 0){
        printf("Phuong trinh vo nghiem");
    }
    if(delta == 0){
        printf("Phuong trinh co nghiem kep");
    }
    if(delta > 0){
        printf("Phuong trinh cho hai nghiem phan biet");
    }


}
