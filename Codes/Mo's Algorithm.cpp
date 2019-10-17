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
#define eb emplace_back
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
int n,q;
struct node
{
    int l,r,i;    
};
int s;
bool comp(node a,node b){
    if((a.l/s)==(b.l/s)){
        return a.r<b.r;
    }
    return (a.l/s)<(b.l/s); 
}
ll answer=0;
ll arr[1000001];
void add(int pos,int *a){
    int x=a[pos];
    int cnt=arr[x];
    arr[x]++;
    answer=answer+((ll)x)*((ll)(2*cnt+1));
}
void remove(int pos,int *a){
    int x=a[pos];
    int cnt=arr[x];
    arr[x]--;
    answer=answer+((ll)x)*((ll)(1-2*cnt));;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout);
    #endif
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    cin>>n>>q;
    int a[n+1];rep(i,n) cin>>a[i+1];
    s=sqrt(n);
    node que[q];
    rep(i,q) cin>>(que[i].l)>>(que[i].r),que[i].i=(i);
    sort(que,que+q,comp);
    ll ans[q];
    int cl=0,cr=0;
    memset(arr,0,sizeof(arr));
    a[0]=0;
    rep(i,q){
        int l=que[i].l,r=que[i].r;
        while(cl<l){
            remove(cl,a);cl++;
        }
        while(cl>l){
            cl--;add(cl,a);
        }
        while(cr<r){
            cr++;add(cr,a);
        }
        while(cr>r){
            remove(cr,a);cr--;
        }
        ans[que[i].i]=answer;
    }
    rep(i,q){
        cout<<ans[i]<<endl;
    }
    return 0;
}     