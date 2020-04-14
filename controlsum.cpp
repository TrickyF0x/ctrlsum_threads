#include <iostream>
#include <string>
#include <fstream>
#include <pthread.h>
#include <unistd.h>

std::string filename, in_str, chk_str;

int get_str() // ПОЛУЧЕНИЕ СОДЕРЖИМОГО ФАЙЛА
{
	std::ifstream inf;
	inf.open(filename);
	if (!inf) // ОШИБКИ СВЯЗАННЫЕ С ФАЙЛОМ
	{
		std::cerr << "File error." << std::endl;
		return 1;
	}
	getline(inf, in_str, '\0');
	inf.close();

	return 0;
}

int cntrl_sum() // РАССЧЕТ СУММЫ
{
	int sum = 0;
	for (int i = 0; in_str[i] != 0; i++) // СУММИРУЕМ КАЖДЫЙ СИМВОЛ
	{
		sum += (int)in_str[i];
	}

	return sum;
}

int main(int argc, char *argv[])
{
	int frst_sum = 0, sec_sum = 0;

	filename = argv[1]; // ПОЛУЧАЕМ ИМЯ ФАЙЛА

	std::cout << "Pid ID "<< getpid() << std::endl;
	
	get_str(); // ПОЛУЧЕНИЕ СОДЕРЖИМОГО ФАЙЛА
    
	frst_sum = cntrl_sum(); // ПОЛУЧЕНИЕ ПЕРВОНАЧАЛЬНОЙ СУММЫ
	std::cout << "Sum is: ";
	std::cout << cntrl_sum() << std::endl; // ВЫВОД СУММЫ

	get_str(); // СНОВА ПОЛУЧАЕМ СОДЕРЖИМОЕ ФАЙЛА ДЛЯ СВЕРКИ СУММ

	sec_sum = cntrl_sum(); // РАССЧИТЫВАЕМ КОНТРОЛЬНУЮ СУММУ 

	if (sec_sum == frst_sum) // ЕСЛИ СУММЫ СОВПАЛИ - ПРОВЕРКА ПРОЙДЕНА
	{
		std::cout << "File " << filename << "  PASS\n\n";
	}
	else
		std::cout << "File " << filename << " DIDNT PASS\n\n";
	
	return 0;
}