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
bool check(int k, int n, int tmax, vector<int> &order){
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++){
        pq.push(order[i]);
    }
    for (int i = k; i < n; i++){
        int time = pq.top();
        pq.pop();
        pq.push(time + order[i]);

    }
    int sum = 0;
    while (!pq.empty()){
        sum = max(sum, pq.top());
        pq.pop();
    }
    if (sum <= tmax) return true;
    return false;
}
int main(){
    ifstream fin ("cowdance.in");
    ofstream fout ("cowdance.out");
    int n, tmax;
    fin >> n >> tmax;
    vector<int> order(n);
    for (int i = 0; i < n; i++){
        fin >> order[i];
    }
    int l = 1, r = n, ans = n;
    while (l < r){
        int mid = (l + r) / 2;
        if (check(mid, n, tmax, order)){
            ans = min(mid, ans);
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    fout << ans << endl;
}