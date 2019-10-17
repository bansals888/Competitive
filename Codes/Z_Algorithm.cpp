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
#define dbg(x) cerr << #x << " == " << x << "\n";
#define endl '\n'
#define init(n) int n;cin>>n;int a[n];rep(i,n)cin>>a[i];
const long double PI = 3.141592653589793238462643383;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<long long int> vll;
typedef vector<pii> vii;
using namespace std;
long long int Ceil(int a, int b){
    if(a%b==0) return a/b;
    else return (a/b)+1;
} 
clock_t time_p=clock();
void aryanc403()
{
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout); 
    #endif
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    // z algorithm
    string s;cin>>s;
    int n=s.size();
    int zarr[n];
    zarr[0]=0;
    int l=-1,r=-1;
    for(int i=1;i<n;i++){
        if(r<=i){
            l=i;
            int j=0;
            r=i;
            while(j<n&&s[j]==s[r]){
                j++;r++;
            }
            zarr[i]=j;
        }
        else{
            if(zarr[i-l]<(r-i+1)){
                zarr[i]=zarr[i-l];
            }
            else{
                r++;
                int j=r-i+1;
                l=i;
                while(r<n&&j<n&&s[j]==s[r]){
                    j++;r++;
                }
                zarr[i]=j-i;
            }
        }
    }   
}