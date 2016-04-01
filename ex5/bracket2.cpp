#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
char inputStr[100];

bool check(){
   int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;
    bool result = true;
    for(int i = 0; i < strlen(inputStr);i++){
        if(inputStr[i] == '('){
            sum1++;
        }
        if(inputStr[i] == ')'){
            sum1--;
        }
        if(inputStr[i] == '['){
            sum2++;
        }
        if(inputStr[i] == ']'){
            sum2--;
        }
        if(inputStr[i] == '{'){
            sum3++;
        }
        if(inputStr[i] == '}'){
            sum3--;
        }
        if(sum1 < 0 || sum2 < 0 || sum3 < 0){
            result = false;
            break;
        }
    }
     if(sum1 != 0 || sum2 != 0 || sum3 != 0){
            result = false;
        }
    return result;
}

int main(){
	freopen("bracket2.inp","r",stdin);
	while(scanf("%s",&inputStr) > 0){
       if(check() == true){
            printf("1\n");
       }else{
            printf("0\n");
       }
	}

	return 0;
}

