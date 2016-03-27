#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

struct toado{
	int h,c;
};

toado huong[5] = {-1,0		// N tren
				  ,0,1		// E phai
				  ,1,0		// S duoi
				  ,0,-1};	// W trai

char str[111];

void input(){
	scanf("%s",&str);
}

int getIndexFromChar(char c){
	if ( c == 'N' )
		return 0;
	if ( c == 'E' )
		return 1;
	if ( c == 'S' )
		return 2;
	return 3;
}

toado doMove(toado oldLoc,int h){
	toado newLoc;

	newLoc.h = oldLoc.h + huong[h].h;	// cap nhat toa do hang moi theo huong h
	newLoc.c = oldLoc.c + huong[h].c;	// cap nhat toa do cot  moi theo huong h

	return newLoc;
}

void solve(){
	int len = strlen(str);
	toado location;

	// khoi tao toa do o goc toa do (0,0)
	location.h = 0;
	location.c = 0;

	for (int i=0;i<len;i++){
		char command = str[i];				// get lenh tu string input

		int h = getIndexFromChar(command);	// convert tu huong N,E,S,W sang dang so 0,1,2,3

		location = doMove(location,h); 		// call ham di chuyen toado theo huong h
		printf("%d %d\n",location.h,location.c);	// in ra vi tri hien tai sau command
	}

	printf("%d %d\n",location.h,location.c);	// in ra vi tri hien tai sau command
}

int main()
{
	int ntest;

	freopen("explore_mini.inp","r",stdin);

	scanf("%d",&ntest);

	for (int itest=0;itest<ntest;itest++){
		input();
		solve();
	}

	return 0;
}

