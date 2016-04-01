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
        if(sum1 < 0 || sum2 < 0){
            result = false;
            break;
        }
    }
     if(sum1 != 0 || sum2 != 0){
            result = false;
        }
    return result;
}

int main(){
	freopen("673.inp","r",stdin);
	int ntest;
    scanf("%d",&ntest);
	for(int i = 0; i < ntest; i++){
        scanf("%s",&inputStr);
       if(check() == true){
            printf("Yes");
       }else{
            printf("No");
       }
       if(i < ntest-1){
            printf("\n");
       }
	}

	return 0;
}

