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

int32_t main(){
   boost;
   int N=11;
   int t[N]={-7, 10, 9, 2, 3, 8, 8, 1, 2, 3, 4};

   /*cin>>N;
   vi t(N,-1);
   for (int n=0; n<N; n++) cin>>t[n];*/

   vi LIS; LIS.pb(t[0]);
   vi idx; idx.pb(0);
   vi prev(N,-1);
   for(int i=1; i<N; i++){ //i=1 because we assume that the first element is already inserted in the LIS
      if(t[i]<t[idx[0]]){ //insert at the beginning
         idx[0]=i;
         LIS[0]=t[i];
      }
      else if(t[i]>t[idx[sz(idx)-1]]){ //insert at the end
         prev[i]=idx[sz(idx)-1];
         idx.pb(i);
         LIS.pb(t[i]);
      }
      else{
         auto pos=upper_bound(all(LIS),t[i])-LIS.begin();
         LIS[pos]=t[i];
         idx[pos]=i;
         prev[i]=idx[pos-1];
      }
   }

   int i=idx[sz(idx)-1];
   vi ans;
   while(i>=0){
      ans.pb(t[i]);
      i=prev[i];
   }

   reverse(all(ans));
   cout << sz(ans) << endl;
   for(int i=0; i<sz(ans); i++) cout << ans[i] << ' ';
   cout << endl;


}

