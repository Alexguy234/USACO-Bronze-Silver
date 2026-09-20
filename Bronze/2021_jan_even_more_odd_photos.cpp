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
    int n;
    cin >> n;
    int even = 0, odd = 0;
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        if (temp % 2 == 0) even++;
        else odd++;
    }
    if (even == odd || even == odd + 1){
        cout << even + odd << endl;
        return 0;
    }
    while (even < odd && odd >= 2){
        odd -= 2;
        even++;
    }
    if (even == odd || even == odd + 1){
        cout << even + odd << endl;
        return 0;
    }
    if (even > odd){
        cout << 2 * odd + 1;
    }
}