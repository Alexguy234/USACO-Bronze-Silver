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
    ifstream fin ("berries.in");
    ofstream fout ("berries.out");
    int n, k;
    fin >> n >> k;
    vector<int> t(n);
    int start = 0;
    for (int i = 0; i < n; i++){
        fin >> t[i];
        start = max(start, t[i]);
    }
    sort(t.begin(), t.end());
    int ans = 0;
    for (int x = 1; x <= start; x++){
        int num_can_make = 0;
        for (int i = 0; i < n; i++){
            num_can_make += (t[i] / x);
        }
        if (num_can_make < k / 2) {
            break;
        }
        if (num_can_make >= k){
            ans = max(ans, (k / 2) * x);
        }
        else{
            vector<int> baskets(num_can_make, x);
            for (int i = n - 1; i >= 0; i--){
                baskets.push_back(t[i] % x);
            }
            while (baskets.size() < k) {
                baskets.push_back(0);
            }
            sort(baskets.begin(), baskets.end());
            int sum = 0;
            for (int i = baskets.size() - k; i < (baskets.size() + (baskets.size() - k)) / 2; i++){
                sum += baskets[i];
            }
            ans = max(ans, sum);
        }
    }
    fout << ans << endl;
}