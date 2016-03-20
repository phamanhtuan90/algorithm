#include <iostream>
#include  <fstream>
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>

using namespace std;

int main(){
    freopen("labiec25.inp","r",stdin);
    int m,n, num2, num3;
    scanf("%d",&m);
    for(int i = 1;i <= m;i++){
        scanf("%d",&n);
        int num, prev1, prev2, khoangcach, result;
        scanf("%d",&prev2);
        scanf("%d",&prev1);
        khoangcach = prev1 - prev2;
        result = 1;
        for(int j = 3;j <= n; j++){
            scanf("%d",&num);
            if(khoangcach != num - prev1){
                result = 0;
            }
            prev2 = prev1;
            prev1 = num;
        }

        if(result == 0){
            printf("Khong phai day so cong \n");
        }else{
            printf("La day so cong %d\n",khoangcach);
        }
    }
    return 0;
}
