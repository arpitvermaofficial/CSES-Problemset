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
    this q is based on dp
    each row of dp is showing the ith throw
    and col shows the sum after ith throw
    the first loop determine the throw 1 to n
    second loop determine the minimum and maximum sum after ith throw minimim is i as if every throw show 1 on dice
    and max is 6*i as every throw shows 6
    then third loop show the j sum is got by which move i.e from 1 to 6
    */
    const  int mxN=100;
    int n , a , b;
    cin >>  n >> a >> b;
    vector<vector<double>>dp(mxN+1,vector<double>(6*mxN+1,0));
    dp[0][0] = 1;  // Base case
 
    for (int i = 0; i < n; ++i) {
        for (int j = i; j <= 6 * i; ++j) {
            for (int k = 1; k <= 6; ++k) {
                    dp[i+1][j+k] += dp[i][j]/6;
              
            }
        }
    }
 
    double totalWays = 0;
    for (int j = a; j <= b; ++j) {
        totalWays += dp[n][j];
    }
   
    cout << fixed << setprecision(6) << totalWays;
   
 
    
 
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
