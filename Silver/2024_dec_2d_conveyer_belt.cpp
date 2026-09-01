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
int add_x[] = {-1, 1, 0, 0};
int add_y[] = {0, 0, -1, 1};
map<char, int> match_dir = {{'?', -1}, {'U', 0}, {'D', 1}, {'L', 2}, {'R', 3}};
int cur_good = 0;
bool is_good(int i, int j, vector<vector<int>> &good, vector<vector<int>> &types, int n){
    if (types[i][j] == -1){
        int good_adj_cell = false;
        for (int l = 0; l < 4; l++){
            int new_x = i + add_x[l], new_y = j + add_y[l];
            if (new_x < 1 || new_x > n || new_y < 1 || new_y > n || good[new_x][new_y]){
                good_adj_cell = true;
                break;
            }
        }
        if (!good_adj_cell) return false;
    }
    else{
        int new_x = i + add_x[types[i][j]], new_y = j + add_y[types[i][j]];
        if (!(new_x < 1 || new_x > n || new_y < 1 || new_y > n || good[new_x][new_y])){
            return false;
        }
    }
    return true;
}
void dfs(int i, int j, int n, vector<vector<int>> &good, vector<vector<int>> &types){
    if (!is_good(i, j, good, types, n) || good[i][j]){
        return;
    }
    good[i][j] = true;
    cur_good++;
    for (int l = 0; l < 4; l++){
        if (i + add_x[l] <= n && i + add_x[l] >= 1 && j + add_y[l] <= n && j + add_y[l] >= 1){
            dfs(i + add_x[l], j + add_y[l], n, good, types);
        }
    }
}
int main(){
    int n, q;
    cin >> n >> q;
    vector<vector<int>> good(n + 1, vector<int> (n + 1, false)), types(n + 1, vector<int> (n + 1, -1));
    vector<pair<pair<int, int>, char>> upds(q);
    vector<int> res;
    int r, c;
    char type;
    for (int i = 0; i < q; i++){
        cin >> r >> c >> type;
        upds[i] = {{r, c}, type};
        types[r][c] = match_dir[type];
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            dfs(i, j, n, good, types);
        }
    }
    pair<pair<int, int>, char> end = upds[0];
    res.push_back(n * n - cur_good);
    reverse(upds.begin(), upds.end());
    for (auto& i : upds){
        if (i == end) break;
        types[i.first.first][i.first.second] = -1;
        dfs(i.first.first, i.first.second, n, good, types);
        res.push_back(n * n - cur_good);
    }
    reverse(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++){
        cout << res[i] << endl;
    }
}