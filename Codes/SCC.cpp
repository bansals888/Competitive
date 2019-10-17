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
struct node
{
    int x,l;
};
int cnt=0;
void dfs(int i, int *visit,int *time,vi *v){
    cnt++;
    visit[i]=1;
    for(auto j:v[i]){
        if(!visit[j])
        {   
            dfs(j,visit,time,v);
        }
    }
    cnt++;
    time[i]=cnt;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout);
    #endif
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s[n];
        rep(i,n)cin>>s[i];
        vector<int> v[n+1];
        rep(i,n){
            rep(j,n){
                if(s[i][j]=='Y'){
                    v[i+1].pb(j+1);
                }
            }
        }
        cnt=0;
        int time[n+1];
        int visit[n+1]={0};
        for(int i=1;i<=n;i++){
            if(!visit[i])
                dfs(i,visit,time,v);
        }
        pii arr[n+1];
        repA(i,1,n){
            arr[i]=mp(time[i],i);
        }
        sort(arr+1,arr+1+n,greater<pii >());
        vector<int> vnew[n+1];
        repA(i,1,n){
            for(auto j:v[i]){
                vnew[j].pb(i);
            }
        }
        repA(i,1,n)visit[i]=0;
        int ans=0;
        for(int i=1;i<=n;i++){
            if(!visit[arr[i].snd]){
                ans++;
               dfs(arr[i].snd,visit,time,vnew);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
