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
int ans = INT_MAX;
//optimize using memoization
vector<vector<vector<bool>>> dp(120, vector<vector<bool>>(105, vector<bool>(120, false)));
void dfs(int x, int y, int k, int m, int cur_x, int cur_y, int step){
    if (dp[cur_x][cur_y][step]) return;
    ans = min(ans, abs(m - (cur_x + cur_y)));
    dp[cur_x][cur_y][step] = true;
    if (step == k){
        return;
    }
    dfs(x, y, k, m, x, cur_y, step + 1);
    dfs(x, y, k, m, cur_x, y, step + 1);
    dfs(x, y, k, m, cur_x, 0, step + 1);
    dfs(x, y, k, m, 0, cur_y, step + 1);
    if (cur_x + cur_y > x){
        dfs(x, y, k, m, x, cur_y - (x - cur_x), step + 1);
    }
    else{
        dfs(x, y, k, m, cur_x + cur_y, 0, step + 1);
    }

    if (cur_y + cur_x > y){
        dfs(x, y, k, m, cur_x - (y - cur_y), y, step + 1);
    }
    else{
        dfs(x, y, k, m, 0, cur_y + cur_x, step + 1);
    }
}
int main(){
    ifstream fin ("pails.in");
    ofstream fout ("pails.out");
    int x, y, k, m;
    fin >> x >> y >> k >> m;
    dfs(x, y, k, m, 0, 0, 0);
    fout << ans << endl;
}