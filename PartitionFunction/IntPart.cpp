/******************************************************************************
*   IntPart.cpp                                                               *
*******************************************************************************
*   2025 © Guillermo M. Davila Andino                                         *
*   All rights reserved.                                                      *
*******************************************************************************                                                                             *
*   This program uses the "partition" function in "IntPart.h"                 *
*   to compute any integer partition given enough resources.                  *
******************************************************************************/

#include "IntPart.h"

int main() {
	std::cout << "Integer Partition! ";
	unsigned long long PartitionCount = 0;
	unsigned long long N;
	std::cout << "Enter Integer: ";
	std::cin >> N;
	while (N != 0) {

		
		std::cout << "Partitions:" << std::endl;
		PartitionCount = 0;
		for (unsigned long long P = 0; P <= N; P++) {
			// Here, we exploit the fact that the integer partition of an integer equals
			// the union of the partitions of that integer into K parts, for 1<=k<=N.
			std::set<std::vector<unsigned long long>> PartitionResults = partition(N, P);
			PartitionCount += PartitionResults.size();
			/*for (auto& i : PartitionResults) {
				PrntPrts(i);
			}*/

		}
		std::cout << "\nTotal: " << std::to_string(PartitionCount) << std::endl;
		std::cout << "Enter Integer: ";
		std::cin >> N;
	}
	return 0;
}