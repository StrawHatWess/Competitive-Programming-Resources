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

// Basic 3 operations: make_set, union_set and find_set

int MXN=1000; //nb of sets
vi p(MXN,-1), ranks(MXN,0), setSize(MXN,0);
int nb_sets=0;

void make_set(int v){
   p[v]=v;
   ranks[v]=0;
   setSize[v]=1;
   nb_sets++;
}

int find_set(int v){
   return p[v]==v ? v: p[v]=find_set(p[v]);
}

void union_set(int u, int v){
   int a=find_set(u), b=find_set(v);
   if(a==b) return;
   nb_sets--;
   if(ranks[b]>ranks[a]) swap(a,b);
   p[b]=a;
   setSize[a]+=setSize[b];
   if(ranks[b]==ranks[a]) ranks[a]++;
}

int size_of_set(int u){
   return setSize[find_set(u)];
}

int32_t main(){
   boost;
   int N; cin>>N;

   for (int i=0; i<N; i++) make_set(i);
   cout << nb_sets << endl;
   union_set(0,1); union_set(1,2);
   cout << nb_sets << endl;
   cout << size_of_set(0) << endl;

   return 0;
}

