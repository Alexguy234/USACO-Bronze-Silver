// USACO 2017 US Open Contest, Silver
// Problem 3. Where's Bessie?
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
struct Rectangle {
    int x1, y1, x2, y2;
};
int main(){
    int n;
    cin >> n;
    int dir_x[] = {1, -1, 0, 0};
    int dir_y[] = {0, 0, 1, -1};
    vector<vector<char>> image(n, vector<char> (n));
    char temp;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> temp;
            image[i][j] = temp;
        }
    }
    int ans = 0;
    vector<Rectangle> valid;
    for (int x1 = 0; x1 < n; x1++){
        for (int y1 = 0; y1 < n; y1++){
            for (int x2 = x1; x2 < n; x2++){
                for (int y2 = y1; y2 < n; y2++){
                    map<char, int> occ;
                    vector<vector<int>> visited(n, vector<int> (n, 0));
                    int stop = false;
                    for (int i = x1; i <= x2; i++){
                        for (int j = y1; j <= y2; j++){
                            if (visited[i][j]) continue;
                            visited[i][j] = true;
                            occ[image[i][j]]++;
                            if (occ.size() > 2) {
                                stop = true;
                                break;
                            }
                            int color = image[i][j];
                            queue<pair<int, int>> q;
                            q.push({i, j});
                            while (!q.empty()){
                                pair<int, int> cur = q.front();
                                q.pop();
                                for (int l = 0; l < 4; l++){
                                    int new_i = cur.first + dir_x[l];
                                    int new_j = cur.second + dir_y[l];
                                    if (new_i >= x1 && new_i <= x2 && new_j >= y1 && new_j <= y2 && 
                                    image[new_i][new_j] == color && !visited[new_i][new_j]){
                                        q.push({new_i, new_j});
                                        visited[new_i][new_j] = true;
                                    }
                                }
                            }
                        }
                        if (stop) break;
                    }
                    if (stop) continue;
                    int i = 0;
                    int num1 = 0, num2 = 0;
                    for (auto& l : occ){
                        if (i == 0) num1 = l.second;
                        else num2 = l.second;
                        i++;
                    }
                    if ((num1 == 1 && num2 >= 2) || (num1 >= 2 && num2 == 1))  valid.push_back({x1, y1, x2, y2});
                }
            }
        }
    }
    for (int i = 0; i < valid.size(); i++) {
        bool contained = false;
        for (int j = 0; j < valid.size(); j++) {
            if (i == j) continue;
            if (valid[j].x1 <= valid[i].x1 &&
                valid[j].y1 <= valid[i].y1 &&
                valid[j].x2 >= valid[i].x2 &&
                valid[j].y2 >= valid[i].y2) {
                contained = true;
                break;
            }
        }

        if (!contained) ans++;
    }
    cout << ans << endl;
}