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
using mat= vector<vector<double>>   ;
mat mat_mul(mat A,mat B)
{
	ll n=A.size(),m=B[0].size();
	mat C(n,vector<double>(m,0));
	for(ll i=0;i<n;i++)
	{
		for(ll k=0;k<A[0].size();k++)
		{
			for(ll j=0;j<m;j++)
			{
					C[i][j]+=A[i][k]*B[k][j];
			}
		}
	}   
	
	return C;
}
mat mat_power(mat A,int e) {
   if(e==1) {
    return  A;
   }
   else if( e%2==0 ){
    return mat_power(mat_mul(A,A),e/2);
   }
   else 
    return mat_mul(A,mat_power(A,e-1));
   
}
void solve() {
    /*
    Approach
    An indicator variable is 1 of something is true or 0 when false
    the expected value of indidicator variable is just the probality the event is true;
    
    we want to find E[no of empty sq]
    let I_{r,c} be indicator variable for wtherer sq {r,c} is empty;
    no of empty sq= \sum_r \sum_c I_{r,c};
    so E[no of empty sq]= E [\sum_r \sum_c I_{r,c};]
    by linerity of expectation E[X+Y]=E[X]+E[y]
    so this is [\sum_r \sum_c E[I_{r,c}]
    this is \sum_r \sum_c P(sq(r,c)) is empty 
    so that we just need to find the probality that each sq is empty. a sq is empty is no robo on it
    let Pk[ab][rc] be the prob the robo start from a,b and ends on r,c after k step
    we need to avoid every robo to stop ending on {r,c} and this is indepent to otheer robo so muliple of individual robo 
    then the prob {r,c} to be empty is \product {ab} (1-pk[ab][rc]) . \product {ab} this mean no of robo on ab which end on rc times multiplication
    so the ans is \sum_{r,c} product {ab} (1-pk[ab][rc])  i.e we calculate for each square what is problaity not to end on that sq and we sum up all prob
    

    */
    ll n=8;
    ll nn =n*n;
    vector<ll>dr{-1, 0, 1, 0};
    vector<ll>dc{0, 1, 0, -1};
    mat p(nn, vector<double>(nn,0.0));
    for(ll r=0; r<n; r++) {
        for(ll c=0; c<n; c++) {
            vector<ll>nbr;
            for(ll d=0; d<4; d++) {
                ll rr=r+dr[d];
                ll cc = c+dc[d];
                if(0<=rr && rr<n && 0<=cc && cc<n) {
                    nbr.push_back(rr*n+cc);
                }
            }
            for(ll y: nbr) {
                p[r*n+c][y]=1.0/nbr.size();
            }
        }
    }
    ll k;
    cin >> k;
    mat pk = mat_power(p,k);
    double ans=0;
    for( ll rc=0; rc<nn; rc++ ) {
        double pempty=1;
        for(ll ab=0; ab<nn; ab++) {
            pempty*=1.0 - pk[ab][rc];
        }
        ans+=pempty;
    }
    cout << fixed << setprecision(6) << ans;
    


}



int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    ll n = 0;
    // cin >> t;
    // for (int i = 1; i <= t; i++)
    {

        solve();
    }
}


// void solve()
// {
//     const int mxN=100;
//     int n;
//     cin >> n;
//     double dp[mxN+1][8][8], ans[8][8];
//     for(int i=0; i<8; i++) {
//         for(int j=0; j<8; j++) {
//             ans[i][j]=1;
//         }
//     }

//     for(int i=0; i<8; i++) {
//         for(int j=0; j<8; j++) {
//             for(int k=0; k<=n; k++) 
//                 for(int i2=0; i2<8; i2++) 
//                     for(int j2=0; j2<8; j2++)
//                         dp[k][i2][j2]=0;
//             dp[0][i][j]=1;
//             for(int k=0; k<n; k++) {
//                 for(int i2=0; i2<8; i2++) {
//                     for(int j2=0; j2<8; j2++) {
//                         int nd= (i2>0)+(i2<7)+(j2>0)+ (j2<7);
//                         if(i2)
//                             dp[k+1][i2-1][j2]+=dp[k][i2][j2]/nd;
//                         if(i2<7)
//                             dp[k+1][i2+1][j2]+=dp[k][i2][j2]/nd;
//                         if(j2)
//                             dp[k+1][i2][j2-1]+=dp[k][i2][j2]/nd;
//                         if(j2<7)
//                             dp[k+1][i2][j2+1]+=dp[k][i2][j2]/nd;  
//                     }
//                 }
//             }
//             for(int i2=0; i2<8; i2++) 
//                 for(int j2=0; j2<8; j2++)
//                     ans[i2][j2]*=(1-dp[n][i2][j2]);
//         }
//     }
//     double a2=0;
//     for(int i=0; i<8; i++) {
//         for(int j=0; j<8; j++) {
//             a2+=ans[i][j];
//         }
//     }
//     cout << fixed << setprecision(6) << a2;

// }