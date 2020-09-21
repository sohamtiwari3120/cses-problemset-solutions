#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MOD 1000000007
#define fi first
#define se second
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define repe(i,n) for(int i = 0 ; i <= n ; i++)
#define repb(i,a,b) for(int i = a ; i < b ; i++)
#define repeb(i,a,b) for(int i = a ; i <= b ; i++)
#define rfor(i,n,a) for(int i = n ; i >= a ; i--)
#define pb push_back
#define popb pop_back()
#define endl "\n"
#define pii pair<int,int> 
#define pll pair < long long, long long >
typedef priority_queue<ll, vector<ll>, greater<ll>> minheap;
typedef priority_queue<ll> maxheap;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a,b) cout << a << " " << b << endl
#define p3(a,b,c) cout << a << " " << b << " " << c << endl
#define p4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl
#define sortv(v) sort(v.begin(),v.end())
#define rsortv(v) sort(v.begin(),v.end(), greater<>());
#define sortby(v,prop) sort( v.begin( ), v.end( ), [ ]( const auto& lhs, const auto& rhs ){ return lhs.prop < rhs.prop; });
#define rsortby(v,prop) sort( v.begin( ), v.end( ), [ ]( const auto& lhs, const auto& rhs ){ return lhs.prop > rhs.prop; });

ll modPower(ll num,ll r){
	if(r==0) return 1;
	if(r==1) return num%MOD;
	ll ans=modPower(num,r/2)%MOD;
	if(r%2==0) {
		return (ans*ans)%MOD;
	} return (((ans*ans)%MOD)*num)%MOD;
}

ll nCr(ll n, ll r) { 
    ll res = 1; 
    if (r > n - r) {
        r = n - r; 
    }
    rep(i,r) { 
        res *= (n - i); 
        res /= (i + 1); 
    } 
    return res; 
}

bool isPrime(long long n)
{
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
 
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
 
    return true;
}


/*-------------------------------------------------*/

void solve() {

	int n, x, mn = INT_MAX;
	cin >> n >> x;

	int a[n];
	rep(i,n) {
		cin >> a[i];
		mn = min(mn,a[i]);
	}

	if(mn > x) {
		p1(-1);
		return;
	}

	sort(a, a+n);

	int dp[n][x+1];

	repeb(i,1,x) {
		if(i % a[0] == 0) {
			dp[0][i] = i / a[0];
		} else {
			dp[0][i] = -1;
		}
	}

	rep(i,n) {
		dp[i][0] = 0;
	}

	repb(i,1,n) {
		repeb(j,1,x) {
			if(a[i] > j) {
				dp[i][j] = dp[i-1][j];
			} else {
				int notchoose = dp[i-1][j];
				int choose = dp[i][j - a[i]];
				if(choose == -1) {
					dp[i][j] = notchoose;
				} else if(notchoose == -1) {
					dp[i][j] = 1 + choose;
				} else {
					dp[i][j] = min(notchoose, 1 + choose);
				}
			}
		}
	}


	// rep(i,n) {
	// 	repe(j,x) {
	// 		p0(dp[i][j]);
	// 	}cout << "\n";
	// }

	p1(dp[n-1][x]);
}




int main()
{
	fastio;
	solve();
	return 0;
}