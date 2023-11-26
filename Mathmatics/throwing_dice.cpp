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
#define mat vector<vector<ll>>

mat provide(int n ,int m) {
    return vector<vector<ll>>(n,vector<ll>(m));
}
mat matMul(mat &a, mat &b)

{
    mat ans = provide(a.size(),b.size());
    ll n=a.size();
    
    for(ll i=0; i<a.size(); i++)
    {
        for(ll j=0; j<b.size(); j++)
        {
            for(ll k=0; k<b[0].size(); k++)
            {
                ans[i][j] = (ans[i][j] + (1LL * a[i][k] * b[k][j]) % mod) % mod;
            }
        }
    }
    return ans;
}
void mul(ll n)
{
    mat b={{0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 1}, {0, 1, 0, 0, 0, 1}, {0, 0, 1, 0, 0, 1}, {0, 0, 0, 1, 0, 1}, {0, 0, 0, 0, 1, 1}};
    mat r={{0, 0, 0, 0, 0, 1}};
    while(n)
    {
        if(n&1)
        {
            r=matMul(r, b);
        }
        b=matMul(b, b);
        n/=2;
    }
    print(r[0][5]);
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
   mul(n);

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
