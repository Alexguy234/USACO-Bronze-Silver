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
    ifstream fin ("mowing.in");
    ofstream fout ("mowing.out");
    int n;
    fin >> n;
    map<char, pair<int, int>> dir_map = {{'N', {0, 1}}, {'E', {1, 0}}, {'S', {0, -1}}, {'W', {-1, 0}}};
    int ans = INT_MAX, x = 0, y = 0;
    vector<pair<char, int>> seq (n);
    map<pair<int, int>, int> visited;
    int time = 0;
    visited[{0, 0}] = 0;
    for (int i = 0; i < n; i++){
        fin >> seq[i].first >> seq[i].second;
        int add_x = dir_map[seq[i].first].first, add_y = dir_map[seq[i].first].second, added_time = seq[i].second;
        for (int j = 1; j <= added_time; j++){
            time++;
            x += add_x;
            y += add_y;
            if (visited[{x, y}] != 0 || (x == 0 && y == 0)){
                ans = min(ans, time - visited[{x, y}]);
                visited[{x, y}] = time;
            }
            else{
                visited[{x, y}] = time;
            }
        }
    }
    if (ans == INT_MAX){
        fout << -1 << endl;
        return 0;
    }
    fout << ans << endl;

}