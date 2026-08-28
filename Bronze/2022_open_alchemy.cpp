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
bool can_craft(int n, int k, vector<int> &r, vector<vector<int>> &craft){
    if (craft[n].empty()){
        return false;
    }
    for (auto& i : craft[n]){
        if (r[i] < 1){
            if (!can_craft(i, k, r, craft)){
                return false;
            }
        }
        else{
            r[i]--;
        }
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    vector<int> resources(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> resources[i];
    }
    int k;
    cin >> k;
    vector<vector<int>> craft(n + 1);
    int crafted;
    for (int i = 0; i < k; i++){
        int num, temp;
        cin >> crafted >> num;
        for (int j = 0; j < num; j++){
            cin >> temp;
            craft[crafted].push_back(temp);
        }
    }
    int ans = 0;
    while (can_craft(n, k, resources, craft)){
        resources[n]++;
    }
    cout << resources[n] << endl;
}