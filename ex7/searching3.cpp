#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

struct st{
	int val;
	int idx;
};

st s[111];
int n,x;

void input(){
	scanf("%d %d",&n,&x);

	for (int i=0;i<n;i++){
		scanf("%d",&s[i].val);
		s[i].idx = i+1;
	}
}

bool cmp(st s1,st s2){
	if ( s1.val < s2.val )
		return 1;
	if ( s1.val > s2.val )
		return 0;
	if ( s1.idx < s2.idx )
		return 1;
	return 0;
}

int timtrai(int so){
	int l = 0;
	int r = n-1;
	int res = -1;

	while ( l <= r ){
		int m = (l+r)/2;

		if ( so == s[m].val ){
			res = m;
			r = m-1;
		} else if ( so > s[m].val ){
			l = m+1;
		} else {
			r = m-1;
		}
	}

	return res;
}

int timphai(int so){
	int l = 0;
	int r = n-1;
	int res = -1;

	while ( l <= r ){
		int m = (l+r)/2;

		if ( so == s[m].val ){
			res = m;
			l = m+1;
		} else if ( so > s[m].val ){
			l = m+1;
		} else {
			r = m-1;
		}
	}

	return res;
}

void solve(){
	sort(s,s+n,cmp);

	int l = timtrai(x);
	printf("L %d\n",l);
	int r = timphai(x);
	printf("R %d\n",r);
	if ( l == -1 || r == -1 ){
		printf("-1\n");
		return;
	}

	for (int i=l;i<=r;i++){
		if ( i > l )
			printf(" ");
		printf("%d",s[i].idx);
	}
	printf("\n");
}

int main()
{
	freopen("searching3.inp","r",stdin);

	int ntest;
	scanf("%d",&ntest);

	for (int itest=0;itest<ntest;itest++){
		input();
		solve();
	}

	return 0;
}


