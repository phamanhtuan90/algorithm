#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <queue>

using namespace std;
queue <int> inputQ;
int number;

void input(){
    for(int i = 1; i <= number; i++){
        inputQ.push(i);
    }
}

void handle(){
    int arr[100];
    int inputSize = inputQ.size();
    for(int i = 0; i < inputSize - 1; i ++){
        int frontNumber = inputQ.front();
        inputQ.pop();
        int sencondNumber = inputQ.front();
        inputQ.pop();
        inputQ.push(sencondNumber);
        arr[i] = frontNumber;
    }
    printf("%s","Discarded cards:");
    for(int i = 0; i < inputSize -1; i ++){
        if(i == inputSize-2){
             printf(" %d", arr[i]);
        }else{
             printf(" %d,", arr[i]);
        }

    }
    printf("\n%s %d","Remaining card:",inputQ.front());
    inputQ.pop();
}

int main()
{
	freopen("10935.inp","r",stdin);
	while(scanf("%d",&number) > 0){
        if(number > 0){
            input();
            handle();
            printf("\n");
        }

	}

	return 0;
}

