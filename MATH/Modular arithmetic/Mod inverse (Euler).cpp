#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ld;

typedef pair<int,int> pi;
#define mp make_pair
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;

#define pb push_back
#define eb emplace_back
#define pf push_front

#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)

const int MOD = 1e9+7; //1000000007
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int modpow(int x, int n, int m){
   if(n==0){
      return 1;
   }
   int y=modpow(x,n/2,m);
   y=(y*y)%m;
   if(n%2==1) y=(y*x)%m;
   return y;
}

int32_t main(){
   boost;
   // mod inverse of x mod m
   // m prime
   int x,m; cin>>x>>m;
   cout << modpow(x,m-2,m) << endl;

   // if m is not prime, the result is modpow(x,phi[m]-1,m)
   // phi[m] can be calculated with sieve for a range of values

}

