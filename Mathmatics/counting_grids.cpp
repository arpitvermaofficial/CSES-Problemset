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
void solve()
{
    /*
    Approach
    Based on burn's side leema theorem
    we have to take average of 0 90 180 270 
    in odd n case middle is not change in 180 and 90 so there are n2-1 squares all having 2 color options 
    so 2^((n^2-1)/2)*2 here  /2 for 180 and /4 for 90 roation and *2 as mid element have 2 color option with rest of suares
    */
    ll N;
    cin >> N;
    ll deg0 = modularbinaryexponention(2, N * N);
    ll deg90 = (N % 2 == 0 ? modularbinaryexponention(2, N * N / 4) : modularbinaryexponention(2, (N * N - 1) / 4) * 2 % mod);
    ll deg180 = (N % 2 == 0 ? modularbinaryexponention(2, N * N / 2) : modularbinaryexponention(2, N * (N - 1) / 2) * modularbinaryexponention(2, N / 2 + 1) % mod);
    ll deg270 = deg90;
 
    cout << (deg0 + deg90 + deg180 + deg270) % mod * 250000002 % mod << '\n';

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