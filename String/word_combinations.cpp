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

int triee[1000005][26];
int endnode[1000005];
int counter = 0;
int dp[50001];
void insert(string s ) {
    int curr=0;
    for(auto i :s) {
        if(triee[curr][i-'a']==0)
        triee[curr][i-'a']=++counter;
        curr = triee[curr][i-'a'];

    }
    endnode[curr]=1;
}
void solve()
{
    /*
    Approach 
    We solve this question using dp and tries
    
    */
    string s ;
    cin >> s;
    int n; 
    cin >> n;
    for(int i=0; i<n; i++) {
        string x;
        cin >> x; 
        insert(x);  
    }
    int m= s.length();
    dp[m]=1;
    for(int i=m-1; i>=0; i--) {
        int curr=0, ans=0;
        for(int j=i; j<m; j++) {
            if(triee[curr][s[j]-'a']==0)
            break;
            curr =triee[curr][s[j]-'a'];
            if(endnode[curr]) {
                ans=(ans+dp[j+1]%mod)%mod;

            }
        }
        dp[i]=ans;
    }
    print(dp[0]);

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