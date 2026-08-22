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
struct bounds{
    int min_x = INT_MAX, min_y = INT_MAX, max_x = INT_MIN, max_y = INT_MIN;
};
int main(){
    ifstream fin ("art.in");
    ofstream fout ("art.out");
    int n;
    fin >> n;
    map<int, bounds> bound;
    vector<vector<pair<int, int>>> coords(10);
    char temp;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            fin >> temp;
            temp = temp - '0';
            bound[temp].min_x = min(i, bound[temp].min_x);
            bound[temp].min_y = min(j, bound[temp].min_y);
            bound[temp].max_x = max(i, bound[temp].max_x);
            bound[temp].max_y = max(j, bound[temp].max_y);
            coords[temp].push_back({i, j});
        }
    }
    int ans = 0;
    for (int i = 1; i <= 9; i++){
        if (coords[i].empty()) continue;
        bool works = true;
        for (int j = 1; j <= 9 && j; j++){
            if (coords[j].empty()) continue;
            if (j == i) continue;
            for (auto& coord : coords[i]){
                if (coord.first >= bound[j].min_x && coord.first <= bound[j].max_x 
                && coord.second >= bound[j].min_y && coord.second <= bound[j].max_y){
                    works = false;
                    break;
                }
            }
            if (!works) break;
        }
        if (works) ans++;
    }
    fout << ans << endl;
}