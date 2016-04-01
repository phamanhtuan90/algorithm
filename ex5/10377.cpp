#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <queue>

using namespace std;

int nhang,ncot;
char arr[100][100];
char operation[1000];
queue <char> myOperations;
int hCurrent = 0;
struct toado {
    int h,c;
};
toado location;
toado huong[5] = {
    -1,0,
    0,1,
    1,0,
    0,-1
};


int huongByChar(char c){
    int result = 0;
    if(c == 'E'){
        result = 1;
    }else if(c == 'S'){
        result = 2;
    }else if(c == 'W'){
        result = 3;
    }else if(c == 'L'){
        result = (hCurrent+3)%4;
    }else if(c == 'R'){
        result = (hCurrent+1)%4;
    }
    return result;
}
char charByHuong(int h){
    char result = 'N';
    if(h == 1){
        result = 'E';
    }else if(h == 2){
        result = 'S';
    }else if(h == 3){
        result = 'W';
    }
    return result;
}
toado doMove(int huongNumber){
    toado newLocation;
    newLocation.h = location.h + huong[huongNumber].h;
    newLocation.c = location.c + huong[huongNumber].c;
    return newLocation;
}
void handle(){
    int operationSize = myOperations.size();
    toado newLocation;
    for(int i = 0;i< operationSize;i++){
         char action = myOperations.front();
         myOperations.pop();

         if(action == 'F'){
             newLocation = doMove(hCurrent);
             if(arr[newLocation.h][newLocation.c] == ' '){
                 location = newLocation;
             }
         }else if(action == 'Q'){
             location.h = location.h + 1;
             printf("%d %d %c",location.h,location.c,charByHuong(hCurrent));
             printf("\n");
            break;
         }else {
            hCurrent = huongByChar(action);
         }

    }
}

void input(){
    scanf("%d %d",&nhang,&ncot);
    for(int i = 0;i<nhang;i++){
         for(int j = 0;j<=ncot;j++){
             scanf("%c",&arr[i][j]);
         }
    }
    scanf("%d %d",&location.h,&location.c);
    location.h = location.h - 1;
    while(gets(operation)){
        for(int i = 0;i < strlen(operation);i++){
            if(operation[i] != ' '){
                myOperations.push(operation[i]);
            }

        }
    }
}

int main()
{
	int ntest;
	freopen("10377.inp","r",stdin);
	scanf("%d",&ntest);
	for (int i=0;i<ntest;i++){
		input();
		handle();

	}

	return 0;
}

