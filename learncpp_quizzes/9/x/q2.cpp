#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string name{};
    int grade{};
};

bool student_compare(const Student& a, const Student& b) {
    return (a.grade > b.grade);
}

std::vector<Student>::size_type input_student_num() {
    std::vector<Student>::size_type input{};
    std::cout << "How many students are there? ";
    std::cin >> input;
    return input;
}

void input_students(std::vector<Student>& students) {
    for (auto& student : students) {
        std::cout << "Input student name: ";
        std::cin >> student.name;
        std::cout << "Input " << student.name << "'s grade: ";
        std::cin >> student.grade;
    }
    std::cout << '\n';
}

void print_students(const std::vector<Student>& students) {
    for (const auto& student : students) {
        std::cout << student.name << " got a grade of " << student.grade << '\n';
    }
}

int main() {
    std::vector<Student>::size_type length{input_student_num()};
    std::vector<Student> students(length);
    input_students(students);

    std::sort(students.begin(), students.end(), student_compare);
    print_students(students);
    
    return 0;
}
