#include <bits\stdc++.h>
using namespace std;

#define MAX_N 100
#define MAX_E 1000
;;
/*

3 3
1 2
2 3
3 1

*/


int tot, head[MAX_N],Nxt[MAX_E],ver[MAX_E];
int s_stack[MAX_N],ans[MAX_N],stop, vis[MAX_E],t=0;

void add(int x, int y) {
	ver[++tot]=y, Nxt[tot]=head[x],head[x]=tot;
}

void euler(int start) {
	s_stack[++stop] = start;
	//
	while(stop) {
		int x = s_stack[stop];
		int i = head[x];
		while(i && vis[i]) i=Nxt[i];
		if (i) {
			s_stack[++stop] = ver[i];
			//head[x]= Nxt[i];
			vis[i]= 1;
			//vis[i^1] = 1;
			
		} else {
			--stop;
			//printf(" end of %d\n", x);
			ans[++t]=x;
		}
	}
}

int main() {
	int m, n;
	cin >>n >> m;
	int tot = 1;
	for (int i=1; i<= m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		add(x, y) ; //,add(y,x);
	}
	euler(1);
	for(int i=t; i; i--) {
		printf(" %d", ans[i]);
	}
	return 0;
}
