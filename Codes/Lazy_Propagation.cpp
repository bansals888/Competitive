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
const int inf = 1e9;
ll p=1000000007;
int n;
void update(vector<ll> &tree,vector<ll> &lazy,int x,int y,ll v,int s,int e,int i){
    if(s>e)return ;
    if(lazy[i]!=0){
        tree[i]+=(lazy[i]*(e-s+1));
        if(s!=e){
            lazy[2*i+1]+=lazy[i];
            lazy[2*i+2]+=lazy[i];
        }
        lazy[i]=0;
    }
    if(x>e||y<s)return ;
    int m=(s+e)/2;
    if(s==e){
        tree[i]+=v;return ;
    }
    if(x<=s&&y>=e){
        tree[i]=tree[i]+(e-s+1)*(v);
        lazy[2*i+1]+=v;
        lazy[2*i+2]+=v;
        return ;
    }
    update(tree,lazy,x,y,v,s,m,2*i+1);
    update(tree,lazy,x,y,v,m+1,e,2*i+2);
    tree[i]=tree[2*i+1]+tree[2*i+2];
}
ll query(vector<ll> &tree,vector<ll> &lazy,int x,int y,int s,int e,int i){
    if(s>e) return 0;
    if(lazy[i]!=0){
        tree[i]+=(lazy[i]*(e-s+1));
        if(s!=e){
            lazy[2*i+1]+=lazy[i];
            lazy[2*i+2]+=lazy[i];
        }
        lazy[i]=0;
    }
    ll sum=0;
    if(x>e||y<s)return 0;
    int m=(s+e)/2;
    if(x<=s&&y>=e){
        return tree[i];
    }
    sum+=query(tree,lazy,x,y,s,m,2*i+1);
    sum+=query(tree,lazy,x,y,m+1,e,2*i+2);
    return sum;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout);
    #endif
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int t2;cin>>t2;
    while(t2--){
        int q;
        cin>>n>>q;
        int l=ceil(log2(n));
        l=2*(1<<l)+5;
        vector<ll> tree(l,0);
        vector<ll> lazy(l,0);
        while(q--){
            int t;cin>>t;
            if(t==0){
                ll x,y,v;cin>>x>>y>>v;x--;y--;
                update(tree,lazy,x,y,v,0,n-1,0);
            }
            else{
                int x,y;cin>>x>>y;
                cout<<query(tree,lazy,x-1,y-1,0,n-1,0)<<endl;
            }
        }
    }
    return 0;
}