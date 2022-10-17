#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include<string>
#include <conio.h>// вызов _getch()
#include <iostream>
#include<stdlib.h> // вызов rand() и srand(); malloc(), calloc() и тд
#include<time.h> // вызов time()
#include<string.h>// вызов strstr()
#include<fstream> // потоки in out puts файлов
#include<Windows.h>// для коррректной записи и чтения русских символов в файл

using namespace std;

enum State {
	begin, middle
};
enum Classification {
	ArrayOfFabric, ArrayOfShirts, ArrayOfDresses
};
string possible_typesClothes[] = { "Man's dress", "Woman's dress", "Kid's dress","Shirt","Trousers","Jacket","Scarf","Gown","Skirt","Mini-skirt" };
string possible_typesLooks[] = { "Man's classic", "Woman's classic", "Kid's classic","Beach classic","Office classic","Home classic","Weekend in country classic","Future look","Modern look","Mountain climber's look" };

const string file_name = "AtelierRecords.txt";
static fstream f_obj;
// name icludes Shirt, Fabric, Dress at the end of the word

int getRandomNumber(int min, int max) {
	srand(time(NULL)); // задаём начальную точку рандома, но так как time(NULL) будет постоянно выдавать разное значение, то всегда разная точка входа
	int nnumber = min + rand() % (max - min + 1);
	return nnumber;
}

int* getThreeRandomNumbers(int* numbers) { // в диапазоне от 0 до 9
	//int numbers[3];
	int flag = 0, flag2 = 0;
	int temp = -1;

	for (int i = 0; i < 3;)
	{
		temp = getRandomNumber(0, 9);
		if (i == 2) {
			if (temp != numbers[i - 1] and temp != numbers[i - 2])
			{
				numbers[i] = temp;
				i++;
			}
		}
		else if (i == 1) {
			if (temp != numbers[i - 1])
			{
				numbers[i] = temp;
				i++;
			}
		}
		else {
			numbers[i] = temp;
			i++;
		}
	}

	return numbers;
}

class Product { // Абстрактный
public:
	int price, large;
	char* name;
	int* ind_numbers;
	virtual void getFields() = 0;
	virtual void setFields(int, int, char*) = 0;
	virtual void getTypes() = 0;
};

class FabricProduct : public Product {
public:
	FabricProduct() {
		large = 0;
		price = 0;
		name = new char[20];
		ind_numbers = new int[3];
	};

	//name = (char*)malloc(25 * sizeof(char))

	FabricProduct(const FabricProduct& obj) { // конструктор копирования
		if (obj.name != NULL and obj.ind_numbers != NULL) {	// если имя и номера объекта не равны нулю то: was deleted 19:01
			name = new char[20];//(char*)malloc((strlen(obj.name)+1)*sizeof(char));
			//ind_numbers = new int[3];

			name = obj.name;//strcpy(name, obj.name);
			ind_numbers = new int[3];
			ind_numbers = obj.ind_numbers;
			*(ind_numbers + 1) = *(obj.ind_numbers + 1);
			*(ind_numbers + 2) = *(obj.ind_numbers + 2);
		}
		price = obj.price;
		large = obj.large;
	};

	const FabricProduct& operator=(const FabricProduct& obj) {
		this->name = obj.name;
		this->ind_numbers = obj.ind_numbers;
		this->large = obj.large;
		this->price = obj.price;
	}

	~FabricProduct() {
		//delete(name); // added the last time
		//delete(ind_numbers);
		ind_numbers = NULL;
		name = NULL;
	};

	void getFields() {
		cout << "Размер (в метрах) - " << this->large << endl << "Цена - " << this->price << endl << "Название - " << this->name << endl;
	}

	void setFields(int pprice, int llarge, char* nname) {
		large = llarge;
		price = pprice;
		name = nname;
		ind_numbers = getThreeRandomNumbers(ind_numbers);
	}

	void getTypes() {

		string ffirst = possible_typesClothes[*(ind_numbers + 0)];
		cout << "Что может получится из " << name << ":\n(1)" << ffirst << endl;
		cout << "(2)" << possible_typesClothes[*(ind_numbers + 1)] << endl;
		cout << "(3)" << possible_typesClothes[*(ind_numbers + 2)] << endl;
	}
};

