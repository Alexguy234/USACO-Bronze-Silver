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
void dfs(int x, int y, int k, int m, int cur_x, int cur_y, int step){
    ans = min(ans, abs(m - (x + y)));
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
        dfs(x, y, k, m, cur_x - (y - cur_y), 0, step + 1);
    }
    else{
        dfs(x, y, k, m, 0, cur_y + cur_x, step + 1);
    }
}
int main(){
    int x, y, k, m;
    cin >> x >> y >> k >> m;
    dfs(x, y, k, m, 0, 0, 0);
    cout << ans << endl;
}