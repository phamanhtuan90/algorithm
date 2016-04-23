#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int h,c;
int arr[111][111];
bool d[111][111];
struct toado{
    int h,c;
};
toado huong[5] = {-1,0
    ,0,1
    ,1,0
    ,0,-1};

void input(){
    memset(d,0,sizeof(d));
    memset(arr,0,sizeof(arr));
	scanf("%d %d",&h,&c);
	for(int i = 0; i < h; i++){
        for(int j = 0; j < c; j++){
            scanf("%d",&arr[i][j]);
        }
	}

}

int isOut(int hang,int cot){
    int result  = 0;
    if(hang >= h || hang < 0){
        result  = 1;
    }
    if(cot >= c || cot < 0){
        result  = 1;
    }
    return result;
}


int dfs(int hang, int cot){
    d[hang][cot] = 1;
    int result = 1;

    for(int i = 0;i < 4;i++){
        int newHang = hang + huong[i].h;
        int newCot = cot + huong[i].c;
        if(isOut(newHang,newCot) == 0 && arr[newHang][newCot] == 0 && d[newHang][newCot] == 0){
            result += dfs(newHang,newCot);
        }
    }
    return result;
}

void solve(){
    vector<int> vect;
    vect.clear();
    int vung = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < c; j++){
           if(arr[i][j] == 0 && d[i][j] == 0){
                int result = dfs(i,j);
                vect.push_back(result);
                vung++;
           }
        }
	}
    sort(vect.begin(),vect.end());
    printf("%d ",vung);
    for(int i = 0;i< vect.size();i++){
        printf("%d ",vect[i]);
    }
    printf("\n");
}

int main()
{
	freopen("loang1dq.inp","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int i = 0; i < ntest; i++){
        input();
        solve();
    }


	return 0;
}