class ShirtProduct : public FabricProduct {
public:
	ShirtProduct() {
		large = 0;
		price = 0;
		name = new char[20];
		ind_numbers = new int[3];
	};
	ShirtProduct(const ShirtProduct& obj) {
		if (obj.name != NULL and obj.ind_numbers != NULL)
		{
			name = new char[strlen(obj.name) + 1];
			ind_numbers = new int[3];

			strcpy(name, obj.name);
			ind_numbers = obj.ind_numbers;
		}
		price = obj.price;
		large = obj.large;
	};
	~ShirtProduct() {
		//delete(name); // added the last time
		//delete(ind_numbers);
		ind_numbers = NULL;
		name = NULL;
	};
	const ShirtProduct& operator=(const ShirtProduct& obj) {
		FabricProduct::operator=(obj);
	}
	void getFields() {
		cout << "Размер (европейский) - " << this->large << endl << "Цена - " << this->price << endl << "Название - " << this->name << endl;
	}
	void setFields(int pprice, int llarge, char* nname) {
		FabricProduct::setFields(pprice, llarge, nname);
	}
	void getTypes() {
		cout << "Что может получится из " << name << ":\n(1)" << possible_typesLooks[*(ind_numbers)] << endl;
		cout << "(2)" << possible_typesLooks[*(ind_numbers + 1)] << endl;
		cout << "(3)" << possible_typesLooks[*(ind_numbers + 2)] << endl;
	}
};

class DressProduct : public ShirtProduct {
public:
	DressProduct() {
		large = 0;
		price = 0;
		name = new char[20];
		ind_numbers = new int[3];
	};
	DressProduct(const DressProduct& obj) { // Возможно ли наследовать определение этого конструктура из класса родителя
		if (obj.name != NULL and obj.ind_numbers != NULL)
		{
			name = new char[strlen(obj.name) + 1];
			ind_numbers = new int[3];

			strcpy(name, obj.name);
			ind_numbers = obj.ind_numbers;
		}
		price = obj.price;
		large = obj.large;
	};
	~DressProduct() {
		//delete(name); // added the last time
		//delete(ind_numbers);
		ind_numbers = NULL;
		name = NULL;
	};
	const DressProduct& operator=(const DressProduct& obj) {
		FabricProduct::operator=(obj);
	}
	void getFields() {
		ShirtProduct::getFields();
	}
	void getTypes() {
		ShirtProduct::getTypes();
	}
	void setFields(int pprice, int llarge, char* nname) {
		FabricProduct::setFields(pprice, llarge, nname);
	}
};

template<class T>
class Presence {
public:
	T* ptr;
	int counter_ptr;
};

template<class T>
class Smart_ptr {
public:
	Presence<T>* smart_ptr;
	Smart_ptr(T* ptr) // конструктор
	{
		if (ptr) {
			smart_ptr = new Presence<T>();
			smart_ptr->ptr = ptr;
			smart_ptr->counter_ptr = 1;
		}
		else {
			smart_ptr = NULL;
		}

	};

	Smart_ptr(const Smart_ptr& obj) :smart_ptr(obj.smart_ptr) // конструктор копирования
	{
		if (smart_ptr) {
			smart_ptr->counter_ptr++;
		}
	};

	~Smart_ptr() // деструктор 
	{
		if (smart_ptr) {
			smart_ptr->counter_ptr--;
			if (smart_ptr->counter_ptr == 0) {
				delete smart_ptr->ptr; // объект
				delete smart_ptr; // умный указатель
			}
		}

	};

	T* operator->() const;

	Smart_ptr& operator=(const Smart_ptr& obj) { // присваивание
		if (smart_ptr)
		{
			//smart_ptr->counter_ptr--; было тут
			if (smart_ptr->counter_ptr == 0)
			{
				delete smart_ptr->ptr; // объект
				delete smart_ptr; // умный указатель
			}
			smart_ptr->counter_ptr--;// стало тут
		}
		//smart_ptr = obj.smart_ptr;
		if (smart_ptr)
			smart_ptr->counter_ptr++;
		return *this;

	}
	void show_counter() {
		cout << "Значение счетчика для объекта " << this->smart_ptr << " равно: " << this->smartPtr->counter_ptr << endl;
	}
};

