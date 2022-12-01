#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <chrono>
#include <iomanip>
#include <random>
#include <fstream>
#include <functional>
#include <string>

const unsigned int s1{100000}, s2{200000}, s3{300000}, s4{400000}, s5{500000};
const unsigned int testAmount{10};
const unsigned int testAmountDescending{10};
class Timer
{
    private: 
        std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
        std::chrono::duration<float> duration;
    public:
        void startClock()
        {
            start = std::chrono::high_resolution_clock::now();
        }
        void endClock()
        {
            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
        }
        float getDuration()
        {
            return duration.count();
        }
};

std::vector<std::vector<int>> generateRandomVector();
void sortDescending(std::vector<std::vector<int>> &v);
int medianOfThree(std::vector<int> &v, int left, int right);
int partition(std::vector<int> &v, int left, int right);
void quickSort(std::vector<int> &v, int left, int right);
void quickSortTest(std::vector<std::vector<int>> v, std::ofstream& out, const unsigned int size, Timer &t, std::string whichVector);
std::vector<int> sedgewickSequence(const unsigned int size);
void shellSort(std::vector<int> &v);
void shellSortTest(std::vector<std::vector<int>> v, std::ofstream& out, const unsigned int size, Timer &t, std::string whichVector);

std::vector<std::vector<int>> generateRandomVector() {
    std::vector<std::vector<int>> vv;
    const unsigned int s1(2500), s2(5000), s3(7777), s4(20001), s5(496281);
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1,10000);
    auto generate = std::bind ( distribution, generator );
    std::vector<int> v1; std::vector<int> v2; std::vector<int> v3; std::vector<int> v4; std::vector<int> v5;
    for (int i = 0; i < s1; i++) {
        v1.push_back(generate());
    }
    for (int i = 0; i < s2; i++) {
        v2.push_back(generate());
    }
    for (int i = 0; i < s3; i++) {
        v3.push_back(generate());
    }
    for (int i = 0; i < s4; i++) {
        v4.push_back(generate());
    }
    for (int i = 0; i < s5; i++) {
        v5.push_back(generate());
    }
    vv.push_back(v1);
    vv.push_back(v2);
    vv.push_back(v3);
    vv.push_back(v4);
    vv.push_back(v5);
    return vv;
}

void sortDescending(std::vector<std::vector<int>> &v) {
    for (int i = 0; i < v.size(); i++) {
        std::sort(v[i].begin(), v[i].end(), std::greater<int>());
    }
}

int medianOfThree(std::vector<int> &v, int left, int right) {
    int mid = (left + right) / 2;
    if (v[left] > v[mid]) {
        std::swap(v[left], v[mid]);
    }
    if (v[left] > v[right]) {
        std::swap(v[left], v[right]);
    }
    if (v[mid] > v[right]) {
        std::swap(v[mid], v[right]);
    }
    return mid;
}

int partition(std::vector<int> &v, int left, int right) {
    int pivot = medianOfThree(v, left, right);
    int i = left;
    int j = right;
    while (i < j) {
        while (v[i] <= v[pivot] && i < right) {
            i++;
        }
        while (v[j] > v[pivot]) {
            j--;
        }
        if (i < j) {
            std::swap(v[i], v[j]);
        }
    }
    std::swap(v[pivot], v[j]);
    return j;
}

void quickSort(std::vector<int> &v, int left, int right) {
    if (left < right) {
        int pivot = partition(v, left, right);
        quickSort(v, left, pivot - 1);
        quickSort(v, pivot + 1, right);
    }
}

void quickSortTest(std::vector<int> v, std::ofstream& out, const unsigned int size, Timer &t, std::string whichVector) {
    std::vector<int> temp;
    for (size_t i{0}; i < size; i++) {
        temp = v;
        t.startClock();
        quickSort(v, 0, v.size() - 1);
        t.endClock();
        std::cout << std::fixed << std::setprecision(6) << whichVector << " vector QuickSort using rule of three took : " << t.getDuration() << " seconds" << std::endl;
        out << std::fixed << std::setprecision(6) << whichVector << " vector QuickSort using rule of three took : " << t.getDuration() << std::endl;
    }
}

