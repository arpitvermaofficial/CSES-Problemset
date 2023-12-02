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

void solve()
{
    /*
    Approach
    if all the piles have even stone then second player win as 
    he mimick the first player move
    if there is atleast one pile than first player win
    as if second player mimick there is 1 stone remain in odd pile which
    is picked by first player
    */
    ll n; 
    cin >> n;
    vector<ll >v(n);
    bool even=true;
    for(int i=0; i<n; i++) {
        cin >> v[i];
        even&= !(v[i]&1);
    }
    print(even?"second":"first");


}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t = 1;
    long long n = 0;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {

        solve();
    }
}