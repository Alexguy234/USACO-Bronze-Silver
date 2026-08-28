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
pair<pair<int, int>, pair<int, int>> great(pair<int, int> a, pair<int, int> b){
    if (a.first > b.first) return {a, b};
    if (b.first > a.first) return {b, a};
    if (a.second > b.second) return {a, b};
    if (b.second > a.second) return {b, a};
}
int main(){
    ifstream fin ("gates.in");
    ofstream fout ("gates.out");
    int n;
    fin >> n;
    char temp;
    set<pair<int, int>> v;
    set<pair<pair<int, int>, pair<int, int>>> e;
    pair<int, int> prev = {0, 0}, cur = {0, 0};
    for (int i = 0; i < n; i++){
        fin >> temp;
        prev = cur;
        if (temp == 'N'){
            cur.second++;
        }
        else if (temp == 'E'){
            cur.first++;
        }
        else if (temp == 'W'){
            cur.first--;
        }
        else{
            cur.second--;
        }
        v.insert({prev.first, prev.second});
        e.insert(great(cur, prev));
    }
    v.insert({cur.first, cur.second});
    fout << (e.size() - v.size()) + 1 << endl;
}