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

const unsigned int s1{4000000}, s2{8000000}, s3{16000000}, s4{32000000}, s5{64000000};
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
void quickSort(std::vector<std::vector<int>> &v, int left, int right);
void quickSortTest(std::vector<std::vector<int>> v, std::ofstream& out, const unsigned int size, Timer &t, std::string whichVector);
std::vector<int> sedgewickSequence(const unsigned int size);
void shellSort(std::vector<int> &v);
void shellSortTest(std::vector<std::vector<int>> v, std::ofstream& out, const unsigned int size, Timer &t, std::string whichVector);


std::vector<std::vector<std::vector<int>>> multiGenerateRandomVectors() {
    std::vector<std::vector<std::vector<int>>> vvv;
    std::default_random_engine rd;
    std::mt19937_64 generator(rd());
    std::uniform_int_distribution<int> distribution(1,1000000);
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
    std::cout << "Set 1 done.\n";

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
    std::cout << "Set 2 done.\n";

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
    std::cout << "Set 3 done.\n";

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
    std::cout << "Set 4 done.\n";

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
    std::cout << "Set 5 done.\n";

    return vvv;

}

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
        std::cout << "\nVector size: 4,000,000" << std::endl;
        out << "\nVector size: 4,000,000" << std::endl;
    }
    else if (size == "Second") {
        std::cout << "\nVector size: 8,000,000" << std::endl;
        out << "\nVector size: 8,000,000" << std::endl;
    }
    else if (size == "Third") {
        std::cout << "\nVector size: 16,000,000" << std::endl;
        out << "\nVector size: 16,000,000" << std::endl;
    }
    else if (size == "Fourth") {
        std::cout << "\nVector size: 32,000,000" << std::endl;
        out << "\nVector size: 32,000,000" << std::endl;
    }
    else if (size == "Fifth") {
        std::cout << "\nVector size: 64,000,000" << std::endl;
        out << "\nVector size: 64,000,000" << std::endl;
    }
}

void quickSort(std::vector<int> &v, int left, int right) {
    if (left < right) {
        int pivot = partition(v, left, right);
        quickSort(v, left, pivot - 1);
        quickSort(v, pivot + 1, right);
    }
}

