#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>

using namespace std;

char s1[300],s2[300];

void input(){
    scanf("%s",&s1);
    scanf("%s",&s2);
}

int buildAndCmp(int i){
    char cmp[300];
    for(int j = 0; j < strlen(s1);j++){
        cmp[j] = s2[i+j];
    }
    cmp[strlen(s1)] = 0;
    return strcmp(cmp,s1);
}

void handle(){
    int result = 0;
    for(int i = 0;i < strlen(s2);i++){
        if(i < strlen(s2) - strlen(s1) + 1){
            if(buildAndCmp(i) == 0){
                result++;
            }
        }
    }
    printf("%d\n",result);
}

int main(){
    freopen("capba5.inp","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int x = 0;x<ntest;x++){
       input();
       handle();
    }

    return 0;
}
