#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>
using namespace std;

int main(){
    int num;
    printf("Nhap so :");
    scanf("%d", &num);
    printf("Binh phuong cua so la %d\n",num * num);
    printf("Lap phuong cua so la %d\n",num * num * num);
    return 0;
}