void quickSortTest(std::vector<std::vector<int>> v, std::ofstream& out, const unsigned int size, Timer &t, std::string whichVector) {
    std::vector<int> temp;
    float average{0};
    float totalAverage{0};
    for (size_t i{0}; i < vectorAmount; i++) {
        whatVectorSize(whichVector, out);
        for (size_t j{0}; j < size; j++) {
            temp = v[i];
            t.startClock();
            quickSort(temp, 0, temp.size() - 1);
            t.endClock();
            std::cout << std::fixed << std::setprecision(2) << whichVector << " vector QuickSort using rule of three took : " << t.getDuration() << " seconds" << std::endl;
            out << std::fixed << std::setprecision(2) << whichVector << " vector QuickSort using rule of three took : " << t.getDuration() << " seconds" << std::endl;
            average += t.getDuration();
        }
        std::cout << std::fixed << std::setprecision(2) << whichVector << " vector QuickSort using rule of three average time: " << average / size << " seconds" << std::endl;
        out << std::fixed << std::setprecision(2) << whichVector << " vector QuickSort using rule of three average time: " << average / size << " seconds" << std::endl;
        totalAverage += average / size;
        average = 0;
    }
    std::cout << std::fixed << std::setprecision(2) << whichVector << " vector QuickSort using rule of three total average time: " << totalAverage / vectorAmount << " seconds" << std::endl;
    out << std::fixed << std::setprecision(2) << whichVector << " vector QuickSort using rule of three total average time: " << totalAverage / vectorAmount << " seconds" << std::endl;
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

void shellSortTest(std::vector<std::vector<int>> v, std::ofstream& out, const unsigned int size, Timer &t, std::string whichVector) {
    std::vector<int> temp;
    float average{0};
    float totalAverage{0};
    for (size_t i{0}; i < vectorAmount; i++) {
        whatVectorSize(whichVector, out);
        for (size_t j{0}; j < size; j++) {
            temp = v[i];
            t.startClock();
            shellSort(temp);
            t.endClock();
            std::cout << std::fixed << std::setprecision(2) << whichVector << " vector ShellSort took : " << t.getDuration() << " seconds" << std::endl;
            out << std::fixed << std::setprecision(2) << whichVector << " vector ShellSort took : " << t.getDuration() << " seconds" << std::endl;
            average += t.getDuration();
        }
        std::cout << std::fixed << std::setprecision(2) << whichVector << " vector ShellSort average time: " << average / size << " seconds" << std::endl;
        out << std::fixed << std::setprecision(2) << whichVector << " vector ShellSort average time: " << average / size << " seconds" << std::endl;
        totalAverage += average / size;
        average = 0;
    }
    std::cout << std::fixed << std::setprecision(2) << whichVector << " vector ShellSort total average time: " << totalAverage / vectorAmount << " seconds" << std::endl;
    out << std::fixed << std::setprecision(2) << whichVector << " vector ShellSort total average time: " << totalAverage / vectorAmount << " seconds" << std::endl;
}

int main() {
    std::vector<std::vector<std::vector<int>>> vvv = multiGenerateRandomVectors();
    Timer t;
    std::ofstream file("time.txt");
    std::vector<std::vector<int>> vv1 = vvv[0]; std::vector<std::vector<int>> vv2 = vvv[1]; std::vector<std::vector<int>> vv3 = vvv[2]; std::vector<std::vector<int>> vv4 = vvv[3]; std::vector<std::vector<int>> vv5 = vvv[4]; 
    std::cout << "Random vectors" << std::endl;
    std::cout << "QUICKSORT USING RULE OF THREE" << std::endl;
    file << "Random vectors" << std::endl;
    file << "QUICKSORT USING RULE OF THREE" << std::endl;
    quickSortTest(vv1, file, testAmount, t, "First"); 
    quickSortTest(vv2, file, testAmount, t, "Second");
    quickSortTest(vv3, file, testAmount, t, "Third");
    quickSortTest(vv4, file, testAmount, t, "Fourth");
    quickSortTest(vv5, file, testAmount, t, "Fifth");
    vv1.clear(); vv2.clear(); vv3.clear(); vv4.clear(); vv5.clear();
    vv1 = vvv[0]; vv2 = vvv[1]; vv3 = vvv[2]; vv4 = vvv[3]; vv5 = vvv[4];
    std::cout << "\n\nSHELLSORT USING SEDGEWICK'S GAPS" << std::endl;
    file << "\n\nSHELLSORT USING SEDGEWICK'S GAPS" << std::endl;
    shellSortTest(vv1, file, testAmount, t, "First");
    shellSortTest(vv2, file, testAmount, t, "Second");
    shellSortTest(vv3, file, testAmount, t, "Third");
    shellSortTest(vv4, file, testAmount, t, "Fourth");
    shellSortTest(vv5, file, testAmount, t, "Fifth");
    vv1.clear(); vv2.clear(); vv3.clear(); vv4.clear(); vv5.clear();
    std::vector<std::vector<std::vector<int>>> ddv = vvv;
    sortDescending(ddv);
    vv1 = ddv[0]; vv2 = ddv[1]; vv3 = ddv[2]; vv4 = ddv[3]; vv5 = ddv[4];
    std::cout << "\n\nDescending random vectors" << std::endl;
    std::cout << "QUICKSORT USING RULE OF THREE" << std::endl;
    file << "\n\nDescending random vectors" << std::endl;
    file << "\n\nQUICKSORT USING RULE OF THREE" << std::endl;
    quickSortTest(vv1, file, testAmountDescending, t, "First");
    quickSortTest(vv2, file, testAmountDescending, t, "Second");
    quickSortTest(vv3, file, testAmountDescending, t, "Third");
    quickSortTest(vv4, file, testAmountDescending, t, "Fourth");
    quickSortTest(vv5, file, testAmountDescending, t, "Fifth");
    vv1.clear(); vv2.clear(); vv3.clear(); vv4.clear(); vv5.clear();
    vv1 = ddv[0]; vv2 = ddv[1]; vv3 = ddv[2]; vv4 = ddv[3]; vv5 = ddv[4];
    std::cout << "\n\nSHELLSORT USING SEDGEWICK'S GAPS" << std::endl;
    file << "\n\nSHELLSORT USING SEDGEWICK'S GAPS" << std::endl;
    shellSortTest(vv1, file, testAmountDescending, t, "First");
    shellSortTest(vv2, file, testAmountDescending, t, "Second");
    shellSortTest(vv3, file, testAmountDescending, t, "Third");
    shellSortTest(vv4, file, testAmountDescending, t, "Fourth");
    shellSortTest(vv5, file, testAmountDescending, t, "Fifth");
    vv1.clear(); vv2.clear(); vv3.clear(); vv4.clear(); vv5.clear();
    vvv.clear(); ddv.clear();
    std::vector<std::vector<std::vector<int>>>().swap(vvv);
    std::vector<std::vector<std::vector<int>>>().swap(ddv);
    std::vector<std::vector<int>>().swap(vv1); std::vector<std::vector<int>>().swap(vv2); std::vector<std::vector<int>>().swap(vv3); std::vector<std::vector<int>>().swap(vv4); std::vector<std::vector<int>>().swap(vv5);
    file.close();
    std::cout << "Press 'ENTER' to exit" << std::endl;
    std::cin.get();
    return 0;
}

