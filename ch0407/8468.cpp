#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <sstream>
using namespace std;

// 寻找从beginWord到endWord的最短转换序列长度
int findShortestPath(string beginWord, string endWord, vector<string> &wordList)
{
    // 建立单词集合，方便查找
    unordered_set<string> dict(wordList.begin(), wordList.end());
    dict.insert(endWord);

    // 队列中存储<当前单词, 路径长度>
    queue<pair<string, int>> q;
    q.push({beginWord, 1}); // 起始单词，长度为1

    // 记录已经访问过的单词
    unordered_set<string> visited;
    visited.insert(beginWord);

    // BFS搜索
    while (!q.empty())
    {
        string currWord = q.front().first; // 当前要处理的单词
        int length = q.front().second;     // 当前路径长度
        q.pop();

        // 找到目标单词
        if (currWord == endWord)
        {
            return length;
        }

        // 尝试改变当前单词的每个字母
        for (int i = 0; i < currWord.length(); i++)
        {
            string newWord = currWord;
            // 尝试替换为a-z的每个字母
            for (char c = 'a'; c <= 'z'; c++)
            {
                newWord[i] = c; // 改变一个字母

                // 如果新单词在词典中且未访问过
                if (dict.find(newWord) != dict.end() &&
                    visited.find(newWord) == visited.end())
                {
                    visited.insert(newWord);       // 标记为已访问
                    q.push({newWord, length + 1}); // 加入队列
                }
            }
        }
    }

    return 0; // 找不到转换序列
}

int main()
{
    // 读入起始单词和目标单词
    string beginWord, endWord;
    cin >> beginWord >> endWord;

    // 读入词典
    string line;
    cin.ignore(); // 忽略第一行剩余的换行符
    getline(cin, line);

    // 将词典字符串分割成单词
    vector<string> wordList;
    stringstream ss(line);
    string word;
    while (ss >> word)
    {
        wordList.push_back(word);
    }

    // 输出结果
    cout << findShortestPath(beginWord, endWord, wordList) << endl;

    return 0;
}