#include <iostream>
using namespace std;
class MyQueue {
private:
    int arr[10000];
    int front;
    int rear;
public:
    MyQueue() {
        front = 0;
        rear = -1;
    }
    void push(int val) {
        if (rear < 9999) {
            rear++;
            arr[rear] = val;
        } else {
            cout << "Queue overflow!" << endl;
        }
    }
    void pop() {
        if (!empty()) {
            front++;
        } else {
            cout << "Queue underflow!" << endl;
        }
    }
    int getFront() {
        return arr[front];
    }
    bool empty() {
        return front > rear;
    }
    int size() {
        return (rear - front + 1);
    }
};
class RecentCounter {
private:
    MyQueue q;
    const int WINDOW = 3000;
public:
    RecentCounter() {}
    int ping(int t) {
        q.push(t);
        while (!q.empty() && q.getFront() < t - WINDOW) {
            q.pop();
        }
        return q.size();
    }
};
int main() {
    RecentCounter obj;
    cout << "Ping(1): " << obj.ping(1) << endl;       // only [1]
    cout << "Ping(100): " << obj.ping(100) << endl;   // [1, 100]
    cout << "Ping(3001): " << obj.ping(3001) << endl; // [1, 100, 3001]
    cout << "Ping(3002): " << obj.ping(3002) << endl; // [100, 3001, 3002]
    return 0;
}
