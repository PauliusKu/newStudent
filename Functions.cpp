//
// Created by Paulius on 2018-06-16.
//

#include "Functions.h"

unsigned int generate_u_int(const unsigned int min, const unsigned int max,  std::mt19937& mt)
{
    std::uniform_int_distribution<unsigned int> dist(min,max);
    return dist(mt);
}

std::vector<unsigned int>generate_vector_u_i (const size_t vec_size, const size_t min, const size_t max)
{
    std::vector<unsigned int> vect;
    std::random_device rd;
    std::mt19937 mt(static_cast<unsigned int>(time(nullptr)));
    std::uniform_int_distribution<unsigned int> dist(min,max);
    for (size_t i = 0; i < vec_size; i++)
    {
        vect.push_back(dist(mt));
    }
    return vect;
}

std::string generate_string (const size_t min_size, const size_t max_size, std::mt19937 &mt)
{
    std::uniform_int_distribution<unsigned int> dist(97,122);
    std::string s;
    s.push_back((char)(dist(mt)-32));
    for (int i = 0; i < (int)dist(mt)-95; i++) //generuoja pavarde
    {
        s.push_back((char)dist(mt));
    }
    return s;
}
