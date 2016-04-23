#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int n,duong;
int arr[100][100];

struct toado{
	int lang1,lang2;
};

toado huong[5] = { -1,0
				  ,0,1
				  ,1,0
				  ,0,-1};
vector<int> vect;
int q[1000];
int d[1000];

void input(){
    memset(d, 0, sizeof(d));
    memset(arr, 0, sizeof(arr));
	scanf("%d %d",&n,&duong);
    int lang1,lang2;
	for (int i=0;i< duong ;i++){
       scanf("%d %d",&lang1,&lang2);
       arr[lang1][lang2] = 1;
       arr[lang2][lang1] = 1;
	}
}

int dfs(int lang){
    int ht,ct;
    d[lang] = 1;
    int result = 1;
    for (int i=1;i<=n;i++){
        if (i != lang && arr[lang][i] == 1 && d[i] == 0){
            result += dfs(i);
        }
    }
    return result;
}

void solve(){
    vect.clear();
    for(int i = 1; i <= n; i++){
        if(d[i] == 0){
           int sz = dfs(i);
           vect.push_back(sz);
        }
    }
}

void output(){
    sort(vect.begin(),vect.end());
    printf("%d ", vect.size());
    for (int i=0;i<vect.size();i++){
        printf("%d ",vect[i]);
    }
    printf("\n");
}

int main()
{
	freopen("loang2dq.inp","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int i = 0; i < ntest; i++){
        input();
        solve();
        output();
    }


	return 0;
}


