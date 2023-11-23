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
 
 vector<ll> factorial;
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
 int  binomialcoefficient(int a, int b) {
    if(b < 0 || a < b) {
        return 0;
    }
    return (((factorial[a]*modularbinaryexponention(factorial[a-b],mod-2))%mod)*modularbinaryexponention(factorial[b],mod-2))%mod;
 
 }
void solve()
{
    /*
    Approach
    We find out how many closing backet remain in remainig string 
    then calculate total permutation of fit remaing closed bracket in remaining string 
    and subtract all non valid have remainig+1 closed bracket like previous q
    */
    ll n;
    cin >> n;
    factorial.resize(n+11,0);
  
    factorial[0]=1;
   
    for(int i=1; i<=n+10; i++) {
        factorial[i] = (i* factorial[i-1] )%mod;
        
    }
    string s;
    cin >> s ;
    if( n%2 ) {
        print(0);
        return ;
    }
    int openb=0, closeb=0;
    for(int i=0; i<s.length() ; i++) {
        if(s[i]==')') 
        closeb++;
        else
        openb++;
        if(closeb>openb) {
            print(0);
            return;
        }
    }
    if(openb*2>n) {
        print(0);
        return ;
    }
    n-=s.length();
    int remaingcloseb=(n+openb-closeb) /2;
    int remainingopenb = n-remaingcloseb;
    // print(remaingcloseb,remainingopenb); 
    // dbg(binomialcoefficient(n,remaingcloseb),binomialcoefficient(n,remaingcloseb+1));
    print((binomialcoefficient(n,remaingcloseb)-binomialcoefficient(n,remaingcloseb+1)+mod)%mod);
 
 
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