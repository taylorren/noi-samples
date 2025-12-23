
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 80;
char map[MAXN][MAXN];
bool vis[MAXN][MAXN];

int dx[] = {0,0,0,-1,1};
int dy[] = {0,-1,1,0,0};

struct State {
    int x, y, step;
};

int w, h, sx, sy, ex, ey;

bool check(int x, int y) {
    if(x >= 0 && x <= w+1 && y >= 0 && y <= h+1 && !vis[x][y]) {
        if(map[x][y] == 'X') return x == ex && y == ey;
        return true;
    }
    return false;
}

void bfs() {
    queue<State> q;
    memset(vis, 0, sizeof(vis));
    
    q.push({sx,sy,0});
    vis[sx][sy] = 1;
    
    while(!q.empty()) {
        State cur = q.front();
        q.pop();
        
        for(int i = 1; i <= 4; i++) {
            State nxt = {cur.x + dx[i], cur.y + dy[i], cur.step + 1};
            
            while(check(nxt.x, nxt.y)) {
                if(nxt.x == ex && nxt.y == ey) {
                    printf("%d segments.\n", nxt.step);
                    return;
                }
                vis[nxt.x][nxt.y] = 1;
                q.push(nxt);
                nxt.x += dx[i];
                nxt.y += dy[i];
            }
        }
    }
    printf("impossible.\n");
}

int main() {
    int boardNum = 0;
    string line;
    
    while(scanf("%d%d", &w, &h) == 2) {
        if(!w && !h) break;
        
        printf("Board #%d:\n", ++boardNum);
        
        memset(map, ' ', sizeof(map));
        getchar();
        
        for(int i = 1; i <= h; i++) {
            getline(cin, line);
            for(int j = 1; j <= w; j++) map[j][i] = line[j-1];
        }
        
        int pairNum = 0;
        while(scanf("%d%d%d%d", &sx, &sy, &ex, &ey) == 4) {
            if(!sx && !sy && !ex && !ey) break;
            printf("Pair %d: ", ++pairNum);
            bfs();
        }
        printf("\n");
    }
    return 0;
}