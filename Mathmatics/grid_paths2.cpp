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

vector<vector<long long>> mul(vector<vector<long long>> &A,vector<vector<long long>> &B)
{
	long long n=A.size(),m=B[0].size();
	vector<vector<long long>> C(n,vector<long long>(m,-1));
	for(long long i=0;i<n;i++)
	{
		for(long long j=0;j<m;j++)
		{
			for(long long k=0;k<A[0].size();k++)
			{
				if(A[i][k]!=0 and B[k][j]!=0)
				{
					if(C[i][j]==-1)
						C[i][j]=(A[i][k]+B[k][j]);
					C[i][j]=min(C[i][j],(A[i][k]+B[k][j]));
				}
			}
		}
	}
	for(long long i=0;i<n;i++)
	{
		for(long long j=0;j<m;j++)
		{
			if(C[i][j]==-1)
			C[i][j]=0;
		}
	}
	return C;
}
void solve()
{
	
	
	/*
	Approach
	Same as previous but little bit twist of cost
	in last q we considered every move as 1 cost so final row value give total cost or total paths
	but in this q we have to choose the minimum path cost nodes
	*/
   long long n;
	long long m;
	long long k;
	cin>>n>>m>>k;
	vector<vector<long long>> graph(n,vector<long long>(n,0));
	for(long long i=0;i<m;i++)
	{
		long long u,v,c;
		cin>>u>>v>>c;
		u--;
		v--;
		if(graph[u][v])
		graph[u][v]=min(graph[u][v],1ll*c);
		else
		graph[u][v]=c;
	}
    vector<vector<long long>> result(graph.size(),vector<long long>(graph[0].size(),0));
 
	for(long long i=0;i<graph.size();i++)
		result[i][i]=1;
	long long count=1;
	while(k)
	{
		if(k&1)
		{
			if(count)
			{
				result=graph;
				count--;
			}
			else
			result=mul(result,graph);
		}
		graph=mul(graph,graph);
		k=k>>1;
	}
    graph=result;
    if(graph[0][n-1]==0)
	graph[0][n-1]=-1;
	cout<<graph[0][n-1];

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