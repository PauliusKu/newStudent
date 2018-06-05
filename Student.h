//
// Created by Paulius on 2018-06-03.
//

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <utility>

class Person{
private:
    std::string Name;
    std::string Surename;
public:
    /**
        * @brief      Constructor for an empty Person object
    */
    Person () : Name(""), Surename("") {};
    /**
        * @brief      Constructor for an filled Person object
    */
    explicit Person (std::string n = "", std::string s = "") : Name(n), Surename(s){}

    /**
        * @brief      This function prints all Person's data
    */
    void printPerson()
    {
        std::cout << "Name: " << Name << std::endl;
        std::cout << "Surename: " << Surename << std::endl;
    }

};

class Student : public Person {
private:
    std::vector<unsigned int> Marks;
    unsigned int Exam_mark;
    double Final_Average;
    double Final_Median;

public:
    /**
        * @brief      Constructor for an empty Student object
    */
    Student() : Person{nullptr}, Exam_mark(1), Final_Average(1), Final_Median(1) {}

    /**
        * @brief      Constructor for an filled Student object
    */
    Student(std::string n, std::string s, unsigned int e, std::vector<unsigned int> m) : Person{n, s}, Exam_mark(e), Marks(m), Final_Average(e), Final_Median(e) {}
    /**
        * @brief      This function prints all Student's data
    */
    void printStudent()
    {
        printPerson();
        std::cout << "Marks: " << std::endl;
        for (auto & itr : Marks)
        {
            std::cout << itr << std::endl;
        }
        std::cout << "Exam_mark: " << Exam_mark << std::endl;
        std::cout << "Finals: " << Final_Average << " " << Final_Median << std::endl;
    }
};
class FinalStudent : public Person{
private:
    unsigned int Final_mark{};
public:
    /**
        * @brief      Constructor for an empty FinalStudent object
    */
    FinalStudent() : Person{nullptr}, Final_mark(0){}

    /**
        * @brief      Constructor for an filled FinalStudent object
    */
    FinalStudent(std::string n, std::string s, unsigned int e) : Person{n, s}, Final_mark(e) {}

    void printFinalStudent()
    {
        printPerson();
        std::cout << Final_mark << std::endl;
    }
};

#endif //STUDENT_H
