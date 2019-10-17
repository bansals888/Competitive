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
void update(vector<vector<int> > &tree,int x,int y,int v){
    x=x+n;y=y+n;
    tree[x][y]=v;
    int z=y/2;
    for(int z=y/2;z>=1;z=z/2){
        tree[x][z]=tree[x][2*z]+tree[x][2*z+1];
    }
    for(int i=x/2;i>=1;i=i/2){
        for(int j=y;j>=1;j=j/2){
            tree[i][j]=tree[2*i][j]+tree[2*i+1][j];
        }
    }
}
int query(vector<vector<int> > &tree,int x1,int y1,int x2,int y2){
    x1=x1+n;y1=y1+n;
    x2=x2+n;y2=y2+n;
    int sum=0;
    while(x1<=x2){
        if(x1%2==1){
            int i=y1,j=y2;
            while(i<=j){
                if(i%2==1){
                    sum+=tree[x1][i];
                    i++;
                }   
                if(j%2==0){
                    sum+=tree[x1][j];
                    j--;
                }
                i=i/2;j=j/2;
            }
            x1++;
        }
        if(x2%2==0){
            int i=y1,j=y2;
            while(i<=j){
                if(i%2==1){
                    sum+=tree[x2][i];
                    i++;
                }   
                if(j%2==0){
                    sum+=tree[x2][j];
                    j--;
                }
                i=i/2;j=j/2;
            }
            x2--;
        }
        x1=x1/2;x2=x2/2;
    }
    return sum;
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
        cin>>n;
        string s;
        cin>>s;
        vector<vector<int> > tree(2*n,vector<int> (2*n,0));
        while(s!="END"){
            if(s=="SET"){
                int x,y,v;cin>>x>>y>>v;
                update(tree,x,y,v);
            }
            else{
                int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
                cout<<query(tree,x1,y1,x2,y2)<<endl;
            }
            cin>>s;
        }
    }
    return 0;
}