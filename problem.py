class FenwickTree:
    def __init__(self, size):
        self.size = size
        self.tree = [0] * (size + 1)

    def update(self, index, value):
        while index <= self.size:
            self.tree[index] += value
            index += index & -index

    def query(self, index):
        result = 0
        while index > 0:
            result += self.tree[index]
            index -= index & -index
        return result

def count_smaller_values_after(arr):
    n = len(arr)
    sorted_arr = sorted(enumerate(arr), key=lambda x: x[1])
    fenwick_tree = FenwickTree(n)
    result = [0] * n

    for i, (_, value) in enumerate(sorted_arr):
        result[sorted_arr[i][0]] = fenwick_tree.query(n) - fenwick_tree.query(sorted_arr[i][0])
        fenwick_tree.update(sorted_arr[i][0] + 1, 1)

    return result

# Example usage:
a = [4, 2, 9, 7, 5]
b = count_smaller_values_after(a)
print("Array a:", a)
print("Array b:", b)
