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
set<int> dis;
void dfs(int step, vector<int>& sizes1, vector<int>& sizes2, int tank1, int tank2){
    if (step == 6){
        dis.insert(tank1);
        return;
    }
    if (step % 2 == 0){
        for (int i = 0; i < sizes1.size(); i++){
            vector<int> copy = sizes1;
            copy.push_back(sizes1[i]);
            dfs(step + 1, sizes1, copy, tank1 - sizes1[i], tank2 + sizes1[i]);
        }
    }
    else{
        for (int i = 0; i < sizes2.size(); i++){
            vector<int> copy = sizes2;
            copy.push_back(sizes2[i]);
            dfs(step + 1, copy, sizes2, tank1 + sizes2[i], tank2 - sizes2[i]);
        }
    }
}
int main(){
    ifstream fin ("backforth.in");
    ofstream fout ("backforth.out");
    vector<int> sizes1(10), sizes2(10);
    for (int i = 0; i < 10; i++){
        fin >> sizes1[i];
    }
    for (int i = 0; i < 10; i++){
        fin >> sizes2[i];
    }
    dfs(2, sizes1, sizes2, 1000, 1000);
    fout << dis.size() << endl;
}