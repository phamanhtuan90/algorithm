#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int arr[111][111];
vector<int> listPerson;
int checkPerson[111];
struct toado{
    int h,c;
};
toado huong[5] = {
    -1,0,
    0,1,
    1,0,
    0,-1
};

int d[111][111];
int countResult;
int countPersonReceiveEmail = 0;
int resultId = 0;
bool myfunction (int i, int j) {
    return (i==j);
}

void pushPerson(int personId){
    if(checkPerson[personId] == 0){
        checkPerson[personId] = 1;
        listPerson.push_back(personId);
    }
}
void input(){
    memset(arr,0,sizeof(arr));
    memset(d,0,sizeof(d));
    memset(checkPerson,0,sizeof(checkPerson));
    listPerson.clear();
    countPersonReceiveEmail = 0;
    resultId = 0;
    
    scanf("%d",&n);
    for(int i = 0; i <n;i++){
        int n1,n2;
        scanf("%d %d",&n1,&n2);
        arr[n1][n2] = 1;
        pushPerson(n1);
        pushPerson(n2);
    }
}

int dfs(int currentPersonId){
    int x = 1;
    for(int i = 0; i <= listPerson.size() ; i++){
        int personId =listPerson[i];
        if(personId != currentPersonId  && arr[currentPersonId][personId] == 1
           && d[currentPersonId][personId] == 0){
            d[currentPersonId][personId] = 1;
            x += dfs(personId);
        }
    }
    return x;
}
void solve(){
    for(int i = 0; i <= listPerson.size() ; i++){
        memset(d,0,sizeof(d));
        int personId = listPerson[i];
        int tmp = dfs(personId);
        if(tmp > countPersonReceiveEmail || (tmp == countPersonReceiveEmail && resultId > personId)){
            countPersonReceiveEmail = tmp;
            resultId = personId;
        }
    }
    printf("%d \n", resultId);
}

int main()
{
    freopen("12442.txt","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int i = 0; i < ntest; i++){
        input();
        solve();
    }
    
    return 0;
}