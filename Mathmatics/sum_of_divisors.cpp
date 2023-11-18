#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
void print() { cout << "\n"; }
template <typename T, typename... types>
void print(const T &first, const types &...args)
{
    cout << first << " ";
    print(args...);
}
void debug(int x) { cerr << x; }
void debug(long x) { cerr << x; }
void debug(long long x) { cerr << x; }
void debug(unsigned x) { cerr << x; }
void debug(unsigned long x) { cerr << x; }
void debug(unsigned long long x) { cerr << x; }
void debug(float x) { cerr << x; }
void debug(double x) { cerr << x; }
void debug(long double x) { cerr << x; }
void debug(char x) { cerr << '\'' << x << '\''; }
void debug(const char *x) { cerr << '\"' << x << '\"'; }
void debug(const string &x) { cerr << '\"' << x << '\"'; }
void debug(bool x) { cerr << (x ? "true" : "false"); }
 
template <typename T, typename V>
void debug(const pair<T, V> &x);
template <typename T>
void debug(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? ", " : ""), debug(i);
    cerr << "}";
}
template <typename T, typename V>
void debug(const pair<T, V> &x)
{
    cerr << '{';
    debug(x.first);
    cerr << ", ";
    debug(x.second);
    cerr << '}';
}
template <typename ST>
void debug(stack<ST> st)
{
    cerr << " ";
    while (!st.empty())
    {
        cerr << st.top() << " ";
        st.pop();
    }
}
template <typename Q>
void debug(queue<Q> que)
{
    while (!que.empty())
    {
        cerr << que.front() << " ";
        que.pop();
    }
}
template <typename DQ>
void debug(deque<DQ> dque)
{
    while (!dque.empty())
    {
        cerr << dque.front() << " ";
        dque.pop_front();
    }
}
void dbg() { cerr << "]\n"; }
template <typename T, typename... V>
void dbg(T t, V... v)
{
    debug(t);
    if (sizeof...(v))
        cerr << ", ";
    dbg(v...);
}
 
#ifdef DEBUG
#define dbg(x...)                                                              \
    cerr << "\e[91m" << __func__ << ":" << __LINE__ << "[" << #x << "] = [";   \
    dbg(x); 	                                                               \
    cerr << "\e[39m" << endl;
#else
#define dbg(x...) 32
#endif
 
const vector<pair<int, int>> d4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const vector<pair<int, int>> d8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
 
bool comp(pair<long long, long long> a, pair<long long, long long> b)
{
    if (a.first > b.first)
        return true;
    return false;
}
 ll mod=1e9+7;
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
    /*Approach
    After observing you notice that each no has some common divisor like 2 is divisior of both 4 and 2
    so in constant time we calculate 2 is divisor of how many no just by diving n by 2 like 5/2 =2 which is 
    true upto 4, 2 is factor of only 4 and 2 .
    but this is not sufficient as no goes upto 10^12 so n time complexity is not sufficent
    you also notice that there are not too unique ans of each no so we have find that
    2*root(n) unique factors upto n 
    like  5/4 =1 also 5/5 =1 this shows 4 ans 5 only occurs 1 times as a facor upto 5 . so we see
    that 1 is common . but we have to make 2 iteration as 1 for 4 contribution and 1for 5 contribution
    in any how we skip these same iteration so we have not to do 10^12 iteration
    we skip common iteration by q formula in code where q is quotient and we are seaching for that no which dont give the 
    same quotient as quotient is the contribution on any no as a factor
    we using here modular binary exponent as (a/b)%mod != (a%mod)/(b%mod) 
    but we can distrubute modulus over multiplication
    in division (a/b)%mod== (a%mod)*((b^(mod-2))%mod)

    */
    ll n, ans=0;
    cin >> n;
    ll modularbinaryexponentionresult=modularbinaryexponention(2,mod-2);
    for(ll i=1,j; i<=n; i=j) {
        ll q= n/i;
         j= n/q +1;
        ll rsumj= ((((j%mod)*((j-1)%mod))%mod)*modularbinaryexponentionresult)%mod;
        ll rsumi= ((((i%mod)*((i-1)%mod))%mod)*modularbinaryexponentionresult)%mod;
        ll diff=(rsumj-rsumi+mod)%mod;
        ans=(ans+(q%mod)*diff)%mod;

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