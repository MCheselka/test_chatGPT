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
    if (a[idx] > a[idx + 1]) {
        std::swap(a[idx], a[idx + 1]);
    }
}

std::string print_vector(const std::vector<int>& a) {
    std::string result = "[";
    for (size_t i = 0; i < a.size(); ++i) {
        result += std::to_string(a[i]);
        if (i < a.size() - 1) {
            result += ", ";
        }
    }
    result += "]";
    return result;
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
            std::cout << "* after the " << count << "-";

            // Print the ordinal suffix (st, nd, rd, th)
            if (count % 10 == 1 && count % 100 != 11) {
                std::cout << "st";
            } else if (count % 10 == 2 && count % 100 != 12) {
                std::cout << "nd";
            } else if (count % 10 == 3 && count % 100 != 13) {
                std::cout << "rd";
            } else {
                std::cout << "th";
            }

            std::cout << " iteration: " << print_vector(temp_a) << ";\n";
        }
        results.push_back(count);
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

    std::cout << "\n";
    std::vector<int> output = num_iterations(t, test_cases);
    for (int result : output) {
        std::cout << "\nSorted in " << result << " iterations\n";
    }

    return 0;
}
