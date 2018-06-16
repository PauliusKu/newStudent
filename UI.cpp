//
// Created by Paulius on 2018-06-16.
//

#include <iostream>
#include <fstream>
#include <string>
#include "UI.h"


void UI()
{
    unsigned int a = 10;
    do{
        std::cout << "Funkcijos: 1 - random generavimas, 2 - ivestis per konsole, 3 - ivestis is failo, 4 - generuoti faila, 5 - testas, 0 - iseiti." << std::endl;
        try{
            a = intFromString(0, 5);

            switch(a)
            {
                case 1: generate_student(); a = 10; break;
                case 2: a = 10; break;
                case 3: a = 10; break;
                case 4: //failo generavimas
                {
                   size_t n{};
                    bool t = true;
                    do{
                        std::cout << "Iveskite, kokio dydzio faila norite sugeneruoti (1-10^7) " << std::endl;
                        t = false;
                        try{
                            n = intFromString(0, 10000000);
                        }catch (const char* msg) {
                            std::cout << msg << std::endl;
                            t = true;
                        }
                    }while (t);
                    generate_file(n);
                    a = 10;
                    break;
                }
                case 5:
                {
                    unsigned int size{};
                    bool t = true;
                    do{
                        std::cout << "Iveskite dydi x (10^x , Max 10^7): " << std::endl;
                        t = false;
                        try{
                            a = intFromString(2, 7);
                        }catch (const char* msg) {
                            std::cout << msg << std::endl;
                            t = true;
                        }
                    }while (t);
                    std::cout << "1-----------------------------------------------------------------------------------" << std::endl;
//                    for (unsigned int i = 2; i <= size; i++) {
//                        //GeneruotiFaila(pow(10, i)); //generuoja faila
//                        auto start = std::chrono::high_resolution_clock::now();
//                        Failas < std::vector < Mokiniai >> (false);
//                        auto end = std::chrono::high_resolution_clock::now();
//                        cout << "Vector Dydis: " << std::setw(8) << (int) pow(10, i) << "  |  "
//                             << std::chrono::duration<double>(end - start).count() << " sekundes" << endl;
//                        auto start1 = std::chrono::high_resolution_clock::now();
//                        Failas < std::deque < Mokiniai >> (false);
//                        auto end1 = std::chrono::high_resolution_clock::now();
//                        cout << "Deque  Dydis: " << std::setw(8) << (int) pow(10, i) << "  |  "
//                             << std::chrono::duration<double>(end1 - start1).count() << " sekundes" << endl;
//                        auto start2 = std::chrono::high_resolution_clock::now();
//                        Failas < std::list < Mokiniai >> (false);
//                        auto end2 = std::chrono::high_resolution_clock::now();
//                        cout << "List   Dydis: " << std::setw(8) << (int) pow(10, i) << "  |  "
//                             << std::chrono::duration<double>(end2 - start2).count() << " sekundes" << endl;
//                        cout << "-----------------------------------------------------------------------------------"
//                             << endl;
//                    }
                    //GeneruotiFaila(0); // sukuria tuscia faila
                    a = 10;
                    break;
                }
                case 0: std::cout << "Programos pabaiga." << std::endl; break;
            }
        }catch (const char* msg)
        {
            std::cout << msg << std::endl;
        }
    }while(a == 10);
}

unsigned int intFromString(int a, int b)
{

    do {
        try {
            std::cin.exceptions(std::ifstream::failbit);
            int c{};
            std::string num{};
            std::getline(std::cin, num);

            if (num == "")
            {
                throw std::invalid_argument("nothing_here");
            }
            for (unsigned int i = 0; i < num.size(); i++)
            {
                if (((int)num[i] < 45 || (int)num[i] > 57) || ((int)num[i] > 45 && (int)num[i] < 48))
                {
                    throw std::invalid_argument("bad_input");
                }
            }
            c = std::stoi(num);
            if (c >= a && c <= b)
            {
                return c;
            }
            else throw std::invalid_argument("too_big/small_number");

        }
        catch (std::invalid_argument& e)
        {
            std::cout << e.what() << std::endl;
            std::cout << "Please, rewrite your input:\n";
        }
    } while (true);
}

void generate_student()
{
    Student s;
    s.random_Student();
    s.print_Student();
}

void generate_file(unsigned int& n)
{
    std::ofstream of("Failas.txt"); //irasymo pradzia

    std::random_device rd;
    std::mt19937 mt(static_cast<unsigned int>(time(nullptr)));
    for (unsigned int i = 0; i < n; i++)
    {
        std::uniform_int_distribution<unsigned int> dist(97,122);
        of << generate_string(4, 15, mt) << " ";
        of << generate_string(5, 20, mt) << " ";

        std::uniform_int_distribution<int> distint(1, 10);
        for (int i = 0; i < (int)dist(mt)-95; i++) //generuoja pazymius
        {
            of << distint(mt) << " ";
        }
        of << std::endl;
    }
    of.close();
}