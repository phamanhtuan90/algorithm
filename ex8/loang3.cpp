#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int n,k;
int arr[100][100];

struct toado{
	int lang1,lang2;
};

toado huong[5] = { -1,0
				  ,0,1
				  ,1,0
				  ,0,-1};
vector<int> vect;
vector<int> vectInput;
int q[1000];
int d[1000];
 int lev[100];
int maxLevel = 0;
void input(){
    memset(d, 0, sizeof(d));
    memset(lev, 0, sizeof(lev));
    memset(q, 0, sizeof(q));
    memset(arr, 0, sizeof(arr));
    maxLevel = 0;
	scanf("%d %d",&n,&k);
	for (int i=0;i< k ;i++){
       int lang1,lang2;
       scanf("%d %d",&lang1,&lang2);
       arr[lang1][lang2] = 1;
       arr[lang2][lang1] = 1;
	}
}

int loang(int lang){
    int dau = 0;
    int cuoi = 1;
    d[lang] = 1;
    q[0] = lang;
    lev[0] = 0; // level sau = level truoc + 1
    while(dau < cuoi){
        int current = q[dau];
        for(int i = 1; i <= n ; i++){
            if(d[i] == 0 && i != current && arr[current][i] == 1){
                q[cuoi] = i;
                d[i]  = 1;
                lev[cuoi] = lev[dau] + 1;
                cuoi++;
            }
        }
        dau++;
    }
    maxLevel = max(maxLevel,lev[cuoi-1]);

    return cuoi;
}

void solve(){
    vect.clear();
    for(int i = 1; i <= n; i++){
        if(d[i] == 0){
           int sz = loang(i);
           vect.push_back(sz);
        }
    }
}

void output(){
	printf("%d",vect.size());

	for (int i=0;i<vect.size();i++)
		printf(" %d",vect[i]);
    printf(" %d",maxLevel);
	printf("\n");
}

int main()
{
	freopen("loang3.inp","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int i = 0; i < ntest; i++){
        input();
        solve();
        output();
    }


	return 0;
}


