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
    as from previous q divisor we know to get know total no of divisior contribution can be calculated as n/k 
    to calculate ans we to add any prime no contribution and subtract those no as countribution count which can be gnerated by combinatioon of prime no
    ex for 20 2 contro=20/2=10 and 5 cntro=20/5= 4 so total contro=14 but 10,20 counted by both 2,5 so we have to subtract it so ans =12
    above relation can be epressed as n/p1+n/p2-n/(p1*p2) where p1,p2 is prime no
    here you see even no contribution is subtracted and odd is add like p1*p2 is even count=2 so subtracted
    so here we se if we gnerate denominator then it is easy but denominatior is just is prime no is contributed in 
    denominator or not so it can be done by bitmasking 0,1 

    */
   ll n, k;
   cin >> n >> k;
   
   vector<ll>primes(k);
   for(int i=0; i<k; i++) {
    cin >> primes[i];
   }
   vector<ll >countNumberOfDivisor(k+1);
   for(int mask=1; mask<(1<<k); mask++) {
    
    int noofdivisiors=__builtin_popcount(mask);
    ll tmp=n;
    for(int i=0; i<k; i++) {
        if((1<<i)&mask) {
            tmp/=primes[i];
        }
    }
    countNumberOfDivisor[noofdivisiors]+=tmp;
   }
   ll ans=0;
   for(int i=1; i<=k; i++) {
    if(i%2==0) {
        ans-=countNumberOfDivisor[i];
    }
    else 
    ans+=countNumberOfDivisor[i];
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
    // for (int i = 1; i <= t; i++)
    {

        solve();
    }
}