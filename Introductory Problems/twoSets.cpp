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

ll power(ll num,ll r){
	if(r==0) return 1;
	if(r==1) return num%MOD;
	ll ans=power(num,r/2)%MOD;
	if(r%2==0) {
		return (ans*ans)%MOD;
	} return (((ans*ans)%MOD)*num)%MOD;
}

/*-------------------------------------------------*/

void solve() {

	ll n;
	cin >> n;

	ll s = 1, e = n;

	vector<ll> one, two;

	if((n - 3) % 4 == 0) {
		one.pb(1);
		one.pb(2);
		two.pb(3);
		s = 4;
		n-= 3;
	}

	int turn = 0;
	if(n % 4 == 0) {

		while(s < e) {
			if(turn % 2 == 0) {
				one.pb(s);
				one.pb(e);
			} else {
				two.pb(s);
				two.pb(e);
			}
			s++;
			e--;
			turn++;
		}

		p1("YES");
		p1(one.size());
		for(auto num : one) {
			p0(num);
		}
		cout << "\n";
		p1(two.size());
		for(auto num : two) {
			p0(num);
		}
		cout << "\n";

	} else {
		p1("NO");
	}

}


int main()
{
	fastio;
	solve();
	return 0;
}