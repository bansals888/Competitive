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
struct node{
    node *a[26];
    int freq;
};  
void insert(string s,node *trie){
    node *cur=trie;
    for(int i=0;i<s.size();i++){
        char  c=s[i];
        if(cur->a[c-'a']==NULL){
            cur->a[c-'a']=new node();
        }
        cur=cur->a[c-'a'];
        cur->freq++;
    }
}
int find(string s,node *trie){
    node *cur=trie;
    for(int i=0;i<s.size();i++){
        char  c=s[i];
        if(cur->a[c-'a']==NULL){
            return 0;
        }
        cur=cur->a[c-'a'];
    }
    
    return cur->freq;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout);
    #endif
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int n,q;cin>>n>>q;
    node *trie;
    trie=new node();
    for(int i=0;i<n;i++){
        string s;cin>>s;
        insert(s,trie);
    }
    while(q--){
        string s;cin>>s;
        int ans=find(s,trie);
        cout<<ans<<endl;
    }
    // find how many strings are prefix of a given string
    return 0;
}     