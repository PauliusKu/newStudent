//
// Created by Paulius on 2018-06-03.
//

#ifndef NEWSTUDENT_STUDENT_H
#define NEWSTUDENT_STUDENT_H

#include <string>
#include <vector>

class Person{
private:
    std::string Name;
    std::string Surename;

};

class Student : public Zmogus{
private:
    std::vector<unsigned int> Marks;
    unsigned int Exam_mark;
    double int Final_mark;
};
#endif //NEWSTUDENT_STUDENT_H
