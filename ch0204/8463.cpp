#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;

// 定义四个区域的相对位置
int map[5][2] = {{0, 0}, {0, 0}, {0, 1}, {1, 1}, {1, 0}};

// 处理坐标变换
void find_how(ll i, ll n, ll &x, ll &y) {
    if (i == 1 || i == 4) {  // 需要旋转的区域
        ll temp = x;
        x = y;
        y = temp;
    }
    if (i == 4) {  // 区域4需要额外翻转
        ll temp = pow(2, n);
        x = temp - x - 1;
        y = temp - y - 1;
    }
}

// 递归找到坐标
void find_xy(ll n, ll animal, ll &x, ll &y) {
    if (n == 0) return;
    
    // 计算每个区块的大小
    ll one_block = pow(2, 2 * (n - 1));
    
    // 找到所在区域
    ll i;
    for (i = 1; i <= 4; i++)
        if (one_block * i >= animal)
            break;
            
    // 递归处理子区域
    find_xy(n - 1, animal - (i - 1) * one_block, x, y);
    
    // 处理旋转
    find_how(i, n - 1, x, y);
    
    // 加上区域偏移
    x += pow(2, n - 1) * map[i][0];
    y += pow(2, n - 1) * map[i][1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        ll n, s, d;
        cin >> n >> s >> d;
        
        ll sx = 0, sy = 0, dx = 0, dy = 0;
        find_xy(n, s, sx, sy);
        find_xy(n, d, dx, dy);
        
        // 计算距离（每个房间10x10）
        ll ans = round(sqrt(pow((sx - dx), 2) + pow((sy - dy), 2)) * 10);
        cout << ans << endl;
    }
    return 0;
}