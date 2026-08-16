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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> val(n + 1, vector<int> (n + 1, 0));
    int m = (n - k) + 1;
    vector<vector<int>> sum(m + 1, vector<int> (m + 1, 0));
    int x, y, num, Q;
    cin >> Q;
    int best_num = -1;
    for (int q = 0; q < Q; q++){
        cin >> x >> y >> num;
        int added = num - val[x][y];
        val[x][y] = num;
        for (int add_i = 0; add_i >= -(k - 1); add_i--){
            for (int add_j = 0; add_j >= -(k - 1); add_j--){
                int new_x = x + add_i, new_y = y + add_j;
                if (new_x >= 1 && new_x <= m && new_y >= 1 && new_y <= m){
                    sum[new_x][new_y] += added;
                    best_num = max(best_num, sum[new_x][new_y]);
                }
            }
        }
        cout << best_num << endl;
    }
}