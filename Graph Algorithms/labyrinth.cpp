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

#define vc vector<char>
#define vvc vector<vc>

int n, m, sx, sy, ex, ey;

bool safe(int i, int j) {
	return 0 <= i && i < n && j >= 0 && j < m; 
}

string c = "RDLU";

void traceAns(vvc &trace) {

    int currX = ex, currY = ey;
    string path = "";

    while(!(currX == sx && currY == sy)) {
        char move = trace[currX][currY];
        path += move;

        if(move == 'L') currY++;
        else if(move == 'R') currY--;
        else if(move == 'D') currX--;
        else if(move == 'U') currX++;
    }

    reverse(path.begin(), path.end());
    p1("YES");
    p1(path.size());
    p1(path);
}

void bfs(vector<string> &a) {
    
    vvc trace(n,vc(m,' '));

    queue<pii> q;
    q.push({sx,sy});
    trace[sx][sy] = 'S'; // start

    while(!q.empty()) {

        pii x = q.front();
        q.pop();

        if(a[x.fi][x.se] == 'B') {
            traceAns(trace);
            return;

        }

        for(int k = 0 ; k < 4 ; k++) {
            int nr = x.fi + dr4[k];
            int nc = x.se + dc4[k];
            if(safe(nr,nc) && a[nr][nc] != '#' && trace[nr][nc] == ' ') {
                trace[nr][nc] = c[k];
                q.push({nr,nc}); 
            }
        }

    }

    p1("NO");
}

void solve() {

	cin >> n >> m;
	vector<string> a(n);

	rep(i,n) cin >> a[i];

	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < m ; j++) {
			if(a[i][j] == 'A') {
                sx = i, sy = j;
			} else if(a[i][j] == 'B') {
                ex = i, ey = j;
            }
		}
	}

    bfs(a);

}


int main()
{
	fastio;
	solve();
	return 0;
}