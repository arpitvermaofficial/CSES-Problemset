#include <bits/stdc++.h>
#include <iomanip>
#include <cmath>
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
     
    */
    ll n ;
    cin >> n;
    vector<ll> R(n,0);
    for(ll i=0 ;i<n; i++) {
        cin >> R[i];
    }
    double ans=0.0;
    for(ll i=0; i<n; i++) {
        for(ll j=i+1; j<n; j++) {
            ll num_inversions=0;
            for(ll a=1; a<=R[i]; a++) {
                num_inversions+=min(a-1, R[j]);
            }
            double p =static_cast<double>( num_inversions)/static_cast<double>(R[i]*R[j]);
            ans+=p;
        }
    }
   
   
    cout <<  fixed;
    cout << setprecision(6);
    cout  << ans;

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