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
    long long l, n, rf, rb;
    fin >> l >> n >> rf >> rb;
    vector<pair<long long, long long>> stops(n);
    long long max_pos = 0;
    for (long long i = 0; i < n; i++){
        fin >> stops[i].first >> stops[i].second;
    }
    vector<long long> stops_to_use;
    long long best = -1;
    for (long long i = n - 1; i >= 0; i--){
        if (stops[i].second > best){
            best = stops[i].second;
            stops_to_use.push_back(i);
        }
    }
    reverse(stops_to_use.begin(), stops_to_use.end());
    long long ans = 0, prev_pos = -1;
    for (long long i : stops_to_use){
        if (prev_pos == -1){
            ans += stops[i].first * (rf - rb) * stops[i].second;
            prev_pos = stops[i].first;
        }
        else{
            long long temp = ((stops[i].first - prev_pos) * (rf - rb) * stops[i].second);
            ans += temp;
            prev_pos = stops[i].first;
        }
    }
    fout << ans << endl;
}