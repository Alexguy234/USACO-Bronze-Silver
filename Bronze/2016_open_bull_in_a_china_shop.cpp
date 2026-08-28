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
int n, k;
vector<pair<int, int>> best_pair(11, {0, 0});
bool works(vector<vector<char>> piece1, vector<vector<char>> piece2, vector<vector<char>> wanted, int k1, int k2){
    for (int i1 = 0; i1 < n; i1++){
        for (int j1 = 0; j1 < n; j1++){
            for (int i2 = 0; i2 < n; i2++){
                for (int j2 = 0; j2 < n; j2++){
                    int old_i1 = i1, old_j1 = j1, old_i2 = i2, old_j2 = j2;
                    i1 = i1 - best_pair[k1].first;
                    j1 = j1 - best_pair[k1].second;
                    i2 = i2 - best_pair[k2].first;
                    j2 = j2 - best_pair[k2].second;
                    bool next_combo = false;
                    vector<vector<char>> res(n, vector<char> (n, '.'));
                    vector<vector<int>> times_put(n, vector<int> (n));
                    for (int i = 0; i < n; i++){
                        for (int j = 0; j < n; j++){
                            int new_i1 = i + i1, new_j1 = j + j1, new_i2 = i + i2, new_j2 = j + j2;
                            if (piece1[i][j] == '#'){
                                if (new_i1 < 0 || new_i1 >= n ||
                                    new_j1 < 0 || new_j1 >= n){
                                    next_combo = true;
                                    break;
                                }
                                times_put[new_i1][new_j1]++;
                                if (times_put[new_i1][new_j1] >= 2){
                                    next_combo = true;
                                    break;
                                }
                                res[new_i1][new_j1] = '#';
                            }
                            
                            if (piece2[i][j] == '#'){
                                if (new_i2 < 0 || new_i2 >= n ||
                                    new_j2 < 0 || new_j2 >= n){
                                    next_combo = true;
                                    break;
                                }
                                times_put[new_i2][new_j2]++;
                            
                                if (times_put[new_i2][new_j2] >= 2){
                                    next_combo = true;
                                    break;
                                }
                                res[new_i2][new_j2] = '#';
                            }
                        }
                        if (next_combo) break;
                    }
                    if (!next_combo){
                        if (res == wanted){
                            return true;
                        }
                    }
                    i1 = old_i1;
                    j1 = old_j1;
                    i2 = old_i2;
                    j2 = old_j2;
                }
            }
        }
    }
    return false;
}
int main(){
    ifstream fin ("bcs.in");
    ofstream fout ("bcs.out");
    fin >> n >> k;
    vector<vector<vector<char>>> pieces(k, vector<vector<char>>(n, vector<char>(n, '.')));
    vector<vector<char>> wanted(n, vector<char> (n, '.'));
    //remember to add 1 for the res
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            fin >> wanted[i][j];
        }
    }
    for (int l = 0; l < k; l++){
        bool best_pair_done = false;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                fin >> pieces[l][i][j];
                if (!best_pair_done && pieces[l][i][j] == '#'){
                    best_pair[l] = {i, j};
                    best_pair_done = true;
                }
            }
        }
    }

    for (int i = 0; i < k; i++){
        for (int j = 0; j < k; j++){
            if (i != j){
                if (works(pieces[i], pieces[j], wanted, i, j)){
                    fout << min(i, j) + 1 << ' ' << max(i, j) + 1 << endl;
                    return 0;
                }
            }
        }
    }
}

//changes: infinite loop, problem where i add both # positions to the result vector even if only one out of the two pieces works