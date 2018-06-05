#include <iostream>
#include "Student.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::vector<unsigned int> vec{4, 5, 7, 8};
    Student s("Lenkas", "Lenkauskas", 10, vec);
    s.printStudent();
    FinalStudent f("Simas", "fdvgsfgv", 5);
    f.printFinalStudent();

    return 0;
}