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
int helper(){
    int n;
    cin >> n;
    vector<int> log(n);
    bool edge_case = true;
    int sum = 0;
    for (int i = 0; i < n; i++){
        cin >> log[i];
        sum += log[i];
        if (i != 0 && log[i] != log[i - 1]){
            edge_case = false;
        }
    }
    if (edge_case){
        cout << 0 << endl;
        return 0;
    }
    int ans = INT_MAX;
    for (int i = 1; i <= sum; i++){
        bool problem = false;
        int steps = 0, temp = 0; 
        if (sum % i == 0){
            for (int j = 0; j < n; j++){
                temp += log[j];
                if (temp < i){
                    steps++;
                }
                else if (temp == i){
                    temp = 0;
                }
                else{
                    problem = true;
                    break;
                }
            }
            if (!problem){
                ans = min(ans, steps);
            }
        }
    }
    cout << ans << endl;
}
int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        helper();
    }
}
