#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0; i < (n); ++i)
#define repA(i, a, n) for(int  i = a; i <= (n); ++i)
#define repD(i, a, n) for(ll i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()
#define fill(a) memset(a, 0, sizeof(a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define endl '\n'
#define init(n) int n;cin>>n;int a[n];rep(i,n)cin>>a[i];
const long double PI = 3.141592653589793238462643383;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<long long int> vll;
typedef vector<pii> vii;
long long int Ceil(int a, int b){
    if(a%b==0) return a/b;
    else return (a/b)+1;
}
ll p=1000000007;
struct node
{   
    int v,w;
};
struct node1
{   
    int u,v,w;
};
const int maxn=100005;
vector<node> graph[maxn];
vector<node1> edge(maxn);
int subtree_size[maxn];
int anc[maxn][20];
int chain_num=0;int n;
int chainind[maxn],chainhead[maxn];
int basearray[maxn],posInbase[maxn];
int ptr=0;
int t[2*maxn];
int height[maxn];
int fun(int a,int b){
    return (a+b);
}
int lca(int a,int b){
    if(height[b]>height[a]){
        swap(a,b);
    }
    int h=abs(height[b]-height[a]);
    for(int k=19;k>=0;k--){
        if(h&(1<<k)){
            a=anc[a][k];
        }
    }
    for(int k=19;k>=0;k--){
        if(anc[a][k]!=anc[b][k]){
            a=anc[a][k];
            b=anc[b][k];
        }
    }
    if(a==b){
        return a;
    }
    return anc[a][0];
}
void dfs(int x,int p){
    subtree_size[x]=1;
    for(auto j:graph[x] ){
        if(p==(j.v)) continue;
        anc[j.v][0]=x;
        height[j.v]=height[x]+1;
        dfs(j.v,x);
        subtree_size[x]+=subtree_size[j.v];
    }
}
void hld(int cur=1,int weight=0,int p=-1){
    if(chainhead[chain_num]==-1){
        chainhead[chain_num]=cur;
    }
    chainind[cur]=chain_num;
    posInbase[cur]=ptr;
    basearray[ptr]=weight;ptr++;
    int wt=0,sc=-1;
    for(auto j:graph[cur] ){
        if(p==(j.v)) continue;
        if(sc==-1||subtree_size[sc]<subtree_size[j.v]){
            sc=j.v;
            wt=j.w;
        }
    }
    if(sc!=-1){
        hld(sc,wt,cur);
    }
    for(auto j:graph[cur] ){
        if(p==(j.v)||sc==(j.v)) continue;
        chain_num++;
        wt=j.w;
        hld(j.v,wt,cur);
    }
}
void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}
// segment tree starts
void make_tree(){
    for (int i = 0; i < n; ++i) t[n+i]=basearray[i];
    for (int i = n - 1; i > 0; --i) t[i] = fun(t[i<<1],t[i<<1|1]);
}
int query_tree(int l, int r) {  // fun on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res =fun(res,t[l++]) ;
    if (r&1) res =fun(res,t[--r]);
  }
  return res;
}
void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = fun(t[p],t[p^1]);
}
// segment tree ends
int query_up(int u,int v){

    if (u==v) return 0;
    int uchain=chainind[u],vchain=chainind[v];
    int ans=0;
    while(1){
        uchain=chainind[u],vchain=chainind[v];
        if(uchain==vchain){
            if(u==v) break;
            ans=fun(ans,query_tree(posInbase[v]+1,posInbase[u]+1));
            break;
        }
        ans=fun(ans,query_tree(posInbase[chainhead[uchain]],posInbase[u]+1));
        //cout<<ans<<endl;
        u=chainhead[uchain];
        u=anc[u][0];
    }
    return ans;
}
int query(int u,int v){
    int lc=lca(u,v);
    //cout<<lc<<endl;
    return fun(query_up(u,lc),query_up(v,lc));
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout);
    #endif
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int t;t=1;
    while(t--){
        cin>>n;
        if(n==1){
            int q;
            return 0;
            cin>>q;
            while(q--){
                int x,y,z;cin>>x>>y>>z;
                cout<<0<<endl;
            }
            
        }

        memset(chainhead,-1,sizeof(chainhead));
        rep(i,n-1){
            int x,y,z;cin>>x>>y>>z; 
            node1 u={x,y,z};edge[i+1]=u;
            graph[x].pb({y,z});graph[y].pb({x,z});
        }
        height[1]=0;
        dfs(1,-1);
        for(int j=1;j<20;j++){
            for(int i=1;i<=n;i++){
                anc[i][j]=anc[anc[i][j-1]][j-1];
            }
        }
        hld();
        make_tree();
        int q;cin>>q;
        while(q--){
            int z;cin>>z;
            if(z==1){
                int x,y;cin>>x>>y;
                //cout<<y<<endl;
                int lc=lca(edge[x].u,edge[x].v);
                if(lc==edge[x].u) lc=edge[x].v; else lc=edge[x].u;
                modify(posInbase[lc],y);
            }
            else{
                int x,y;cin>>x>>y;
                cout<<query(x,y)<<endl;
            }
        }
    }
    return 0;
}