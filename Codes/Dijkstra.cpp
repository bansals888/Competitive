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
	ll v,w;
};
using namespace std;
int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);   
	freopen("output.txt", "w", stdout);	
	#endif
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int t;t=1;
	while(t--){
		ll n,m,s,d;cin>>n>>m>>s;
	    vector<node> graph[n+1];
	    rep(i,m){
	    	ll x,y,z;cin>>x>>y>>z;
	    	z=-z;
	    	graph[x].pb({y,z});
	    	graph[y].pb({x,z});
	    }	
		priority_queue <pii >q;
		q.push(mp(0,s));
		int visit[n+1]={0};
		ll dis[n+1];
		while(!q.empty()){
			pair<ll,ll> p =q.top();q.pop();
			if(visit[p.snd])
				continue;
			dis[p.snd]=-(p.fst);
			visit[p.snd]=1;
			for(auto i: graph[p.snd]){
				q.push(mp(p.fst+i.w,i.v));
			}
		}
	}
    
	// dijstra with nodes from 1 to n
  	return 0;
}