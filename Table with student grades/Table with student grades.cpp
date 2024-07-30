#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;


class student {
public:
	student() = delete;
	student(std::string FIOP, std::string ocenkaP) :FIO(FIOP) {
		//cout << "Запущен конструктор" << endl;
		int pos = 0;
		while (pos <= 4) {
			ocenka[pos] = ocenkaP[pos];
			++pos;
		}
	}

	/// <summary>
	/// Вывод на экран ФИО и оценок выбранного студена
	/// </summary>
	void printALL() {
		cout << "\nФИО " << this->FIO << endl;
		cout << "Оценки ";
		for (size_t i = 0; i < 5; i++)
		{
			cout << this->ocenka[i] << " ";
		}
		cout << endl;
	}


	/// <summary>
	/// Вывод на экран ФИО выбранного студента
	/// </summary>
	void printFIO() {
		cout << "\nФИО " << this->FIO << endl;
	}


	/// <summary>
	/// Вывод на экран ФИО отличника
	/// </summary>
	void printOtlicnik() {
		bool isOtlichnik = true;
		for (int c = 0; c < 5; ++c) {
			if (this->ocenka[c] != '5') isOtlichnik = false;
		}
		if (isOtlichnik)	cout << "\nОтличник ФИО " << this->FIO << endl;
	}


	/// <summary>
	/// Вывод на экран ФИО троечника
	/// </summary>
	void printTroyka() {
		bool isTroyka = false;
		for (int c = 0; c < 5; ++c) {
			if (this->ocenka[c] = '3') isTroyka = true;
			break;
		}
		if (isTroyka)	cout << "\nЕсть тройка ФИО " << this->FIO << endl;
	}

	/// <summary>
	/// Вывод на экран ФИО двоечника
	/// </summary>	
	bool printDvoechnic() {
		bool isDva = false;
		int count = 0;
		for (int c = 0; c < 5; ++c) {
			if (this->ocenka[c] = '2') isDva = true;
			++count;
		}
		if (isDva)	cout << "\nДвоечник ФИО " << this->FIO << endl;

		if (count > 1) {
			cout << "\nДвоечник ФИО " << this->FIO << endl;
			return 1;
		}
		return 0;
	}

private:
	std::string FIO;
	char ocenka[5];
};


/// <summary>
/// Загрузка данных из таблицы
/// </summary>
/// <param name="filename">	Название файла для загрузки	</param>
/// <param name="Stud">	Вектор для записи данных из файла	</param>
void loadTablFromFile(const std::string& filename, std::vector<student>& Stud) {
	std::ifstream tabl;

	tabl.open(filename, std::ios::in);
	if (tabl.is_open()){
		//std::cout << "\nFile is opened\n"; 

		std::string line;

		while (std::getline(tabl, line)) {

			std::istringstream iss(line);
			std::string fio, ocen;
			if (std::getline(iss, fio, '!') && std::getline(iss, ocen)) {
				Stud.push_back(student(fio, ocen));
			}
		}

		tabl.close();
		//if (!tabl.is_open()) std::cout << "\nFile: " << filename << " is cloused\n";
	}
}

/// <summary>
/// Печатает полную информацию (ФИО и оценки) всех студентов загруженных из файла (хранящихся в векторе)
/// </summary>
/// <param name="Stud"> Вектор, хранящий данные из файла	</param>
void PrintAllStudents(std::vector<student>& Stud) {
	int i = 0;
	while (i < Stud.size()) {
		Stud[i].printALL();
		++i;
	}
}

/// <summary>
/// Печатает ФИО всех студентов загруженных из файла (хранящихся в векторе)
/// </summary>
/// <param name="Stud"> Вектор, хранящий данные из файла	</param>
void PrintFIOStudents(std::vector<student>& Stud) {
	int i = 0;
	while (i < Stud.size()) {
		Stud[i].printFIO();
		++i;
	}
}


/// <summary>
/// Вывод на экран списка ФИО студентов отличников загруженных из файла (хранящихся в векторе)
/// </summary>
/// <param name="Stud"> Вектор, хранящий данные из файла	</param>
void PrintOtlicnik(std::vector<student>& Stud) {
	int i = 0;
	while (i < Stud.size()) {
		Stud[i].printOtlicnik();
		++i;
	}
}

/// <summary>
/// Вывод на экран списка ФИО студентов троечников загруженных из файла (хранящихся в векторе)
/// </summary>
/// <param name="Stud">  Вектор, хранящий данные из файла	</param>
void PrintTroyka(std::vector<student>& Stud) {
	int i = 0;
	while (i < Stud.size()) {
		Stud[i].printTroyka();
		++i;
	}
}

/// <summary>
/// Вывод на экран списка ФИО студентов двоечников загруженных из файла (хранящихся в векторе) и удаление их из вектора
/// </summary>
/// <param name="Stud">  Вектор, хранящий данные из файла	</param>
void PrintDvoechnic(std::vector<student>& Stud) {
	int i = 0;
	while (i < Stud.size()) {
		if (Stud[i].printDvoechnic()) Stud.erase(Stud.begin() + i);
		cout << "Исключен из списка!";
		++i;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");

	std::vector<student> Stud;
	std::string filename{ "tabl.txt" };


	loadTablFromFile(filename, Stud);

	PrintAllStudents(Stud);
	cout << endl;
	PrintFIOStudents(Stud);

}