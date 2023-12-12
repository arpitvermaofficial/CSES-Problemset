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
#define endl '\n'

const int mxN = 1e5+5;
int sa[mxN], pos[mxN], tmp[mxN];
int gap, N;
string S;

bool comp(int x, int y) {
    if (pos[x] != pos[y])
        return pos[x] < pos[y];
    x += gap;
    y += gap;
    return (x < N && y < N) ? pos[x] < pos[y] : x > y;
}

void suffix() {
    for (int i = 0; i < N; i++)
        sa[i] = i, pos[i] = S[i];

    for (gap = 1;; gap <<= 1) {
        sort(sa, sa+N, comp);
        for (int i = 0; i < N-1; i++)
            tmp[i+1] = tmp[i] + comp(sa[i], sa[i+1]);
        for (int i = 0; i < N; i++)
            pos[sa[i]] = tmp[i];
        if (tmp[N - 1] == N - 1)
            break;
    }
}

int check(int m, string &x) {
    int f = -1, k = x.size(), j = sa[m];
    if (N - j >= k) 
        f = 0;
    for (int i = 0; i < min(N - j, k); i++) {
        if (S[j+i] < x[i])
            return -1;
        if (S[j+i] > x[i])
            return 1;
    }
    return f;
}


void solve()
{
    /*
    Approach
    This uses the concept of suffix array 
    in suffix array we store leaxographically sorted string
    but instead of storing all the suffix string we store the index from 
    where suffix string start
    then we apply binary search on it as allstring are stored in
    sorted order so binary search eaisly implemented and we check if any prefix of 
    suffix string match then we find pattrn if prefix of suffix string is small so we move
    towards right as alphabetically large element found on right as suffix arrray is sorted
    either wise move to the left
    */
        string x; cin>>x;
        int l = 0, r = N - 1;
        int f = 0;
        while (l <= r) {
            int m = l + (r-l)/2;
            int v = check(m, x);
            if (v == 0) {
                f = 1;
                break;
            }
            else if (v == -1)
                l = m + 1;
            else
                r = m - 1;
        }
        cout << (f ? "YES" : "NO") << endl;

}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t = 1;
    long long n = 0;
    cin>>S;
    N = S.size();
    suffix();
    cin >> t;
    for (int i = 1; i <= t; i++)
    {

        solve();
    }
}
