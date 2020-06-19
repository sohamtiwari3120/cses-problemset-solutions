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

ll modPower(ll num,ll r) {
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

/*-------------------------------------------------*/

void solve() {

	ll n, ans = 2;
	cin >> n;

	if(n <= 2) {
		p1(n);
		return;
	}

	repeb(i,2,sqrt(n)) {
		if(n % i == 0) {
			if(i == n / i) {
				ans++;
			} else {
				ans += 2;
			}
		}
	}

	p1(ans);
}


int main()
{
	fastio;
	int tc, sz = 0, n;
	cin >> tc;

	queue<int> tcs;

	while(tc--)	{
		cin >> n;
		tcs.push(n);
		sz = max(n,sz);
	}

	int sieve[sz + 1]{0};

	repeb(i,2,sqrt(sz)) {
		for(int j = i ; j <= sz ; j += i) {
			sieve[j]++;
		}
	}

	while(!tcs.empty()) {
		int x = tcs.front();
		tcs.pop();
		p1(2 + sieve[x]);
	}

	return 0;
}