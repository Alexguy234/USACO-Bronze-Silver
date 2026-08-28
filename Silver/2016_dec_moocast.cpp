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
struct cow{
double x, y;
double power;
};
int main(){
    ifstream fin ("moocast.in");
    ofstream fout ("moocast.out");
    int n;
    fin >> n;
    vector<cow> cows(n);
    for (int i = 0; i < n; i++){
        fin >> cows[i].x >> cows[i].y >> cows[i].power;
    }
    int ans = -1;
    for (int i = 0; i < n; i++){
        int cnt = 1;
        vector<int> visited(n);
        queue<cow> q;
        q.push(cows[i]);
        visited[i] = true;
        while (!q.empty()){
            cow cur = q.front();
            q.pop();
            double x = cur.x, y = cur.y, power = cur.power;
            for (int i = 0; i < n; i++){
                if (!visited[i] && 
                sqrt((x - cows[i].x) * (x - cows[i].x) + (y - cows[i].y) * (y - cows[i].y)) <= power){
                    q.push(cows[i]);
                    visited[i] = true;
                    cnt++;
                }
            }
        }
        ans = max(ans, cnt);
    }
    fout << ans << endl;
}