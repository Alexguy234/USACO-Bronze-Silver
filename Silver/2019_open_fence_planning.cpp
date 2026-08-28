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
int main(){
    ifstream fin ("fenceplan.in");
    ofstream fout ("fenceplan.out");
    int n, m;
    fin >> n >> m;
    vector<pair<int, int>> cow_coor(n + 1);
    for (int i = 1; i <= n; i++){
        fin >> cow_coor[i].first >> cow_coor[i].second;
    }
    vector<vector<int>> adj(n + 1);
    int temp1, temp2;
    for (int i = 0; i < m; i++){
        fin >> temp1 >> temp2;
        adj[temp1].push_back(temp2);
        adj[temp2].push_back(temp1);
    }
    vector<int> visited(n + 1);
    int ans = INT_MAX;
    while (true){
        int should_break = true, start_cow = 0;
        for (int i = 1; i <= n; i++){
            if (!visited[i]){
                should_break = false;
                start_cow = i;
                break;
            }
        }
        if (should_break) break;
        queue<int> q;
        q.push(start_cow);
        int min_x = INT_MAX, max_x = -1, min_y = INT_MAX, max_y = -1;
        while (!q.empty()){
            int cur = q.front();
            q.pop();
            min_x = min(min_x, cow_coor[cur].first);
            max_x = max(max_x, cow_coor[cur].first);
            min_y = min(min_y, cow_coor[cur].second);
            max_y = max(max_y, cow_coor[cur].second);
            for (auto& i : adj[cur]){
                if (!visited[i]){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        ans = min(ans, 2 * ((max_x - min_x) + (max_y - min_y)));
    }
    fout << ans << endl;
}