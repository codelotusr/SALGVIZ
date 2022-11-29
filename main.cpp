#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <chrono>
#include <iomanip>
#include <fstream>
using namespace std;

void shuffleVector(vector<int> &v) {
    int n = v.size();
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(v[i], v[j]);
    }
}

vector<int> generateRandomVector(int size) {
    vector<int> v;
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        v.push_back(rand() % 100);
    }
    shuffleVector(v);
    return v;
}

vector<int> generateRandomVectorDescending(int size) {
    vector<int> v = generateRandomVector(size);
    shuffleVector(v);
    sort(v.begin(), v.end(), greater<int>());
    return v;
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


int main() {
    const unsigned int s1(2500), s2(5000), s3(7777), s4(20001), s5(496281);
    std::vector<int> v1(s1), v2(s2), v3(s3), v4(s4), v5(s5), v6(s1), v7(s2), v8(s3), v9(s4), v10(s5);
    std::vector<int> temp1(s1), temp2(s2), temp3(s3), temp4(s4), temp5(s5); // for normal random vector
    std::vector<int> temp6(s1), temp7(s2), temp8(s3), temp9(s4), temp10(s5); // for descending random vector
    double averageTime1(0), averageTime2(0), averageTime3(0), averageTime4(0), averageTime5(0);
    std::ofstream file("time.txt");

    std::cout << "QUICKSORT USING RULE OF THREE" << std::endl;
    std::cout << "Normally distributed random vector" << std::endl;
    std::cout << "Vector size: " << s1 << std::endl;
    file << "QUICKSORT USING RULE OF THREE" << std::endl;
    file << "Normally distributed random vector" << std::endl;
    file << "Vector size: " << s1 << std::endl;
    for (int i = 0; i < 10; i++) {
        v1 = generateRandomVector(s1);
        temp1 = v1;
        auto start = std::chrono::high_resolution_clock::now();
        quicksort(temp1, 0, s1 - 1);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        averageTime1 += elapsed_seconds.count();
        std::cout << "First vector quicksort using rule of three elapsed time: " << elapsed_seconds.count() << "s\n";
        file << "First vector quicksort using rule of three elapsed time: " << elapsed_seconds.count() << "s\n";;
    }
    std::cout << "Average time: " << averageTime1 / 10 << "s" << std::endl;
    file << "Average time: " << averageTime1 / 10 << "s" << std::endl;

    std::cout << "Vector size: " << s2 << std::endl;
    file << "Vector size: " << s2 << std::endl;
    for (int i = 0; i < 10; i++) {
        v2 = generateRandomVector(s2);
        temp2 = v2;
        auto start = std::chrono::high_resolution_clock::now();
        quicksort(temp2, 0, s2 - 1);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        averageTime2 += elapsed_seconds.count();
        std::cout << "Second vector quicksort using rule of three elapsed time: " << elapsed_seconds.count() << "s\n";
        file << "Second vector quicksort using rule of three elapsed time: " << elapsed_seconds.count() << "s\n";;
    }
    std::cout << "Average time: " << averageTime2 / 10 << "s" << std::endl;
    file << "Average time: " << averageTime2 / 10 << "s" << std::endl;

    std::cout << "Vector size: " << s3 << std::endl;
    file << "Vector size: " << s3 << std::endl;
    for (int i = 0; i < 10; i++) {
        v3 = generateRandomVector(s3);
        temp3 = v3;
        auto start = std::chrono::high_resolution_clock::now();
        quicksort(temp3, 0, s3 - 1);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        averageTime3 += elapsed_seconds.count();
        std::cout << "Third vector quicksort using rule of three elapsed time: " << elapsed_seconds.count() << "s\n";
        file << "Third vector quicksort using rule of three elapsed time: " << elapsed_seconds.count() << "s\n";;
    }
    std::cout << "Average time: " << averageTime3 / 10 << "s" << std::endl;
    file << "Average time: " << averageTime3 / 10 << "s" << std::endl;

    std::cout << "Vector size: " << s4 << std::endl;
    file << "Vector size: " << s4 << std::endl;
    for (int i = 0; i < 10; i++) {
        v4 = generateRandomVector(s4);
        temp4 = v4;
        auto start = std::chrono::high_resolution_clock::now();
        quicksort(temp4, 0, s4 - 1);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        averageTime4 += elapsed_seconds.count();
        std::cout << "Fourth vector quicksort using rule of three elapsed time: " << elapsed_seconds.count() << "s\n";
        file << "Fourth vector quicksort using rule of three elapsed time: " << elapsed_seconds.count() << "s\n";;
    }
    std::cout << "Average time: " << averageTime4 / 10 << "s" << std::endl;
    file << "Average time: " << averageTime4 / 10 << "s" << std::endl;

    std::cout << "Vector size: " << s5 << std::endl;
    file << "Vector size: " << s5 << std::endl;
    for (int i = 0; i < 10; i++) {
        v5 = generateRandomVector(s5);
        temp5 = v5;
        auto start = std::chrono::high_resolution_clock::now();
        quicksort(temp5, 0, s5 - 1);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        averageTime5 += elapsed_seconds.count();
        std::cout << "Fifth vector quicksort using rule of three elapsed time: " << elapsed_seconds.count() << "s\n";
        file << "Fifth vector quicksort using rule of three elapsed time: " << elapsed_seconds.count() << "s\n";;
    }
    std::cout << "Average time: " << averageTime5 / 10 << "s" << std::endl;
    file << "Average time: " << averageTime5 / 10 << "s" << std::endl;
    std::cout << "TOTAL AVERAGE TIME: " << (averageTime1 + averageTime2 + averageTime3 + averageTime4 + averageTime5) / 50 << "s" << std::endl;
    file << "TOTAL AVERAGE TIME: " << (averageTime1 + averageTime2 + averageTime3 + averageTime4 + averageTime5) / 50 << "s" << std::endl;

    std::cout << "\n\nDescendingly distributed random vector" << std::endl;
    std::cout << "Vector size: " << s1 << std::endl;
    file << "Descendingly distributed random vector" << std::endl;
    file << "Vector size: " << s1 << std::endl;
    for (int i = 0; i < 10; i++) {
        v6 = generateRandomVectorDescending(s1);
        temp6 = v6;
        auto start = std::chrono::high_resolution_clock::now();
        quicksort(temp6, 0, s1 - 1);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "First vector quicksort using rule of three elapsed time: " << elapsed_seconds.count() << "s\n";
        file << "First vector quicksort using rule of three elapsed time: " << elapsed_seconds.count() << "s\n";;
    }
    std::cout << "Vector size: " << s2 << std::endl;
    file << "Vector size: " << s2 << std::endl;
    for (int i = 0; i < 10; i++) {
        v7 = generateRandomVectorDescending(s2);
        temp7 = v7;
        auto start = std::chrono::high_resolution_clock::now();
        quicksort(temp7, 0, s2 - 1);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "Second vector quicksort using rule of three elapsed time: " << elapsed_seconds.count() << "s\n";
        file << "Second vector quicksort using rule of three elapsed time: " << elapsed_seconds.count() << "s\n";;
    }
    std::cout << "Vector size: " << s3 << std::endl;
    file << "Vector size: " << s3 << std::endl;
    for (int i = 0; i < 10; i++) {
        v8 = generateRandomVectorDescending(s3);
        temp8 = v8;
        auto start = std::chrono::high_resolution_clock::now();
        quicksort(temp8, 0, s3 - 1);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "Third vector quicksort using rule of three elapsed time: " << elapsed_seconds.count() << "s\n";
        file << "Third vector quicksort using rule of three elapsed time: " << elapsed_seconds.count() << "s\n";;
    }
    std::cout << "Vector size: " << s4 << std::endl;
    file << "Vector size: " << s4 << std::endl;
    for (int i = 0; i < 10; i++) {
        v9 = generateRandomVectorDescending(s4);
        temp9 = v9;
        auto start = std::chrono::high_resolution_clock::now();
        quicksort(temp9, 0, s4 - 1);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "Fourth vector quicksort using rule of three elapsed time: " << elapsed_seconds.count() << "s\n";
        file << "Fourth vector quicksort using rule of three elapsed time: " << elapsed_seconds.count() << "s\n";;
    }
    std::cout << "Vector size: " << s5 << std::endl;
    file << "Vector size: " << s5 << std::endl;
    for (int i = 0; i < 10; i++) {
        v10 = generateRandomVectorDescending(s5);
        temp10 = v10;
        auto start = std::chrono::high_resolution_clock::now();
        quicksort(temp10, 0, s5 - 1);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "Fifth vector quicksort using rule of three elapsed time: " << elapsed_seconds.count() << "s\n";
        file << "Fifth vector quicksort using rule of three elapsed time: " << elapsed_seconds.count() << "s\n";;
    }
    std::cout << std::endl << std::endl;
    file << std::endl << std::endl;
    std::cout << "SHELL SORT USING SEDGEWICKS GAPS" << std::endl;
    std::cout << "Normally distributed random vector" << std::endl;
    std::cout << "Vector size: " << s1 << std::endl;
    file << "SHELL SORT USING SEDGEWICKS GAPS" << std::endl;
    file << "Normally distributed random vector" << std::endl;
    file << "Vector size: " << s1 << std::endl;
    for (int i = 0; i < 10; i++) {
        v1 = generateRandomVector(s1);
        temp1 = v1;
        auto start = std::chrono::high_resolution_clock::now();
        shellsort(temp1);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "First vector shellsort using Sedgewicks gaps elapsed time: " << elapsed_seconds.count() << "s\n";
        file << "First vector shellsort using Sedgewicks gaps elapsed time: " << elapsed_seconds.count() << "s\n";;
    }
    std::cout << "Vector size: " << s2 << std::endl;
    file << "Vector size: " << s2 << std::endl;
    for (int i = 0; i < 10; i++) {
        v2 = generateRandomVector(s2);
        temp2 = v2;
        auto start = std::chrono::high_resolution_clock::now();
        shellsort(temp2);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "Second vector shellsort using Sedgewicks gaps elapsed time: " << elapsed_seconds.count() << "s\n";
        file << "Second vector shellsort using Sedgewicks gaps elapsed time: " << elapsed_seconds.count() << "s\n";;
    }
    std::cout << "Vector size: " << s3 << std::endl;
    file << "Vector size: " << s3 << std::endl;
    for (int i = 0; i < 10; i++) {
        v3 = generateRandomVector(s3);
        temp3 = v3;
        auto start = std::chrono::high_resolution_clock::now();
        shellsort(temp3);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "Third vector shellsort using Sedgewicks gaps elapsed time: " << elapsed_seconds.count() << "s\n";
        file << "Third vector shellsort using Sedgewicks gaps elapsed time: " << elapsed_seconds.count() << "s\n";;
    }
    std::cout << "Vector size: " << s4 << std::endl;
    file << "Vector size: " << s4 << std::endl;
    for (int i = 0; i < 10; i++) {
        v4 = generateRandomVector(s4);
        temp4 = v4;
        auto start = std::chrono::high_resolution_clock::now();
        shellsort(temp4);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "Fourth vector shellsort using Sedgewicks gaps elapsed time: " << elapsed_seconds.count() << "s\n";
        file << "Fourth vector shellsort using Sedgewicks gaps elapsed time: " << elapsed_seconds.count() << "s\n";;
    }
    std::cout << "Vector size: " << s5 << std::endl;
    file << "Vector size: " << s5 << std::endl;
    for (int i = 0; i < 10; i++) {
        v5 = generateRandomVector(s5);
        temp5 = v5;
        auto start = std::chrono::high_resolution_clock::now();
        shellsort(temp5);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "Fifth vector shellsort using Sedgewicks gaps elapsed time: " << elapsed_seconds.count() << "s\n";
        file << "Fifth vector shellsort using Sedgewicks gaps elapsed time: " << elapsed_seconds.count() << "s\n";;
    }
    std::cout << "\nDescendingly distributed random vector" << std::endl;
    std::cout << "Vector size: " << s1 << std::endl;
    file << "\nDescendingly distributed random vector" << std::endl;
    file << "Vector size: " << s1 << std::endl;
    for (int i = 0; i < 10; i++) {
        v6 = generateRandomVectorDescending(s1);
        temp6 = v6;
        auto start = std::chrono::high_resolution_clock::now();
        shellsort(temp6);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "First vector shellsort using Sedgewicks gaps elapsed time: " << elapsed_seconds.count() << "s\n";
        file << "First vector shellsort using Sedgewicks gaps elapsed time: " << elapsed_seconds.count() << "s\n";;
    }
    std::cout << "Vector size: " << s2 << std::endl;
    file << "Vector size: " << s2 << std::endl;
    for (int i = 0; i < 10; i++) {
        v7 = generateRandomVectorDescending(s2);
        temp7 = v7;
        auto start = std::chrono::high_resolution_clock::now();
        shellsort(temp7);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "Second vector shellsort using Sedgewicks gaps elapsed time: " << elapsed_seconds.count() << "s\n";
        file << "Second vector shellsort using Sedgewicks gaps elapsed time: " << elapsed_seconds.count() << "s\n";;
    }
    std::cout << "Vector size: " << s3 << std::endl;
    file << "Vector size: " << s3 << std::endl;
    for (int i = 0; i < 10; i++) {
        v8 = generateRandomVectorDescending(s3);
        temp8 = v8;
        auto start = std::chrono::high_resolution_clock::now();
        shellsort(temp8);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "Third vector shellsort using Sedgewicks gaps elapsed time: " << elapsed_seconds.count() << "s\n";
        file << "Third vector shellsort using Sedgewicks gaps elapsed time: " << elapsed_seconds.count() << "s\n";;
    }
    std::cout << "Vector size: " << s4 << std::endl;
    file << "Vector size: " << s4 << std::endl;
    for (int i = 0; i < 10; i++) {
        v9 = generateRandomVectorDescending(s4);
        temp9 = v9;
        auto start = std::chrono::high_resolution_clock::now();
        shellsort(temp9);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "Fourth vector shellsort using Sedgewicks gaps elapsed time: " << elapsed_seconds.count() << "s\n";
        file << "Fourth vector shellsort using Sedgewicks gaps elapsed time: " << elapsed_seconds.count() << "s\n";;
    }
    std::cout << "Vector size: " << s5 << std::endl;
    file << "Vector size: " << s5 << std::endl;
    for (int i = 0; i < 10; i++) {
        v10 = generateRandomVectorDescending(s5);
        temp10 = v10;
        auto start = std::chrono::high_resolution_clock::now();
        shellsort(temp10);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "Fifth vector shellsort using Sedgewicks gaps elapsed time: " << elapsed_seconds.count() << "s\n";
        file << "Fifth vector shellsort using Sedgewicks gaps elapsed time: " << elapsed_seconds.count() << "s\n";;
    }
    file.close();
    return 0;
}

