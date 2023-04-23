#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
struct FitnessData {
    int duration;
    int client_id;
    int month;
    int year;
};
void task1() {
    cout << "---------------------" << endl;
    int p;
    cout << "Input p(10<p<50): ";
    cin >> p;
    cout << "---------------------" << endl;
    vector<FitnessData> data_list;
    ifstream fin("input.txt");
    FitnessData d;
    cout << "input.txt:" << endl;
    cout << "---------------------" << endl;
    while (fin >> d.duration >> d.client_id >> d.month >> d.year) {
        data_list.push_back(d);
        cout << d.duration << " " << d.client_id << " " << d.month << " " << d.year << endl;
    }
    fin.close();
    cout << "---------------------" << endl;
    map<int, vector<int>> year_month_data;
    for (FitnessData d : data_list) {
        int year = d.year;
        int month = d.month;
        int duration = d.duration;

        if (year_month_data.count(year) == 0) {
            year_month_data[year] = vector<int>(13, 0);
        }

        year_month_data[year][month] += duration;
        year_month_data[year][0] += duration;
    }
    vector<pair<int, int>> result;
    for (auto year : year_month_data) {
        int sum_year = year.second[0];
        bool flag = false;
        for (int i = 1; i <= 12; i++) {
            int sum_month = year.second[i];
            if (sum_month > (sum_year * p / 100.0)) {
                flag = true;
                year.second[i] = 1;
            }
            else {
                year.second[i] = 0;
            }
        }
        if (flag) {
            int count_month = count(year.second.begin() + 1, year.second.end(), 1);
            result.push_back(make_pair(count_month, year.first));
        }
        else {
            result.push_back(make_pair(0, year.first));
        }
    }
    stable_sort(result.begin(), result.end(), [](auto a, auto b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        else {
            return a.first > b.first;
        }
        });
    ofstream fout("output.txt");
    cout << "output.txt:"<<endl;
    for (auto r : result) {
        fout << r.first << " " << r.second << endl;
        cout << r.first << " " << r.second << endl;
    }
    fout.close();
    cout << "---------------------" << endl;
}

