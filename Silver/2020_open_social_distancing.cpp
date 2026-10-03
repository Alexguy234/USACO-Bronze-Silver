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
bool check(vector<pair<long long, long long>> &ranges, long long checked, long long n, long long m){
    long long num_cows = 0, prev_placed = LLONG_MIN;
    for (long long i = 0; i < m; i++){
        long long start;
        if (prev_placed + checked < ranges[i].first){
            start = ranges[i].first;
        }
        else{
            if (prev_placed + checked <= ranges[i].second){
                start = prev_placed + checked;
            }
            else{
                continue;
            }
        }
        long long can_place = (ranges[i].second - start) / checked + 1;
        num_cows += can_place;
        long long last_cow = start + ((can_place - 1) * checked);
        prev_placed = last_cow;
        if (num_cows >= n){
            return true;
        }
    }
    return false;
}
int main(){
    ifstream fin ("socdist.in");
    ofstream fout ("socdist.out");
    long long n, m;
    fin >> n >> m;
    vector<pair<long long, long long>> ranges(m);
    for (long long i = 0; i < m; i++){
        fin >> ranges[i].first >> ranges[i].second;
    }   
    sort(ranges.begin(), ranges.end());
    long long l = 1, r = ranges[m - 1].second, ans = -1;
    while (l < r){
        long long mid = (l + r) / 2;
        if (check(ranges, mid, n, m)){
            l = mid + 1;
            ans = max(ans, mid);
        }
        else{
            r = mid;
        }
    }
    fout << ans << endl;
}