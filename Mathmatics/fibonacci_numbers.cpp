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


vector<vector<ll>> matMul(vector<vector<ll>> &a, vector<vector<ll>> &b)
{
    vector<vector<ll>> ans = {{0, 0}, {0, 0}};
    
    for(ll i=0; i<2; i++)
    {
        for(ll j=0; j<2; j++)
        {
            for(ll k=0; k<2; k++)
            {
                ans[i][j] = (ans[i][j] + (1LL * a[i][k] * b[k][j]) % mod) % mod;
            }
        }
    }
    return ans;
}
vector<vector<ll>> mul(ll n)
{
    vector<vector<ll>> x = {{1, 1}, {1, 0}};
    vector<vector<ll>> ans={{1, 0}, {0, 1}};
    while(n)
    {
        if(n&1)
        {
            ans=matMul(ans, x);
        }
        x=matMul(x, x);
        n/=2;
    }
    return ans;
}

void solve()
{
    /*
    Approach
    nth fabonacci can be find out in log n complxeity
    we declare a matrix
    [ 1 1 ] this matrix equivalent to [f2 f1] and if we multiply this matricx again we got [f2*f2+f1*f1  f2*f1+f1*f0 ] => [2 1] => [f3 f2]
    [ 1 0 ]                           [f1 f0]                                              [f1*f1+f0*f0  f1**f1+f0+f0]    [1 1]    [f2 f1]
    so we notice that every time we multiply by 01 matrix we got next number. so like calculating pow(x,y) in log n 
    time we can do the same
    */
    ll n;
    cin >> n;
    vector<vector<ll>> ans=mul(n);
    print( ans[1][0]%mod);

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
