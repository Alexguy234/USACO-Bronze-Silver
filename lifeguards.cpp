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
int main(){
    ifstream fin ("lifeguards.in");
    ofstream fout ("lifeguards.out");
    int n;
    fin >> n;
    vector<pair<int, int>> shifts(n);
    for (int i = 0; i < n; i++){
        fin >> shifts[i].first >> shifts[i].second;
    }
    if (n == 1){
        cout << shifts[0].second - shifts[0].first << endl;
        return 0;
    }
    sort(shifts.begin(), shifts.end());
    int ans = -1;
    for (int i = 0; i < n; i++){
        vector<pair<int, int>> temp;
        for (int j = 0; j < n; j++){
            if (j != i){
                temp.push_back(shifts[j]);
            }
        }
        int cnt = temp[n - 2].second - temp[0].first;
        for (int j = 1; j < n - 1; j++){
            if (temp[j].first > temp[j - 1].second){
                cnt -= temp[j].first - temp[j - 1].second;
            }
        }
        ans = max(ans, cnt);
    }
    fout << ans << endl;
}