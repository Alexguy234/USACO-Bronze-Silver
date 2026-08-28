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
struct coor{
    int x, y;
};
int main(){
    ifstream fin ("perimeter.in");
    ofstream fout ("perimeter.out");
    int dir_x[] = {1, -1, 0, 0}, dir_y[] = {0, 0, 1, -1};
    int n;
    fin >> n;
    vector<vector<int>> grid(n + 1, vector<int> (n + 1, 0));
    char temp;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            fin >> temp;
            if (temp == '#'){
                grid[i][j] = 1;
            }
        }
    }
    vector<vector<bool>> visited(n + 1, vector<bool> (n + 1, 0));
    int best_area = -1, per = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (!visited[i][j] && grid[i][j]){
                int area = 0;
                queue<coor> q;
                visited[i][j] = true;
                q.push({i, j});
                vector<pair<int, int>> part_of_blob;
                while (!q.empty()){
                    coor cur = q.front();
                    q.pop();
                    area++;
                    part_of_blob.push_back({cur.x, cur.y});
                    for (int k = 0; k < 4; k++){
                        int new_x = cur.x + dir_x[k];
                        int new_y = cur.y + dir_y[k];
                        if (new_x >= 1 && new_x <= n && new_y >= 1 && new_y <= n
                            && !visited[new_x][new_y] && grid[new_x][new_y]){
                            q.push({new_x, new_y});
                            visited[new_x][new_y] = true;
                        }
                    }
                }
                if (area >= best_area){
                    int cnt = 0;
                    for (auto& i : part_of_blob){
                        for (int k = 0; k < 4; k++){
                            int new_x = i.first + dir_x[k];
                            int new_y = i.second + dir_y[k];
                            if (new_x <= 0 || new_x > n || new_y <= 0 || new_y > n){
                                cnt++;
                            }
                            else if (!grid[new_x][new_y]){
                                cnt++;
                            }
                        }
                    }
                    if (area == best_area){
                        per = min(per, cnt);
                    }
                    else{
                        per = cnt;
                        best_area = area;
                    }
                }
            }
        }
    }
    fout << best_area << " " << per << endl;
}