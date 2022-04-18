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

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

const int MXN=1000+1;
int N;
int t[MXN][MXN];
int ft[MXN][MXN]={0};

int LSB(int i){
   return i&(-i);
}

void update(int i, int j, int delta){
   int x=i, y;
   while(x<=N){
      y=j;
      while(y<=N){
         ft[x][y]+=delta;
         y+=LSB(y);
      }
      x+=LSB(x);
   }
}

void build(){
   for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) {
      update(i,j,t[i][j]);
   }

   /*for (int i=1; i<=N; i++){
      for (int j=1; j<=N; j++) cout << ft[i][j] << ' ';
      cout << endl;
   }*/
}

int getSum(int i, int j){
   int x=i,y;
   int res=0;
   while(x!=0){
      y=j;
      while(y!=0){
         res+=ft[x][y];
         y-=LSB(y);
      }
      x-=LSB(x);
   }
   return res;
}

int sum(int x1, int y1, int x2, int y2){
   return getSum(x2,y2)-getSum(x1-1,y2)-getSum(x2,y1-1)+getSum(x1,y1);
}

int32_t main(){
   boost;
	cin>>N;
	for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) cin>>t[i][j];

	build();
	cout << sum(1,1,5,6) << endl;
	update(2,2,7); // add 7 to t[2][2]
	cout << sum(1,1,5,6) << endl;

   return 0;
}

/*
8
1 1 3 2 1 1 3 2
2 3 3 3 2 3 3 3
1 1 1 1 1 1 1 1
1 9 3 1 1 9 3 1
1 1 3 2 1 1 3 2
2 3 3 3 2 3 3 3
1 1 1 1 1 1 1 1
1 9 3 1 1 9 3 1
*/
