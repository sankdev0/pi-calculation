// pi-calculation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include "common-header.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

    double pi;

    //std::cout << "1. Демо вычисления числа Пи в одном потоке\n";
    //pi = calc_pi_single_threaded();
    //printf("Полученное значение числа Пи: %15.12f\n", pi);

    std::cout << "2. Демо вычисления числа Пи в нескольких потоках\n";
    pi = calc_pi_multi_threaded();
    printf("Полученное значение числа Пи: %15.12f\n", pi);

}