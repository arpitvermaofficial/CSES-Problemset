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
if the sum n no is odd then it is not possible to divide into two eqal halves
else
divide like two sets
1st set 1 4
2nd set 2 3
*/
long long n;
cin >> n;
if ( (n*(n+1)/2)%2) {
   print("NO");
}
else {
   print( "YES");
   vector < long long >v1,v2;
     long long j=4;
   if(n%4) {
	   j=3;
   }
   for( long long  i=0 ;i<(n-1)/4 ;i++) {
	   v1.push_back(4*i +1+j);
	   v1.push_back(4*i +4+j);
	   v2.push_back(4*i +3+j);
	   v2.push_back(4*i +2+j);
   }
	if (n%4) {
	   v1.push_back(1);
	   v1.push_back(2);
	   v2.push_back(3);
	}
	else {
	   v1.push_back(1);
	   v1.push_back(4);
	   v2.push_back(3);
	   v2.push_back(2);
	}
	
	 print(v1.size());
	 for( long long  i=0 ; i<v1.size() ;i++) {
	   cout << v1[i] << " ";

	 }
     print();
	 print(v2.size());
	 for( long long  i=0 ; i<v2.size() ;i++ ) {
	   cout << v2[i] << " ";

	 }
	 print();


}

}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t = 1;
    long long n = 0;
    // cin >> t;
    for (int i = 1; i <= t; i++)
    {

        solve();
    }
}