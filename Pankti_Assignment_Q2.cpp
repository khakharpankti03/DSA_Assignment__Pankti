#include <iostream>
#include <string>
using namespace std;
class MyStack {
private:
    char *arr;
    int capacity;
    int topIndex;
public:
    MyStack(int cap) {
        capacity = cap;
        arr = new char[capacity];
        topIndex = -1;
    }
    ~MyStack() {
        delete[] arr;
    }
    bool empty() const {
        return (topIndex == -1);
    }
    char top() const {
        return arr[topIndex];
    }
    void push(char c) {
        if (topIndex + 1 < capacity) {
            arr[++topIndex] = c;
        }
    }
    void pop() {
        if (!empty()) {
            topIndex--;
        }
    }
    int size() const {
        return (topIndex + 1);
    }
    string toString() const {
        return string(arr, arr + topIndex + 1);
    }
};
string removeAllAdjacentDuplicates(string s) {
    int n = s.length();
    MyStack st(n);
    for (int i = 0; i < n; ++i) {
        char c = s[i];
        if (!st.empty() && st.top() == c) {
            st.pop();
        }
        else {
            st.push(c);
        }
    }
    return st.toString();
}
int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    string result = removeAllAdjacentDuplicates(s);
    cout << "String after removing adjacent duplicates: " << result << endl;
    return 0;
}
