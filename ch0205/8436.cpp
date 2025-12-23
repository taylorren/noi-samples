/*
 * 迷宫寻路问题：需要按顺序收集钥匙，可以选择性地消灭蛇
 * 使用优先队列的BFS来寻找最短路径
 * 状态包含：位置(x,y)、已收集钥匙数、已消灭的蛇的状态、当前用时
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#include<cmath>
#include<string>
#include<queue>
#define eps 1e-9
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
 
// 四个方向的移动：上下左右
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
 
const int maxn=100+10;
int n,m;  // n: 地图大小, m: 需要收集的钥匙数量
char mp[maxn][maxn];  // 地图
 
// 状态节点结构体
struct Node {
    int x,y;        // 当前位置
    int key;        // 已收集的钥匙数量
    int time;       // 当前用时
    int snake;      // 已消灭的蛇的状态（位运算）
    // 优先队列的比较函数，用时少的优先
    friend bool operator<(Node n1,Node n2) {
        return n2.time<n1.time;
    }
};
 
priority_queue<Node>Q;  // 优先队列，用于BFS
 
Node st,en;  // 起点和终点状态
 
// vis[x][y][key]: 标记是否访问过状态(x,y,key)
bool vis[maxn][maxn][11];
// snake[x][y]: 记录每条蛇的编号，用于位运算
int snake[maxn][maxn];
 
// 检查位置是否合法且可以移动
bool check(int x,int y) {
    if(x>=1&&x<=n&&y>=1&&y<=n&&mp[x][y]!='#')
        return true;
    return false;
}
 
// 检查是否已经消灭过某条蛇
int judge(Node p,int dd) {
    if(p.snake&(1<<dd))
        return 0;
    return 1;
}
 
// BFS搜索最短路径
int bfs() {
   int xx,yy;
   while(!Q.empty())  Q.pop();
   Node cur,next;
   memset(vis,false,sizeof(vis));
   vis[st.x][st.y][0]=true;
   Q.push(st);

   while(!Q.empty()) {
       cur=Q.top();
       Q.pop();
       
       // 到达终点且收集了所有钥匙
       if(cur.x==en.x&&cur.y==en.y&&cur.key==m)
            return cur.time;
            
       // 尝试四个方向移动
       for(int i=0;i<4;i++) {
           xx=cur.x+dx[i];
           yy=cur.y+dy[i];
           
           // 如果新位置合法且未访问过该状态
           if(check(xx,yy)&&!vis[xx][yy][cur.key]) {
                // 遇到下一个需要收集的钥匙
                if(mp[xx][yy]==cur.key+1+'0') {
                    vis[xx][yy][cur.key+1]=true;
                    next.x=xx,next.y=yy;
                    next.snake=cur.snake;
                    next.key=cur.key+1;
                    next.time=cur.time+1;
                    Q.push(next);
                }
                // 遇到蛇的处理
                else if(mp[xx][yy]=='S') {
                   // 如果这条蛇还没被消灭过
                   if(!(cur.snake&(1<<snake[xx][yy]))) {
                     next.x=xx,next.y=yy;
                     next.key=cur.key;
                     next.snake=cur.snake|(1<<snake[xx][yy]);  // 标记蛇被消灭
                     next.time=cur.time+2;  // 消灭蛇需要额外1分钟
                     vis[xx][yy][next.key]=true;
                     Q.push(next);
                   }
                   // 如果这条蛇已经被消灭过
                   else {
                        next.x=xx,next.y=yy;
                        next.key=cur.key;
                        next.snake=cur.snake;
                        next.time=cur.time+1;
                        vis[xx][yy][next.key]=true;
                        Q.push(next);
                    }
                }
               // 普通移动
               else {
                   next.x=xx,next.y=yy;
                   next.key=cur.key;
                   next.snake=cur.snake;
                   next.time=cur.time+1;
                   vis[xx][yy][next.key]=true;
                   Q.push(next);
               }
           }
       }
   }
   return -1;  // 无法到达终点
}
 
// 读取地图并初始化起点、终点和蛇的信息
void Read_Graph() {
    char str[maxn];
    memset(snake,-1,sizeof(snake));
    int cnt=0;  // 蛇的编号计数
    for(int i=1;i<=n;i++) {
        scanf("%s",str+1);
        for(int j=1;j<=n;j++) {
            mp[i][j]=str[j];
            if(mp[i][j]=='K') {  // 起点
                st.x=i;
                st.y=j;
                st.key=0;
                st.time=0;
                st.snake=0;
            }
            else if(mp[i][j]=='T') {  // 终点
                en.x=i;
                en.y=j;
                en.key=m;
            }
            else if(mp[i][j]=='S')  // 给每条蛇编号
              snake[i][j]=cnt++;
        }
    }
}
 
int main() {
     while(~scanf("%d%d",&n,&m)) {
        if(n==0&&m==0)  return 0;
        Read_Graph();
        int ans=bfs();
        if(ans==-1)
            printf("impossible\n");
        else
            printf("%d\n",ans);
     }
    return 0;
}
 
/*
示例输入：
3 2
K#T
.S.
21.
*/