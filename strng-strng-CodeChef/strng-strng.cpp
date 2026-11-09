#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

#define pb push_back

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define endl '\n'        
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (a); i >= (b); i--)
const int MOD = 1e9 + 7;

const ll INF = 1e18;
const int MAXN = 2e5 + 5;


void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

#ifdef LOCAL
    #define debug(x) cerr << #x << " = " << (x) << endl;
    #define debugVec(v) { cerr << #v << " = [ "; for (auto& x : v) cerr << x << " "; cerr << "]" << endl; }
#else
    #define debug(x)
    #define debugVec(v)
#endif


void solve() {
    int n;
    cin>>n;
    vi v(n);
    int counti = 0;
    rep(i,0,n){
        cin>>v[i];
        if(v[i] == 1) counti++;
    }
    
    if(counti>1){
        cout<<0<<endl;
        return;
    }
    if(counti==1){
        cout<<1<<endl;
        return;
    }
    sort(all(v));
    int first = v[0];
    int second = v[1];
    int count = 0;
    rep(i,2,n){
        int g1 = __gcd(first,v[i]);
        int g2 = __gcd(second,v[i]);
        if(g1==1){
            count++;
        }
        if(g2==1){
            count++;
        }
    }
    int r = __gcd(first,second);
    if(r==1){
        count++;
    }
    if(count == 1){
        cout<<1<<endl;
        return;
    }
    else if(count==0){
        cout<<n<<endl;
        return;
    }
    else{
        cout<<0<<endl;
        return;
    }

}

int main() {
    fastio();

    int t = 1;
    cin >> t;         
    while (t--) {
        solve();
    }

    return 0;
}


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna