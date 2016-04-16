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
int level[100];
int tmp[100][100];
int maxLevel;
vector<int> vectCountVung;
vector<int> maxRangeInfo;
int vung = 0;
int langcolap = 0;
int cau = 0;
int parent[111];

void input(){
    memset(arr, 0, sizeof(arr));
    memset(qDemVung, 0, sizeof(qDemVung));
    memset(dDemVung, 0, sizeof(dDemVung));
    memset(level, 0, sizeof(level));
    memset(tmp, 0, sizeof(tmp));
    vectCountVung.clear();
    vung = 0;
    langcolap = 0;
    cau = 0;
    maxLevel = 0;
	scanf("%d",&n);
	for (int i=1;i <= n ;i++){
       parent[i] = i;
       for (int j=1;j <= n ;j++){
            int inputNumber;
            scanf("%d",&inputNumber);
            arr[i][j] = inputNumber;
            arr[j][i] = inputNumber;
       }
	}

}
void setMaxRangeInfo(int lang){
    maxRangeInfo.clear();
    int prevLang = lang;
    maxRangeInfo.push_back(prevLang);
    while(true){
        if(prevLang == parent[prevLang]){
            break;
        }
        prevLang = parent[prevLang];
        maxRangeInfo.push_back(prevLang);
    }


}
int demvung (int lang){
    int dau = 0;
    int cuoi = 1;
    qDemVung[0] = lang;
    dDemVung[lang] = 1;
    level[0] = 0;
    while(dau < cuoi){
        int current = qDemVung[dau];
        for(int nlang = 1;nlang <= n; nlang++){
            if(nlang != current && dDemVung[nlang] == 0 && arr[current][nlang] == 1){
                dDemVung[nlang] = 1;
                qDemVung[cuoi] = nlang;
                parent[nlang] = current;
                level[cuoi] = level[dau] + 1;
                cuoi++;
            }
        }
        dau++;
    }
    if(level[cuoi-1] > maxLevel){
        maxLevel =level[cuoi-1];
        setMaxRangeInfo(qDemVung[cuoi-1]);
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
    for (int i=1;i <= n ;i++){
        if(dDemVung[i] == 0){
            int sz = demvung(i);
            vung++;
            if(sz == 1){
                langcolap++;
            }
            vectCountVung.push_back(sz);
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
}

void output(){
	sort(vectCountVung.begin(),vectCountVung.end());
    reverse(maxRangeInfo.begin(), maxRangeInfo.end());
    printf("%d ", vung);
    for(int i = 0; i < vectCountVung.size();i++){
         printf("%d ",vectCountVung[i]);
    }
    printf("\n");
    printf("%d %d \n", langcolap,cau);
    printf("%d",maxLevel);
    for(int a = 0; a < maxRangeInfo.size();a++){
         printf(" %d",maxRangeInfo[a]);
    }
    printf("\n");
    printf("\n");
}

int main()
{
	freopen("loang5.inp","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int i = 0; i < ntest; i++){
        input();
        solve();
        output();
    }


	return 0;
}


