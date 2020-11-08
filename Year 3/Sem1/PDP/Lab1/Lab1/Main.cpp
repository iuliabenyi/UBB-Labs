#include <iostream>
#include "Bill.h"
#include "Transaction.h"
#include <Windows.h>
#include <string>

int main()
{

	int num_threads = 7;
	std::vector<std::thread*> Pool;
	int quantity = 1000;
	Product* product = new Product(50, quantity);
	int i;
	int j = 0;
	while (j < 7) {
		std::cout << "\n======================= " << j + 1 << " =======================\n\n";
		for (i = 0; i < num_threads; i++) {
			Pool.push_back(new std::thread(&Transaction::sale, product, (i + 1) * 10));
		}
		for (i = 0; i < num_threads; i++) {
			Pool[i]->join();
		}
		Pool.clear();
		j++;
		Sleep(1000);
	}
	system("pause");
	return 0;
}
