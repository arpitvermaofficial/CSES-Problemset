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
    let only a one person so read all the book total time is sum of all book reading time 
    which be the minimum time when two person read
    let books have 2 8 3 timing so the when a person read a book 8 the other person read 2,3 
    similarly vica versa so in this case total reading time is max time *2
    we have to take the maximum of two above time
    */
    ll n;
    cin >> n;
    vector<ll>v(n);
    ll sum=0;
    for(int i=0; i<n; i++) {
        cin >> v[i];
        sum+=v[i];
    }
    ll maxi=*max_element(v.begin(), v.end());
    print(max(2*maxi,sum));
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