#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 220;
struct MAZE {
    int Around[4];  // [0]:up [1]:down [2]:left [3]:right
} maze[MAXN][MAXN], Clear;

struct Point {
    int x, y, tot;
} cur;

int main() {
    memset(Clear.Around, 0, sizeof(Clear.Around));
    
    while(true) {
        // 初始化迷宫
        for(int i = 0; i < MAXN; i++)
            for(int j = 0; j < MAXN; j++)
                maze[i][j] = Clear;
                
        int Wall, Door;
        int F[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};  // 四个方向的移动
        int walked[MAXN][MAXN] = {};  // 记录到达每个点所需的最少门数
        int r = -1e8, c = -1e8;  // 记录最大的行和列
        
        scanf("%d%d", &Wall, &Door);
        if(Wall == -1 && Door == -1) break;
        
        // 处理墙
        for(int i = 0; i < Wall; i++) {
            int x, y, f, len;
            scanf("%d%d%d%d", &x, &y, &f, &len);
            for(int j = 0; j < len; j++) {
                if(f) {  // 垂直墙
                    maze[x][y+j].Around[0] = 1;
                    if(x-1 >= 0) maze[x-1][y+j].Around[1] = 1;
                    c = max(c, y+j+2);
                } else {  // 水平墙
                    maze[x+j][y].Around[2] = 1;
                    if(y-1 >= 0) maze[x+j][y-1].Around[3] = 1;
                    r = max(r, x+j+2);
                }
            }
        }
        
        // 处理门
        for(int i = 0; i < Door; i++) {
            int x, y, f;
            scanf("%d%d%d", &x, &y, &f);
            if(f) {  // 垂直门
                maze[x][y].Around[0] = 2;
                if(x-1 >= 0) maze[x-1][y].Around[1] = 2;
                c = max(c, y+2);
            } else {  // 水平门
                maze[x][y].Around[2] = 2;
                if(y-1 >= 0) maze[x][y-1].Around[3] = 2;
                r = max(r, x+2);
            }
        }
        
        double Nemox, Nemoy;
        scanf("%lf%lf", &Nemox, &Nemoy);
        
        // 检查Nemo是否在范围内
        if(Nemox < 0 || Nemox >= 200 || Nemoy < 0 || Nemoy >= 200) {
            printf("0\n");
            continue;
        }
        
        // BFS寻找最短路径
        cur.x = cur.y = cur.tot = 0;
        r = max(r, int(Nemox+2));
        c = max(c, int(Nemoy+2));
        
        queue<Point> q;
        q.push(cur);
        memset(walked, -1, sizeof(walked));
        walked[0][0] = 0;
        
        while(!q.empty()) {
            for(int i = 0; i < 4; i++) {
                Point next = q.front();
                cur = next;
                cur.x += F[i][0];
                cur.y += F[i][1];
                
                if(maze[next.x][next.y].Around[i] == 2) cur.tot++;
                
                if(cur.x < 0 || cur.x >= r || cur.y < 0 || cur.y >= c || 
                   (walked[cur.x][cur.y] <= cur.tot && walked[cur.x][cur.y] != -1) || 
                   maze[next.x][next.y].Around[i] == 1) continue;
                   
                walked[cur.x][cur.y] = cur.tot;
                q.push(cur);
            }
            q.pop();
        }
        
        printf("%d\n", walked[int(Nemox)][int(Nemoy)]);
    }
    return 0;
}