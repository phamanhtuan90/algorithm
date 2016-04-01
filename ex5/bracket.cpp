#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
char inputStr[100];

bool check(){
    int sum = 0;
    bool result = true;
    for(int i = 0; i < strlen(inputStr);i++){
        if(inputStr[i] == '('){
            sum++;
        }
        if(inputStr[i] == ')'){
            sum--;
        }
        if(sum < 0){
            result = false;
            break;
        }
    }
    if(sum != 0){
        result = false;
    }
    return result;
}

int main(){
	freopen("bracket.inp","r",stdin);
	while(scanf("%s",&inputStr) > 0){
       if(check() == true){
            printf("1\n");
       }else{
            printf("0\n");
       }
	}

	return 0;
}

