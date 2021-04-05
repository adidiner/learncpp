#include <array>
#include <cassert>
#include <iostream>

class Stack {
private:
    static constexpr int MAX_SIZE = 10;
    std::array<int, MAX_SIZE> m_stack_array{};
    size_t m_size = 0;

public:
    void reset() {
        m_size = 0;
    }

    bool push(int value) {
        if (m_size == MAX_SIZE) { // stack is full
            return false;
        }

        m_stack_array[m_size++] = value;
        return true;
    }

    int pop() {
        assert (m_size > 0);
        return m_stack_array[--m_size];
    }

    void print() {
        std::cout << "( ";
        for (size_t i = 0; i < m_size; ++i) {
            std::cout << m_stack_array[i] << ' ';
        }
        std::cout << ")\n";
    }
};

int main() {
    Stack stack;
    stack.reset();
 
    stack.print();
 
    stack.push(5);
    stack.push(3);
    stack.push(8);
    stack.print();
 
    stack.pop();
    stack.print();
 
    stack.pop();
    stack.pop();
 
    stack.print();

    return 0;
}
