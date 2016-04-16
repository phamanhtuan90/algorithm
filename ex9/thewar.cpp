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
int arr[100][100];

struct toado{
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
bool d[100][100];
toado q[100];
vector<int> vect;


toado doMove(toado from,int hg){
	toado to;

	to.h = from.h + huong[hg].h;
	to.c = from.c + huong[hg].c;

	return to;
}

bool isOut(toado t){
	if ( t.h < 0 || t.h >= n )
		return 1;
	if ( t.c < 0 || t.c >= n )
		return 1;
	return 0;
}

void input(){
    memset(d, 0, sizeof(d));
    memset(q, 0, sizeof(q));
    memset(arr, 0, sizeof(arr));
    char ch[100][100];
	scanf("%d",&n);
	for (int i=0;i< n ;i++){
	    scanf("%s",&ch[i]);
        for (int j=0;j< n ;j++){
            arr[i][j] = 1;
            if(ch[i][j] == '0'){
                arr[i][j] = 0;
            }
        }
	}
}

int loang(int h, int c){
    int dau = 0;
    int cuoi = 1;
    toado current;
    current.h = h;
    current.c = c;
    q[0] = current;
    d[h][c] = 1;
    while(dau < cuoi){
        toado tmp = q[dau];
        dau++;
        for(int i = 0; i < 8;i++){
            toado next = doMove(tmp,i);
            if(isOut(next)) continue;
            if(d[next.h][next.c] == 0 && arr[next.h][next.c] == 1 ){
                q[cuoi] = next;
                d[next.h][next.c] = 1;
                cuoi++;
            }
        }
    }
    return cuoi;
}

void solve(){
     vect.clear();
     for (int i=0;i< n ;i++){
        for (int j=0;j< n ;j++){
            if(arr[i][j] == 1 && d[i][j] == 0){
                int sz = loang(i,j);
                vect.push_back(sz);

            }
        }
	}
}

void output(){
	printf("%d",vect.size());
	printf("\n");
}

int main()
{
	freopen("thewar.inp","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int i = 0; i < ntest; i++){
        input();
        solve();
        output();
    }


	return 0;
}


