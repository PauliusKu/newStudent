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
                case 2: input_student(); a = 10; break;
                case 3: read_from_file(); a = 10; break;
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
                            size = intFromString(2, 7);
                        }catch (const char* msg) {
                            std::cout << msg << std::endl;
                            t = true;
                        }
                    }while (t);
                    std::cout << "1-----------------------------------------------------------------------------------" << std::endl;
                    for (unsigned int i = 2; i <= size; i++) {
                        generate_file(pow(10, i)); //generuoja faila
                        auto start = std::chrono::high_resolution_clock::now();
                        read_from_file(false);
                        auto end = std::chrono::high_resolution_clock::now();
                        std::cout << "Vector Dydis: "<< std::setw(8)<< (int)pow(10, i) << "  |  "<< std::chrono::duration<double>(end-start).count() << " sekundes" << std::endl;

                    }
                    generate_file(0);; // sukuria tuscia faila
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
    std::cout << "Pasirinkote: random generavimas" << std::endl;
    Student s;
    s.random_Student();
    s.print_Student();
    std::cout << "Funkcijos pabaiga" << std::endl;
    std::cout << "-----------------------------------------------------------------------------------------------------------" << std::endl;

}

void generate_file(unsigned int n)
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

void input_student()
{
    Student s;

    s.set_Name_Surename();

    std::cout << "Pasirinkote: ivestis per konsole. Noredami pabaigti pazymiu ivedima, iveskite 0" << std::endl;
    unsigned int a = 0;
    bool t = true;

    do{ //ivedimas is konsoles
        std::cout << s.get_marks_size()+1 << "-asis pazymys ";
        try{
            a = intFromString(0, 10);
            if (a == 0)
            {
                if (s.get_marks_size() == 0)
                {
                    throw "Neivedete nei vieno pazymio";
                } else t = false;
                std::cout << "Pazymiu ivedimas baigtas" << std::endl;
            } else s.push_back(a);
        }catch (const char* msg) {
            std::cout << msg << std::endl;
        }
    }while (t);

    do{ //ivedimas is konsoles
        std::cout << "Mokinio egzamino ivertinimas: ";
        t = false;
        try{
            a = intFromString(1, 10);
        }catch (const char* msg) {
            std::cout << msg << std::endl;
            t = true;
        }
    }while (t);
    s.set_Exam_mark(a);
    s.calculate_finals();
    s.print_Student();

    std::cout << "Funkcijos pabaiga" << std::endl;
    std::cout << "-----------------------------------------------------------------------------------------------------------" << std::endl;
}

bool Less(Student &stud){
    return stud.get_average() < 6;
}

bool customCompare(Student &stud1, Student &stud2){
    return stud1.get_surename() < stud2.get_surename();
}

void read_from_file(const bool b)
{
    vector_s Stud;
    //auto start = std::chrono::high_resolution_clock::now();
    read_data(Stud);
    //auto end = std::chrono::high_resolution_clock::now();
    //std::cout << std::chrono::duration<double>(end-start).count() << " sekundes" << std::endl;

    auto start1 = std::chrono::high_resolution_clock::now();
    std::sort(Stud.begin(), Stud.end(), customCompare);
    auto it = Stud.end();
    auto pivot = std::stable_partition (Stud.begin(), Stud.end(), Less);

    auto end1 = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration<double>(end1-start1).count() << " sekundes" << std::endl;

    vector_s Win(std::distance(pivot, Stud.end()));

    std::copy(pivot, Stud.end(), Win.begin());

    advance(it, -1);
    advance(pivot, -1);
    Stud.resize(Stud.size()-Win.size());

    if (b)
    {
        std::cout << "LOSERS" << std::endl;
        for (size_t i = 0; i < Stud.size(); i++)
        {
            Stud[i].print_Person();
            Stud[i].print_Student_Finals();
            std::cout << std::endl;
        }
        std::cout << "WINNERS" << std::endl;
        for (size_t i = 0; i < Win.size(); i++)
        {
            Win[i].print_Person();
            Win[i].print_Student_Finals();
            std::cout << std::endl;
        }
    }
}

void read_data(vector_s &vect)
{
    std::ifstream myfile("Failas.txt");
    while (!myfile.eof())
    {
        Student in;
        std::string input{};
        std::vector<std::string> words;
        std::getline(myfile, input);
        std::stringstream ss(input);

        std::string temp;
        while (ss >> temp)
        {
            words.push_back(temp);
        }
        if (words.size() > 3)
        {
            in.set_name(words[0]);
            in.set_surename(words[1]);
            for (size_t j = 2; j < words.size()-1; j++)
            {
               in.push_back((unsigned int)std::stoi(words[j]));
            }
            in.set_Exam_mark((unsigned int)std::stoi(words[words.size()-1]));
            in.calculate_finals();
            vect.push_back(in);
        }
    }
    myfile.close();
}