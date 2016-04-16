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

int qDemVung[1000];
int dDemVung[1000];
int tmp[100][100];
vector<int> vect;

void input(){
    memset(arr, 0, sizeof(arr));
    memset(qDemVung, 0, sizeof(qDemVung));
    memset(dDemVung, 0, sizeof(dDemVung));
    memset(tmp, 0, sizeof(tmp));

	scanf("%d",&n);
	for (int i=1;i <= n ;i++){
       for (int j=1;j <= n ;j++){
            int inputNumber;
            scanf("%d",&inputNumber);
            arr[i][j] = inputNumber;
            arr[j][i] = inputNumber;
       }
	}

}

int demvung (int lang){
    int dau = 0;
    int cuoi = 1;
    qDemVung[0] = lang;
    dDemVung[lang] = 1;
    while(dau < cuoi){
        int current = qDemVung[dau];
        dau++;
        for(int nlang = 1;nlang <= n; nlang++){
            if(nlang != current && dDemVung[nlang] == 0 && arr[current][nlang] == 1){
                dDemVung[nlang] = 1;
                qDemVung[cuoi] = nlang;
                cuoi++;
            }
        }
    }
    return cuoi;
}

int demCau(int bd, int kt){
   bool d[1000];
   int q[1000];
   memset(d, 0, sizeof(d));
   memset(q, 0, sizeof(q));
   int dau = 0;
   int cuoi = 1;
   q[0] = bd;
   d[bd] = 1;
   tmp[bd][kt] = 1;
   tmp[kt][bd] = 1;
   while(dau < cuoi){
        int current = q[dau];
        dau++;
        for(int lang = 1; lang <= n; lang++){
            int isOk = arr[current][lang];
            if(lang != current && d[lang] == 0 && isOk == 1){
                d[lang] = 1;
                q[cuoi] = lang;
                cuoi++;
                if(lang == kt){
                    return 1;
                }
            }
        }
   }

   return 0;
}

void solve(){
    int vung = 0;
    int langcolap = 0;
    int cau = 0;
    for (int i=1;i <= n ;i++){
        if(dDemVung[i] == 0){
            int sz = demvung(i);
            vung++;
            if(sz == 1){
                langcolap++;
            }
        }
    }

    for (int i=1;i <= n ;i++){
        for (int j=1;j <= n ;j++){
            if(arr[i][j] == 1 && tmp[i][j] == 0 ){
                arr[i][j] = 0;
                arr[j][i] = 0;
                if (demCau(i,j) == 0){

                    cau++;
                }
                arr[i][j] = 1;
                arr[j][i] = 1;
            }
        }
    }
      printf("%d %d %d\n",vung, langcolap,cau);
}

void output(){
	//printf("%d",vect.size());
	printf("\n");
}

int main()
{
	freopen("loang4.inp","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int i = 0; i < ntest; i++){
        input();
        solve();
        //output();
    }


	return 0;
}


