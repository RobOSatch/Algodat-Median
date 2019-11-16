#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <iterator>

namespace median {
	
	// Quicksort first then return median
	int partition(std::vector<int>& arr, int left, int right, int pivot) {
		while (left <= right) {
			while (arr[left] < pivot) {
				left++;
			}
			while (arr[right] > pivot) {
				right--;
			}

			if (left <= right) {
				std::swap(arr[left], arr[right]);
				left++;
				right--;
			}
		}

		return left;
	}

	void quicksort(std::vector<int>& arr, int left, int right) {
		if (left >= right) return;

		int pivot = arr[left + (std::rand() % (right - left + 1))];
		int index = partition(arr, left, right, pivot);
		quicksort(arr, left, index - 1);
		quicksort(arr, index, right);
	}

	int sortedMedian(std::vector<int> arr, int i) {
		quicksort(arr, 0, arr.size() - 1);
		return arr[i];
	}

	int randomizedPartition(std::vector<int> &arr, int p, int r) {
		int pivot = p + (std::rand() % (r - p + 1));
		std::swap(arr[p], arr[pivot]);
		pivot = p;
		p++;
		
		while (p <= r) {
			if (arr[p] < arr[pivot]) {
				std::swap(arr[p], arr[pivot]);
				pivot = p;
				p++;
			}
			else {
				std::swap(arr[p], arr[r]);
				r--;
			}
		}

		return pivot;
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

	// Torben
	int torben(std::vector<int> arr, int n) {
		int i, less, greater, equal, min, max, guess, maxltguess, mingtguess;

		min = max = arr[0];
		for (i = 1; i < n; i++) {
			if (arr[i] < min) min = arr[i];
			if (arr[i] > max) max = arr[i];
		}

		while (true) {
			guess = (min + max) / 2;
			less = 0;
			greater = 0;
			equal = 0;
			maxltguess = min;
			mingtguess = max;

			for (int i = 0; i < n; i++) {
				if (arr[i] < guess) {
					less++;
					if (arr[i] > maxltguess) maxltguess = arr[i];
				}
				else if (arr[i] > guess) {
					greater++;
					if (arr[i] < mingtguess) mingtguess = arr[i];
				}
				else equal++;
			}

			if (less <= (n + 1) / 2 && greater <= (n + 1) / 2) break;
			else if (less > greater) max = maxltguess;
			else min = mingtguess;
		}

		if (less >= (n + 1) / 2) return maxltguess;
		else if (less + equal >= (n + 1) / 2) return guess;
		else return mingtguess;
	}

	// C++ nth-element
	int cppMedian(std::vector<int> arr , int i) {
		std::nth_element(arr.begin(), arr.begin() + i, arr.end());
		return arr[i];
	}

}