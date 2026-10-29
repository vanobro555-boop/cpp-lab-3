#include <iostream>
#include <string>

using namespace std;

//интерфейс дрессируемый
class ITrainable {
public:
	virtual ~ITrainable() = default;
	virtual void performTrick() = 0;

	virtual void showYourself() const {
		cout << "я метод первого интерфейса" << endl;
	}
};

//интерфейс кормируемый
class IFeedable {
public:
	virtual ~IFeedable() = default;
	virtual void getPortion() = 0;
};

//интерфейс перемещаемый
class IMoveable {
public:
	virtual ~IMoveable() = default;
	virtual void toMove() = 0;

	virtual void showYourself() const {
		cout << "я метод второго интерфейса" << endl;
	}
};

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
class Lion : public Animal, public IFeedable {
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

	virtual void getPortion() override {
		cout << "лев получил кусок мяса" << endl;
	}

	void LionAction() {
		cout << "лев ходит по вольеру" << endl;
	}
};

//подкласс слон
class Elephant : public Animal, public IMoveable, public IFeedable {
private:
	double m_earSize; //размер ушей
public:
	Elephant(int age, double weight, string species, double earSize) : Animal(age, weight, species), m_earSize(earSize) {}

	double getEarSize() const {
		return m_earSize;
	}

	//переопределение методов
	virtual void makeTheSound() override {
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

	virtual void getPortion() override {
		cout << "слон получил траву" << endl;
	}

	virtual void toMove() override {
		cout << "слон переместился" << endl;
	}

	virtual void showYourself() const override {
		IMoveable::showYourself();
	}

	void ElephantAction() {
		cout << "слон поднимает совй хобот" << endl;
	}
};

//подкласс пингвин
class Penguin : public Animal, public ITrainable, public IFeedable, public IMoveable {
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

	virtual void getPortion() override {
		cout << "пингвин получил рыбу" << endl;
	}

	virtual void toMove() override {
		cout << "пингвин переместился" << endl;
	}

	virtual void performTrick() override {
		cout << "пингвин сделал сальто назад" << endl;
	}

	//разрешение конфликта
	virtual void showYourself() const override {
		IMoveable::showYourself();
		ITrainable::showYourself();
	}

	void PenguinAction() {
		cout << "пингвин прыгает с обрыва в океан" << endl;
	}
};

//подкласс дельфин
class Dolphin : public Animal {
private:
	double m_jumpHeight;
public:
	Dolphin(int age, double weight, string species, double jumpHeight) : Animal(age, weight, species), m_jumpHeight(jumpHeight) {}

	double getJumpHeight() const {
		return m_jumpHeight;
	}

	//переопределение методов
	virtual void makeTheSound() override {
		cout << "Дельфин издает какой-то звук" << endl;
	}

	virtual void toEat() override {
		cout << "Дельфин ест рыбу" << endl;
	}

	virtual void toDescribe() override {
		cout << "Животное: Дельфин" << endl;
		cout << "age: " << getAge() << endl;
		cout << "weight: " << getWeight() << endl;
		cout << "species: " << getSpecies() << endl;
		cout << "jumpHeight: " << getJumpHeight() << endl;
	}

	void DolphinAction() {
		cout << "Дельфин прыгает над океаном" << endl;
	}
};

int main() {
	setlocale(LC_ALL, "RU");

	//полиморфизм через ссылки на интерфейсы
	//массив кормируемых
	IFeedable* animals1[2];
	animals1[0] = new Lion(10, 100.0, "лев", 50.0);
	animals1[1] = new Penguin(5, 20.0, "пингвин", 200);

	for (int i = 0; i < 2; i++) {
		animals1[i]->getPortion();
	}

	//массив пеемещаемых
	IMoveable* animals2[2];
	animals2[0] = new Elephant(10, 3000.0, "слон", 50.0);
	animals2[1] = new Penguin(5, 20.0, "пингвин", 200);


	for (int i = 0; i < 2; i++) {
		animals2[i]->showYourself();
		animals2[i]->toMove();
	}


	//очистка памяти
	for (int i = 0; i < 2; i++) {
		delete animals1[i];
		delete animals2[i];
	}

	return 0;
}
