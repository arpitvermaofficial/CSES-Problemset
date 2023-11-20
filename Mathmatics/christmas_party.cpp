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
const int maxA=2e6;
void solve()
{
    /*
    Approach
    Binoamial Problem of derrangement with recursive formula !n=(n−1)⋅(!(n−1)+!(n−2))
    */
    ll n;
    cin >> n;
    vector <ll >v(maxA +1);
    v[0]=1;
    for(int i=2; i<=maxA; i++) {
        v[i]=((i-1)*(v[i-1])+(i-1)*v[i-2])%mod;
    }
    print(v[n]);

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