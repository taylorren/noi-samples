#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 100001;
bool visited[MAXN];

// TODO: 定义Point结构体
// 需要存储：
// 1. 位置pos
// 2. 到达该位置的时间time
struct Point {
    int pos, step;
    Point(int _pos, int _step) : pos(_pos), step(_step) {}
};

// TODO: 实现isValid函数
// 检查位置是否在合法范围内且未访问过
bool isValid(int pos) {
    return (pos>=0&&pos<MAXN && !visited[pos]);
}

// TODO: 实现BFS函数
// 从起点N到终点K的最短时间
int bfs(int N, int K) {
    // 完成此函数
    for(int i=0;i<MAXN;i++)
    {
        visited[i]=false;
    }

    queue<Point> q;
    q.push(Point(N,0));
    visited[N]=true;

    while(!q.empty())
    {
        Point cur=q.front();
        q.pop();

        if(cur.pos==K)
        {
            return cur.step;
        }

        //一种移动：前后跳跃
        if(isValid(cur.pos-1))
        {
            q.push(Point(cur.pos-1,cur.step+1));
            visited[cur.pos-1]=true;
        }
        if(isValid(cur.pos+1))
        {
            q.push(Point(cur.pos+1,cur.step+1));
            visited[cur.pos+1]=true;
        }
        //第二种移动：翻倍
        if(isValid(2*cur.pos))
        {
            q.push(Point(2*cur.pos,cur.step+1));
            visited[2*cur.pos]=true;
        }
    }
    return -1;
}

int main() {
    int N, K;
    cin >> N >> K;
    cout << bfs(N, K) << endl;
    return 0;
}