std::vector<int> sedgewickSequence(const unsigned int n) {
    std::vector<int> v;
    int k{0};
    int gap{0};
    while (gap < n) {
        if (k % 2 == 0) {
            gap = 9 * (pow(2, k) - pow(2, k / 2)) + 1;
        } else {
            gap = 8 * pow(2, k) - 6 * pow(2, (k + 1) / 2) + 1;
        }
        v.push_back(gap);
        k++;
    }
    return v;
}

void shellSort(std::vector<int> &v) {
    std::vector<int> gaps = sedgewickSequence(v.size());
    for (int i = gaps.size() - 1; i >= 0; i--) {
        for (int j = gaps[i]; j < v.size(); j++) {
            int temp = v[j];
            int k;
            for (k = j; k >= gaps[i] && v[k - gaps[i]] > temp; k -= gaps[i]) {
                v[k] = v[k - gaps[i]];
            }
            v[k] = temp;
        }
    }
}

void shellSortTest(std::vector<int> &v, std::ofstream& out, const unsigned int size, Timer &t, std::string whichVector) {
    std::vector<int> temp;
    for (size_t i{0}; i < size; i++) {
        temp = v;
        t.startClock();
        shellSort(temp);
        t.endClock();
        std::cout << std::fixed << std::setprecision(6) << whichVector << " vector ShellSort took : " << t.getDuration() << " seconds" << std::endl;
        out << std::fixed << std::setprecision(6) << whichVector << " vector ShellSort took : " << t.getDuration() << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> vv = generateRandomVector();
    std::vector<std::vector<int>> dv = generateRandomVector();
    sortDescending(dv);
    Timer t;
    std::ofstream file("time.txt");
    std::vector<int> v1 = vv[0]; std::vector<int> v2 = vv[1]; std::vector<int> v3 = vv[2]; std::vector<int> v4 = vv[3]; std::vector<int> v5 = vv[4];
    std::cout << "Random vectors" << std::endl;
    std::cout << "QUICKSORT USING RULE OF THREE" << std::endl;
    std::cout << "\nVector size: " << s1 << std::endl;
    file << "Random vectors" << std::endl;
    file << "QUICKSORT USING RULE OF THREE" << std::endl;
    file << "\nVector size: " << s1 << std::endl;
    quickSortTest(v1, file, testAmount, t, "First"); 
    std::cout << "\nVector size: " << s2 << std::endl;
    file << "\nVector size: " << s2 << std::endl;
    quickSortTest(v2, file, testAmount, t, "Second");
    std::cout << "\nVector size: " << s3 << std::endl;
    file << "\nVector size: " << s3 << std::endl;
    quickSortTest(v3, file, testAmount, t, "Third");
    std::cout << "\nVector size: " << s4 << std::endl;
    file << "\nVector size: " << s4 << std::endl;
    quickSortTest(v4, file, testAmount, t, "Fourth");
    std::cout << "\nVector size: " << s5 << std::endl;
    file << "\nVector size: " << s5 << std::endl;
    quickSortTest(v5, file, testAmount, t, "Fifth");
    v1.clear(); v2.clear(); v3.clear(); v4.clear(); v5.clear();
    v1 = vv[0]; v2 = vv[1]; v3 = vv[2]; v4 = vv[3]; v5 = vv[4];
    std::cout << "\n\nSHELLSORT USING SEDGEWICK'S GAPS" << std::endl;
    file << "\n\nSHELLSORT USING SEDGEWICK'S GAPS" << std::endl;
    std::cout << "\nVector size: " << s1 << std::endl;
    file << "\nVector size: " << s1 << std::endl;
    shellSortTest(v1, file, testAmount, t, "First");
    std::cout << "\nVector size: " << s2 << std::endl;
    file << "\nVector size: " << s2 << std::endl;
    shellSortTest(v2, file, testAmount, t, "Second");
    std::cout << "\nVector size: " << s3 << std::endl;
    file << "\nVector size: " << s3 << std::endl;
    shellSortTest(v3, file, testAmount, t, "Third");
    std::cout << "\nVector size: " << s4 << std::endl;
    file << "\nVector size: " << s4 << std::endl;
    shellSortTest(v4, file, testAmount, t, "Fourth");
    std::cout << "\nVector size: " << s5 << std::endl;
    file << "\nVector size: " << s5 << std::endl;
    shellSortTest(v5, file, testAmount, t, "Fifth");
    v1.clear(); v2.clear(); v3.clear(); v4.clear(); v5.clear();
    v1 = dv[0]; v2 = dv[1]; v3 = dv[2]; v4 = dv[3]; v5 = dv[4];
    std::cout << "\n\nDescending random vectors" << std::endl;
    std::cout << "QUICKSORT USING RULE OF THREE" << std::endl;
    std::cout << "\nVector size: " << s1 << std::endl;
    file << "\n\nDescending random vectors" << std::endl;
    file << "\n\nQUICKSORT USING RULE OF THREE" << std::endl;
    file << "\nVector size: " << s1 << std::endl;
    quickSortTest(v1, file, testAmountDescending, t, "First");
    std::cout << "\nVector size: " << s2 << std::endl;
    file << "\nVector size: " << s2 << std::endl;
    quickSortTest(v2, file, testAmountDescending, t, "Second");
    std::cout << "\nVector size: " << s3 << std::endl;
    file << "\nVector size: " << s3 << std::endl;
    quickSortTest(v3, file, testAmountDescending, t, "Third");
    std::cout << "\nVector size: " << s4 << std::endl;
    file << "\nVector size: " << s4 << std::endl;
    quickSortTest(v4, file, testAmountDescending, t, "Fourth");
    std::cout << "\nVector size: " << s5 << std::endl;
    file << "\nVector size: " << s5 << std::endl;
    quickSortTest(v5, file, testAmountDescending, t, "Fifth");
    v1.clear(); v2.clear(); v3.clear(); v4.clear(); v5.clear();
    v1 = dv[0]; v2 = dv[1]; v3 = dv[2]; v4 = dv[3]; v5 = dv[4];
    std::cout << "\n\nSHELLSORT USING SEDGEWICK'S GAPS" << std::endl;
    file << "\n\nSHELLSORT USING SEDGEWICK'S GAPS" << std::endl;
    std::cout << "\nVector size: " << s1 << std::endl;
    file << "\nVector size: " << s1 << std::endl;
    shellSortTest(v1, file, testAmountDescending, t, "First");
    std::cout << "\nVector size: " << s2 << std::endl;
    file << "\nVector size: " << s2 << std::endl;
    shellSortTest(v2, file, testAmountDescending, t, "Second");
    std::cout << "\nVector size: " << s3 << std::endl;
    file << "\nVector size: " << s3 << std::endl;
    shellSortTest(v3, file, testAmountDescending, t, "Third");
    std::cout << "\nVector size: " << s4 << std::endl;
    file << "\nVector size: " << s4 << std::endl;
    shellSortTest(v4, file, testAmountDescending, t, "Fourth");
    std::cout << "\nVector size: " << s5 << std::endl;
    file << "\nVector size: " << s5 << std::endl;
    shellSortTest(v5, file, testAmountDescending, t, "Fifth");
    v1.clear(); v2.clear(); v3.clear(); v4.clear(); v5.clear();
    vv.clear(); dv.clear();
    std::vector<std::vector<int>>().swap(vv);
    std::vector<std::vector<int>>().swap(dv);
    std::vector<int>().swap(v1); std::vector<int>().swap(v2); std::vector<int>().swap(v3); std::vector<int>().swap(v4); std::vector<int>().swap(v5);
    file.close();
    std::cout << "Press 'ENTER' to exit" << std::endl;
    std::cin.get();
    return 0;
}

