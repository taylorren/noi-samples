#include <iostream>
#include <map>
#include <cmath>
#include <vector>

using namespace std;

struct Member {
    int id;
    int power;
};

class FightClub {
public:
    void addMember(int id, int power);  // 新会员加入
    vector<pair<int, int>> getMatches(); // 获取比赛纪录

private:
    map<int, int> members; // 记录实力值与会员id的对应关系
    vector<pair<int, int>> matches; // 确保存储新旧会员的比赛纪录
};

void FightClub::addMember(int id, int power) {
    if (members.empty()) {
        members[power] = id;
    } else {
        auto it = members.lower_bound(power);
        if (it == members.begin()) {
            matches.emplace_back(id, it->second);
        } else if (it == members.end()) {
            --it;
            matches.emplace_back(id, it->second);
        } else {
            auto high = it;
            auto low = --it;
            if (abs(high->first - power) < abs(low->first - power) ||
                (abs(high->first - power) == abs(low->first - power) && high->first > power)) {
                matches.emplace_back(id, high->second);
            } else {
                matches.emplace_back(id, low->second);
            }
        }
        members[power] = id;
    }
}

vector<pair<int, int>> FightClub::getMatches() {
    return matches;
}

int main() {
    FightClub club;

    int n; // 会员总数
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int id, power;
        cin >> id >> power;
        club.addMember(id, power);
    }

    auto matches = club.getMatches();

    for (const auto& match : matches) {
        cout << match.first << " " << match.second << endl;
    }

    return 0;
}
