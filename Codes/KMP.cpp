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
typedef pair<long long, long long> pii;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<long long int> vll;
typedef vector<pii> vii;
long long int Ceil(int a, int b){
    if(a%b==0) return a/b;
    else return (a/b)+1;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout);
    #endif
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    string pat,tex;cin>>pat>>tex;
    int n,m;
    n=tex.size(),m=pat.size();
    int lps[m]={0};
    repA(i,1,m-1){
        int j=lps[i-1];
        while(j>=0){
            if(pat[j]==pat[i]){
                lps[i]=j+1;
                break;
            }
            if(j<1)break;
            j=lps[j-1]; 
        }
    }
    int j=0;
    rep(i,n){
        if(tex[i]==pat[j]){
            j++;
            if(j==m){
                cout<<(i-m+1)<<endl;
                j=lps[j-1];
            }
        }
        else{
            if(j==0){
                continue;
            }
            i--;j=lps[j-1];
        }
        
    }

    return 0;
}     