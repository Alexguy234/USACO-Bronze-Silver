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
    vector<int> cows(n);
    for (int i = 0; i < n; i++){
        cin >> cows[i];
    }
    int cnt = 1;
    for (int i = n - 2; i >= 0; i--){
        if (cows[i] > cows[i + 1]) break;
        cnt++;
    }
    cout << n - cnt << endl;
}