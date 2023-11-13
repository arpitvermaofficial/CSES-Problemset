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

void solve()
{
    /*
    Approach
    we sort the array based on departure time we do so as we want as soon the person go the
    room is immeditely to be filled
    then we use set to check is for current person arival time is there any room whose
    departure time is less or eual so then we allocate that room to current person
    we do so by using lower bound //
    */
    ll n;
    cin >> n;
    vector<pair<ll,pair<ll ,ll >>>v(n);
    for(int i=0; i<n; i++) {
        ll x, y;
        cin >> x >> y;
        v[i].second.first=x;
        v[i].first=y;
        v[i].second.second=i;
    }
    sort(v.begin(), v.end());
    // dbg(v);
    vector<ll>ans(n);
    set<pair<ll, ll>>s; 
    for(int i=0; i<n; i++) {
        auto it= s.lower_bound({v[i].second.first,0ll});
        int x=distance(s.begin(),it);
        // dbg(x);

        if(it==s.begin()) {
            ans[v[i].second.second]=s.size();
            s.insert({v[i].first, s.size()});
        }
        else {
            --it;
            ans[v[i].second.second]=(*it).second;
            int x=(*it).second;
            s.erase(it);
            s.insert({v[i].first, x});
        }
        // dbg(ans);
        // dbg(s);
    }
    print(s.size());
    for(int  i=0; i<n; i++) {
        cout << ans[i]+1 << " ";
    }

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
