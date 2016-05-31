#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#define inf 1000000000
using namespace std;

int n, m , bd, kt;
char arrStr[111][111];
int arr[111][111];
bool d[111];
int b[111];
int parent[111];
struct toado{
    int h,c;
};
toado huong[5] = {
    -1,0,
    0,1,
    1,0,
    0,-1
};
map <string, int> listCity;
int listCityIndex;
int caseNumber = 0;
void pushListCity(string city){
    if(listCity[city] == 0){
        listCity[city] = listCityIndex;
        listCityIndex++;
    }
}
void input(){
    memset(arr,0,sizeof(arr));
    memset(b,0,sizeof(b));
    memset(d,0,sizeof(d));
    memset(parent,0,sizeof(parent));
    memset(arrStr,0,sizeof(arrStr));
    listCity.clear();
    listCityIndex = 1;
    caseNumber++;
    for(int i = 1; i <= m ; i++){
        char city1[30], city2[30];
        int weight;
        scanf("%s %s %d", &city1, &city2, &weight);
        pushListCity(city1);
        pushListCity(city2);
        arr[listCity[city1]][listCity[city2]] = weight;
        arr[listCity[city2]][listCity[city1]] = weight;
        
    }
    char cityBd[30], cityKt[30];
    scanf("%s %s", &cityBd, &cityKt);
    bd = listCity[cityBd];
    kt = listCity[cityKt];
    
    
}

void resetParams(){
    memset(b,0,sizeof(b));
    memset(d,0,sizeof(d));
    memset(parent,0,sizeof(parent));
    for (int i=1;i<=n;i++){
        b[i] = 0;
        d[i] = 0;
        parent[i] = -1;
    }
}

int findBest(){
    int result = -1;
    int tmp = 0;
    for(int i = 1; i <= n; i++){
        if(d[i] == 1){
            continue;
        }
        if( b[i] >  tmp ){
            tmp = b[i];
            result = i;
        }
    }
    return result;
}


void editLabel(int index){
    for(int i = 1; i <= n; i++){
        if(arr[index][i] != 0){
            int tmp =  min(b[index],arr[index][i]);
            
            if (tmp > b[i]){
                b[i] = tmp;
                d[i] = 0;
                parent[i] = index;
            }
        }
    }
}



void solve(){
    resetParams();
    b[bd] = inf;
    while(d[kt] == 0){
        int bestIndex = findBest();
        if(bestIndex == -1){
            break;
        }
        d[bestIndex] = 1;
        editLabel(bestIndex);
    }
    printf("Scenario #%d : %d tons\n", caseNumber, b[kt] );
      
    
    
    
    
}

int main()
{
    freopen("544.txt","r",stdin);
    while(true){
        scanf("%d %d",&n,&m);
        if(n == 0 || m == 0){
            break;
        }
        input();
        solve();
        //output();
    }
    return 0;
}