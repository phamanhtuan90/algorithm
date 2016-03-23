#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>
#include <math.h>

using namespace std;
int n;
int arr[100];

void input()
{
    scanf("%d",&n);
    for(int i = 0; i < n; i++ )
    {
        scanf("%d",&arr[i]);
    }
}

bool checkSNT(int n)
{
    if (n<2) return 0;
    for (int i=2; i<= sqrt(n) ; i++ )
        if (n%i==0) return false;
    return true;
}
int getCount(int num,int i){
    int countByNum = 0;
    for(i; i < n; i++ )
    {
        int sum = num + arr[i];
        if(checkSNT(sum)){
            countByNum++;
        }
    }
    return countByNum;
}


void handle()
{
    int result = 0;
    for(int i = 0; i < n; i++ )
    {
        result += getCount(arr[i],i+1);
    }

    printf("%d\n",result);
}

int main()
{

    freopen("tieuhoc11.inp","r",stdin);
    int ntest;
    scanf("%d",&ntest);
    for(int x = 0; x<ntest; x++)
    {
        input();
        handle();
    }

    return 0;
}
