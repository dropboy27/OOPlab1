#include "str_ops.h"
#include <iostream>
#include <limits>

int main(){
	char* s = nullptr;
	while(true){
		std::cout << "1. Ввести строку\n";
		std::cout << "2. Напечатать\n";
		std::cout << "3. Длина\n";
		std::cout << "4. Скопировать в буфер и напечатать\n";
		std::cout << "5. Алгоритм варианта\n";
		std::cout << "0. Выход\n";
		int choice;
		if (!(std::cin >> choice)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Некорректный ввод\n";
			continue;
		}
		switch (choice) {
			case 0:
				break;
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			default:
				break;
		}
	}