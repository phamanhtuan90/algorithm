#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
int nInput[100];
int n;

void bubbleSort()
{
    int i, j, flag = 1;
    int temp;
    int numLength = n;

    while(flag == 1)
    {
        flag = 0;
        for (j=0; j < (numLength - 1); j++)
        {
            if (nInput[j] > nInput[j+1] )
            {
                temp = nInput[j];
                nInput[j] = nInput[j+1];
                nInput[j+1] = temp;
                flag = 1;
            }
        }
    }
    return;
}

void input()
{
    printf("n : %d\n",n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&nInput[i]);
    }
}
void handle()
{
    bubbleSort();
    int sum = 0;
    int result = 0;
    for(int i = 0; i < n; i++)
    {
        if(i  == 0){
            sum += nInput[i];
        }else{
            sum+= nInput[i] ;
            result+= sum;
        }
    }
    printf("%d",result);
}


int main()
{
    freopen("10954.inp","r",stdin);
    int x = 0;
    while(true)
    {
        scanf("%d",&n);
        if(n > 0)
        {
            if(x > 0)
            {
                printf("\n");
            }
            input();
            handle();
            x++;
        }
        else
        {
            break;
        }
    }

    return 0;
}

