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

class Node {
public:
	int moves;
	int person;
	int i;
	int j;

	bool operator<(const Node &a) const {
		
		if(moves != a.moves) {
			return moves < a.moves;
		} else {
			if(person != a.person) {
				return person < a.person;
			} else {
				if(i == a.i) return j < a.j;
				else return i < a.i;
			}
		}
	}
};

string c = "RDLU";
int n, m, sx, sy;

bool safe(int i, int j) {
	return 0 <= i && i < n && j >= 0 && j < m; 
}

void traceback(vvc &trace, int ex, int ey) {

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

void solve() {

	int openings = 0;
	cin >> n >> m;
	vector<string> a(n);

	rep(i,n) cin >> a[i];

	vvi vis(n,vi(m,0));
	vvc trace(n,vc(m,' '));
	multiset<Node> q;

	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < m ; j++) {
			if(a[i][j] == 'A') {
				sx = i, sy = j;
				vis[i][j] = 1;
				q.insert({0,1,i,j});
			} else if(a[i][j] == 'M') {
				vis[i][j] = 2;
				q.insert({0,0,i,j});
			}

			if(a[i][j] == '.') {
				if(i==0||i==n-1||j==0||j==m-1) {
					openings++;
				}
			}

			if(a[i][j] == 'A') {
				if(i==0||i==n-1||j==0||j==m-1) {
					p1("YES");
					p1("0");
					return;
				}
			}
		}
	}

	if(openings == 0) {
		p1("NO");
		return;
	}


	while(!q.empty()) {

		Node x = *q.begin();
		q.erase(x);


		if(x.person) {
			// p4("person:",x.moves,x.i,x.j);

			if(x.i==0 || x.i == n-1 || x.j == 0 || x.j == m-1) {
				traceback(trace,x.i,x.j);
				return;
			}

			for(int i = 0 ; i < 4 ; i++) {
				int nr = x.i + dr4[i];
				int nc = x.j + dc4[i];
				if(safe(nr,nc) && a[nr][nc] == '.' && vis[nr][nc] == 0) {
					vis[nr][nc] = 1;
					trace[nr][nc] = c[i];
					q.insert({x.moves+1,x.person,nr,nc});
				}
			}
		} else {
			// p4("monster:",x.moves,x.i,x.j);

			for(int i = 0 ; i < 4 ; i++) {
				int nr = x.i + dr4[i];
				int nc = x.j + dc4[i];
				if(safe(nr,nc) && a[nr][nc] != '#' && vis[nr][nc] != 2) {
					vis[nr][nc] = 2;
					q.insert({x.moves+1,x.person,nr,nc});
				}
			}
		}
	}

	p1("NO");
}


int main()
{
	fastio;
	solve();
	return 0;
}