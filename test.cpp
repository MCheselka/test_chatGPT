#include <iostream>
#include <vector>
#include <algorithm>

bool is_sorted(const std::vector<int>& a) {
    for (size_t i = 0; i < a.size() - 1; ++i) {
        if (a[i] > a[i + 1]) {
            return false;
        }
    }
    return true;
}

void f(std::vector<int>& a, size_t idx) {
    std::cout << a[idx];
    if (a[idx] > a[idx + 1]) {
        std::swap(a[idx], a[idx + 1]);
    }
}

std::vector<int> num_iterations(int t, const std::vector<std::pair<int, std::vector<int>>>& test_cases) {
    std::vector<int> results;
    for (const auto& [n, a] : test_cases) {
        int count = 0;
        std::vector<int> temp_a(a);
        while (!is_sorted(temp_a)) {
            if (count % 2 == 0) {
                for (size_t i = 0; i < n - 1; i += 2) {
                    f(temp_a, i);
                }
            } else {
                for (size_t i = 1; i < n - 1; i += 2) {
                    f(temp_a, i);
                }
            }
            count++;
        }
        results.push_back(count);
        std::cout << std::endl;
    }
    return results;
}

int main() {
    int t;
    std::cin >> t;
    std::vector<std::pair<int, std::vector<int>>> test_cases(t);
    for (int i = 0; i < t; ++i) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int j = 0; j < n; ++j) {
            std::cin >> a[j];
        }
        test_cases[i] = {n, a};
    }

    std::vector<int> output = num_iterations(t, test_cases);
    for (int result : output) {
        std::cout << result << std::endl;
    }

    return 0;
}
