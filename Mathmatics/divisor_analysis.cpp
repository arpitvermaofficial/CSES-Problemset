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
void print(){cout << "\n";}template<typename T, typename...types> void print(const T& first, const types&...args) {cout << first << " "; print(args...);}

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
ll geometricsum(ll base, ll power) {
    ll numerator=(modularbinaryexponention(base,power+1)-1+mod)%mod;
    ll denominatorinverse=modularbinaryexponention(base-1, mod-2);
    return (numerator*denominatorinverse)%mod;
}
void solve()
{
    /*
    Approach
    no of divisior of any no x=(p1^a1)*(p2^a2)... = (a1+1)*(a2+1)*.... where p1 ,p2 are prime numbers

    sum of all divisor of any no x=(p1^0+p1^1....)(p2^0+p2^1 ....)... =(geometric sum of p1)*(geometric sum of p2).... = (((p1^(a1+1))-1)/(p1-1))*(((p2^(a2+1))-1)/(p2-1))...

    
    */
    ll n;
    cin >> n;
    vector<ll>prime(n);
    vector<ll>exponent(n);
    for(int i=0; i<n; i++) {
        cin >> prime[i] >> exponent[i];
    }
    ll numberofdivisors=1;
    for(int i=0; i<n; i++) {
        numberofdivisors=(numberofdivisors * (exponent[i]+1))%mod;
    }
    ll sumofdivisors=1;
    for(int i=0; i<n; i++) {
        sumofdivisors=(sumofdivisors*geometricsum(prime[i],exponent[i]))%mod;
    }
    ll productofdivisors=1;
    bool oddexponent=false;
    int postionofoddexponent;
    for(int i=0; i<n; i++) {
        if(exponent[i]%2) {
            oddexponent=true, postionofoddexponent=i;
        }
    }
    if(oddexponent) {
        ll outerexponent=1;
        for(int i=0; i<n; i++) {
            if(i == postionofoddexponent) {
                outerexponent= (outerexponent * (exponent[i]+1)/2)%(mod-1);
            }
            else 
            outerexponent= (outerexponent * (exponent[i]+1))%(mod-1);
        }
        for(int i=0; i<n; i++) {
           productofdivisors = (productofdivisors * modularbinaryexponention(prime[i], (exponent[i]*outerexponent)%(mod-1)))%mod;
        }
    }
    else {
        ll outerexponent = 1;
        for(int i=0; i<n; i++) {
            outerexponent= (outerexponent * (exponent[i]+1))%(mod-1);
        }
        for(int i=0; i<n; i++) {
           productofdivisors = (productofdivisors * modularbinaryexponention(prime[i], ((exponent[i]/2)*outerexponent)%(mod-1)))%mod;
        }

    }
    cout << numberofdivisors << " " << sumofdivisors << " " << productofdivisors;
    

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