/******************************************************************************
*   IntPart.h                                                                 *
*******************************************************************************
*   2025 © Guillermo M. Davila Andino                                         *
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

	while (Sum <= Number) {
		if (Sum == Number) {
			Partitions.insert(Par);
		} else PartitionTree.insert(Par);
		if (Par.size() > 0) Par[Parts - 1]++;
		Sum = 0;
		for (unsigned long long i : Par) {
			Sum += i;
		}	
	}

	for (unsigned long long i = 0; i < Number; i++) {
		while(!PartitionTree.empty()) {
			Par = *PartitionTree.begin();
			PartitionTree.erase(PartitionTree.begin());

			if (Par[Parts - 1] >= i) {
				for (unsigned long long k = 1; k <= Parts; k++) {
					Par[Parts - k]++;
					Sum = 0;
					for (unsigned long long l : Par) Sum += l;
					
					if (Sum == Number) {
						Partitions.insert(Par);
					}
					if (Par[Parts - 1] >= i + 1 && Sum < Number) {
						PartitionTree.insert(Par);
					}
				}
			}
		}
	}
	return Partitions;
}
