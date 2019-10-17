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
struct node
{
    int u,v,c;
};
bool comp(node a,node b){
    return a.c<b.c;
}
int root(int u,int *arr){
    while(arr[u]!=u){
        u=arr[u];
    }
    return u;
}
int find(int u,int v,int *arr){
    return root(u,arr)==root(v,arr);
}
void nion(int u,int v,int* arr,int *size){
    u=root(u,arr),v=root(v,arr);
    if(size[u]<size[v]){
        size[v]+=size[u];
        arr[u]=arr[v];
    }
    else{
        size[u]+=size[v];
        arr[v]=arr[u];
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout);
    #endif
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int n,m;cin>>n>>m;
    node graph[m];
    rep(i,m){
        cin>>graph[i].u>>graph[i].v>>graph[i].c;
    }
    //mst
    sort(graph,graph+m,comp);
    vector<pii > tree[n+1];
    int arr[n+1];
    int size[n+1];
    repA(i,1,n)
    arr[i]=i,size[i]=1;
    for(auto i:graph){
        if(!find(i.u,i.v,arr)){
            tree[i.u].pb(mp(i.v,i.c));tree[i.v].pb(mp(i.u,i.c));
            nion(i.u,i.v,arr,size);
        }
    }
    // tree is Kruskal MST
    return 0;
}