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
    if (a.first < b.first)
        return true;
        else if(a.first==b.first){
            if(a.second>b.second)
            return true;
            else
            return false;
        }
    return false;
}
 
void solve()
{
    /*
    Approach
    This problem is similar to proble movie festivals1
    but in that prob only person but here is 2
    so we this problem using the same method but after 
    every operation we chek set size since there are two 
    person so they see atmost 2 movies at a time one each
    so when the set size is <2 means movie is watched so incese
    ans
    
    */
    long long n, k;
cin >> n >> k;
vector<pair<ll, pair<ll ,ll >>>v(n);
 
for(int i=0; i<n; i++) {
    ll x, y;
    cin >> x >> y;
    v[i]={y,{x,i}};
    
 }
 sort(v.begin(), v.end());
 set<pair<ll,ll>>s;
 vector<ll>ans(n);
 ll ans2=0;
 for(int i=0; i<n; i++) {
    auto it =s.lower_bound({v[i].second.first+1,0});
    if(it!=s.begin()) {
        --it;
        ans[v[i].second.second]=(*it).first;
        s.erase(it);
    } else {
        ans[v[i].second.second]=s.size();
    }
    if(s.size()<k) {
        s.insert({v[i].first, v[i].second.second});
        ans2++;
    }

 }
 print(ans2);
 
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