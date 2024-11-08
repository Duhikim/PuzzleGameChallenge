#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long get_time(const vector<int>& diffs, const vector<int>& times, int lv) {
    long long time_prev = times[0];

    for (int i = 1; i < diffs.size(); i++) {
        if (lv >= diffs[i]) 
        {
            time_prev += times[i];
        }
        else 
        {
            time_prev = (diffs[i] - lv) * (time_prev + times[i]) + times[i];
        }
    }

    return time_prev;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    
    if (diffs.size() == 1) return times[0]; // 길이가 1인 경우 그대로 리턴.

    int max = *max_element(diffs.begin(), diffs.end()); // 최대 난이도

    //1부터 최대난이도까지 레벨을 올려가며 시간 측정. limit 안으로 들어오는순간 해당 index=레벨을 리턴.
    for (int i = 1; i <= max; i++)
    {
        if (get_time(diffs, times, i) <= limit)
        {
            // cout << i << '\n';
            return i;
        }
    }     
}

int main() {
    vector<int> diffs;
    vector<int> times;
    long long limit;
    int expected;

    //1번 테케
    diffs = {1, 5, 3};
    times = {2, 4, 7};
    limit = 30;
    expected = 3;
    if (solution(diffs, times, limit) == expected) cout << "정답" << '\n';
    else cout << "오답" << '\n';

    //2번 테케
    diffs = {1, 4, 4, 2};
    times = {6, 3, 8, 2};
    limit = 59;
    expected = 2;
    if (solution(diffs, times, limit) == expected) cout << "정답" << '\n';
    else cout << "오답" << '\n';

    //3번 테케
    diffs = {1, 328, 467, 209, 54};
    times = {2, 7, 1, 4, 3};
    limit = 1723;
    expected = 294;
    if (solution(diffs, times, limit) == expected) cout << "정답" << '\n';
    else cout << "오답" << '\n';

    //4번 테케
    diffs = {1, 99999, 100000, 99995};
    times = {9999, 9001, 9999, 9001};
    limit = 3456789012;
    expected = 39354;
    if (solution(diffs, times, limit) == expected) cout << "정답" << '\n';
    else cout << "오답" << '\n';

    return 0;
}