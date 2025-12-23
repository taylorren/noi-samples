#include <bits/stdc++.h>

using namespace std;
const int N = 25;

int n, ans = 0;
string str[N];
int cnt[N];//单词使用次数

//求这两个单词的重叠长度
int check(string s1, string s2) {
    //看s2能不能接在s1的屁股后面，也就是：s2单词的头部的部分是s1单词的尾部的部分

    //倒着找到一个重叠肯定就是最优，尽可能让重叠部分很少的两个单词拼接到一块
    for (int i = s1.size() - 1; i >= 0; --i) {
        if (s1[i] == s2[0]) {
            //标记重叠部分在s1开始的索引
            int index = i;
            //找到了可能是重叠部分的头部了，向后扫描
            for (int j = 0; j < s2.size(); ++j) {
                if (s1[index] == s2[j]) index++;
                else break;
            }
            //说明重叠部分相同
            if (index == s1.size()) {
            	//返回重叠部分的长度
                return index - i;
            }
        }
    }

    //这两个单词不可以相连，也就是没有重叠的
    return 0;
}

//s是之前接好的龙，len是当前接龙的总长度
void dfs(string s, int len) {
    ans = max(ans, len);
    //枚举每个单词
    for (int i = 0; i < n; ++i) {
        //第i个单词是否已经使用两次
        if (cnt[i] == 2)
            continue;
        //l为这两个单词重叠的长度
        int l = check(s, str[i]);
        if (l) {
            cnt[i]++;
            //以当前新字符串当结尾开始向后连接
            //len + str[i].size() - l ：当前最大长度加上拼接上来的长度（去除重叠）
            dfs(str[i], len + str[i].size() - l);
            cnt[i]--;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> str[i];
    }
    string start;
    cin >> start;
    dfs(start, 1);
    cout << ans;
    return 0;
}

