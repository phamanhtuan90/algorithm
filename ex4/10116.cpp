#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <map>

using namespace std;

int nhang,ncot,start;
int arr[100][100];

struct toado {
    int h,c;
};

toado huong[5] = {
    -1,0,
    0,1,
    1,0,
    0,-1
};
toado diary[100];

int getStepAstray(toado check,int n){
    for(int i = 0; i <= n; i++){
        if(diary[i].h == check.h && diary[i].c == check.c){
            return  i;
        }
    }
    return 0;
}

int huongByChar(char c){
    int result = 0;
    if(c == 'E'){
        result = 1;
    }else if(c == 'S'){
        result = 2;
    }else if(c == 'W'){
        result = 3;
    }
    return result;
}
toado doMove(toado current,int huongNumber){
    toado newResult;
    newResult.h = current.h + huong[huongNumber].h;
    newResult.c = current.c + huong[huongNumber].c;
    return newResult;
}


void input(){
    scanf("%d %d %d",&nhang,&ncot,&start);
    for(int i = 0;i< nhang;i++){
        char sHang[100];
        scanf("%s",&sHang);
       for(int j = 0;j< ncot;j++){
            arr[i][j] = huongByChar(sHang[j]);
       }
    }
}

void handle(){
    toado current;
    current.h = 0;
    current.c = start - 1;
    diary[0].h = 0;
    diary[0].c = start - 1;
    int step = 1;
    int loopNumberAstray = 0;
    current = doMove(current,arr[current.h][current.c]);
    for(int i = 0;i <= nhang * ncot;i++){
        current = doMove(current,arr[current.h][current.c]);
        step++;
        diary[i+1].h = current.h;
        diary[i+1].c = current.c;
        if(current.h >= nhang || current.h < 0 || current.c >= ncot || current.c < 0){
            break;
        }
        int stepAstray = getStepAstray(current,i);
        if(stepAstray > 0){
             loopNumberAstray = i + 1 - stepAstray;
             step = step - loopNumberAstray;
             break;
        }
    }
    if(loopNumberAstray > 0){
        printf("%d step(s) before a loop of %d step(s)\n",step,loopNumberAstray);
    }else{
        printf("%d step(s) to exit\n",step);
    }


}

int main()
{
	int ntest;
	freopen("10116.inp","r",stdin);

	scanf("%d",&ntest);
	for (int i=0;i<ntest;i++){
		input();
		handle();

	}

	return 0;
}

