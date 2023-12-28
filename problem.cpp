#include <iostream>
#include <vector>
#include <algorithm>

class FenwickTree {
public:
    FenwickTree(int size) : size(size), tree(size + 1, 0) {}

    void update(int index, int value) {
        while (index <= size) {
            tree[index] += value;
            index += index & -index;
        }
    }

    int query(int index) {
        int result = 0;
        while (index > 0) {
            result += tree[index];
            index -= index & -index;
        }
        return result;
    }

private:
    int size;
    std::vector<int> tree;
};

std::vector<int> countSmallerValuesAfter(const std::vector<int>& arr) {
    int n = arr.size();
    std::vector<std::pair<int, int>> indexedArr(n);
    for (int i = 0; i < n; ++i) {
        indexedArr[i] = {i, arr[i]};
    }

    std::sort(indexedArr.begin(), indexedArr.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    FenwickTree fenwickTree(n);
    std::vector<int> result(n, 0);

    for (int i = 0; i < n; ++i) {
        result[indexedArr[i].first] = fenwickTree.query(n) - fenwickTree.query(indexedArr[i].first);
        fenwickTree.update(indexedArr[i].first + 1, 1);
    }

    return result;
}

int main() {
    std::vector<int> a = {4, 2, 9, 7, 5};
    std::vector<int> b = countSmallerValuesAfter(a);

    std::cout << "Array a:";
    for (int num : a) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    std::cout << "Array b:";
    for (int num : b) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    return 0;
}
