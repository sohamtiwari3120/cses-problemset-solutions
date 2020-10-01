#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
#define ll long long
#define FOR(i, k, n) for (i = k; i < n; i++)
int main()
{
    string s;
    getline(cin, s);
    int n = s.length();
    vector<string> result;
    unordered_map<string, int> umap;
    vector<char> permutation;

    for (int i = 0; i < n; i++)
    {
        permutation.push_back(s[i]);
    }
    int ctr = 0;
    sort(permutation.begin(), permutation.end());
    do
    {
        // process permutation
        string temp(permutation.begin(), permutation.end());
        if(umap[temp]==1)
            continue;
        umap[temp]=1;
        result.push_back(temp);
        ctr++;
    } while (next_permutation(permutation.begin(), permutation.end()));

    cout<<ctr<<ln;
    int i;
    sort(result.begin(), result.end());
    FOR(i, 0, ctr)
        cout<<result[i]<<ln;
    return 0;
}