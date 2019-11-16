// Algo1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "median.h"
#include <iostream>
#include <vector>
#include <stdlib.h>

#include "Timer.h"

int main()
{
	int n = 1000000;
	int medianIndex = n / 2;
	std::vector<int> arr;
	for (int i = 0; i < n; i++) {
		int randInt = rand() % n + 1;
		arr.push_back(randInt);
	}

	Timer::start();
	std::cout << "Median ist " << median::sortedMedian(arr, medianIndex) << std::endl;
	Timer::stop();

	Timer::start();
	std::cout << "Median ist " << median::randomizedSelect(arr, 0, arr.size() - 1, medianIndex + 1) << std::endl;
	Timer::stop();

	Timer::start();
	std::cout << "Median ist " << median::torben(arr, n) << std::endl;
	Timer::stop();

	Timer::start();
	std::cout << "Median ist " << median::cppMedian(arr, medianIndex) << std::endl;
	Timer::stop();
}