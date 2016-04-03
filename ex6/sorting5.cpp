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
char title[100];
int nGamer;
struct info {
   int all,t,b,h;
   float point;
   char name;
};
map <char, info> mapInfo;
info result[5];
int nRound;
vector<string> listRound;
void input()
{
    listRound.clear();
    scanf("%d",&n);
    gets(title);
    scanf("%d\n",&nGamer);
    for (int i=0; i<nGamer; i++)
    {
        char name;
        scanf("%c\n",&name);
        info gamerInfo;
        gamerInfo.point = 0;
        gamerInfo.all = 0;
        gamerInfo.t = 0;
        gamerInfo.b = 0;
        gamerInfo.h = 0;
        gamerInfo.name = name;
        mapInfo[name] = gamerInfo;
    }
    scanf("%d\n",&nRound);
    for(int i = 0; i < nRound; i++)
    {
        char roundInfo[3];
        char roundInputStr[100];
        gets(roundInputStr);
        int x = 0;
        for(int i = 0; i< strlen(roundInputStr); i++)
        {
            if(roundInputStr[i] != ' ')
            {
                roundInfo[x] = roundInputStr[i];
                x++;
            }
        }
        listRound.push_back(roundInfo);
    }


}

void calculatorPoint(char name,float point)
{
    mapInfo[name].point += point;
    mapInfo[name].all += 1;
    if(point == 0){
        mapInfo[name].b += 1;
    }
    if(point == 0.5){
        mapInfo[name].h += 1;
    }
    if(point == 1){
        mapInfo[name].t += 1;
    }



}

bool cmp (info gamer1, info gamer2)
{
    if(gamer1.point > gamer2.point ){
        return 1;
    }
    if(gamer1.point < gamer2.point ){
        return 0;
    }
    if(gamer1.name < gamer2.name ){
        return 1;
    }

    return 0;
}


void handle()
{
    for(int i = 0; i < nRound; i++)
    {
        string rountInfo = listRound[i].c_str();
        char gamer1 = rountInfo[0];
        char gamer2 = rountInfo[1];

        if(rountInfo[2] == 'T')
        {
            calculatorPoint(gamer1,1);
            calculatorPoint(gamer2,0);
        }
        if(rountInfo[2] == 'H')
        {
            calculatorPoint(gamer1,0.5);
            calculatorPoint(gamer2,0.5);
        }
        if(rountInfo[2] == 'B')
        {
            calculatorPoint(gamer1,0);
            calculatorPoint(gamer2,1);
        }
    }
    int i = 0;
    for (map<char,info>::iterator it=mapInfo.begin(); it!=mapInfo.end(); ++it){
        result[i] = it->second;
        i++;
    }
    sort(result, result+nGamer,cmp);

}

void output(){
    printf("%s\n",title);
    for( int i = 0; i < nGamer; i++){
        printf("%d)  %c %f diem, %d tran, %d thang, %d hoa, %d bai\n"
               ,i+1,result[i].name,result[i].point,result[i].all,result[i].t,result[i].h,result[i].b);
    }

}

int main()
{
    freopen("sorting5.inp","r",stdin);
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


