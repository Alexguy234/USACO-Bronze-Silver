#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <deque>
using namespace std;
struct worm{
    int a, b, w;
};
bool works(int n, int m, vector<vector<pair<int, int>>>& adj, int min_wormhole, vector<int>& order){
    int component = 0;
    vector<int> comp(n + 1, -1);
    for (int i = 1; i <= n; i++){
        if (comp[i] != -1){
            continue;
        } 
        queue<int> q;
        q.push(i);
        comp[i] = component;
        while (!q.empty()){
            int cur = q.front();
            q.pop();
            for (auto& j : adj[cur]){
                if (comp[j.first] == -1 && j.second >= min_wormhole){
                    q.push(j.first);
                    comp[j.first] = component;
                }
            }
        }
        component++;
    }
    for (int i = 1; i <= n; i++){
        if (order[i] != i){
            if (!(comp[order[i]] == comp[i])){
                return false;
            }
        }
    }
    return true;
}
int main(){
    ifstream fin ("wormsort.in");
    ofstream fout ("wormsort.out");
    int n, m;
    fin >> n >> m;
    vector<int> order(n + 1, 0);
    int temp;
    bool edge = true;
    for (int i = 1; i <= n; i++){
        fin >> temp;
        if (i != temp) edge = false;
        order[temp] = i;
    }
    if (edge){ fout << -1 << endl; return 0;} 
    vector<vector<pair<int, int>>> adj(n + 1);
    int max_width = -1;
    int a, b, w;
    for (int i = 0; i < m; i++){
        fin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
        max_width = max(max_width, w);
    }
    int l = 0, r = max_width, ans = -1;
    while (l <= r){
        int mid = (l + r) / 2;
        if (works(n, m, adj, mid, order)){
            ans = max(ans, mid);
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    fout << ans << endl;
}