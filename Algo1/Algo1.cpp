// Algo1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "median.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "Timer.h"

int main()
{
	// Randomize seed
	srand(time(NULL));

	std::cout << "MEDIAN" << std::endl << std::endl;

	// Generates n random numbers 
	int n = 10000000;
	int medianIndex = n / 2;

	std::vector<int> arr;
	for (int i = 0; i < n; i++) {
		int randInt = rand() % n + 1;
		arr.push_back(randInt);
	}

	srand(time(NULL));
	int median;

	// Check if the array is even or odd numbered and calculate the according median
	if (n % 2 != 0) {
		Timer::start();
		median = median::sortedMedian(arr, medianIndex);
		Timer::stop();

		Timer::start();
		median::randomizedSelect(arr, 0, arr.size() - 1, medianIndex + 1);
		Timer::stop();

		Timer::start();
		median::torben(arr, n);
		Timer::stop();

		Timer::start();
		median::cppMedian(arr, medianIndex);
		Timer::stop();
	}
	else {
		Timer::start();
		(median::sortedMedian(arr, medianIndex) + median::sortedMedian(arr, medianIndex - 1)) / 2;
		Timer::stop();

		Timer::start();
		(median::randomizedSelect(arr, 0, arr.size() - 1, medianIndex + 1) + median::randomizedSelect(arr, 0, arr.size() - 1, medianIndex)) / 2;
		Timer::stop();

		Timer::start();
		median::torben(arr, n);
		Timer::stop();

		Timer::start();
		(median::cppMedian(arr, medianIndex) + median::cppMedian(arr, medianIndex - 1)) / 2;
		Timer::stop();
	}

	std::getchar();
	return 0;
}