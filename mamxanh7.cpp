#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>
using namespace std;

int main(){
    float pi, r, s, v;
    pi = 3.14;
    printf("Tinh dien tinh va the tich hinh cau\n");
    printf("Nhap ban kinh\n");
    scanf("%f", &r);
    s = 4 * r * r * pi;
    v = (4/3) * pi * r * r * r;
    printf("Dien tich hinh cau la : %f \n",s);
    printf("The tich hinh cau la : %f \n",v);
    return 0;
}
