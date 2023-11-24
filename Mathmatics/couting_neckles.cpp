// C++ program for implementing the
// Orbit counting theorem
// or Burnside's Lemma

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

long long modularbinaryexponention(long long b, long long p) {
    if (p == 0) {
        return 1;
    }
    long long result = modularbinaryexponention(b, p / 2);
    result = (result * result) % mod;
    if (p % 2) {
        result = (result * b) % mod;
    }
    return result;
}

void countDistinctWays(long long N, long long M)
{

	
}

void solve()
{
    /*
    Approach
    Based on Burnside's leema theorem of counting object when there is symmnetry 
    total distinct ways= sumation over 0<=i<=N-1 => ((M^gcd(i,N))/N);
    */
    long long N , M ;
    cin >> N >> M;
    long long  ans = 0;
	for (long long  i = 0; i < N; i++) {
		long long  K = __gcd(i, N);
		ans =(ans%mod+ modularbinaryexponention(M,K)%mod)%mod;
	}

	ans=(ans*modularbinaryexponention(N,mod-2))%mod;

	print( ans );

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


