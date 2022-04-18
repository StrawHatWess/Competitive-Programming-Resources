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

const int MAXV=100;
int V,s,t;
int res[MAXV][MAXV];
vi p;
int f;

void augment(int v, int minEdge){
   if(v==s){
      f=minEdge;
      return;
   }
   if(p[v]!=-1){
      augment(p[v],min(minEdge,res[p[v]][v]));
      res[p[v]][v]-=f; res[v][p[v]]+=f;
   }
   return;
}

int32_t main(){
   boost;
   memset(res,0,sizeof(res));

   //input staff
   cin>>V>>s>>t;
   for (int i=0; i<V; i++){
      int x; cin>>x;
      for (int j=0; j<x; j++){
         int v,w; cin>>v>>w;
         res[i][v]=w;
      }
   }

   int mf=0;
   while(1){
      f=0;
      //BFS;
      vi dist(V,INF); dist[s]=0;
      queue<int> q; q.push(s);
      p.assign(V,-1);

      while(!q.empty()){
         int u=q.front(); q.pop();
         if(u==t) break;
         for (int v=0; v<V; v++) if(res[u][v]>0 && dist[v]==INF){
            dist[v]=dist[u]+1;
            q.push(v);
            p[v]=u;
         }
      }
      augment(t,INF);
      if(f==0) break; // no more augmenting paths
      mf+=f;
   }
   cout << mf << endl;

   return 0;
}

