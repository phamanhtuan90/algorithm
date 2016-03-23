#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>

using namespace std;

int main(){
    freopen("tieuhoc5.inp","r",stdin);
    int ntest;
    int n;
    int k;
    int arr[10];
    scanf("%d",&ntest);
    for(int x = 0;x<ntest;x++){
        scanf("%d",&n);
        scanf("%d",&k);
        for(int i = 0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        for(int i = 0;i<n;i++){
            int z = 0;
            int number1 = arr[i];
            for(int j = 0;j<n;j++){
                int number2 = arr[j];
                if(number1 > number2){
                    z++;
                }
            }
            if(z == (n - k)){
                printf("%d\n",number1);
                break;
            }
        }
    }

    return 0;
}