template <class T>
T* Smart_ptr<T>::operator->() const { // сама разадрезсация(получение нашего объекта)
	if (smart_ptr)
	{
		return smart_ptr->ptr; // сам объект
	}
	else return NULL;
}

template <class T> // шаблонный класс
class Service {

public:
	T* currentPiece;
	Service() {
		currentPiece = new T();
	};
	Service& operator=(const Service& obj);
	Service(const Service& obj);
	~Service() { // added 18:50
		if(!currentPiece)
			delete currentPiece;
		currentPiece = NULL;	//delete currentPiece;
		//currentPiece = NULL; // added 10.10 16:53
	};
};

template<class T>
Service<T>& Service<T>::operator=(const Service& obj) {
	if (this != &obj) { // выдаёт ошибку если не использовать разадресацию????
		delete currentPiece;
		currentPiece = new T(*currentPiece);// is it eclose "T(*(obj.currentState))".
		currentPiece = obj.currentPiece;
	}
	return *(this);
}

template<class T>
Service<T>::Service(const Service& obj) { // 09.10.11:57
	delete currentPiece;
	currentPiece = new T(*(obj.currentPiece)); // другое?
	//currentPiece = obj.currentPiece; // лишнее?? - deleted 09.10
}

template <class T> // Транзация класс
class Transaction {
public:
	T* prevState;
	T* currentState;
	Transaction() : currentState(new T), prevState(NULL) {} // конструктор без парам
	Transaction(const Transaction& obj) {
		this->currentState = new T(*(obj.currentState));
		this->prevState = NULL;
		if (obj.prevState != NULL)
			this->prevState = new T(*(obj.prevState));
	} // конструктор копирования
	~Transaction() { delete currentState; delete prevState; currentState = NULL; prevState = NULL; } // added NULLs 16:49 10.10; 

	void showState(State state); // отображение состояний объекта (current, prev)

	void beginTransaction(int, int, char*); // начало
	void commit(); // закрепить состояние
	void deleteTransaction(); // откат ИЛИ возвращение назад

	Transaction& operator=(const Transaction& obj); // оператор присваивания
	T* operator->(); // перегрузка оператора доступа к содержимому объекта через указатель
};

template <class T>
Transaction<T>& Transaction<T>::operator=(const Transaction<T>& obj) {
	if (this != &obj) { // выдаёт ошибку если не использовать разадресацию????
		delete currentState;
		currentState = new T(*obj.currentState);
		if (obj.prevState != NULL) { //added 16.01; deleted 16.15 // added 16:50 10.10
			delete prevState;
			prevState = obj.prevState;
		}	// is it eclose "T(*(obj.currentState))".
		//currentState = obj.currentState; added morning; deleted 15.27
	}
	return *(this);
}

template <class T>
T* Transaction<T>::operator->() {
	return currentState;
}

template <class T>
void Transaction<T>::beginTransaction(int pprice, int llarge, char* nname) {
	delete prevState;
	//prevState = NULL;
	prevState = currentState; // сохраняем значение
	currentState = new T(*prevState); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	if (!currentState) return;
	currentState->currentPiece->setFields(pprice, llarge, nname);
}

template <class T>
void Transaction<T>::commit() { //// провреку на то, чтобы current!= NULL ?????????????????
	delete prevState;
	prevState = NULL;
}

template <class T>
void Transaction<T>::deleteTransaction() {
	if (prevState != NULL)
	{
		delete currentState;
		currentState = prevState;
		prevState = NULL;
	}
	else { cout << "К сожалению сделать это не получится, потому что прошлое состояние отсутствует!\n"; }
}

template <class T>
void Transaction<T>::showState(State state) {
	cout << endl << "Состояние объекта: " << endl;
	if (!state) { // begin
		cout << "До начала транзакции " << endl;
	}
	else { // middle
		cout << "После выполнения транзакции " << endl;
	}
	if (prevState) { // существуем
		cout << "prev state (" << prevState << "):" << endl;
		prevState->currentPiece->getFields();
		cout << endl;
	}
	else { // не существуем
		cout << "prev state (NULL):" << endl;
	}
	cout << "current state (" << currentState << "):" << endl;
	currentState->currentPiece->getFields();
	cout << endl;
}

