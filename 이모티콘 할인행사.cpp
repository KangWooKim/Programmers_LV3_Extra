// https://school.programmers.co.kr/learn/courses/30/lessons/150368?language=cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxPlusServiceSubscribers = 0;
int maxSales = 0;
vector<int> discounts = {10, 20, 30, 40};

// 각 이모티콘의 할인율에 따라 사용자의 반응을 계산하는 함수
void calculateResults(const vector<vector<int>>& users, const vector<int>& emoticons, const vector<int>& discountRates) {
    int plusServiceSubscribers = 0;
    int totalSales = 0;

    for (const auto& user : users) {
        int thresholdRate = user[0];
        int thresholdPrice = user[1];
        int userTotalPrice = 0;

        for (int i = 0; i < emoticons.size(); ++i) {
            if (discountRates[i] >= thresholdRate) {
                userTotalPrice += emoticons[i] * (100 - discountRates[i]) / 100;
            }
        }

        if (userTotalPrice >= thresholdPrice) {
            plusServiceSubscribers++;
        } else {
            totalSales += userTotalPrice;
        }
    }

    if (plusServiceSubscribers > maxPlusServiceSubscribers || (plusServiceSubscribers == maxPlusServiceSubscribers && totalSales > maxSales)) {
        maxPlusServiceSubscribers = plusServiceSubscribers;
        maxSales = totalSales;
    }
}

// 백트래킹을 이용해 모든 할인율 조합을 탐색하는 함수
void findBestDiscounts(const vector<vector<int>>& users, const vector<int>& emoticons, vector<int>& discountRates, int idx) {
    if (idx == emoticons.size()) {
        calculateResults(users, emoticons, discountRates);
        return;
    }

    for (int discount : discounts) {
        discountRates[idx] = discount;
        findBestDiscounts(users, emoticons, discountRates, idx + 1);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> discountRates(emoticons.size());
    findBestDiscounts(users, emoticons, discountRates, 0);
    return {maxPlusServiceSubscribers, maxSales};
}

int main() {
    vector<vector<int>> users1 = {{40, 10000}, {25, 10000}};
    vector<int> emoticons1 = {7000, 9000};
    vector<int> result1 = solution(users1, emoticons1);
    cout << "Result: [" << result1[0] << ", " << result1[1] << "]" << endl;

    vector<vector<int>> users2 = {{40, 2900}, {23, 10000}, {11, 5200}, {5, 5900}, {40, 3100}, {27, 9200}, {32, 6900}};
    vector<int> emoticons2 = {1300, 1500, 1600, 4900};
    vector<int> result2 = solution(users2, emoticons2);
    cout << "Result: [" << result2[0] << ", " << result2[1] << "]" << endl;

    return 0;
}
