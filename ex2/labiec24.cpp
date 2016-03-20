#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>

using namespace std;


int main(){
    for(int i = 1; i <= 10;i++){
        for(int j = 1; j <= 10;j++){
            int result = i * j;
            printf("%4d",result);
        }
        printf("\n");
    }
    return 0;
}
