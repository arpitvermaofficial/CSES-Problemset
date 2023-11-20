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
    Simple binomial q with formula =(a+b-1)C(b-1)
    */

    ll a, b;
    cin >> a >> b;
    vector<ll> factorial(a+b);
  
    factorial[0]=1;
   
    for(int i=1; i<a+b; i++) {
        factorial[i] = (i* factorial[i-1] )%mod;
        
    }
    cout <<   (((factorial[a+b-1]
    *modularbinaryexponention(factorial[b],mod-2))%mod)
    *modularbinaryexponention(factorial[a-1],mod-2))%mod;
    
    
        
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t = 1;
    long long n = 0;
        solve();
}