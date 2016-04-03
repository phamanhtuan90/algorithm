#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[100];

void input()
{
    scanf("%d",&n);
    for(int i = 0; i < n;i++){
        int countNumber, number,sum = 0;
        scanf("%d",&countNumber);
        for(int j = 0;j< countNumber; j++){
            scanf("%d",&number);
            sum+= number;
        }
        arr[i] = sum;
    }

}


int main()
{
    freopen("10026.inp","r",stdin);
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


