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
void solve()
{
    /*
    Approach
    no with n is odd not generate valid parenthes as no of opening bract != no of closing braket
    for is valid parenthes no of opening bract != no of closing braket=n/2;
    and for at any postion in a string no of opening brac >= no of closing bracket
    so to find our ans we subract total invaid prarenhes from total combination
    total combination =nC(n/2) as we to choose n/2 postion for opening brac over n
    invalid combination is = (n/2)-1C(n/2)+1 
    so ans = nC(n/2) - (n/2)-1C(n/2)+1 
    after solving we get Ck= (1/k+1) *(2kCk)  this is called Catalan no have many application
    after solving we have recuurrence realtion Ck=((4k-2)/(k+1))*(ck-1)
    
    */
    ll n;
    cin >> n;
    if(n%2) {
        print(0);
        return ;
    }
    n/=2;
    vector<ll>validbracketsequence(n+1);
    validbracketsequence[0]=1;
    for(int i=1; i<=n; i++) {
        validbracketsequence[i] = (
            (((4*i-2)*modularbinaryexponention(i+1,mod-2))%mod)*validbracketsequence[i-1]
        )%mod;
    }
    print(validbracketsequence[n]);
   

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