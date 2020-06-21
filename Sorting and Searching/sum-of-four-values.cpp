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

/*-------------------------------------------------*/

void solve() {

	int n, x, num;
	cin >> n >> x;
	vector<pii> a;

	rep(i,n) {
		cin >> num;
		a.pb({num,i});
	}

	sortby(a,fi);

	rep(i,n-1) {
		repb(j,i+1,n) {

			ll sum = x - a[i].fi - a[j].fi, l = 0, h = n - 1;

			while(l < h) {
				if(l == i || l == j) {
					l++;
					continue;
				} else if(h == i || h == j) {
					h--;
					continue;
				}

				ll num = a[l].fi + a[h].fi;
				if(num == sum) {
					p4(a[i].se+1,a[j].se+1,a[l].se+1,a[h].se+1);
					return;
				} else if(num > sum) {
					h--;
				} else {
					l++;
				}
			}

		}
	}

	p1("IMPOSSIBLE");

}


int main()
{
	fastio;
	solve();
	return 0;
}