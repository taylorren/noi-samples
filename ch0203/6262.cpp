#include <iostream>
#include <vector>
using namespace std;

bool has_infected_neighbor(const vector<vector<char>>& grid, int i, int j, int n) {
    if(i > 0 && grid[i-1][j] == '@') return true;      // 上
    if(i < n-1 && grid[i+1][j] == '@') return true;    // 下
    if(j > 0 && grid[i][j-1] == '@') return true;      // 左
    if(j < n-1 && grid[i][j+1] == '@') return true;    // 右
    return false;
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<char>> grid(n, vector<char>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    
    int m;
    cin >> m;
    
    // 从第2天开始模拟传染
    for(int day = 2; day <= m; day++) {
        vector<vector<char>> new_grid = grid;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '.') {  // 只有健康的人才可能被传染
                    if(has_infected_neighbor(grid, i, j, n)) {
                        new_grid[i][j] = '@';
                    }
                }
            }
        }
        
        grid = new_grid;
    }
    
    int infected = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == '@') {
                infected++;
            }
        }
    }
    
    cout << infected << endl;
    return 0;
}