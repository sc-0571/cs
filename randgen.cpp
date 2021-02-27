#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int main() {
  freopen("C:\\study\\np\\output.txt", "w", stdout); 	
  srand((unsigned) time(0));	
  int n = 5000 + rand()%5000;
  printf("%d\n", n);
  for (int i=1; i<= n; i++)	 {
  	int type = rand() %1000;
  	int type1=0, type2=0,type3=0;
  	long x = 1 + (rand() % 1000);
	/*if (type < 200) {
  		x = x * x * x,type1++;
	} else if (type < 600) {
		x = x * x,type2++;
	} else {
		x = rand() %1000,type3++;
	}*/
  	printf("%d ", x*x*x);
  }
  return 0;
}
