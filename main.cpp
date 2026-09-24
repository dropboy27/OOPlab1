#include "str_ops.h"
#include <iostream>
#include <limits>
#include <iomanip>
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
			case 1:{
				const std::size_t BUF_SIZE = 256;
				char buffer[BUF_SIZE];
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Введите строку: ";
				std::cin.getline(buffer, BUF_SIZE);
				str_delete(s);
				s = str_alloc(buffer);
				break;
				}
			case 2:
				if (s == nullptr) {
					std::cout << "Строка не введена\n";
				} else {
					str_print(s);
					std::cout << std::endl;
				}
				break;
			case 3:
				if (s == nullptr) {
					std::cout << "Строка не введена\n";
				} else {
					std::size_t length = str_len(s);
					std::cout << "Длина строки: " << length << std::endl;
				}
				break;
			case 4: {
				if (s == nullptr) {
					std::cout << "Строка не введена\n";
				} else {
					std::size_t len = str_len(s);
					char* buffer = new char[len + 1];

					str_copy(buffer, s);            
					std::cout << "Скопированная строка: ";
					str_print(buffer);
					std::cout << std::endl;

					delete[] buffer;                 
				}
				break;
			}	
			case 5: {
				if (s == nullptr){
					std::cout<<"Строка не введена"<< std::endl;
					break;
				}
				std::cout<<"1. Посчитать слова"<<std::endl;
				std::cout<<"2. Найти подстроку"<<std::endl;
				int choice_alg;
				std::cin >> choice_alg;
				if (choice_alg != 1 && choice_alg != 2 ){
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Некорректный ввод\n";
					break;
				}
				if (choice_alg == 1){
					std::cout<<str_count_words(s)<<std::endl;
				}else{
					const std::size_t SUB_SIZE = 256;
					char substr[SUB_SIZE];
					int position;
					std::cout<<"Введите подстроку"<<std::endl;
					std::cin>>std::setw(SUB_SIZE)>>substr;
					if(!(str_find_substr(s,substr,position))){
						std::cout<<"Подстрока не найдена"<<std::endl;
					}else{
						std::cout<<position<<std::endl;
					}
				}
				break;
			}
			case 0:
				str_delete(s);
				return 0;
			default:
				break;
		}
	}
}