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
int n, k;
bool check(vector<int>& hay, int r){
    int cows = k, prev = 0;
    for (int x = 0; x < n; x++){
        if (prev < hay[x]){
            if (cows <= 0) return false;
            int mid = hay[x] + r;
            prev = mid + r;
            cows--;
        }
    }
    return true;
}
int main(){
    ifstream fin ("angry.in");
    ofstream fout ("angry.out");
    fin >> n >> k;
    vector<int> hay(n, 0);
    for (int i = 0; i < n; i++){
        fin >> hay[i];
    }
    sort(hay.begin(), hay.end());
    int l = 1, r = hay[n - 1], ans = hay[n - 1];
    while (l < r){
        int mid = (l + r) / 2;
        if (check(hay, mid)){
            r = mid;
            ans = min(ans, mid);
        }
        else{
            l = mid + 1;
        }
    }
    fout << ans << endl;
}