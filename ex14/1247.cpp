#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#define inf 1000000000
using namespace std;

int n,m;
int arr[111][111];

struct toado{
    int h,c;
};
toado huong[5] = {
    -1,0,
    0,1,
    1,0,
    0,-1
};
int d[111];
int b[111];
int parent[50];
int q, bd, kt;
vector <char> listTransport ;

void input(){
    memset(arr,0,sizeof(arr));
    memset(b,0,sizeof(b));
    memset(d,0,sizeof(d));
    scanf("%d %d\n",&n, &m);
    for (int j=0;j<m;j++){
        char l1, l2;
        int s;
        scanf("%c %c %d\n", &l1, &l2, &s);
        listTransport.push_back(l1);
        listTransport.push_back(l1);
        arr[l1][l2] = s;
        arr[l2][l1] = s;
    }
    scanf("%d\n", &q);
    unique(listTransport.begin(),listTransport.end());
    
    
}

void resetParams(){
    memset(parent,0,sizeof(parent));
    for(int i = 0 ; i < n; i++){
        parent[i] = -1;
    }
    for(int i = 0 ; i < n; i++){
        b[i] = inf;
        d[i] = 0;
    }
}


int getNumberByChar(char t){
    int result = -1;
    for(int i = 0; i < n; i++){
        if(t == listTransport[i]){
            return i;
        }
    }
    return result;
}

int findMin(){
    int result = -1;
    int flag = inf;
    for(int i = 0; i < n; i++){
        if(d[i] == 1){
            continue;
        }
        if(flag > b[i]){
            result = i;
            flag = b[i];
        }
    }
    return result;
}


void editLabel(int node){
    for(int i = 0; i < n; i++){
        int arrValue = arr[listTransport[node]][listTransport[i]];
        if(arrValue != 0){
            int flag = b[node] + arrValue;
            if(b[i] > flag){
                b[i] = flag;
                d[i] = 0;
                parent[i] = node;
                
            }
        }
    }
}

void output(){
    int flag = kt;
    vector <int> result;
    while (flag >= 0) {
        result.push_back(flag);
        flag = parent[flag];
    }
    for(long i = result.size() - 1; i >= 0; i--){
        printf("%c ", listTransport[result[i]]);
    }
    printf("\n");
}

void solve(){
    for(int i = 0; i < q; i++){
        resetParams();
        char t1,t2;
        scanf("%c %c\n", &t1, &t2);
        bd = getNumberByChar(t1);
        kt = getNumberByChar(t2);
        b[bd] = 0;
        while (d[kt]  == 0) {
            int currentMin = findMin();
            if(currentMin == -1){
                break;
            }
            d[currentMin] = 1;
            editLabel(currentMin);
        }
        output();
    }

}

int main()
{
    freopen("1247.txt","r",stdin);
    input();
    solve();
    
    
    return 0;
}