#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <map>

using namespace std;

int nhang, ncot;
int arr[100][100];
struct toado {
    int h,c;
};

toado huong[9] = {
    -1,0,
    -1,1,
    0,1,
    1,1,
    1,0,
    1,-1,
    0,-1,
    -1,-1

};
void input(){
    scanf("%d %d",&nhang,&ncot);
    for(int i = 0;i< nhang;i++){
        char sHang[100];
        scanf("%s",&sHang);
       for(int j = 0;j< ncot;j++){
            arr[i][j] = sHang[j];
       }
    }

}

//int dembom(int h, int c){
//     int sum = 0;
//     for(int i = 0;i< nhang;i++){
//       for(int j = 0;j< ncot;j++){
//            if( (i >= (h-1) && i <= (h+1)) && (j >= (c-1) && j <= (c+1)) ){
//                if(arr[i][j] == '*'){
//                    sum++;
//                }
//            }
//       }
//    }
//    return sum;
//}
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
int dembom(int h, int c){
     int sum = 0;
     for(int i = 0;i< 8;i++){
        int newH = h+huong[i].h;
        int newC = c+huong[i].c;
        if(arr[h+huong[i].h][c+huong[i].c] == '*'){
            sum++;
        }


     }
    return sum;
}

void handle(){
    int result[100][100];

    for(int i = 0;i< nhang;i++){
       for(int j = 0;j< ncot;j++){
            if(arr[i][j] == '*'){
               result[i][j] = arr[i][j];
            }else{
                result[i][j] = dembom(i,j);
            }
       }
    }

    for(int i = 0;i< nhang;i++){
       for(int j = 0;j< ncot;j++){
           if(arr[i][j] == '*'){
             printf("*");
           }else{
             printf("%d", result[i][j] );
           }

       }
       printf("\n");
    }
    printf("\n");

}

int main()
{
	int ntest;
	freopen("minesweeper.inp","r",stdin);

	scanf("%d",&ntest);
	for (int i=0;i<ntest;i++){
		input();
		handle();

	}

	return 0;
}

