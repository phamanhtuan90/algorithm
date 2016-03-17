#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>
using namespace std;

int main(){
    int sNumber, h, m , s;
    printf("Nhap so giay:");
    scanf("%d", &sNumber);
    h = sNumber/3600;
    m = (sNumber%3600) /60;
    s = (sNumber%3600) % 60;
    printf("So gio la : %d:%d:%d", h, m, s);
    return 0;
}