template <class T>
Smart_ptr<T> addValueInit(Smart_ptr<T> obj) { // бу
	int money, size;
	char* name;
	if (!(name = (char*)malloc(25 * sizeof(char))))   //Необходимо всегда 
	{
		puts("Not enough memory");           // проверять выделилась ли память
		_getch();
		return obj;
	}

	cout << "Введите цену: ";
	cin >> money;
	cout << endl;
	cout << "Введите размер (для одежды или ширину отреза ткани): ";
	cin >> size;
	cout << endl;
	cout << "Введите имя: ";
	cin >> name;
	cout << endl;
	obj->setFields(money, size, name);
	return obj;
}

template <class T>
Transaction<Service<T>> addValueTrans(Transaction<Service<T>> obj) {
	int money, size;
	char name[25];

	cout << "Введите цену: ";
	cin >> money;
	cout << endl;
	cout << "Введите размер (для одежды или ширину отреза ткани): ";
	cin >> size;
	cout << endl;
	cout << "Введите имя: ";
	cin >> name;
	//добавить \0 в конец?
	cout << endl;
	obj.beginTransaction(money, size, name);

	//Transaction<Service<T>> copy_obj = obj;

	return obj; // вызывается деструктор и всё рушит!!!!///////////////////////////////////////////////////////////////////
}

template<class T>
Transaction<Service<T>> TransMenu(Transaction<Service<T>>& obj, State addState)
{
	int menu_flag = 0;
	while (menu_flag != -1) {
		cout << "1 - Удалить прошлое изменение - commit\n2 - Удалить текущее изменение и оставить прошлое изменение - delete\n3 - Показать текущее состояние\n4 - Оставить так как есть\nВаш выбор: ";
		cin >> menu_flag;
		switch (menu_flag) {
		case 1: {
			obj.commit();
			_getch();
			break;
		}
		case 2: {
			obj.deleteTransaction();
			_getch();
			break;
		}
		case 3: {
			obj.showState(addState);
			_getch();
			break;
		}
		case 4: {
			menu_flag = -1;
			break;
		}
		default: {
			cout << "Введено неверное значение, попробуйте снова" << endl;
			_getch();
			break;
		}
		}
	}
	return obj;
}

void fileRead(string file_name) {
	f_obj.open(file_name, fstream::in | fstream::out | fstream::app);
	if (!f_obj.is_open()) {
		cout << "Ошибка открытия файла!\n";
		return;
	}
	else {
		char ch;
		cout << "Чтение из файла:" << endl;
		while (f_obj.get(ch))
		{
			cout << ch;
		}
		cout << "Чтение из файла завершено! " << endl;
	}

	f_obj.close();
}

template <class T>
void fileWright(string file_name, Transaction<Service<T>> obj, State state, Classification classific, int trans_number) {
	f_obj.open(file_name, fstream::in | fstream::out | fstream::app);
	if (!f_obj.is_open()) {
		cout << "Ошибка открытия файла!\n";
		return;
	}
	f_obj << "Транзакция #" << trans_number << "\n\n";
	f_obj << "Состояние объекта:\n";
	if (!state) { // begin
		f_obj << "До начала транзакции:\n";
	}
	else { // middle
		f_obj << "После выполнения транзакции #" << trans_number << "\n";
	}
	if (obj.prevState) { // существуем
		if (classific != 0) {
			f_obj << "Размер (европейский) - " << obj.prevState->currentPiece->large << "\n" << "Цена - " << obj.prevState->currentPiece->price << "\n" << "Название - " << obj.prevState->currentPiece->name << "\n";//obj->prevState->currentPiece;
		}
		else
			f_obj << "Ширина куска ткани (в метрах) - " << obj.prevState->currentPiece->large << "\n" << "Цена - " << obj.prevState->currentPiece->price << "\n" << "Название - " << obj.prevState->currentPiece->name << "\n";//obj->prevState->currentPiece;
	}
	else { // не существуем
		f_obj << "Прошлое состояние пустое\n";
	}
	f_obj << "Текущее состояние\n";
	if (classific != 0) {
		f_obj << "Размер (европейский) - " << obj.currentState->currentPiece->large << "\n" << "Цена - " << obj.currentState->currentPiece->price << "\n" << "Название - " << obj.currentState->currentPiece->name << "\n";
		f_obj<< "\nЧто может получится из " << obj.currentState->currentPiece->name << ":\n(1)" << possible_typesLooks[*(obj.currentState->currentPiece->ind_numbers)] << "\n";
		f_obj << "(2)" << possible_typesLooks[*(obj.currentState->currentPiece->ind_numbers + 1)] << "\n";
		f_obj << "(3)" << possible_typesLooks[*(obj.currentState->currentPiece->ind_numbers + 2)] << "\n\n";
	}
	else
		f_obj << "Ширина куска ткани (в метрах) - " << obj.currentState->currentPiece->large << "\n" << "Цена - " << obj.currentState->currentPiece->price << "\n" << "Название - " << obj.currentState->currentPiece->name << "\n\n";
		f_obj << "Что может получится из " << obj.currentState->currentPiece->name << ":\n(1)" << possible_typesClothes[*(obj.currentState->currentPiece->ind_numbers + 0)] << "\n";
		f_obj << "(2)" << possible_typesClothes[*(obj.currentState->currentPiece->ind_numbers + 1)] << "\n";
		f_obj << "(3)" << possible_typesClothes[*(obj.currentState->currentPiece->ind_numbers + 2)] << "\n\n";

	f_obj.close();
}


