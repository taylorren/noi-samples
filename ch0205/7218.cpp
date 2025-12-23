#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 205;  // 最大地图大小
char maze[MAXN][MAXN];  // 存储地图
int R, C;  // 地图的行数和列数
// 记录位置和到达该位置所需的时间
struct Point {
    int x, y, time;
    Point(int x = 0, int y = 0, int t = 0) : x(x), y(y), time(t) {}
};

// 四个方向：上、右、下、左
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

bool between(int low, int high, int v)
{
    return v>=low and v<=high-1;
}
// 判断坐标是否在迷宫内且可以走
bool isValid(int x, int y) {
    return (between(0,R, x)&&between(0,C, y)&&maze[x][y]!='#');
}

// 使用BFS寻找最短路径
int findPath(int startX, int startY) {
    bool visited[MAXN][MAXN] = {false};
    queue<Point> q;

    Point s = Point(startX, startY, 0);
    q.push(s);
    visited[startX][startY] = true;

    while(!q.empty()) {
        Point cur = q.front();
        q.pop();
        if(maze[cur.x][cur.y] == 'E') {
            return cur.time;
        }
        for(int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(isValid(nx, ny) && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push(Point(nx, ny, cur.time + 1));
            }
        }
    }
    return -1;
}

int main() {
    int T;
    cin >> T;  // 读入测试数据组数
    
    while(T--) {
        // 读入地图大小
        cin >> R >> C;
        
        int startX, startY;  // 起点坐标
        
        // 读入地图
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                cin >> maze[i][j];
                if(maze[i][j] == 'S') {
                    startX = i;
                    startY = j;
                }
            }
        }
        
        // 寻找最短路径
        int result = findPath(startX, startY);
        
        // 输出结果
        if(result == -1) {
            cout << "oop!" << endl;
        } else {
            cout << result << endl;
        }
    }
    
    return 0;
}