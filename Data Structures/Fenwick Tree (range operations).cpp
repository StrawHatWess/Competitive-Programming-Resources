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

int MXN=10000+1;
int N;
vi ft(MXN,0), ft2(MXN,0);

int LSB(int i){
   return i&(-i);
}

void add(int nb, int pos, int x){
   if(nb==1){
      while(pos<=N){
         ft[pos]+=x;
         pos+=LSB(pos);
      }
   }
   else if(nb==2){
      while(pos<=N){
         ft2[pos]+=x;
         pos+=LSB(pos);
      }
   }
}

void update(int l, int r, int x){
   add(1,l,x);
   add(1,r+1,-x);
   add(2,l,x*(l-1));
   add(2,r+1,-x*r);
}

int getSum(int i){
   int idx=i,x=0,y=0;
   while(idx>0){
      x+=ft[idx];
      idx-=LSB(idx);
   }
   idx=i;
   while(idx>0){
      y+=ft2[idx];
      idx-=LSB(idx);
   }
   return i*x-y;
}

int sum(int l, int r){
   return getSum(r)-getSum(l-1);
}

int32_t main(){
   boost;
   cin>>N;
   update(4,9,2);
   update(2,6,5);
   cout << sum(2,8) << endl;
   update(1,1,3);
   cout << sum(1,6) << endl;

   return 0;
}
