//
// Created by Paulius on 2018-06-16.
//

#ifndef NEWSTUDENT_FUNCTIONS_H
#define NEWSTUDENT_FUNCTIONS_H

#include <string>
#include <random>
#include <chrono>
#include <vector>

unsigned int generate_u_int(unsigned int, unsigned int,  std::mt19937&);
std::vector<unsigned int> generate_vector_u_i (size_t, size_t, size_t);
std::string generate_string (size_t, size_t, std::mt19937&);

#endif //NEWSTUDENT_FUNCTIONS_H
