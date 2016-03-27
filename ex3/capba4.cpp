#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>

using namespace std;

char s1[100], s2[100], s3[100];

void input(){
    scanf("%s %s %s",&s1,&s2,&s3);
}

int buildAndCmp(int i){
    char cmp[300];
    for(int j = 0; j < strlen(s2);j++){
        cmp[j] = s1[i+j];
    }
    cmp[strlen(s2)] = 0;
    return strcmp(cmp,s2);
}

void handle(){
    int cmpArr[100];
    char result[100] = "";
    int totalReplace = 0;
    int subLeng = strlen(s2) - strlen(s3);
    for(int i = 0; i < strlen(s1);i++){
        if(i < strlen(s1) - strlen(s2) + 1){
            if(buildAndCmp(i) == 0){
                for(int j = 0; j < strlen(s3);j++){
                    result[i+j - (totalReplace *subLeng) ] = s3[j];
                }
                i+= strlen(s2) - 1;
                totalReplace++;

            }else{
                result[i - (totalReplace *subLeng) ] = s1[i];
            }
        }else{
            result[i - (totalReplace *subLeng)] = s1[i];
        }
    }

    printf("%s\n",result);
    printf("\n");
}

int main(){
    freopen("capba4.inp","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int x = 0;x<ntest;x++){
        input();
        handle();
    }

    return 0;
}
