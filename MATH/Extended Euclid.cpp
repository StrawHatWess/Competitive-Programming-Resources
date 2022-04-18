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

int d; //gcd
int x,y;

void ext(int a, int b){
   if(b==0){
      d=a;
      x=1;
      y=0;
      return;
   }
   ext(b,a%b);
   swap(x,y);
   y-=(a/b)*x; //x: prev y

}

int32_t main(){
   boost;
   //solve ax + by = gcd(a,b)
   int a,b;
   cin>>a>>b;
   ext(a,b);
   cout << x << ' ' << y << endl;

}

