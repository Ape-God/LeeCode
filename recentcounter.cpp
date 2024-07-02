#include <iostream>
#include <deque>
#include<queue>
using namespace std;

//class RecentCounter {
//private:
//    deque<int> requests;
//
//public:
//    RecentCounter() {
//        // ���캯����ʼ������Ϊ��
//    }
//
//    int ping(int t) {
//        // ����ǰʱ�����ӵ�����ĩβ
//        requests.push_back(t);
//
//        // �Ƴ����ڵ�ʱ���
//        while (!requests.empty() && requests.front() <= t - 3000) {
//            requests.pop_front();
//        }
//
//        // ���ص�ǰ���еĴ�С������ȥ3000�����ڵ�������
//        return requests.size();
//    }
//};


class RecentCounter {
private:
    queue<int> q;
public:
    RecentCounter() {

    }

    int ping(int t) {
        q.push(t);

        while (q.front() < t - 3000) {
            q.pop();
        }
        return q.size();
    }
};


int main() {
    RecentCounter rc;
    cout << "Request at 1ms, ping count: " << rc.ping(1) << endl;  // 1
    cout << "Request at 100ms, ping count: " << rc.ping(100) << endl; // 2
    cout << "Request at 3000ms, ping count: " << rc.ping(3000) << endl; // 3
    cout << "Request at 3001ms, ping count: " << rc.ping(3001) << endl; // 3 (��һ�������ѹ���)
    return 0;
}