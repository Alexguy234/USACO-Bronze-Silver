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
using namespace std;
int main(){
    ifstream fin ("closing.in");
    ofstream fout ("closing.out");
    int n, m;
    fin >> n >> m;
    vector<vector<int>> adj(n + 1);
    int temp1, temp2;
    for (int i = 0; i < m; i++){
        fin >> temp1 >> temp2; 
        adj[temp1].push_back(temp2);
        adj[temp2].push_back(temp1);
    }
    int farm_to_close = -1;
    vector<bool> closed_farm(n + 1, false);
    for (int i = -1; i < n - 1; i++){
        if (i > -1){
            fin >> farm_to_close;
            closed_farm[farm_to_close] = true;
        }
        queue<int> q;
        int temp = 1;
        while (closed_farm[temp]){
            temp++;
        }
        q.push(temp);
        vector<bool> visited(n + 1, false);
        while (!q.empty()){
            int cur = q.front();
            q.pop();
            if (closed_farm[cur]){
                continue;
            }
            visited[cur] = true;
            for (auto& j : adj[cur]){
                if (!visited[j] && !closed_farm[j]){
                    visited[j] = true;
                    q.push(j);
                }
            }
        }
        bool ans = true;
        for (int j = 1; j <= n; j++){
            if (!visited[j] && !closed_farm[j]){
                ans = false;
            }
        }
        fout << ((ans == true) ? "YES" : "NO") << endl;
    }
}