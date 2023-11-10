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
 vector<ll> powerOfTen(19,1);
    
void solve()
{
    /*
    Approach
    to find digit at a particular index first we have to find no of which index is pointing to
    so find no we calulate no of digits bw two tenth power no
    let given index is 100 we have to find digit at 100 pos
    so no which belong 1 -- 10 --100
    no of digit bw 1-9 =9
    no of digit bw 10-99=(99-10+1)*2=180 digit each no has two digit
    so total digits upto 100 no is 9+180=189
    so no x must be belogs to 9<=x<=99
    then we put binary search to find the actual no to which index is point to
    then get digit at particular index by using to_string fun
    */

   
    ll index;
        cin >> index;
        ll digitsSoFar = 0;
        ll digitsBeforeActualBlock = 0;
        int numberOfDigits;
        for(int i = 1; i <= 18; i++)
        {
            digitsSoFar += (powerOfTen[i]-powerOfTen[i-1])*i;
            if (digitsSoFar >= index)
            {
                numberOfDigits = i;
                break;
            }
            digitsBeforeActualBlock += (powerOfTen[i]-powerOfTen[i-1])*i;
        }
        ll smallestValue = powerOfTen[numberOfDigits-1];
        ll largestValue = powerOfTen[numberOfDigits]-1;
        ll bestValue = 0;
        ll startingPositionOfBestValue;
        while (smallestValue <= largestValue)
        {
            ll actualValue = (smallestValue + largestValue)/2;
            ll startingPositionOfActualValue = 
                digitsBeforeActualBlock + 1 +
                (actualValue - powerOfTen[numberOfDigits-1]) * numberOfDigits;
            if (startingPositionOfActualValue <= index)
            {
                if (actualValue > bestValue)
                {
                    bestValue = actualValue;
                    startingPositionOfBestValue = startingPositionOfActualValue;
                }
                smallestValue = actualValue + 1;
            }
            else
                largestValue = actualValue - 1;
        }
        string number = to_string(bestValue);
        cout << number[index-startingPositionOfBestValue] << '\n'; 

}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t = 1;
    long long n = 0;
    for(int i = 1; i < 19; i++)
        powerOfTen[i] = powerOfTen[i-1] * 10;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {

        solve();
    }
}