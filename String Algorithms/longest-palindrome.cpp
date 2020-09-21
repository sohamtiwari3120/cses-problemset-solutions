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

/*-------------------------------------------------*/

int n, maxLen, start;
string s;

void checkPalin(int i, int j) {
    
    while(i >= 0 && j < n && s[i] == s[j]) {
            if(j - i + 1 > maxLen) {
                
                maxLen = j - i + 1;
                start = i;
            }
            i--;
            j++;
        }
}


void solve() {

    cin >> s;
    n = s.size(), maxLen = 1, start = 0;
    
    for(int k = n/2 ; k < n-1 ; k++) {
        
        checkPalin(k-1,k); // even length
        checkPalin(k-1,k+1); // odd length
        
        if(maxLen == n) break;
        if(maxLen == n-1) break;
    }

    for(int k = n/2-1 ; k >= 1 ; k--) {
        
        checkPalin(k-1,k+1); // odd length
        checkPalin(k-1,k); // even length
        
    }
    
    string ans = s.substr(start,maxLen);
    p1(ans);
}


int main()
{
    fastio;
    solve();
    return 0;
}