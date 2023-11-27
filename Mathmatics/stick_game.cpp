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

vector<bool> winning_positions(int n, const unordered_set<int>& P) {
    vector<bool> dp(n + 1, false);

    // Base case: If there are 0 sticks, the first player loses
    dp[0] = false;

    // Fill the array for each number of sticks from 1 to n
    for (int i = 1; i <= n; ++i) {
        // Check all possible moves
        for (int p : P) {
            if (i - p >= 0 && !dp[i - p]) {
                // If the current move leads to a losing position for the opponent, mark it as a winning position for the current player
                dp[i] = true;
                break;
            }
        }
    }

    return vector<bool>(dp.begin() + 1, dp.end());  // Exclude the 0-index, as we're using 1-based indexing for the sticks
}

void solve()
{
    /*
    Approach
    We used dp to store previous move result of game when i th move done
    we check for each no of stick pick by first player i.e from 1 to n
    and then pick i length stick then check if ith move stick length is smaller or equal
    so there is chance that last move done by first player if length is greater so first player
    is not to allow play this move so looses
    */
    int n;
    cin >> n;

    unordered_set<int> P;
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int p;
        cin >> p;
        P.insert(p);
    }

    // Call the function and print the result
    vector<bool> result = winning_positions(n, P);
    for (int i = 1; i <= n; ++i) {
        cout << (result[i - 1] ? "W" : "L");
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

