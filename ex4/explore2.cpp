#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <map>

using namespace std;

struct toado {
    int h,c;
};
toado huong[5] = {
    -1,0,
    0,1,
    1,0,
    0,-1
};
char inputStr[100];
int lastMove = 0;
toado diary[100];

void input(){
    scanf("%s",inputStr);
}

int huongByChar(char c){
    int result = 0;
    if(c == 'L'){
        result = lastMove - 1;
        if(result == -1){
            result = 3;
        }
    }else if(c == 'R'){
        result = lastMove + 1;
        if(result == 4){
            result = 0;
        }
    }else if(c == 'C'){
        result = lastMove;
    }else if(c == 'B'){
        result = lastMove - 2;
        if(lastMove == 0 || lastMove == 1){
            result = lastMove + 2;
        }
    }else if(c == 'E'){
        result = 1;
    }else if(c == 'S'){
        result = 2;
    }else if(c == 'W'){
        result = 3;
    }
    return result;
}
float range(toado toado2){
    toado toado1;
    toado1.h = 0;
    toado1.c = 0;
    return sqrt(pow(toado1.h - toado2.h,2) + pow(toado1.c - toado2.c,2));
}
toado doMove(toado old,int huongNumber){
    toado newResult;
    newResult.h = old.h + huong[huongNumber].h;
    newResult.c = old.c + huong[huongNumber].c;
    return newResult;
}

int isAstray(toado check,int n){
    for(int i = 0; i <= n; i++){
        if(diary[i].h == check.h && diary[i].c == check.c){
            return  1;
        }
    }
    return 0;
}

void handle(){
    toado result;
    result.h = 0;
    result.c = 0;
    diary[0].h = result.h;
    diary[0].c = result.c;
    //lac duong
    int astray = 0;
    for(int i = 0; i < strlen(inputStr);i++){
        int huongNumber = huongByChar(inputStr[i]);
        result = doMove(result,huongNumber);
        if(isAstray(result,i) == 1){
            astray++;
        }
        diary[i+1].h = result.h;
        diary[i+1].c = result.c;
        lastMove = huongNumber;
    }
    printf("%f %d\n",range(result),astray);
}

int main()
{
	int ntest;

	freopen("explore2.inp","r",stdin);

	scanf("%d",&ntest);
	for (int i=0;i<ntest;i++){
		input();
		handle();
	}

	return 0;
}

