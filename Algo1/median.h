#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <iterator>

namespace median {
	
	// Quicksort first then return median
	int sortedMedian(std::vector<int> arr, int i) {
		std::sort(arr.begin(), arr.end());
		return arr[i];
	}

	int randomizedPartition(std::vector<int> &arr, int p, int r) {
		int randomIndex = p + (std::rand() % (r - p + 1));
		std::swap(arr[p], arr[randomIndex]);
		randomIndex = p;
		p++;
		
		while (p <= r) {
			if (arr[p] < arr[randomIndex]) {
				std::swap(arr[p], arr[randomIndex]);
				randomIndex = p;
				p++;
			}
			else {
				std::swap(arr[p], arr[r]);
				r--;
			}
		}

		return randomIndex;
	}

	// Randomized select
	int randomizedSelect(std::vector<int> arr, int p, int r, int i) {
		if (p == r) return arr[p];

		int q = randomizedPartition(arr, p, r);
		int k = q - p + 1;

		if (i == k) return arr[q];
		else if (i < k) return randomizedSelect(arr, p, q - 1, i);
		else return randomizedSelect(arr, q + 1, r, i - k);
	}

	// C++ nth-element
	int cppMedian(std::vector<int> arr , int i) {
		std::nth_element(arr.begin(), arr.begin() + i, arr.end());
		return arr[i];
	}

}