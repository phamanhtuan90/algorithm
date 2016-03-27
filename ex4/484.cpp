#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include <math.h>
#include <vector>
#include <map>

#define pb push_back

using namespace std;
int n;
int arr[100];


int main()
{
    int x;
    vector<int> vect;
    map <int,int> myMap;
    map <int,bool> flag;
    vect.clear();
    myMap.clear();
    freopen("484.inp","r",stdin);
    while(scanf("%d",&x) > 0){
        vect.pb(x);
        myMap[x]++;
    }
    for(int i = 0; i < vect.size();i++){
        int x = vect[i];
        if(flag[x] != 0){
            continue;
        }
        flag[x] = 1;
        printf("%d %d\n",x,myMap[x]);
    }
    return 0;
}
