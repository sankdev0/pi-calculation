// pi-calculation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include "common-header.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������

    double pi;

    //std::cout << "1. ���� ���������� ����� �� � ����� ������\n";
    //pi = calc_pi_single_threaded();
    //printf("���������� �������� ����� ��: %15.12f\n", pi);

    std::cout << "2. ���� ���������� ����� �� � ���������� �������\n";
    pi = calc_pi_multi_threaded();
    printf("���������� �������� ����� ��: %15.12f\n", pi);

}