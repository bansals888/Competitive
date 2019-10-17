#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0; i < (n); ++i)
#define repA(i, a, n) for(int  i = a; i <= (n); ++i)
#define repD(i, a, n) for(ll i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()
#define fill(a) memset(a, 0, sizeof(a))
#define fst first0000
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
ll power(ll x, ll y){
    if(y==0){
        return 1;
    }
    if(y%2==0){
        ll q=power(x,y/2);
        q=q%p;
        return (q*q)%p;
    }
    ll q=power(x,y/2);
    q=q%p;
    return ((x%p)*((q*q)%p))%p; 
}

int first[maxn];
int last[maxn];
vector<int> euler;
int t=0;
int anc[maxn][20];
int tree[2*maxn];
int size;
int height[maxn];
void dfs(int x,int p){
    first[x]=t;
    t++;
   // cout<<x<<endl;
    euler.pb(x);
    for(auto j:graph[x] ){
     //   cout<<(j.v)<<endl;
        if(p==(j.v)) continue;
        anc[j.v][0]=x;
        height[j.v]=height[x]+1;
        dfs(j.v,x);
    }
    
    euler.pb(x);
    last[x]=t;
    t++;
}

void update(int ind,int val){
    ind++;
    while(ind<=size){
        tree[ind]+=val;
        ind=ind+(ind&(-ind));
    }
}
int getsum(int ind){
    ind++;
    int sum=0;
    while(ind>0){
        sum+=tree[ind];
        ind=ind-(ind&(-ind));
    }
    return sum;
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
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout);
    #endif
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int n;cin>>n;
    node1 edge[n];
    rep(i,n-1){
        int x,y,z;cin>>x>>y>>z;
        node1 u={x,y,z};
        edge[i+1]=u;
        graph[x].pb({y,z});graph[y].pb({x,z});
    }
    int q;cin>>q;
    anc[1][0]=1;
    height[1]=0;
    dfs(1,-1);
    size=euler.size();
    
    for(int j=1;j<20;j++){
        for(int i=1;i<=n;i++){
            anc[i][j]=anc[anc[i][j-1]][j-1];
        }
    }
    // rep(i,size){
    //     cout<<euler[i]<<" ";
    // }
    // cout<<endl;
    rep(i,n-1){
        int u=edge[i+1].u;
        int v=edge[i+1].v;
        int w=edge[i+1].w;
        int sub=lca(u,v);
        //cout<<sub<<endl;
        if(sub==u) sub=v;
        else sub=u;   
        //cout<<sub<<endl;
        int val=w;
        //cout<<sub<<" "<<first[sub]<<" "<<last[sub]<<endl;
        update(first[sub],val);
        update(last[sub] ,-val);
    }
    int val;
    int x=1,y=4;
    val=getsum(first[x])+getsum(first[y])-2*getsum(first[lca(x,y)]);
  //  cout<<val<<endl;
    //cout<<height[5]<<endl;
    //cout<<"lca"<<lca(4,5)<<endl;
    while(q--){
        int t,x,y;cin>>t>>x>>y;
        if(t==1){
            int u=edge[x].u;
            int v=edge[x].v;
            int w=edge[x].w;
            int sub=lca(u,v);
            if(sub==u) sub=v;
            else sub=u;   
            int val=y-w;
            edge[x].w=y;
            update(first[sub],val);
            update(last[sub] ,-val);
        }
        else{
            int val;
            val=getsum(first[x])+getsum(first[y])-2*getsum(first[lca(x,y)]);
            cout<<val<<endl;
        }
    }
    return 0;
}