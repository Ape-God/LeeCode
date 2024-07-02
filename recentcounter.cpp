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
//        // 构造函数初始化队列为空
//    }
//
//    int ping(int t) {
//        // 将当前时间戳添加到队列末尾
//        requests.push_back(t);
//
//        // 移除过期的时间戳
//        while (!requests.empty() && requests.front() <= t - 3000) {
//            requests.pop_front();
//        }
//
//        // 返回当前队列的大小，即过去3000毫秒内的请求数
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
    cout << "Request at 3001ms, ping count: " << rc.ping(3001) << endl; // 3 (第一个请求已过期)
    return 0;
}