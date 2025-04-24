#include <vector>

std::vector<int> nums = {1, 2, 3, 4, 5};

nums.push_back(6);  // добавляет элемент в конец
nums.pop_back();    // удаляет последний элемент

for (int num : nums) {
    std::cout << num << " ";  // 1 2 3 4 5
}
