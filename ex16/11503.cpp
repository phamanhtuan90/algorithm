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

int n, m;
int arr[111][111];
int parent[111];
int quantity[111];
struct toado{
    double h,c;
};
toado huong[5] = {
    -1,0,
    0,1,
    1,0,
    0,-1
};
map <string, int> listUser;
int userIndex;
void pushUser(string user){
    if(listUser[user] == 0){
        listUser[user] = userIndex;
        userIndex++;
    }
}

void solve(){
    memset(parent,0,sizeof(parent));
    scanf("%d", &n);
    userIndex = 1;
    for(int i = 0; i < n; i++){
        char user1[30], user2[30];
        scanf("%s %s", &user1, &user2);
        pushUser(user1);
        pushUser(user2);
        printf("%d\n", userIndex - 1);
    }
    
}

int main()
{
    freopen("11503.txt","r",stdin);
    int ntest;
    scanf("%d", &ntest);
    for(int i = 0; i < ntest; i++){
        solve();
    }
    
    
    return 0;
}