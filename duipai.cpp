#include<bits/stdc++.h>
using namespace std;
int n, k, a[10000001];
long long dp[10000001], ans;

long long test2() {
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=k;i++)dp[i]=a[i];
	for(int i=k+1;i<=n;i++) {
		for(int j=1;j<=k;j++)
			dp[i]=min(dp[i],dp[i-j]+a[i]);
	}
	long long ans = 0x7fffffffffffffff;
	for(int i=n-k+1;i<=n;i++) {
    ans=min(ans,dp[i]);
	}
	return ans;
}

long long test1() {
	for(int i=1;i<=k;i++)dp[i]=a[i];
	for(int i=k+1;i<=n;i++) {
		long long temp = INT_MAX;
		for(int j=1;j<=k;j++)
			temp=min(temp,dp[i-j]);
		dp[i] = temp + a[i];
	}
	long long ans = 0x7fffffffffffffff;
	for(int i=n-k+1;i<=n;i++) {
    ans=min(ans,dp[i]);
	}
	return ans;
}

long long test3() {
	deque<long>D;
	D.push_back(0);
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		while(!D.empty()&&D.front()<i-k)D.pop_front();
		dp[i]=dp[D.front()]+a[i];
		while(!D.empty()&&dp[D.back()]>dp[i])D.pop_back(); 
		D.push_back(i);
	}
	long long ans = 0x7fffffffffffffff;
	for(int i=n-k+1;i<=n;i++) {
      ans=min(ans,dp[i]);
	}
	return ans;
}
int main() {
	for (int x = 1; x < 100; x++) {
		n = rand() % 10000000 + 1;
		k = rand() % 10 + 1;
		for(int i=1;i<=n;i++) {
			a[i] = rand() % 1000000 + 1;
		}
		long long t2 = test2(); 
		long long t1 = test3();
		if (t2 != t1) {
			cout << t2 << " " << t1 << endl;
		} else {
			//cout << t2 << " " << t1 << endl;
			cout << "right" << endl;
		}
    }
}

