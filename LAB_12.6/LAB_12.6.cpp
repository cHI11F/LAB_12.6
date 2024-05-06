#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <ctime>

using namespace std;

// Реалізація черги за допомогою списку
class QueueList {
private:
    list<int> queue;
public:
    void enqueue(int item) {
        queue.push_back(item);
    }

    int dequeue() {
        if (is_empty())
            return -1;
        int front = queue.front();
        queue.pop_front();
        return front;
    }

    bool is_empty() {
        return queue.empty();
    }

    int size() {
        return static_cast<int>(queue.size());
    }

    void print_queue() {
        cout << "Queue (List): ";
        for (auto it = queue.begin(); it != queue.end(); ++it)
            cout << *it << " ";
        cout << endl;
    }
};

// Реалізація черги за допомогою масиву
class QueueArray {
private:
    vector<int> queue;
public:
    void enqueue(int item) {
        queue.push_back(item);
    }

    int dequeue() {
        if (is_empty())
            return -1;
        int front = queue[0];
        queue.erase(queue.begin());
        return front;
    }

    bool is_empty() {
        return queue.empty();
    }

    int size() {
        return static_cast<int>(queue.size());
    }

    void print_queue() {
        cout << "Queue (Array): ";
        for (int i = 0; i < queue.size(); ++i)
            cout << queue[i] << " ";
        cout << endl;
    }
};

// Реалізація черги за допомогою двох стеків
class QueueTwoStacks {
private:
    stack<int> in_stack;
    stack<int> out_stack;
public:
    void enqueue(int item) {
        in_stack.push(item);
    }

    int dequeue() {
        if (out_stack.empty()) {
            while (!in_stack.empty()) {
                out_stack.push(in_stack.top());
                in_stack.pop();
            }
        }
        if (out_stack.empty())
            return -1;
        int front = out_stack.top();
        out_stack.pop();
        return front;
    }

    bool is_empty() {
        return in_stack.empty() && out_stack.empty();
    }

    int size() {
        return static_cast<int>(in_stack.size()) + static_cast<int>(out_stack.size());
    }

    void print_queue() {
        cout << "Queue (Two Stacks): ";
        stack<int> temp_stack = out_stack;
        while (!temp_stack.empty()) {
            cout << temp_stack.top() << " ";
            temp_stack.pop();
        }
        stack<int> temp_in_stack;
        while (!in_stack.empty()) {
            temp_in_stack.push(in_stack.top());
            in_stack.pop();
        }
        while (!temp_in_stack.empty()) {
            cout << temp_in_stack.top() << " ";
            temp_in_stack.pop();
        }
        cout << endl;
    }
};

// Порівняння швидкодії операцій
void compare_operations(QueueList& list_queue, QueueArray& array_queue, QueueTwoStacks& two_stacks_queue) {
    cout << "Queue Operations Comparison:" << endl;
    cout << "Initial Queues:" << endl;
    list_queue.print_queue();
    array_queue.print_queue();
    two_stacks_queue.print_queue();

    // Додавання елементу
    clock_t start_time = clock();
    list_queue.enqueue(1);
    clock_t end_time = clock();
    cout << "Time taken for enqueue operation (List): " << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC << endl;

    start_time = clock();
    array_queue.enqueue(1);
    end_time = clock();
    cout << "Time taken for enqueue operation (Array): " << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC << endl;

    start_time = clock();
    two_stacks_queue.enqueue(1);
    end_time = clock();
    cout << "Time taken for enqueue operation (Two Stacks): " << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC << endl;

    // Вилучення елементу
    start_time = clock();
    list_queue.dequeue();
    end_time = clock();
    cout << "Time taken for dequeue operation (List): " << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC << endl;

    start_time = clock();
    array_queue.dequeue();
    end_time = clock();
    cout << "Time taken for dequeue operation (Array): " << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC << endl;

    start_time = clock();
    two_stacks_queue.dequeue();
    end_time = clock();
    cout << "Time taken for dequeue operation (Two Stacks): " << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC << endl;

    // Пошук елементу (просто перевірка чи він є у черзі)
    start_time = clock();
    bool is_empty_list = list_queue.is_empty();
    end_time = clock();
    cout << "Time taken for checking if queue is empty (List): " << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC << endl;
    cout << "Is list queue empty: " << (is_empty_list ? "Yes" : "No") << endl;

    start_time = clock();
    bool is_empty_array = array_queue.is_empty();
    end_time = clock();
    cout << "Time taken for checking if queue is empty (Array): " << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC << endl;
    cout << "Is array queue empty: " << (is_empty_array ? "Yes" : "No") << endl;

    start_time = clock();
    bool is_empty_two_stacks = two_stacks_queue.is_empty();
    end_time = clock();
    cout << "Time taken for checking if queue is empty (Two Stacks): " << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC << endl;
    cout << "Is two stacks queue empty: " << (is_empty_two_stacks ? "Yes" : "No") << endl;
}

int main() {
    QueueList list_queue;
    QueueArray array_queue;
    QueueTwoStacks two_stacks_queue;

    compare_operations(list_queue, array_queue, two_stacks_queue);

    return 0;
}
