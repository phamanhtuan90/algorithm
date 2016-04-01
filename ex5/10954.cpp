#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
int nInput[100];
int n;

void input(){
    for(int i = 0; i < n; i++){
        scanf("%d",&nInput[i]);
    }
}
void handle(){
    int sum = nInput[0];
    int result = 0;
    for(int i = 1; i < n; i++){
        sum+= nInput[i] ;

        result+= sum;
    }
    printf("%d",result);
}

int main(){
	freopen("10954.inp","r",stdin);
	int x = 0;
	while(scanf("%d",&n) > 0){
	    if(n > 0){
            if(x > 0){
                printf("\n");
            }
            input();
            handle();
            x++;
	    }
	}

	return 0;
}

