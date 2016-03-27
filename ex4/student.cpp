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
int ntest;
int ninput;

struct student {
    char name[100];
    int num1,  num2, num3;
};
student sv[10];
void input(){
     scanf("%d\n",&ninput);
     for(int i = 0; i < ninput;i++){
        gets(sv[i].name);
        scanf("%d %d %d\n",&sv[i].num1,&sv[i].num2,&sv[i].num3);
     }
}

void handle(){
   int point = 0;
   int index = 0;
   for(int i = 0; i < ninput;i++){
        int pointCheck = sv[i].num1 +  sv[i].num2  +  sv[i].num3;
        if(pointCheck > point){
            point = pointCheck;
            index = i;
        }
   }
   printf("%s\n",sv[index].name);
   printf("%d\n",point);
}

int main()
{
    freopen("student.inp","r",stdin);
    scanf("%d",&ntest);
    for(int i = 0; i < ntest;i++){
        input();
        handle();
    }
    return 0;
}
