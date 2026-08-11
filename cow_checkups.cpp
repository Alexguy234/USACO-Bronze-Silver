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
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), res(n + 1, 0);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int num_same = 0;
    vector<int> pref_sums(n + 1, 0), suff_sums(n + 1, 0);
    for (int i = 1; i <= n; i++){
        cin >> b[i];
        if (b[i] == a[i]){
            num_same++;
            pref_sums[i] = pref_sums[i - 1] + 1;
        }
        else{
            pref_sums[i] = pref_sums[i - 1];
        }
    }
    //pref[r] - pref[l - 1]
    for (int i = 2; i <= n * 2; i++){
        int l = i / 2;
        int r = i - l;
        int same_after = 0;
        while (l >= 1 && r <= n){
            if (l == r){
                same_after += (a[l] == b[l]);
            }
            else{
                same_after += (a[l] == b[r]);
                same_after += (a[r] == b[l]);
            }
            int same_before = pref_sums[r] - pref_sums[l - 1];
            int total = (same_after - same_before) + num_same;
            res[total]++;
            l--;
            r++;
        }
    }
    for (auto& i : res){
        cout << i << endl;
    }
}