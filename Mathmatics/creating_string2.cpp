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
    Just simple binomial formula = n!/(a1!*a2!*a3...) where a1,a2 freq of each unique character
    */
   string s ;
   cin >> s;
   ll ans=1, n=s.length();
   map<char,ll>m;
   for(int i=0; i<n; i++ ) {
    m[s[i]]++;
   }
   ans*=factorial[n]%mod;
   for(auto i:m) {
    ans= (ans*inversefactorial[i.second])%mod;
   }
   print(ans);
    
        
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