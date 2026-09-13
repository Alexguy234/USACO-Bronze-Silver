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
    ifstream fin ("reststops.in");
    ofstream fout ("reststops.out");
    int l, n, rf, rb;
    fin >> l >> n >> rf >> rb;
    vector<pair<int, int>> stops(n);
    int max_pos = 0;
    for (int i = 0; i < n; i++){
        fin >> stops[i].first >> stops[i].second;
    }
    vector<int> stops_to_use;
    int best = -1;
    for (int i = n - 1; i >= 0; i--){
        if (stops[i].second > best){
            best = stops[i].second;
            stops_to_use.push_back(i);
        }
    }
    reverse(stops_to_use.begin(), stops_to_use.end());
    int ans = 0, prev_pos = -1;
    for (int i : stops_to_use){
        if (prev_pos == -1){
            ans += stops[i].first * (rf - rb) * stops[i].second;
            prev_pos = stops[i].first;
        }
        else{
            ans += (stops[i].first - prev_pos) * (rf - rb) * stops[i].second;
        }
    }
    fout << ans << endl;
}