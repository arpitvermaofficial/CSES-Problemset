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
const int maxA=1e6;
void print(){cout << "\n";}template <typename T, typename... types> void print(const T& first, const types &...args) { cout << first << " "; print(args...);}


vector<ll> factorial(maxA+1);
vector<ll> inversefactorial(maxA+1);
ll modularbinaryexponention(ll b , ll p) {
    if( p==0) {
        return 1;
    }
    ll result =modularbinaryexponention(b,p/2);
    if(p%2) {
        return (((result*result)%mod)*b)%mod;
    }
    else 
    return (result*result)%mod;
 }
void solve()
{
    /*
    Approach 
    Simple binomial exponention calculation with modularbinaryexponention
    */
    ll n;
    cin >> n;
    vector<pair<ll ,ll>>v;
    for(int i=0; i<n; i++ ) {
    ll a, b;
    cin >> a >> b;
    print((((factorial[a]*inversefactorial[a-b])%mod)*inversefactorial[b])%mod);
    }
    
        
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t = 1;
    long long n = 0;
    // cin >> t;
    factorial[0]=1;
    inversefactorial[0]=1;
    for(int i=1; i<=maxA; i++) {
        factorial[i] = (i* factorial[i-1] )%mod;
        inversefactorial[i]= modularbinaryexponention(factorial[i],mod-2);
    }
    

    // for (int i = 1; i <= t; i++)
    // {

        solve();
    // }
}