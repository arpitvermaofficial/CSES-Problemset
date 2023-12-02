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
    Simple application of Z algorithim
    */
    string s;
    cin >> s;
    int n = s.length();
    int x=0 , y=0;
    vector<int>z(n,0);
    for(int i=1; i<n; i++) {
        z[i]=max(0,min(z[i-x],y-i+1));
        while(i+z[i] < n && s[z[i]] == s[i+ z[i]]) {
            x=i, y=i+z[i] ,z[i]++;
        }
    }
    for(int i=1; i<n; i++) {
        if(z[i]+i==n)
        cout << i << " ";
    }
    cout << n;
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