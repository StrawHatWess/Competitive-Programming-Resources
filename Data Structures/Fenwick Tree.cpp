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

const int MXN=100000;
int N;
int t[MXN];

vi ft;

int LSB(int i){
   return i&(-i);
}

void build(){
   for (int i=1; i<=N; i++) ft[i]=t[i];
   for (int i=1; i<=N; i++){
      int idx=i + LSB(i);
      if(idx<=N) ft[idx]+=ft[i];
   }
   //for (int i=1; i<=N; i++) cout << ft[i] << ' ';
}

int getSum(int i){
   int res=0;
   while(i!=0){
      res+=ft[i];
      i-=LSB(i);
   }
   return res;
}

int sum(int i, int j){
   return getSum(j)-getSum(i-1);
}

void update(int i, int x){
   while(i<=N){
      ft[i]+=x;
      i+=LSB(i);
   }
}

int32_t main(){ //range sum queries
   boost;

   cin>>N;
   for (int i=1; i<=N;i++) cin>>t[i];
   ft.assign(N+1,0);

	build();
	cout << getSum(7) << endl;
	cout << sum(1,5) << endl;

   cout << sum(1,12) << endl;
	update(6,8); update(9,-2);
	cout << sum(1,12) << endl;

   return 0;
}

/*
12
2 1 1 3 2 3 4 5 6 7 8 9
*/
