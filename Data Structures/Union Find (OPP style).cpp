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

class UnionFind{
private:
   vi p,rank,setSize;
   int numSets;
public:
   UnionFind(int N){ //Create N disjoint sets;
      p.assign(N,0); for (int i=0; i<N;i++) p[i]=i;
      rank.assign(N,0); setSize.assign(N,1);
      numSets=N;
   }
   int findSet(int i){ return p[i]==i ? i : p[i]=findSet(p[i]); } //find root
   bool isSame(int i, int j){ return findSet(i)==findSet(j); } //same set
   void unionSet(int i, int j){
      if(!isSame(i,j)){
         numSets--;
         int x=findSet(i),y=findSet(j);
         if(rank[x]>rank[y]){ p[y]=x; setSize[x]+=setSize[y];}
         else{
            p[x]=y; setSize[y]+=setSize[x];
            if(rank[x]==rank[y]) rank[y]++;   }}}

   int numDisjointSets(){ return numSets; }
   int sizeofSet(int i){ return setSize[findSet(i)]; }
};

int32_t main(){
   boost;

   UnionFind UF(5); //create 5 Disjoint Sets

   cout << UF.numDisjointSets() << endl;
   UF.unionSet(0,1);
   UF.unionSet(2,3);
   UF.unionSet(3,4);
   cout << UF.numDisjointSets() << endl;

   cout<< UF.isSame(0,3) << endl;
   for (int i=0; i<5; i++) cout <<UF.findSet(i) << ' ' <<  UF.sizeofSet(i) << endl;
   cout << endl;

   return 0;
}

