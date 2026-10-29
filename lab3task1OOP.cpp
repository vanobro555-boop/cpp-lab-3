#include <iostream>
#include <string>

using namespace std;

//абстрактный класс с общими полями и абстрактными методами
class Animal {
private:
	int m_age;
	double m_weight;
	string m_species;
public:
	//конструктор по умолчанию
	Animal() {}

	//конструктор с параметрами
	Animal(int age, double weight, string species) : m_age(age), m_weight(weight), m_species(species) {}

	//чистые виртуальные функции
	virtual void makeTheSound() = 0;
	virtual void toEat() = 0;
	virtual void toDescribe() = 0;

	//геттеры
	int getAge() const {
		return m_age;
	}

	double getWeight() const {
		return m_weight;
	}

	string getSpecies() const {
		return m_species;
	}

	//обычный метод для демонстрации раннего полиморфизма
	void sleep() const {
		cout << m_species << " спит" << endl;
	}

	//виртуальные деструктор
	virtual ~Animal() {}
};

//подкласс лев
class Lion : public Animal {
private:
	double m_runningSpeed; //скорость бега
public:
	Lion(int age, double weight, string species, double runningSpeed) : Animal(age, weight, species), m_runningSpeed(runningSpeed) {}

	double getRunningSpeed() const {
		return m_runningSpeed;
	}

	//переопределение методов
	virtual void makeTheSound() override {
		cout << "Лев рычит" << endl;
	}

	virtual void toEat() override {
		cout << "Лев ест мясо" << endl;
	}

	virtual void toDescribe() override {
		cout << "Животное: Лев" << endl;
		cout << "age: " << getAge() << endl;
		cout << "weight: " << getWeight() << endl;
		cout << "species: " << getSpecies() << endl;
		cout << "runningSpeed: " << getRunningSpeed() << endl;
	}

	void LionAction() {
		cout << "лев ходит по вольеру" << endl;
	}
};

//подкласс слон
class Elephant : public Animal {
private:
	double m_earSize; //размер ушей
public:
	Elephant(int age, double weight, string species, double earSize) : Animal(age, weight, species), m_earSize(earSize) {}

	double getEarSize() const {
		return m_earSize;
	}

	//переопределение методов
	virtual void makeTheSound() override{
		cout << "Слон трубит" << endl;
	}

	virtual void toEat() override {
		cout << "Слон ест листья" << endl;
	}

	virtual void toDescribe() override {
		cout << "Животное: Слон" << endl;
		cout << "age: " << getAge() << endl;
		cout << "weight: " << getWeight() << endl;
		cout << "species: " << getSpecies() << endl;
		cout << "earSize: " << getEarSize() << endl;
	}

	void ElephantAction() {
		cout << "слон поднимает совй хобот" << endl;
	}
};

//подкласс пингвин
class Penguin : public Animal {
private:
	int m_flockSize; //размер стаи
public:
	Penguin(int age, double weight, string species, int flockSize) : Animal(age, weight, species), m_flockSize(flockSize) {}

	int getFlockSize() const {
		return m_flockSize;
	}

	//переопределение методов
	virtual void makeTheSound() override {
		cout << "Пингвин пищит" << endl;
	}

	virtual void toEat() override {
		cout << "Пингвин ест рыбу" << endl;
	}

	virtual void toDescribe() override {
		cout << "Животное: Пингвин" << endl;
		cout << "age: " << getAge() << endl;
		cout << "weight: " << getWeight() << endl;
		cout << "species: " << getSpecies() << endl;
		cout << "flockSize: " << getFlockSize() << endl;
	}

	void PenguinAction() {
		cout << "пингвин прыгает с обрыва в океан" << endl;
	}
};

int main() {
	setlocale(LC_ALL, "RU");

	//массив обьетов суперкласса
	//массив указателей на обьекты
	Animal* animals[3];

	animals[0] = new Lion(10, 100.0, "лев", 30.0);
	animals[1] = new Elephant(5, 3000.0, "слон", 50.0);
	animals[2] = new Penguin(3, 20.0, "пингвин", 300);

	//полиморфные вызовы
	for (int i = 0; i < 3; i++) {
		cout << "Животное: " << animals[i]->getSpecies() << endl;
		animals[i]->makeTheSound();
		animals[i]->toEat();
		animals[i]->toDescribe();
		cout << endl;
	}

	//вызов спецефических методов для каждого класса

	// 1. Для Льва
	Lion* lionPtr = dynamic_cast<Lion*>(animals[0]);
	if (lionPtr != nullptr) { // Проверяем, удалось ли приведение
		lionPtr->LionAction();
	}

	// 2. Для Слона
	Elephant* elephantPtr = dynamic_cast<Elephant*>(animals[1]);
	if (elephantPtr != nullptr) {
		elephantPtr->ElephantAction();
	}

	// 3. Для Пингвина
	Penguin* penguinPtr = dynamic_cast<Penguin*>(animals[2]);
	if (penguinPtr != nullptr) {
		penguinPtr->PenguinAction();
	}

	//демонстрация связывания
	Animal* testPtr = new Lion(10, 100.0, "лев", 30.0);

	//поздний полиморфизм
	testPtr->makeTheSound();

	//ранний полиморфизм
	testPtr->sleep();

	//очистка памяти
	for (int i = 0; i < 3; i++) {
		delete animals[i];
	}

	delete testPtr;

	return 0;
}