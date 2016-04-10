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
int arr[100][100];
bool d[100][100];

struct toado{
	int h,c;
};

toado huong[5] = { -1,0
				  ,0,1
				  ,1,0
				  ,0,-1};
toado q[10000];
vector<int> vect;
char ch[100][100];
toado doMove(toado from,int hg){
	toado to;

	to.h = from.h + huong[hg].h;
	to.c = from.c + huong[hg].c;

	return to;
}

bool isOut(toado t){
	if ( t.h < 0 || t.h >= h )
		return 1;
	if ( t.c < 0 || t.c >= c )
		return 1;
	return 0;
}

void input(){
	scanf("%d %d",&h,&c);
	for (int i=0;i<h;i++){
	    scanf("%s",&ch[i]);
        for(int j = 0; j < c; j++){
            arr[i][j] = 1;
            if(ch[i][j] == 0){
                arr[i][j] = 0;
            }
        }
	}

}

int loang(int hang, int cot){
    int dau = 0;
    int cuoi = 1;
    toado current, nextMove;
    current.h = hang;
    current.c = cot;
    q[0] = current;
    d[hang][cot] = 1;
    while(dau < cuoi){
        current = q[dau];
        dau++;
        for(int i = 0; i < 4 ; i = i+2){
            nextMove = doMove(current,i);
            if(isOut(nextMove)) continue;
            if(d[nextMove.h][nextMove.c] == 0 && arr[nextMove.h][nextMove.c] == 0){
                d[nextMove.h][nextMove.c] = 1;
                q[cuoi] = nextMove;
                cuoi++;
            }
        }
    }
    return cuoi;

}


void solve(){
	vect.clear();
	for (int i=0;i<h;i++)
		for (int j=0;j<c;j++)
			d[i][j] = 0;

	for (int i=0;i<h;i++){
		for (int j=0;j<c;j++){
			if ( d[i][j] == 0 && arr[i][j] == 0){
				int sz = loang(i,j);
				vect.push_back(sz);
			}
		}
	}

	sort(vect.begin(),vect.end());
}

void output(){
	printf("%d",vect.size());
	printf("\n");
}

int main()
{
	freopen("dangiay.inp","r",stdin);
	 int ntest;
    scanf("%d",&ntest);
    for(int i = 0; i < ntest; i++){
        input();
        solve();
        output();
    }


	return 0;
}


