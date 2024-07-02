#include <iostream>
#include <vector>
#include <unordered_map>
#include <random>
#include <algorithm>

class RandomizedSet {
private:
	std::unordered_map<int, int> index_map; // 存储元素到索引的映射
	std::vector<int> elements; // 存储所有元素

public:
	RandomizedSet() {}

	bool insert(int val) {
		// 如果元素已存在，返回false
		if (index_map.find(val) != index_map.end()) {
			return false;
		}
		// 将元素添加到vector中，并记录索引
		index_map[val] = elements.size();
		elements.push_back(val);
		return true;
	}

	bool remove(int val) {
		// 如果元素不存在，返回false
		if (index_map.find(val) == index_map.end()) {
			return false;
		}
		// 将最后一个元素替换到要删除的元素的位置
		int lastElement = elements.back();
		int toDeleteIndex = index_map[val];
		elements[toDeleteIndex] = lastElement;
		index_map[lastElement] = toDeleteIndex; // 更新最后一个元素的索引映射
		// 从map和vector中删除原元素
		index_map.erase(val);
		elements.pop_back();
		return true;
	}

	int getRandom() {
		int randomIndex = rand() % elements.size();
		return elements[randomIndex];

		//// 随机选择一个索引，然后返回对应的元素
		//std::random_device rd;
		//std::mt19937 gen(rd());
		//std::uniform_int_distribution<> dis(0, elements.size() - 1);
		//return elements[dis(gen)];
	}
};

int main() {
	RandomizedSet randomizedSet;
	randomizedSet.insert(1);
	randomizedSet.insert(2);
	std::cout << "Get a random element: " << randomizedSet.getRandom() << std::endl;
	randomizedSet.remove(1);
	std::cout << "Get a random element after removal: " << randomizedSet.getRandom() << std::endl;

	return 0;
}