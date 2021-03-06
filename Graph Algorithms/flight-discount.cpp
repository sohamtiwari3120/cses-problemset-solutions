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
#define vi vector<ll>
#define vb vector<bool>
#define vvi vector<vi>
#define pii pair < long long, long long >
typedef priority_queue<ll, vector<ll>, greater<ll>> minheap;
typedef priority_queue<ll> maxheap;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a,b) cout << a << " " << b << endl
#define p3(a,b,c) cout << a << " " << b << " " << c << endl
#define p4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl
#define p6(a,b,c,d,e,f) cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << endl
#define p7(a,b,c,d,e,f,g) cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << " " << g << endl
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

    template <typename T1, typename T2>
inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p)
{
    return os << "(" << p.first << ", " << p.second << ")";
}

    template<typename T>
inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v)
{
    bool first = true;
    os << "[";
    for(unsigned int i = 0; i < v.size(); i++)
    {
        if(!first)
            os << ", ";
        os << v[i];
        first = false;
    }
    return os << "]";
}

    template<typename T>
inline std::ostream &operator << (std::ostream & os,const std::set<T>& v)
{
    bool first = true;
    os << "[";
    for (typename std::set<T>::const_iterator iii = v.begin(); iii != v.end(); ++iii)
    {
        if(!first)
            os << ", ";
        os << *iii;
        first = false;
    }
    return os << "]";
}

    template<typename T1, typename T2>
inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v)
{
    bool first = true;
    os << "[";
    for (typename std::map<T1, T2>::const_iterator iii = v.begin(); iii != v.end(); ++iii)
    {
        if(!first)
            os << ", ";
        os << *iii ;
        first = false;
    }
    return os << "]";
}

int dr4[] = {0,1,0,-1}, dc4[] = {1,0,-1,0};
int dr8[] = {0,1,1,1,0,-1,-1,-1}, dc8[] = {1,1,0,-1,-1,-1,0,1};

/*-------------------------------------------------*/

// read once, read again, think, code 

int n, m, u, v, d;
#define INF 1e18

class Node {
public:
    int from;
    int to;
    ll dist;
};

void dijkstra(vector<pii> *adj, vi &dist, int st) {

    dist[st] = 0;
    multiset<pii> pq;
    pq.insert({0,st});
    vi vis(n+1,0); 


    while(!pq.empty()) {

        pii x = *pq.begin();
        pq.erase(x);

        if(vis[x.se]) continue;
        vis[x.se] = true;

        for(auto it : adj[x.se]) {

            if(!vis[it.fi]) {
                if(dist[it.fi] > dist[x.se] + it.se) {
                    dist[it.fi] = dist[x.se] + it.se;
                    pq.insert({dist[it.fi], it.fi});
                }
            }
        }
    }
} 

void solve() {

	cin >> n >> m;

	vector<pii> adj1[n+1], adj2[n+1];
    vector<Node> edges;

	rep(i,m) {
		cin >> u >> v >> d;
        adj1[u].pb({v,d});
		adj2[v].pb({u,d});
        edges.pb({u,v,d});
	}

	vi distSrc(n+1,INF), distDest(n+1,INF);

    dijkstra(adj1,distSrc,1);
	dijkstra(adj2,distDest,n);

    ll ans = INF;
    for(auto edge : edges) {
        ll curr = distSrc[edge.from] + edge.dist/2 + distDest[edge.to];
        ans = min(ans,curr);
    }

    p1(ans);
}


int main()
{
	fastio;
	solve();
	return 0;
}