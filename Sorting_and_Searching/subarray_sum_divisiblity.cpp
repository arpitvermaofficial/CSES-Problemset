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
    In this we store the remainder valure if got the same remainder again that mean
    we add the no which is divisible by n and after adding this it will give the same reminder
    so we have to remove old remainder sub array and the remainig array is divisible by n
    for negative case when we take remainder of negtive val it should give the no which we subtract to no 
    so that the overall no is divisible by n as like in postive no but it does't give the same as 
    we aspect but it give the negative no so to get pos reminder we add n
    */
   ll n;
   cin >> n;
   vector<ll>v(n);
   map<ll,ll>m;
   m[0]++;
   ll sum=0, ans=0;
   for( int i=0; i<n; i++) {
    cin >>v[i];
    sum=(sum+v[i]%n+n)%n;
    ans+=m[sum];
    m[sum]++;

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