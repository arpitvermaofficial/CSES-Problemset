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

void solve()
{
    /*
    Approach
    xor of two same no is zero
    we take xor of all elements if xor is 0 then second is win otherwise forst win
    when xor xero then as the first player moves first then the second player mimic the first player moves
    so pick same no so he pick the last stone
    when xor is not zero so first player take the sufficient stone so that now xor is  zero
    and now second turn after second's turn first player mimick the second's move so he pick last stones
    then he win
    as xor of two no is same then its insures that there can be possible mimicking move

    In the Nim game you remove the selection, but in this game you can move it down so it remains in the game.

 

    However, since the first stair (stair number 1) cannot be selected, moving from stair 2 to stair 1
    has the same effect as removing the ball. In other words, the game ends when the last ball
    remains on the second step. Therefore, by calculating Nim Sum for the balls on even-numbered
    stairs, you can find out the winner of the game.

    */
   ll n; 
   cin >>  n;
   vector< ll > v(n);
   for(int i=0 ; i<n; i++)
   cin >> v[i];
   int x=0;
   for(int i=0; i<n; i++) {
    if(i%2)
    x^=v[i];
   }
   cout << (x?"first":"second") << endl;
   //


}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t = 1;
    long long n = 0;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {

        solve();
    }
}