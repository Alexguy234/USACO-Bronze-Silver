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
vector<vector<int>> class_rankings;
bool check_cons(int a, int b, int n, int k){
    bool a_over_b = true, b_over_a = true;
    for (int i = 0; i < k; i++){
        bool seen_a = false;
        for (int j = 0; j < n; j++){
            if (class_rankings[i][j] == a){
                seen_a = true;
            }
            if (!seen_a && class_rankings[i][j] == b){
                a_over_b = false;
                break;
            }
        }
        if (a_over_b == false) break;
    }
    for (int i = 0; i < k; i++){
        bool seen_b = false;
        for (int j = 0; j < n; j++){
            if (class_rankings[i][j] == b){
                seen_b = true;
            }
            if (!seen_b && class_rankings[i][j] == a){
                b_over_a = false;
                break;
            }
        }
        if (b_over_a == false) break;
    }
    return a_over_b || b_over_a;
}
int main(){
    ifstream fin ("gymnastics.in");
    ofstream fout ("gymnastics.out");
    int k, n;
    fin >> k >> n;
    class_rankings.resize(k, vector<int>(n));
    for (int i = 0; i < k; i++){
        for (int j = 0; j < n; j++){
            fin >> class_rankings[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            if (check_cons(i, j, n, k)){
                ans++;
            }   
        }
    }
    fout << ans << endl;
}
