#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int n,nduong;
bool flag[111][111];
int q[111];
bool d[111];

void input(){
	int a,b;
	
	scanf("%d %d",&n,&nduong);
	
	// reset mang danh dau duong
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			flag[i][j] = 0;
	
	for (int i=0;i<nduong;i++){
		scanf("%d %d",&a,&b);
		
		// danh dau duong 2 chieu a --> b va b --> a
		flag[a][b] = 1;
		flag[b][a] = 1;
	}
}

void loang(int lang){
	int dau = -1;
	int cuoi = 0;
	
	// khoi tri queue
	q[0] = lang;
	// danh dau diem dau tien
	d[lang] = 1;
	
	while ( dau < cuoi ){	// khi queue van con trang thai chua xet
		dau++;
		int cur = q[dau];
		
		for (int next = 1;next <=n; next++){
			// check dieu kien de lang lien thong va lang nay chua di qua bao h
			if ( next != cur && d[next] == 0 && flag[cur][next] == 1 ){
				// danh dau va them lang vao queue
				d[next] = 1;
				cuoi++;
				q[cuoi] = next;
			}
		}
	}
}

void solve(){
	// reset cac lang chua di qua
	for (int i=1;i<=n;i++)
		d[i] = 0;
		
	int demvung = 0;
	for (int i=1;i<=n;i++){
		if ( d[i] == 0 ){
			loang(i);
			demvung++;
		}
	}
	
	printf("%d\n",demvung);
}

int main()
{
	freopen("loang2.inp","r",stdin);
	
	int ntest;
	scanf("%d",&ntest);
	
	for (int itest=0;itest<ntest;itest++){
		input();
		solve();
	}
	
	return 0;
}

