#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int n,aidsId;
int arr[111][111];

struct toado{
    int h,c;
};
int d[111];
int q[111];
int maxSum;
toado tick[111][111];
toado huong[5] = {
    -1,0,
    0,1,
    1,0,
    0,-1
};

int best[111][111];
void input(){
    memset(arr,0,sizeof(arr));
    memset(d,0,sizeof(d));
    scanf("%d %d",&n,&aidsId);
    for(int i = 1;i <= n; i++){
        int numberPerson;
        scanf("%d",&numberPerson);
        for(int j = 0; j < numberPerson; j++){
            int x;
            scanf("%d",&x);
            arr[i][x] = 1;
            arr[x][i] = 1;
        }
        
    }

    
}
int countPerson;
vector<int> vect;
void loang(int person){
    int dau  = 0;
    int cuoi = 1;
    d[person] = 1;
    q[dau] = person;
    while(dau < cuoi){
        int currentPerson = q[dau];
        dau++;
        for(int i  = 1 ; i <= n; i++){
            if(currentPerson != i && arr[currentPerson][i] == 1 && d[i] == 0){
                q[cuoi] = i;
                d[i] = 1;
                vect.push_back(i);
                countPerson++;
                cuoi++;
            }
        }
    }
}

void solve(){
    countPerson = 1;
    vect.push_back(aidsId);
    loang(aidsId);
    printf("%d\n",countPerson);
    sort(vect.begin(),vect.end());
    for(int i  = 0 ; i < vect.size(); i++){
        printf("%d ", vect[i]);
    }
}

int main()
{
    freopen("sars.txt","r",stdin);
    input();
    solve();
    
    return 0;
}