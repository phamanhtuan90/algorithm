#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

int n;
struct arr {
   int a,b;
};
arr s[10];
int sumAll = 0;
int current = 0;
int biggest = 0;
int result;
void input()
{
    scanf("%d",&n);
    for (int i=0; i<n; i++){
       scanf("%d %d",&s[i].a,&s[i].b);
       current += s[i].a;
       sumAll += s[i].b;
       if(s[i].b > biggest){
            biggest = s[i].b ;
       }
    }
}
void handle(){
    result = (sumAll - current)/biggest;
    if((sumAll - current)%biggest != 0){
        result+= 1;
    }
}
void output()
{
    printf("%d\n",result);
}



int main()
{
    freopen("water.inp","r",stdin);
    int ntest ;
    scanf("%d",&ntest);
    for(int i = 0; i < ntest; i++)
    {
        input();
        handle();
        output();
    }

    return 0;
}


