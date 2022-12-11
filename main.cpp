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

const unsigned int s1{10000000}, s2{25000000}, s3{50000000}, s4{75000000}, s5{100000000};
const unsigned int testAmount{10};
const unsigned int testAmountDescending{10};
const unsigned int vectorAmount{5};
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
        }
        float getDuration()
        {
            duration = end - start;
            return duration.count();
        }
};

// std::vector<std::vector<int>> generateRandomVector();
std::vector<std::vector<std::vector<int>>> multiGenerateRandomVectors();
void sortDescending(std::vector<std::vector<std::vector<int>>> &vvv);
int medianOfThree(std::vector<int> &v, int left, int right);
int partition(std::vector<int> &v, int left, int right);
void whatVectorSize(std::string size, std::ofstream& out);
void quickSort(std::vector<int> &v, int left, int right);
void quickSortTest(std::vector<std::vector<int>> v, std::ofstream& out, const unsigned int size, Timer &t, std::string whichVector);
std::vector<int> sedgewickSequence(const unsigned int size);
void shellSort(std::vector<int> &v);
void shellSortTest(std::vector<std::vector<int>> v, std::ofstream& out, const unsigned int size, Timer &t, std::string whichVector);


std::vector<std::vector<std::vector<int>>> multiGenerateRandomVectors() {
    std::vector<std::vector<std::vector<int>>> vvv;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1,100000);
    auto generate = std::bind ( distribution, generator );
    std::vector<std::vector<int>> vv1; std::vector<std::vector<int>> vv2; std::vector<std::vector<int>> vv3; std::vector<std::vector<int>> vv4; std::vector<std::vector<int>> vv5;
    for (int i = 0; i < vectorAmount; i++) {
        std::vector<int> v1; std::vector<int> v2; std::vector<int> v3; std::vector<int> v4; std::vector<int> v5;
        for (int j = 0; j < s1; j++) {
            v1.push_back(generate());
        }
        for (int j = 0; j < s1; j++) {
            v2.push_back(generate());
        }
        for (int j = 0; j < s1; j++) {
            v3.push_back(generate());
        }
        for (int j = 0; j < s1; j++) {
            v4.push_back(generate());
        }
        for (int j = 0; j < s1; j++) {
            v5.push_back(generate());
        }
        vv1.push_back(v1);
        vv1.push_back(v2);
        vv1.push_back(v3);
        vv1.push_back(v4);
        vv1.push_back(v5);
    }
    vvv.push_back(vv1);

    for (int i = 0; i < vectorAmount; i++) {
        std::vector<int> v1; std::vector<int> v2; std::vector<int> v3; std::vector<int> v4; std::vector<int> v5;
        for (int j = 0; j < s2; j++) {
            v1.push_back(generate());
        }
        for (int j = 0; j < s2; j++) {
            v2.push_back(generate());
        }
        for (int j = 0; j < s2; j++) {
            v3.push_back(generate());
        }
        for (int j = 0; j < s2; j++) {
            v4.push_back(generate());
        }
        for (int j = 0; j < s2; j++) {
            v5.push_back(generate());
        }
        vv2.push_back(v1);
        vv2.push_back(v2);
        vv2.push_back(v3);
        vv2.push_back(v4);
        vv2.push_back(v5);
    }
    vvv.push_back(vv2);

    for (int i = 0; i < vectorAmount; i++) {
        std::vector<int> v1; std::vector<int> v2; std::vector<int> v3; std::vector<int> v4; std::vector<int> v5;
        for (int j = 0; j < s3; j++) {
            v1.push_back(generate());
        }
        for (int j = 0; j < s3; j++) {
            v2.push_back(generate());
        }
        for (int j = 0; j < s3; j++) {
            v3.push_back(generate());
        }
        for (int j = 0; j < s3; j++) {
            v4.push_back(generate());
        }
        for (int j = 0; j < s3; j++) {
            v5.push_back(generate());
        }
        vv3.push_back(v1);
        vv3.push_back(v2);
        vv3.push_back(v3);
        vv3.push_back(v4);
        vv3.push_back(v5);
    }
    vvv.push_back(vv3);

    for (int i = 0; i < vectorAmount; i++) {
        std::vector<int> v1; std::vector<int> v2; std::vector<int> v3; std::vector<int> v4; std::vector<int> v5;
        for (int j = 0; j < s4; j++) {
            v1.push_back(generate());
        }
        for (int j = 0; j < s4; j++) {
            v2.push_back(generate());
        }
        for (int j = 0; j < s4; j++) {
            v3.push_back(generate());
        }
        for (int j = 0; j < s4; j++) {
            v4.push_back(generate());
        }
        for (int j = 0; j < s4; j++) {
            v5.push_back(generate());
        }
        vv4.push_back(v1);
        vv4.push_back(v2);
        vv4.push_back(v3);
        vv4.push_back(v4);
        vv4.push_back(v5);
    }
    vvv.push_back(vv4);

    for (int i = 0; i < vectorAmount; i++) {
        std::vector<int> v1; std::vector<int> v2; std::vector<int> v3; std::vector<int> v4; std::vector<int> v5;
        for (int j = 0; j < s5; j++) {
            v1.push_back(generate());
        }
        for (int j = 0; j < s5; j++) {
            v2.push_back(generate());
        }
        for (int j = 0; j < s5; j++) {
            v3.push_back(generate());
        }
        for (int j = 0; j < s5; j++) {
            v4.push_back(generate());
        }
        for (int j = 0; j < s5; j++) {
            v5.push_back(generate());
        }
        vv5.push_back(v1);
        vv5.push_back(v2);
        vv5.push_back(v3);
        vv5.push_back(v4);
        vv5.push_back(v5);
    }
    vvv.push_back(vv5);

    return vvv;

}

