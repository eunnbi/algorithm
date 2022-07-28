#include <bits/stdc++.h>
using namespace std;

int N;
vector<tuple<string, int, int, int>> stu;

bool cmp(tuple<string, int, int, int>& a, tuple<string, int, int, int> &b) {
    string nameA, nameB;
    int korA, engA, mathA;
    int korB, engB, mathB;
    tie(nameA, korA, engA, mathA) = a;
    tie(nameB, korB, engB, mathB) = b;
    if (korA != korB) return korA > korB;
    else if (engA != engB) return engA < engB;
    else if (mathA != mathB) return mathA > mathB;
    else {
        int indexA = 0, indexB = 0;
        while (indexA < nameA.size() && indexB < nameB.size()) {
            if (nameA[indexA] == nameB[indexB]) {
                indexA++;
                indexB++;
                continue;
            }
            return nameA[indexA] < nameB[indexB];
        }
        return nameA.size() < nameB.size();
    }
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
     
    cin >> N;
    string name;
    int kor, eng, math;
    for (int i = 0; i < N; i++) {
        cin >> name >> kor >> eng >> math;
        stu.push_back({ name, kor, eng, math });
    }

    sort(stu.begin(), stu.end(), cmp);
    for (int i = 0; i < stu.size(); i++) {
        tie(name, kor, eng, math) = stu[i];
        cout << name << '\n';
    }

    return 0;
}