//
// Created by Paulius on 2018-06-16.
//

#ifndef NEWSTUDENT_UI_H
#define NEWSTUDENT_UI_H

#include "Student.h"
#include <sstream>
#include <algorithm>

unsigned int intFromString(int, int);
void generate_student();
void UI();
void generate_file(unsigned int);
void input_student();
void read_data(vector_s &);
void read_from_file(bool b = true);
#endif //NEWSTUDENT_UI_H