// std::vector<std::vector<int>> generateRandomVector() {
//     std::vector<std::vector<int>> vv;
//     std::default_random_engine generator;
//     std::uniform_int_distribution<int> distribution(1,1000000);
//     auto generate = std::bind ( distribution, generator );
//     std::vector<int> v1; std::vector<int> v2; std::vector<int> v3; std::vector<int> v4; std::vector<int> v5;
//     for (int i = 0; i < s1; i++) {
//         v1.push_back(generate());
//     }
//     for (int i = 0; i < s2; i++) {
//         v2.push_back(generate());
//     }
//     for (int i = 0; i < s3; i++) {
//         v3.push_back(generate());
//     }
//     for (int i = 0; i < s4; i++) {
//         v4.push_back(generate());
//     }
//     for (int i = 0; i < s5; i++) {
//         v5.push_back(generate());
//     }
//     vv.push_back(v1);
//     vv.push_back(v2);
//     vv.push_back(v3);
//     vv.push_back(v4);
//     vv.push_back(v5);
//     return vv;
// }

void sortDescending(std::vector<std::vector<std::vector<int>>> &vvv) {
    for (int i = 0; i < vvv.size(); i++) {
        for (int j = 0; j < vvv[i].size(); j++) {
            std::sort(vvv[i][j].begin(), vvv[i][j].end(), std::greater<int>());
        }
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

void whatVectorSize(std::string size, std::ofstream& out) {
    if (size == "First") {
        std::cout << "\nVector size: 10,000,000" << std::endl;
        out << "\nVector size: 10,000,000" << std::endl;
    }
    else if (size == "Second") {
        std::cout << "\nVector size: 25,000,000" << std::endl;
        out << "\nVector size: 25,000,000" << std::endl;
    }
    else if (size == "Third") {
        std::cout << "\nVector size: 50,000,000" << std::endl;
        out << "\nVector size: 50,000,000" << std::endl;
    }
    else if (size == "Fourth") {
        std::cout << "\nVector size: 75,000,000" << std::endl;
        out << "\nVector size: 75,000,000" << std::endl;
    }
    else if (size == "Fifth") {
        std::cout << "\nVector size: 100,000,000" << std::endl;
        out << "\nVector size: 100,000,000" << std::endl;
    }
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
    whatVectorSize(whichVector, out);
    for (size_t i{0}; i < size; i++) {
        temp = v;
        t.startClock();
        quickSort(temp, 0, temp.size() - 1);
        t.endClock();
        std::cout << std::fixed << std::setprecision(2) << whichVector << " vector QuickSort using rule of three took : " << t.getDuration() << " seconds" << std::endl;
        out << std::fixed << std::setprecision(2) << whichVector << " vector QuickSort using rule of three took : " << t.getDuration() << " seconds" << std::endl;
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
    whatVectorSize(whichVector, out);
    for (size_t i{0}; i < size; i++) {
        temp = v;
        t.startClock();
        shellSort(temp);
        t.endClock();
        std::cout << std::fixed << std::setprecision(2) << whichVector << " vector ShellSort took : " << t.getDuration() << " seconds" << std::endl;
        out << std::fixed << std::setprecision(2) << whichVector << " vector ShellSort took : " << t.getDuration() << " seconds" << std::endl;
    }
}

int main() {
    std::vector<std::vector<std::vector<int>>> vvv = multiGenerateRandomVectors();
    std::vector<std::vector<std::vector<int>>> dvvv = multiGenerateRandomVectors();
    sortDescending(dvvv);
    Timer t;
    std::ofstream file("time.txt");
    std::vector<std::vector<int>> vv1 = vvv[0]; std::vector<std::vector<int>> vv2 = vvv[1]; std::vector<std::vector<int>> vv3 = vvv[2]; std::vector<std::vector<int>> vv4 = vvv[3]; std::vector<std::vector<int>> vv5 = vvv[4]; 
    std::cout << "Random vectors" << std::endl;
    std::cout << "QUICKSORT USING RULE OF THREE" << std::endl;
    file << "Random vectors" << std::endl;
    file << "QUICKSORT USING RULE OF THREE" << std::endl;
    quickSortTest(v1, file, testAmount, t, "First"); 
    quickSortTest(v2, file, testAmount, t, "Second");
    quickSortTest(v3, file, testAmount, t, "Third");
    quickSortTest(v4, file, testAmount, t, "Fourth");
    quickSortTest(v5, file, testAmount, t, "Fifth");
    v1.clear(); v2.clear(); v3.clear(); v4.clear(); v5.clear();
    v1 = vv[0]; v2 = vv[1]; v3 = vv[2]; v4 = vv[3]; v5 = vv[4];
    std::cout << "\n\nSHELLSORT USING SEDGEWICK'S GAPS" << std::endl;
    file << "\n\nSHELLSORT USING SEDGEWICK'S GAPS" << std::endl;
    shellSortTest(v1, file, testAmount, t, "First");
    shellSortTest(v2, file, testAmount, t, "Second");
    shellSortTest(v3, file, testAmount, t, "Third");
    shellSortTest(v4, file, testAmount, t, "Fourth");
    shellSortTest(v5, file, testAmount, t, "Fifth");
    v1.clear(); v2.clear(); v3.clear(); v4.clear(); v5.clear();
    v1 = dv[0]; v2 = dv[1]; v3 = dv[2]; v4 = dv[3]; v5 = dv[4];
    std::cout << "\n\nDescending random vectors" << std::endl;
    std::cout << "QUICKSORT USING RULE OF THREE" << std::endl;
    file << "\n\nDescending random vectors" << std::endl;
    file << "\n\nQUICKSORT USING RULE OF THREE" << std::endl;
    quickSortTest(v1, file, testAmountDescending, t, "First");
    quickSortTest(v2, file, testAmountDescending, t, "Second");
    quickSortTest(v3, file, testAmountDescending, t, "Third");
    quickSortTest(v4, file, testAmountDescending, t, "Fourth");
    quickSortTest(v5, file, testAmountDescending, t, "Fifth");
    v1.clear(); v2.clear(); v3.clear(); v4.clear(); v5.clear();
    v1 = dv[0]; v2 = dv[1]; v3 = dv[2]; v4 = dv[3]; v5 = dv[4];
    std::cout << "\n\nSHELLSORT USING SEDGEWICK'S GAPS" << std::endl;
    file << "\n\nSHELLSORT USING SEDGEWICK'S GAPS" << std::endl;
    shellSortTest(v1, file, testAmountDescending, t, "First");
    shellSortTest(v2, file, testAmountDescending, t, "Second");
    shellSortTest(v3, file, testAmountDescending, t, "Third");
    shellSortTest(v4, file, testAmountDescending, t, "Fourth");
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

