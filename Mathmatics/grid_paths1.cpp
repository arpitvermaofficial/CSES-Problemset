#include <bits/stdc++.h>
#ifdef DEBUG
#include "D:\CP\debug.cpp"
#else
#define dbg(x...)
#endif
typedef  long long ll;
const int mod = 1e9+7;
#define len(x) int((x).size())
using namespace std;
void print(){cout << "\n";}template <typename T, typename... types> void print(const T& first, const types &...args) { cout << first << " "; print(args...);}

vector<vector<ll>> mul(vector<vector<ll>> &a,vector<vector<ll>> &b)
{
	ll n=a.size(),m=b[0].size();
	vector<vector<ll>> c(n,vector<ll>(m,0));
 
	for(ll i=0;i<a.size();i++)
	{
		for(ll j=0;j<m;j++)
		{
			for(ll k=0;k<a[0].size();k++)
				c[i][j]=(c[i][j]+(1ll*a[i][k]*b[k][j])%mod)%mod;
		}
	}
   
	return c;
}
void solve()
{
	/*
	Approach
	this is basic application of  matrix exponention 
	every row in a matrix no of ways to reach j from i and columns tells that in how many ways we reach j from any other node
	as our task to reach n node from 1 so basically we looking for 1st row last node as it tell in how many ways we reach
	n from 1 but other task is to reach using exactly k nodes 
	so we multiply matrix exactly k times as every time we multiply it adds a nodes bw path 1 to n as a middle node
	so we require k maultiplicaion
	*/
    long long n;
 
	cin>>n;
	long long m,k;
	cin>>m>>k;
	vector<vector<long long>> A(n,vector<long long> (n,0));
 
 
	for(long long i=0;i<m;i++)
	{
		long long u,v;
		cin>>u>>v;
		u--;
		v--;
 
		A[u][v]+=1;
	}

    vector<vector<long long>> ans(A.size(),vector<long long> (A[0].size(),0));
    
	for(long long i=0;i<A.size();i++)
	ans[i][i]=1;
    
	while(k)
	{
		if(k&1)
		ans=mul(ans,A);
      
		A=mul(A,A);
		k/=2;
        
	}
    
    print(ans[0][n-1]);

}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t = 1;
    long long n = 0;
    // cin >> t;
    // for (int i = 1; i <= t; i++)
    {

        solve();
    }
}