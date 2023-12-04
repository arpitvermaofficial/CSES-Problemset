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

string updatedString(const string &str)
{
    string newString = "#";
    for (char ch : str)
    {
        newString += ch;
        newString += '#';
    }
    return newString;
}

void manachen(const string &str)
{
    string updatedStr = updatedString(str);
    int len = updatedStr.length();

    int *LPS = new int[len];
    int C = 0;
    int R = 0;

    for (int i = 0; i < len; ++i)
    {
        int iMirror = 2 * C - i;
        if (R > i)
        {
            LPS[i] = min(R - i, LPS[iMirror]);
        }
        else
        {
            LPS[i] = 0;
        }

        while (updatedStr[i + 1 + LPS[i]] == updatedStr[i - 1 - LPS[i]])
        {
            LPS[i] += 1;
        }

        if (i + LPS[i] > R)
        {
            C = i;
            R = i + LPS[i];
        }
    }

    int r = 0, c = 0;
    for (int i = 0; i < len; ++i)
    {
        if (LPS[i] > r)
        {
            r = LPS[i];
            c = i;
        }
    }
    string ans = updatedStr.substr(max(0, c - r), 2 * r);
    for (int i = 0; i < (int)ans.length(); i++)
    {
        if (ans[i] != '#')
        {
            cout << ans[i];
        }
    }

    delete[] LPS;
}


void solve()
{
    /*
    Approach 
    Based on Manacher's algo
    */
    string s;
    cin >>s;
     manachen(s);

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
