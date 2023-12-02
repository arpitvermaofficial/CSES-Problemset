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
    this is kmp algo 
    to reason behind is there any suffix which has matching prefix is we skip that prefix and avoid 
    time take to match same prefix which we already see their is match
    */
    string s,t;
    cin >> s >> t;
    int n=s.length(), m=t.length();
    s=t+"X"+s;
    vector<ll>pre(n+m+1);
    int len=0,  i=1;
    n=n+m+1;
    pre[0]=0;
    while(i < n) {
        if(s[i]==s[len]) {
            len++;
            pre[i]=len;
            i++;
        }
        else if( s[i]!=s[len]) {
            if(len==0) {
                pre[i]=0;
                i++;
            }
            else {
                len=pre[len-1];   
            }
        }dbg(pre);
    }
    dbg(pre);
    int c=0;
    for(auto i: pre) {
        if(i==m) c++;
    }
    print(c);


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