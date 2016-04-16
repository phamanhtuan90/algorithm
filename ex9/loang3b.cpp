#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int n,m;
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
int parent[111];
int q[100];
bool d[100];
vector<int> vect;

void input(){
	scanf("%d %d",&n, &m);
    memset(d, 0, sizeof(d));
    memset(q, 0, sizeof(q));
    memset(arr, 0, sizeof(arr));
    memset(parent, 0, sizeof(parent));
	int lang1,lang2;
	for (int i=0;i < m ;i++){
        scanf("%d %d",&lang1, &lang2);
        arr[lang1][lang2] = 1;
        arr[lang2][lang1] = 1;
	}
}

void output(int kt){
    vect.clear();
    int tmp = kt;
    vect.push_back(tmp);
    while(true){
        if(parent[tmp] == tmp){
            break;
        }
        tmp = parent[tmp];
        vect.push_back(tmp);
    }
    reverse(vect.begin(), vect.end());

    printf("%d\n",vect.size() - 1);
    for (int i=0;i<vect.size();i++)
        printf("%d ",vect[i]);
    printf("\n\n");
}

int loang(int bd, int kt){

    int dau = 0;
    int cuoi = 1;
    q[0] = bd;
    d[bd] = 1;
    while(dau < cuoi){
        int current = q[dau];
        dau++;
        for(int lang = 1;lang <= n; lang++){
            if(lang != current && d[lang] == 0 && arr[current][lang] == 1){
                d[lang] = 1;
                q[cuoi] = lang;
                parent[lang] = current;
                if(lang == kt) {
                    output(kt);
                    return 1;
                }
                cuoi++;
            }
        }
    }
    return 0;
}

void solve(){
    int bd, kt;
    for (int lang=1;lang<=n;lang++){
        parent[lang] = lang;
    }
    scanf("%d %d", &bd, &kt);
    int result = loang(bd,kt);
    if(result == 0){
        printf("0 \n\n");
    }
}

int main()
{
	freopen("loang3b.inp","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int i = 0; i < ntest; i++){
        input();
        solve();
    }


	return 0;
}