void test1() {

	char fabric1[] = "WoolFabric";
	char shirt1[] = "SatinShirt";
	char shirt2[] = "SilkShirt";
	char dress1[] = "DiorDress";

	cout << "Начальная инициализация для ткани" << endl;
	Smart_ptr<FabricProduct> wool = new FabricProduct();
	wool->setFields(45, 3, fabric1);
	Transaction<Service<FabricProduct>> TrailFabric;
	TrailFabric->currentPiece = wool.smart_ptr->ptr;
	TrailFabric.showState(State::begin);
	//TrailFabric->currentPiece->
	///////////////////////////////////////////////////////////////////////////////////////
	cout << endl << "Начальная инициализация для рубашки" << endl;
	Smart_ptr<ShirtProduct> satin = new ShirtProduct();
	satin->setFields(90, 42, shirt1);
	Transaction<Service<ShirtProduct>> TrailShirt;
	TrailShirt->currentPiece = satin.smart_ptr->ptr;
	TrailShirt.showState(State::begin);


	cout << endl << "Первая транзакция" << endl;
	TrailShirt.beginTransaction(200, 42, shirt1);//satin->setFields(200, 42, shirt1);
	TrailShirt.showState(State::middle);
	cout << endl << "Первая транзакция - done" << endl;

	TrailShirt.deleteTransaction();
	cout << endl << "Первая транзакция отменена" << endl;
	TrailShirt.commit();
	TrailShirt.showState(State::middle);
	//satin->getTypes(); // второй варик
	//TrailShirt->ShirtLooks(satin); // первый

	cout << endl << "Вторая транзакция" << endl;
	TrailShirt.beginTransaction(400, 48, shirt2);
	TrailShirt.showState(State::begin);
	cout << endl << "Вторая транзакция прошла успешена" << endl;

	TrailShirt.commit();
	cout << endl << "Вторая транзакция закреплена" << endl;
	TrailShirt.showState(State::middle);
	///////////////////////////////////////////////////////////////////////////////////////


	cout << endl << "Начальная инициализация для платья" << endl;
	Smart_ptr<DressProduct> dior = new DressProduct();
	dior->setFields(450, 38, dress1);
	Transaction<Service<DressProduct>> TrailDress;
	TrailDress->currentPiece = dior.smart_ptr->ptr;
	TrailDress.showState(State::begin);

}

