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
    
    if (diffs.size() == 1) return times[0]; // ���̰� 1�� ��� �״�� ����.

    int max = *max_element(diffs.begin(), diffs.end()); // �ִ� ���̵�

    //1���� �ִ볭�̵����� ������ �÷����� �ð� ����. limit ������ �����¼��� �ش� index=������ ����.
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

    //1�� ����
    diffs = {1, 5, 3};
    times = {2, 4, 7};
    limit = 30;
    expected = 3;
    if (solution(diffs, times, limit) == expected) cout << "����" << '\n';
    else cout << "����" << '\n';

    //2�� ����
    diffs = {1, 4, 4, 2};
    times = {6, 3, 8, 2};
    limit = 59;
    expected = 2;
    if (solution(diffs, times, limit) == expected) cout << "����" << '\n';
    else cout << "����" << '\n';

    //3�� ����
    diffs = {1, 328, 467, 209, 54};
    times = {2, 7, 1, 4, 3};
    limit = 1723;
    expected = 294;
    if (solution(diffs, times, limit) == expected) cout << "����" << '\n';
    else cout << "����" << '\n';

    //4�� ����
    diffs = {1, 99999, 100000, 99995};
    times = {9999, 9001, 9999, 9001};
    limit = 3456789012;
    expected = 39354;
    if (solution(diffs, times, limit) == expected) cout << "����" << '\n';
    else cout << "����" << '\n';

    return 0;
}