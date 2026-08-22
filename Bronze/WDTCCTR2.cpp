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
    ifstream fin ("circlecross.in");
    ofstream fout ("circlecross.out");
    map<char, pair<int, int>> barn;
    map<char, bool> seen;
    char temp;
    for (int i = 0; i < 52; i++){
        fin >> temp;
        if (seen[temp]){
            barn[temp].second = i;
        }
        else{
            barn[temp].first = i;
            seen[temp] = true;
        }
    }
    int ans = 0;
    for (auto& i : barn){
        for (auto&j : barn){
            if (i != j){
                if ((i.second.first > j.second.first && i.second.second > j.second.second && i.second.first < j.second.second)
            || (i.second.first < j.second.first && i.second.second < j.second.second && j.second.first < i.second.second)){
                ans++;
            }
            }
        }
    }
    fout << ans / 2 << endl;
}