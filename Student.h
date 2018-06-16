//
// Created by Paulius on 2018-06-03.
//

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include "Functions.h"
#include <iomanip>

typedef std::vector<unsigned int> vector_u_i;

class Person{
private:
    std::string Name_;
    std::string Surename_;
public:
    /**
        * @brief      Constructor for an empty Person object
    */
    Person () : Name_(""), Surename_("") {};
    /**
        * @brief      Constructor for an filled Person object
    */
    explicit Person (std::string n = "", std::string s = "") : Name_(n), Surename_(s){}

    /**
        * @brief      This function prints all Person's data
    */
    void print_Person(std::ostream& s = std::cout)
    {
        s << std::setw(20) << std::left << Name_;
        s << std::setw(20) << std::left << Surename_;
    }
    void random_Person()
    {
        generate_2_strings(4, 20, Name_, Surename_);
    }
    void set_name(std::string n = "")
    {
        Name_ = n;
    }
    void set_surename(std::string s = "")
    {
        Surename_ = s;
    }
    void set_Name_Surename()
    {
        std::cout << "Mokinio vardas: " << std::endl;
        getline(std::cin, Name_);
        std::cout << "Mokinio pavarde: " << std::endl;
        getline(std::cin, Surename_);
    }

    std::string get_name()
    {
        return Name_;
    }
	std::string get_surename()
    {
        return "fbfdbfbfdb";
    }
};

class Student : public Person {
private:
    vector_u_i Marks_;
    unsigned int Exam_mark_;
    double Final_Average_;
    double Final_Median_;

public:

    /**
        * @brief      Constructor for an empty Student object
    */
    Student() : Person{"", ""}, Exam_mark_(1), Final_Average_(1), Final_Median_(1) {}

    /**
        * @brief      Constructor for an filled Student object
    */
    Student(std::string n, std::string s, unsigned int e, vector_u_i m) : Person{n, s}, Exam_mark_(e), Marks_(m), Final_Average_(get_average()), Final_Median_(get_median()) {}
    /**
        * @brief      This function prints all Student's data
    */

    void print_Student(std::ostream& s = std::cout, const bool finals = true)
    {
        print_Person(s);
        for (auto & itr : Marks_)
        {
            s << itr << " ";
        }
        s << Exam_mark_ << std::endl;
        if (finals)
        {
            s << std::fixed;
            s << std::setprecision(2) << "Final average: " << Final_Average_ << std::endl;
            s << std::setprecision(2) << "Final median: " << Final_Median_ << std::endl;
        }
    }

	inline bool operator<(const Student & stud) { return stud.Final_Average_ - Final_Average_ < 0; }

    void print_Student_Finals(std::ostream& s = std::cout)
    {
        s << std::fixed;
        s << std::setprecision(2) << Final_Average_ <<" ";
        s << std::setprecision(2) << Final_Median_;
    }

    void random_Student()
    {
        random_Person();
        std::mt19937 mt(static_cast<unsigned int>(time(nullptr)));
        Marks_= generate_vector_u_i(generate_u_int(2, 12, mt), 1, 10);
        Exam_mark_ = generate_u_int(1, 10, mt);
        Final_Average_ = get_average();
        Final_Median_ = get_median();
    }

    double get_average()
    {
        return (double)(std::accumulate(Marks_.begin(), Marks_.end(), (unsigned int)0))/Marks_.size()*0.4+Exam_mark_*0.6;
    }
    double get_median()
    {
        std::sort(Marks_.begin(), Marks_.end());
        if (Marks_.size() % 2 == 1)
        {
            return (Marks_[Marks_.size()/2])*0.4+Exam_mark_*0.6;
        } else return (double)(Marks_[Marks_.size()/2] + (double)(Marks_[Marks_.size()/2-1]))/2*0.4+Exam_mark_*0.6;
    }
    size_t get_marks_size()
    {
        return Marks_.size();
    }
    void push_back(const unsigned int &val)
    {
        Marks_.push_back(val);
    }
    void set_Exam_mark(const unsigned int &val)
    {
        Exam_mark_ = val;
    }
    void calculate_finals()
    {
        Final_Median_ = get_median();
        Final_Average_ = get_average();
    }
};
//class FinalStudent : public Person{
//private:
//    unsigned int Final_mark_{};
//public:
//    /**
//        * @brief      Constructor for an empty FinalStudent object
//    */
//    FinalStudent() : Person{"", ""}, Final_mark_(0){}
//
//    /**
//        * @brief      Constructor for an filled FinalStudent object
//    */
//    FinalStudent(std::string n, std::string s, unsigned int e) : Person{n, s}, Final_mark_(e) {}
//
//    void print_FinalStudent(std::ostream& s = std::cout)
//    {
//        print_Person(s);
//        s << Final_mark_ << std::endl;
//    }
//
//    void random_FinalStudent()
//    {
//        random_Person();
//        std::mt19937 mt(static_cast<unsigned int>(time(nullptr)));
//        Final_mark_ = generate_u_int(1, 10, mt);
//    }
//};

typedef std::vector<Person> vector_p;
typedef std::vector<Student> vector_s;
//typedef std::vector<FinalStudent> vector_f;


#endif //STUDENT_H
