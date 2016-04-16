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
bool flag[100];
bool d[1000];
int q[1000];
int level[100];
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

vector<int> vect;
int arrInput[200];
void input(){
    memset(arr, 0, sizeof(arr));
    memset(flag, 0, sizeof(flag));
    vect.clear();
	int net1,net2;
	for (int i=0;i < n ;i++){
        scanf("%d %d",&net1, &net2);
        arr[net1][net2] = 1;
        arr[net2][net1] = 1;
        flag[net1] = 1;
        flag[net2] = 1;
	}
	for(int i = 1; i <= sizeof(flag);i++ ){
        if(flag[i] == 1){
           vect.push_back(i);
        }
    }

}

int loang(int network, int ttl){
    int dau = 0;
    int cuoi = 1;
    int currentTtl = 0;
    q[0] = network;
    d[network] = 1;
    level[dau] = 0;
    while(dau < cuoi){
        int nCurrent = q[dau];
        for(int i = 0; i < vect.size(); i++){
            int nNext = vect[i];
            if(nCurrent != nNext && d[nNext] == 0 && arr[nCurrent][nNext] == 1){
                q[cuoi] = nNext;
                d[nNext] = 1;
                int nextLevel = level[dau] + 1;
                if(nextLevel > ttl){
                    return cuoi ;
                }
                level[cuoi] = nextLevel;
                cuoi++;

            }
        }

        dau++;


    }
    return cuoi;
}

void handle(){
    int network, ttl;
    int ncase = 1;
    while(scanf("%d %d",&network, &ttl) > 0){
         if(network == 0 && ttl == 0){
            break;
         }
         memset(q, 0, sizeof(q));
         memset(d, 0, sizeof(d));
         memset(level, 0, sizeof(level));
         int sz = loang(network, ttl);
         printf("Case %d : %d nodes not reachable from node %d with TTL = %d.\n",ncase, vect.size() - sz,network,ttl);
         ncase++;
    }
}

int main()
{
	freopen("network1.inp","r",stdin);
    while(scanf("%d",&n)> 0){
        input();
        handle();


    }


	return 0;
}


