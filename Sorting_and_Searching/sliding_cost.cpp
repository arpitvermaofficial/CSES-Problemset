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
#define dbg(x...)                                                            \
	cerr << "\e[91m" << __func__ << ":" << __LINE__ << "[" << #x << "] = ["; \
	dbg(x);                                                                  \
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
	we find out eaisly the median using last question sliding median approach
    to find out cost we have to calculate cost of that window using window median 
    
	*/
	ll n , k;
	cin >> n >> k;
	vector<ll> v(n);
	for (ll i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	set<pair<ll, ll>> left, right;
	if (k == 1) {
		for (ll i = 0; i < n; i++)
	{
		cout << 0 << " ";
	}
	}
	else if(k == 2) {
		for(ll i=1; i<n; i++) {
			cout << abs(v[i-1]-v[i]) << " ";
		}
	}
	else {
		vector<pair<ll, ll>>st;
		for(ll i=0; i<k; i++) {
			st.push_back({v[i], i});
		}
		sort(st.begin(), st.end());
        ll leftsum=0, rightsum=0;
		
		for(ll i=0; i<k/2+(k%2); i++) {
			left.insert(st[i]);
            leftsum+=st[i].first;
		}
		for(ll i=k/2+(k%2); i<k; i++) {
			right.insert(st[i]);
            rightsum+=st[i].first;
		}
		
		
		ll median=left.rbegin()->first;

		cout << median*left.size()-leftsum+rightsum-median*right.size() << " ";
		for(ll j=1; j<n-k+1; j++) {
			if(left.count({v[j-1],j-1})) {
               leftsum-=v[j-1];
				left.erase({v[j-1],j-1});
			}
			else {
                 rightsum-=v[j-1];
				right.erase({v[j-1],j-1});
			}
			if(*(left.rbegin())< make_pair(v[k-1+j],k-1+j)) {
				right.insert({v[k-1+j],k-1+j});
                rightsum+=v[k-1+j];
                  
			}
			else {
				left.insert({v[k-1+j],k-1+j});
                leftsum+=v[k-1+j];
                  
			}
		
			while (left.size()<k/2+(k%2)) {
				pair<ll, ll >z=(*right.begin());
				left.insert(z);
                leftsum+=z.first;
				right.erase(z);
                rightsum-=z.first;

			}
			while (left.size()>k/2+(k%2)) {
				pair<ll, ll >z=(*left.rbegin());
				left.erase(z);
                leftsum-=z.first;
			    right.insert(z);
                rightsum+=z.first;
				
			}
            median=left.rbegin()->first;
            cout << median*left.size()-leftsum+rightsum-median*right.size() << " ";
			
		}
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