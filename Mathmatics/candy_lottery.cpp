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
    // Let X be a positive-integer valued random variable.
// E[X] = 1*P(1) + 2*P(2) + 3*P(3) + 4*P(4) + ...

        = P(1) + P(2)+ P(3)+ P(4) + ... = P(X>=1)
               + P(2)+ P(3)+ P(4) + ... = P(X>=2)
                     + P(3) + P(4)+ ... = P(X>=3)
                            + P(4)+ ... = P(X>=4)
                                 + ...
         = P(X>=1) + P(X>=2) + P(X>=3) + P(X>=4) +...
// We want to find E[max number of candies]
// P(max number of candies >= A) = 1 - P(max<A)
                                = 1 - P(all children get <A candies)
                                   
// P(child gets <A candies) = (A-1)/K
// P(all N children get <A candies) =((A-1)/K) ^N

// P(max>=A) = 1 - ((A-1)/K) ^N
// ans = sum_{A=1}^K ((A-1)/K) ^N
    */
   ll n, k;
   cin >> n >> k;
   double ans=0;
   for(int i=1; i<=k; i++ ) {
    double x= (i-1.0)/k;
    ans+=1- pow( x, n);
   }
   cout << fixed << setprecision(6) <<  ans;



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