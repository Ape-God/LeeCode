#include <iostream>
#include <vector>
#include <unordered_map>
#include <random>
#include <algorithm>

class RandomizedSet {
private:
	std::unordered_map<int, int> index_map; // �洢Ԫ�ص�������ӳ��
	std::vector<int> elements; // �洢����Ԫ��

public:
	RandomizedSet() {}

	bool insert(int val) {
		// ���Ԫ���Ѵ��ڣ�����false
		if (index_map.find(val) != index_map.end()) {
			return false;
		}
		// ��Ԫ����ӵ�vector�У�����¼����
		index_map[val] = elements.size();
		elements.push_back(val);
		return true;
	}

	bool remove(int val) {
		// ���Ԫ�ز����ڣ�����false
		if (index_map.find(val) == index_map.end()) {
			return false;
		}
		// �����һ��Ԫ���滻��Ҫɾ����Ԫ�ص�λ��
		int lastElement = elements.back();
		int toDeleteIndex = index_map[val];
		elements[toDeleteIndex] = lastElement;
		index_map[lastElement] = toDeleteIndex; // �������һ��Ԫ�ص�����ӳ��
		// ��map��vector��ɾ��ԭԪ��
		index_map.erase(val);
		elements.pop_back();
		return true;
	}

	int getRandom() {
		int randomIndex = rand() % elements.size();
		return elements[randomIndex];

		//// ���ѡ��һ��������Ȼ�󷵻ض�Ӧ��Ԫ��
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