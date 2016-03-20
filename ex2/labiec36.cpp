#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>

using namespace std;

void printF(int num, char character){
    for(int i = 0; i<num; i++){
        printf("%c",character);
    }
}

int main(){
    freopen("labiec35.inp","r",stdin);
    //freopen("labiec35.out","w",stdout);
    int h, w, range;
    scanf("%d %d %d", &h, &w, &range);
    for(int i = 0; i < h; i++){
        if(i + 1 == h){
            printF(w,'*');
        }else{
            for(int j = 0; j < w; j++){
                if(j == 0 || j % range == 0){
                    printF(1,'*');
                }else{
                    printF(1,' ');
                }
            }
        }

        printF(1,'\n');
    }
    return 0;
}
