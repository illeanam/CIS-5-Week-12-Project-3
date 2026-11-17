// Illeana Martinez - Project 3

#include <iostream>
#include <cstdlib>
#include <ctime>

void countGrades(const int scores[], int n, int& a, int& b, int& c, int& d, int& failing) {
	a = 0;
	b = 0;
	c = 0;
	d = 0;
	failing = 0;
	if (n <= 0 || scores == nullptr) return;
    // TODO: for loop. Add 1 to the matching count.
// A is 90 and up. B is 80 to 89. C is 70 to 79. D is 60 to 69.
// Failing is below 60. A 60 is a D. Do not print.
    for (int i = 0; i < n; ++i) {
        if (scores[i] >= 90) {
            ++a;
        }
        else if (scores[i] >= 80) {
            ++b;
        }
        else if (scores[i] >= 70) {
            ++c;
        }
        else if (scores[i] >= 60) {
            ++d;
        }
        else {
            ++failing;
        }
    }
}
double average(const int scores[], int n) {
    if (n <= 0 || scores == nullptr) return 0.0;
    // TODO: return the mean as a double (sum * 1.0 / n). Do not print.
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += scores[i];
    }
    return sum * 1.0 / n;
}
void officeHours(const int scores[], int n, int* failingCount) {
    if (failingCount != nullptr) *failingCount = 0;
    if (n <= 0 || scores == nullptr) return;
    // TODO: while loop. If scores[i] is under 60, print:
    // Student at index i needs to come to office hours.
    // If failingCount is not nullptr, write how many lines you printed
    // through *failingCount. If it is nullptr, do not write through it.

    int count = 0;
    int i = 0;
    while (i < n) {
        if (scores[i] < 60) {
            std::cout << "Student at index " << i << " needs to come to office hours.\n";
            ++count;
        }
        ++i;
    }

    if (failingCount != nullptr) {
        *failingCount = count;
    }
}
int main() {
    const int N = 50;
    int scores[N];

    // Do not edit this boilerplate. It randomly generates 50 scores.
    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < N; ++i) {
        scores[i] = rand() % 100;
    }

    for (int i = 0; i < N; ++i) {
        std::cout << "[" << i << "] " << scores[i] << "\n";
    }

    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int failing = 0;
    countGrades(scores, N, a, b, c, d, failing);

    std::cout << "A: " << a << std::endl;
    std::cout << "B: " << b << std::endl;
    std::cout << "C: " << c << std::endl;
    std::cout << "D: " << d << std::endl;
    std::cout << "Failing: " << failing << std::endl;
    std::cout << "Average: " << average(scores, N) << std::endl;

    int lines = 0;
    officeHours(scores, N, &lines);
    std::cout << "Office hours: " << lines << std::endl;

    return 0;
}
