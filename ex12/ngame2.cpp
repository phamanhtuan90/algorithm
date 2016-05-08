#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int h,c;
int arr[111][111];
int d[111];
struct toado{
    int h,c;
};
int maxSum;
toado huong[5] = {
    -1,0,
    0,1,
    1,0,
    0,-1
};
toado point[4];
int vectMaxIndex  = -1;
int indexCheck = -1;
vector<toado> vect;
int result = 0;
int best[111][111];
void input(){
    memset(arr,0,sizeof(arr));
    result = 0;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&arr[i][j]);
            if(arr[i][j] == 0){
                toado tmp;
                tmp.h = i;
                tmp.c = j;
                vect.push_back(tmp);
                vectMaxIndex++;
                if(i < 2){
                    indexCheck++;
                }
                
            }
        }
    }
}

int sumRow(int row){
    int sum = 0;
    for(int col = 0; col < n; col++){
        sum += arr[row][col];
    }
    return sum;
}

bool checkAll(){
    bool result = true;
    int check[10];
    memset(check,0,sizeof(check));
    for(int row = 1; row < n; row++){
        if(sumRow(row) != sumRow(row - 1)){
            result = false;
        }
    }
    if(result == true){
        for(int i = 0; i < vect.size(); i++){
            int num = arr[vect[i].h][ vect[i].c];
            if(check[num] == 1){
                 result = false;
            }
            check[num]= 1;
            
            
        }
    }
    return result;
}

void output(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void dfs(int hang, int cot, int index){
    if(result == 1){
        return;
    }
    if(index > vectMaxIndex){
        return;
    }
    for(int i = 1; i <= 9; i++){
        arr[hang][cot] = i;
        if(index == indexCheck){
            if(sumRow(0) != sumRow(1)){
                continue;
            }
        }
        
        if(index == vectMaxIndex){
            if(checkAll()){
                result = 1;
                output();
                return;
            }
        }
        int nextIndex = index+1;
        dfs(vect[nextIndex].h,vect[nextIndex].c,nextIndex);
    }
}

void solve(){
    dfs(vect[0].h,vect[0].c,0);
    if(result == 0){
        printf("Khong tim thay ket qua phu hop");
    }
}

int main()
{
    freopen("ngame2.txt","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int i = 0; i < ntest; i++){
        input();
        solve();
    }
    
    return 0;
}