void MainMenu() {
	int menu_flag = 0, flag1 = 0, flag2 = 0, flag3 = 0;
	static Smart_ptr<FabricProduct> FabricArray = new FabricProduct();
	static Transaction<Service<FabricProduct>> TrailFabric;
	static Smart_ptr<ShirtProduct> ShirtArray = new ShirtProduct();
	static Transaction<Service<ShirtProduct>> TrailShirt;
	static Smart_ptr<DressProduct> DressArray = new DressProduct();
	static Transaction<Service<DressProduct>> TrailDress;

	while (menu_flag != -1) {
		cout << "Добрый день, менеджер!\n1 - Добавить ткань\n2 - Добавить рубашку\n3 - Добавить платье\n4 - Вызов тестировки-1\n5 - Меню транзакций\n6 - Меню стилиста\n7 - Выход\nВаш выбор: ";
		cin >> menu_flag;
		switch (menu_flag) {
		case 1: {
			if (flag1 == 0) {// инициализация
				addValueInit(FabricArray);
				TrailFabric->currentPiece = FabricArray.smart_ptr->ptr;
				cout << "Первоначальная инициализация завершена\n\n";
			}
			else {
			// begintransaction
				int money, size;
				char* aname = new char;
				cout << "Введите цену: ";
				cin >> money;
				cout << endl;
				cout << "Введите размер (для одежды или ширину отреза ткани): ";
				cin >> size;
				cout << endl;
				cout << "Введите имя: ";
				cin >> aname;
				cout << endl;
				TrailFabric.beginTransaction(money, size, aname);
				TransMenu(TrailFabric, State::middle);
				cout << "Выполнена транзакиця #" << flag1 << "\n";
				aname = NULL;
			}
			flag1++;
			if (flag1 >= 2)
				TrailFabric.commit();
			_getch();
			break;
		}
		case 2: {
			if (flag2 == 0) {// инициализация
				addValueInit(ShirtArray);
				TrailShirt->currentPiece = ShirtArray.smart_ptr->ptr;
				cout << "Первоначальная инициализация завершена\n";
			}
			else { // begintransaction
				int money, size;
				char* aname = new char;
				cout << "Введите цену: ";
				cin >> money;
				cout << endl;
				cout << "Введите размер (для одежды или ширину отреза ткани): ";
				cin >> size;
				cout << endl;
				cout << "Введите имя: ";
				cin >> aname;
				cout << endl;
				TrailShirt.beginTransaction(money, size, aname);
				TransMenu(TrailShirt, State::middle);
				cout << "Выполнена транзакиця #" << flag2 << "\n";
				aname = NULL;
			}
			flag2++;
			if (flag2 >= 2)
				TrailFabric.commit();
			_getch();
			break;
		}
		case 3: {
			if (flag3 == 0) {// инициализация
				addValueInit(DressArray);
				TrailDress->currentPiece = DressArray.smart_ptr->ptr;
				cout << "Первоначальная инициализация завершена\n";
				//TransMenu(TrailFabric, State::begin);//TrailFabric = TransMenu(TrailFabric, State::begin);
			}
			else { // begintransaction
				//TrailFabric=addValueTrans(TrailFabric);
				int money, size;
				char* aname = new char;
				cout << "Введите цену: ";
				cin >> money;
				cout << endl;
				cout << "Введите размер (для одежды или ширину отреза ткани): ";
				cin >> size;
				cout << endl;
				cout << "Введите имя: ";
				cin >> aname;
				cout << endl;
				TrailDress.beginTransaction(money, size, aname);
				TransMenu(TrailDress, State::middle);
				cout << "Выполнена транзакиця #" << flag3 << "\n";
				aname = NULL;
			}
			flag3++;
			if (flag3 >= 2)
				TrailFabric.commit();
			_getch();
			break;
		}
		case 4: {
			test1();
			_getch();
			break;
		}
		case 5: {
			int trans_menu_flag = 0;
			cout << "Какое открыть меню транзакций?\n1 - Ткань\n2 - Рубашки\n3 - Платья\nВаш выбор: ";
			cin >> trans_menu_flag;
			switch (trans_menu_flag)
			{
			case 1: {
				if (flag1 == 1)
					TrailFabric = TransMenu(TrailFabric, State::begin);
				else if (flag1 > 1)
					TrailFabric = TransMenu(TrailFabric, State::middle);
				else
				{
					cout << "Проинициализиуйте объект ткани для работы!\n";
					_getch();
				}
				break;
			}
			case 2: {
				if (flag2 == 1)
					TrailShirt = TransMenu(TrailShirt, State::begin);
				else if (flag2 > 1)
					TrailShirt = TransMenu(TrailShirt, State::middle);
				else
				{
					cout << "Проинициализиуйте объект рубашки для работы!\n";
					_getch();
				}
				break;
			}
			case 3: {
				if (flag3 == 1)
					TrailDress = TransMenu(TrailDress, State::begin);
				else if (flag3 > 1)
					TrailDress = TransMenu(TrailDress, State::middle);
				else
				{
					cout << "Проинициализиуйте объект платья для работы!\n";
					_getch();
				}
				break;
			}
			default: {
				cout << "Введено неверное значение, попробуйте снова" << endl;
				_getch();
				break;
			}

			}
			_getch();
			break;
		}
		case 6:
		{
			int stylist_menu_flag = 0;
			cout << "Какое открыть меню транзакций?\n\n!!!!!!!!!!!!!!!!!!!!!!!! Стилист работает только с текущим объектом, если вы хотите получить услугу с прошлым из объектов, то обратитесь в Меню транзакций !!!!!!!!!!!!!!!!!!!!!!!!\n\n1 - Ткань\n2 - Рубашки\n3 - Платья\n4 - Выход назад\nВаш выбор: ";
			cin >> stylist_menu_flag;
			switch (stylist_menu_flag) {
			case 1: {
				if (flag1 >= 1)
					TrailFabric->currentPiece->getTypes();
				else
				{
					cout << "Проинициализиуйте объект ткани для работы!\n";
					_getch();
					break;
				}
				_getch();
				break;
			}
			case 2: {
				if (flag2 >= 1)
					TrailShirt->currentPiece->getTypes();
				else
				{
					cout << "Проинициализиуйте объект ткани для работы!\n";
					_getch();
					break;
				}
				_getch();
				break;
			}
			case 3: {
				if (flag3 >= 1)
					TrailDress->currentPiece->getTypes();
				else
				{
					cout << "Проинициализиуйте объект ткани для работы!\n";
					_getch();
					break;
				}
				_getch();
				break;
			}
			case 4: {
				break;
			}
			default: {
				cout << "Введено неверное значение, попробуйте снова" << endl;
				_getch();
				break;
			}
			}
			_getch();
			break;
		}
		case 7: {
			cout << endl;
			menu_flag = -1;
			if (TrailFabric.currentState != NULL and flag1 != 0) {
				//TrailFabric.commit();
				State state_end;
				if (flag1 == 1) {
					state_end = State::begin;
				} else
					state_end = State::middle;
				fileWright(file_name, TrailFabric,state_end, Classification::ArrayOfFabric,flag1-1);
			}
			if (TrailShirt.currentState != NULL and flag2!=0) {
				//TrailShirt.commit();
				State state_end;
				if (flag2 == 1) {
					state_end = State::begin;
				}
				else
					state_end = State::middle;
				fileWright(file_name,TrailShirt, state_end, Classification::ArrayOfShirts, flag2-1);
			}
			if (TrailDress.currentState != NULL and flag3 != 0) {
				//TrailDress.commit();
				State state_end;
				if (flag3 == 1) {
					state_end = State::begin;
				}
				else
					state_end = State::middle;
				fileWright(file_name, TrailDress, state_end, Classification::ArrayOfShirts, flag3-1);
			}
			_getch();
			break;
		}
		default: {
			cout << "Введено неверное значение, попробуйте снова" << endl;
			_getch();
			break;
		}
		}
	}
}

int main()
{
	
	//fs.open(file_name, fstream::in | fstream::out | fstream::app);
	setlocale(0, "RUS");
	MainMenu();

	/*
	fstream fs;
	fs.open(file_name,fstream::in | fstream::out | fstream::app);
	if (!fs.is_open()) {
		cout << "Ошибка открытия файла!\n";
	}
	else {
		cout << "Файл открыт!\n";
		int value;
		string msg;
		cout << "1 wright\n2 read\n";
		cin >> value;

		if (value == 1) {
			SetConsoleCP(1251);
			cin >> msg;
			fs << msg << "\n";
			SetConsoleCP(866);
		}

		if (value == 2) {
		/*	while (!fs.eof()) {
				msg = "";
				fs >> msg;//ф-ия для чтения из файла
				cout << msg << endl;
			}
			char ch;
			while (fs.get(ch))
			{
				cout << ch;
			}
		}

		fs.close();
	}
	*/

	exit;
	return 1;
}

