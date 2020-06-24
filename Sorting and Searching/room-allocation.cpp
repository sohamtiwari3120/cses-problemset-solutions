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

	int n, st, et, curr = 0, ans = 0, k = 0, last;
	cin >> n;

	vector<pll> start, end, rooms;
	queue<ll> nextAvailable;
	set<ll> occupied;

	map<ll,ll> roomOccupied;

	nextAvailable.push(1);

	rep(i,n) {
		ll st, et;
		cin >> st >> et;;
		start.pb({st,i});
		end.pb({et,i});
	}

	sortby(start,fi);
	sortby(end,fi);

	for(auto st : start) {

		for(;end[k].fi < st.fi && k < end.size();k++) {
			curr--;
			nextAvailable.push(roomOccupied[end[k].se]);
			occupied.erase(roomOccupied[end[k].se]);
		}

		if(nextAvailable.empty()) {
			int next = 1;
			bool flag = false;
			for(auto it : occupied) {
				if(it != next) {
					nextAvailable.push(next);
					flag = true;
					break;
				} else {
					next++;
				}
			}

			if(!false) {
				nextAvailable.push(next);
			}
		}

		// nextAvailable.push(100);
		
		ll room = nextAvailable.front();
		nextAvailable.pop();
		rooms.pb({room,st.se});
		last = room;
		roomOccupied[st.se] = room;
		occupied.insert(room);

		curr++;
		ans = max(ans,curr);
	}

	sortby(rooms,se);

	p1(ans);
	for(auto it : rooms) {
		p0(it.fi);
	} 

	cout << "\n";
}


int main()
{
	fastio;
	solve();
	return 0;
}