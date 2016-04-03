#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

int n;
int s[100];
int result [100][100];
struct toado {
    int h,c;
};
int flag[100][100];
toado currentLocation;
toado huong[5] = {
    -1,0,
    0,1,
    1,0,
    0,-1
};
int hCurrent;

int huongByChar(char c){
    int h = 0;
    if(c == 'E'){
        h = 1;
    }else if(c == 'S'){
        h = 2;
    }else if(c == 'W'){
        h = 3;
    }else if(c == 'L'){
        h = (hCurrent+3)%4;
    }else if(c == 'R'){
        h = (hCurrent+1)%4;
    }
    return h;
}

toado doMove(int huongNumber){
    toado newLocation;
    newLocation.h = currentLocation.h + huong[huongNumber].h;
    newLocation.c = currentLocation.c + huong[huongNumber].c;
    return newLocation;
}

void input()
{
    hCurrent = 3;
    memset(s, 0, sizeof(s));
    memset(result, 0, sizeof(result));
    scanf("%d",&n);
    for (int i=0; i< n * n; i++){
       scanf("%d",&s[i]);
    }
}

bool cmp (int n1, int n2)
{
    if(n1 < n2){
        return 1;
    }
    return 0;
}
bool isTurnLeft(){
    int currentH = currentLocation.h;
    int currentC = currentLocation.c;
    bool isTurnLeft = false;
    if(flag[currentH+1][currentC-1] == 1 ){
        isTurnLeft =  true;
    }
    if(flag[currentH-1][currentC-1] == 1){
        isTurnLeft =  true;
    }

    if(flag[currentH-1][currentC+1] == 1 ){
        isTurnLeft =  true;
    }

    if(flag[currentH+1][currentC+1] == 1){
        isTurnLeft =  true;
    }
    if(isTurnLeft == true){
         int newH = (hCurrent+3)%4;
         toado newLocation = doMove(newH);
         if(result[newLocation.h][newLocation.c] != 0){
            isTurnLeft = false;
         }
    }
    return isTurnLeft;
}
void solve()
{
    sort(s, s+(n*n),cmp);
    toado newLocation;
    for (int i=0; i< n * n; i++){
       if(i == 0){
           currentLocation.h = n/2;
           currentLocation.c = n/2;
           flag[currentLocation.h][currentLocation.c] = 1;
       }else if(i == 1){
           currentLocation = doMove(hCurrent);
           hCurrent = huongByChar('L');
           flag[currentLocation.h][currentLocation.c] = 1;
       }else{
           currentLocation = doMove(hCurrent);
           if(isTurnLeft() == true){
                 hCurrent = huongByChar('L');
                 flag[currentLocation.h][currentLocation.c] = 1;
           }

       }
       result[currentLocation.h][currentLocation.c] = s[i];
    }

}

void output()
{
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            printf("%2d ",result[i][j]);
        }
         printf("\n");
    }
    printf("\n");
}

int main()
{
    freopen("xoanoc.inp","r",stdin);
    int ntest ;
    scanf("%d",&ntest);
    for(int i = 0; i < ntest; i++)
    {
        input();
        solve();
        output();
    }

    return 0;
}


