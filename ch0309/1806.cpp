#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string, string> dictionary;
    string line;

    // 读取词典部分
    while (getline(cin, line) && !line.empty())
    {
        istringstream iss(line);
        string english, foreign;
        iss >> english >> foreign;
        dictionary[foreign] = english;
    }

    // 读取文档部分并进行翻译
    vector<string> translated_document;
    while (getline(cin, line) && !line.empty())
    {
        if (dictionary.find(line) != dictionary.end())
        {
            translated_document.push_back(dictionary[line]);
        }
        else
        {
            translated_document.push_back("eh");
        }
    }

    // 输出翻译后的结果
    for (const string &word : translated_document)
    {
        cout << word << endl;
    }

    return 0;
}
