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
    long long n, m, k;
    cin >> n >> m >> k;
    vector<pair<long long, long long>> weights(n);
    for (long long i = 0; i < n; i++){
        cin >> weights[i].first >> weights[i].second;
    }
    sort(weights.begin(), weights.end());
    deque<pair<long long, long long>> towers;
    //bottom weight, number of towers with that
    long long ans = 0, towers_made = 0;
    for (auto& i : weights){
        long long at_most = i.first - k;
        while (!towers.empty() && towers.front().first <= at_most && i.second > 0){
            pair<long long, long long> cur = towers.front();
            if (i.second >= cur.second){
                towers.pop_front();
                if (!towers.empty() && towers.back().first == i.first){
                    towers.back().second += cur.second;
                }
                else{
                    towers.push_back({i.first, cur.second});
                }
                ans += cur.second;
                i.second -= cur.second;
            }
            else{
                towers.pop_front();
                towers.push_front({cur.first, cur.second - i.second});
                if (!towers.empty() && towers.back().first == i.first){
                    towers.back().second += i.second;
                }
                else{
                    towers.push_back({i.first, i.second});
                }
                ans += i.second;
                i.second = 0;
            }
        }
        if (towers_made < m && i.second > 0){
            if (m - towers_made >= i.second){
                if (!towers.empty() && towers.back().first == i.first){
                    towers.back().second += i.second;
                }
                else{
                    towers.push_back({i.first, i.second});
                }
                ans += i.second;
                towers_made += i.second;
            }
            else{
                if (!towers.empty() && towers.back().first == i.first){
                    towers.back().second += m - towers_made;
                }
                else{
                    towers.push_back({i.first, m - towers_made});
                }
                ans += m - towers_made;
                towers_made = m;
            }
        }
    }
    std::cout << ans << endl;
}