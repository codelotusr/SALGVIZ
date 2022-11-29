#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <chrono>
using namespace std;

class Lehmer {
public:
    Lehmer(unsigned int seed = 1) {
        setSeed(seed);
    }
    void setSeed(unsigned int seed) {
        if (seed == 0) {
            seed = 1;
        }
        x = seed;
    }
    unsigned int next() {
        x = (a * x + c) % m;
        return x;
    }
private:
    unsigned int x;
    static const unsigned int a = 48271;
    static const unsigned int c = 0;
    static const unsigned int m = 2147483647;
};

void generateRandomNumbers(vector<int> &v, int n, Lehmer &rng) {
    for (int i = 0; i < n; i++) {
        if (rng.next() != 0) {
            v.push_back(rng.next());
        }
    }
}

void quicksort(vector<int> &v, int left, int right) {
    int i = left;
    int j = right;
    int pivot = v[(left + right) / 2];
    while (i <= j) {
        while (v[i] < pivot) {
            i++;
        }
        while (v[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }
    if (left < j) {
        quicksort(v, left, j);
    }
    if (i < right) {
        quicksort(v, i, right);
    }
}

void shellsort(vector<int> &v) {
    int n = v.size();
    int h = 1;
    while (h < n / 9) {
        h = 3 * h + 1;
    }
    while (h >= 1) {
        for (int i = h; i < n; i++) {
            for (int j = i; j >= h && v[j] < v[j - h]; j -= h) {
                swap(v[j], v[j - h]);
            }
        }
        h /= 3;
    }
}

void printVector(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// generate random numbers in a descending order
void generateDescending(vector<int> &v, int n, Lehmer &rng) {
    for (int i = 0; i < n; i++) {
        if (rng.next() != 0) {
            v.push_back(rng.next());
        }
    }
    sort(v.begin(), v.end(), greater<int>());
}

int main() {
    Lehmer rng;
    rng.setSeed(time(0));
    std::vector<int> v(2500);
    std::vector<int> temp1(2500);
    std::vector<int> temp2(2500);
    unsigned int choice;
    bool exit = false;
    while (exit == false) {
        cout << "1. Generate random numbers" << endl;
        cout << "2. Sort random numbers using quicksort" << endl;
        cout << "3. Sort random numbers using shell sort" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            system("cls");
            generateRandomNumbers(v, 2500, rng);
            temp1 = v;
            temp2 = v;
            printVector(v);
            cout << "Random numbers generated" << endl;
        }
        else if (choice == 2) {
            system("cls");
            auto start = chrono::high_resolution_clock::now();
            quicksort(temp1, 0, temp1.size() - 1);
            auto finish = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed = finish - start;
            printVector(temp1);
            cout << "Quicksort took " << elapsed.count() << " seconds" << endl;
        }
        else if (choice == 3) {
            system("cls");
            auto start = chrono::high_resolution_clock::now();
            shellsort(temp2);
            auto finish = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed = finish - start;
            printVector(temp2);
            cout << "Shellsort took " << elapsed.count() << " seconds" << endl;
        }
        else if (choice == 4) {
            exit = true;
        }
        else {
            system("cls");
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}

