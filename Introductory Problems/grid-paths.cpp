#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MOD 1000000007
#define fi first
#define se second
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define repe(i,n) for(ll i = 0 ; i <= n ; i++)
#define repb(i,a,b) for(ll i = a ; i < b ; i++)
#define repeb(i,a,b) for(ll i = a ; i <= b ; i++)
#define rfor(i,n,a) for(ll i = n ; i >= a ; i--)
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


/*-------------------------------------------------*/


#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define vi vector<int>
#define vb vector<bool>
#define vvvi vector<vvi>

unordered_map<char,int> m;
int dr[] = {0,1,0,-1};
int dc[] = {1,0,-1,0};
int ans;
string s;

bool inRange(int x, int y) {
	return (0 <= x && x < 7 && 0 <= y && y < 7);
}

void backtrack(int idx,int r, int c, vvb &vis, vvvi &dp) {

	if(!inRange(r,c)) return;
	p4(idx,r,c,dp[r][c][idx]);
	if(idx == 48) {
		if(r == 6 && c == 0) ans++;
		return;
	}

	if(dp[r][c][idx] != -1) return;

	// if(vis[r][c]) return;

	vis[r][c] = true;

	if(s[idx] == '?') {
		
		rep(i,4) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if(inRange(nr,nc) && !vis[nr][nc]) {
				vis[nr][nc] = true;
				backtrack(idx+1,nr,nc,vis,dp);
				// p4(idx,nr,nc,ans);
				vis[nr][nc] = false;
			}
		}

	} else {
		
		// vis[r][c] = true;

		int nr = r + dr[m[s[idx]]];
		int nc = c + dc[m[s[idx]]];

		if(inRange(nr,nc) && !vis[nr][nc]) {
			vis[nr][nc] = true;
			backtrack(idx+1,nr,nc,vis,dp);
			vis[nr][nc] = false;

		}
		
		// vis[r][c] = false;
	}

	dp[r][c][idx] = ans;
	vis[r][c] = false;
}
/*
??URRRRRDDDLUULDDDLDR?URDDLLLLLURULURRUULDL?DDD?
*/
void solve() {

	cin >> s;
	ans = 0;

	vvvi dp(8,vvi(8,vi(49,-1)));
	vvb vis(7,vb(7,false));
	
	m['R'] = 0;
	m['D'] = 1;
	m['L'] = 2;
	m['U'] = 3;
	
	// vis[0][0] = true;
	backtrack(0,0,0,vis,dp);
	p1(ans);
}


int main()
{
	fastio;
	solve();
	return 0;
}