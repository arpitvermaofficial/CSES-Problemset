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
    ll maxval=1e6+10;
    ll n;
    cin >> n;
    vector<ll> val(n);
    for(int i=0; i<n; i++) {
        cin >> val[i];
    }
    vector<ll> sieve(maxval);
    vector<vector<ll>>divisorsof(maxval);
    for(int i=2; i<maxval; i++) {
        if(divisorsof[i].size()==0) {
            divisorsof[i].push_back(i); 
            for( int j=2*i; j<maxval; j+=i) {
                divisorsof[j].push_back(i);
            }
        }
    }
    vector<ll>valuedivisibleby(maxval);
    vector<ll>priremediviorsof(maxval);
    for(int i=0; i<n ;i++) {
        for(int mask=1; mask<(1<<(divisorsof[val[i]].size())); mask++) {
            int combination = 1;
            int primedivisors = 0;
            for(int pos =0; pos<divisorsof[val[i]].size(); pos++) {
                if((1<<pos)&mask) {
                    combination*= divisorsof[val[i]][pos];
                    primedivisors++;
                }
            }
            valuedivisibleby[combination]++;
            priremediviorsof[combination]=primedivisors;
        }
    }
    ll totalnoofpairs=((ll)n*((ll)(n-1)))/2;
    ll vaildpairs=0;
    for(int i=0; i<maxval; i++) {
        if (priremediviorsof[i]%2)
        vaildpairs += ((ll)valuedivisibleby[i]*((ll)valuedivisibleby[i]-1))/2;
        else
        vaildpairs -= ((ll)valuedivisibleby[i]*((ll)valuedivisibleby[i]-1))/2;

    }
    print(totalnoofpairs-vaildpairs);


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