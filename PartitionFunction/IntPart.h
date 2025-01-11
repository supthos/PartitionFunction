/******************************************************************************
*   IntPart.h                                                                 *
*******************************************************************************
*   2025 � Guillermo M. Davila Andino                                         *
*   All rights reserved.                                                      *
*******************************************************************************
*   This header file implements an integer partition function "partition"     *
*   to part unsigned integers into k parts in standard ISO C++20.             *
******************************************************************************/

#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <algorithm>

void PrntPrts(std::vector<unsigned long long> Parts) {
	std::string Partition;
	for (unsigned long long j = 0; j < Parts.size(); j++) {
		Partition = Partition + std::to_string(Parts[j]);
		if (j >= 0 && (j + 1 < Parts.size())) Partition = Partition + ", ";
	}
	std::cout << Partition << std::endl;
}

std::set<std::vector<unsigned long long>> partition(unsigned long long Number, unsigned long long Parts) {
	unsigned long long Sum = 0;
	std::vector<unsigned long long> Par;

	std::set<std::vector<unsigned long long>> PartitionTree;
	std::set<std::vector<unsigned long long>> NewPartTree;
	std::set<std::vector<unsigned long long>> Partitions;

	if (Parts == 0) {
		if (Number == 0) {
			Par.push_back(0);
			Partitions.insert(Par);
		}
		return Partitions;
	}
	for (unsigned long long i = 0; i < Parts; i++) {
		Par.push_back(1);
		Sum++;
	}
	//std::sort(Par.begin(), Par.end());
	while (Sum <= Number) {
		PartitionTree.insert(Par);
		if (Par.size() > 0) Par[Parts - 1]++;
		Sum = 0;
		for (unsigned long long i : Par) {
			Sum += i;

		}	
	}

	// Now, all the elements of PartitionTree have Sum < Number


	for (unsigned long long i = 0; i < Number; i++) {
		NewPartTree.clear();
		for (auto& j : PartitionTree) {

			Sum = 0;
			for (unsigned long long k : j) {
				Sum += k;
			}
			if (Sum <= Number && j[Parts - 1] >= i) {
				Par = j;
				//std::sort(Par.begin(), Par.end());

				for (unsigned long long k = 1; k < Number && Sum <= Number; k++) {
					std::sort(Par.begin(), Par.end());
					if (Sum == Number) {
						Partitions.insert(Par);
					}
					if (j[Parts - 1] >= i + 1 && Sum < Number) {
						NewPartTree.insert(Par);
					}
					

					Par[(Parts + Parts - k) % Parts]++;

					Sum = 0;
					for (unsigned long long l : Par) Sum += l;

				}
			}
		}
		PartitionTree.clear();
		PartitionTree = NewPartTree;

	}

	return Partitions;
}
