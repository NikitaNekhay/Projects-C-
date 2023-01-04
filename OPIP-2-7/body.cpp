#pragma once
#include"head.h"

Client::Client() {
	ABC = 'C';
	strcpy(s_name, "None");
}

bool Client::Add() {
	try{

		int flag = 0;
		while (flag == 1 || flag == 0)
		{
			cout << "Введите фамилию для клиента";
			cin >> this->s_name;
			if (!CheckLetters(this->s_name))
			{
				flag = 1;
				cout << "Введена некорректная строка. Попробуйте ещё раз\n";
			}
			else flag = 2;
		}

		flag = 0;
		while (flag == 1 || flag == 0)
		{
			cout << "Введите оценку по ABC анализу для клиента:";
			cin >> ABC;
			if (!CheckLettersABC(this->ABC))
			{
				flag = 1;
				cout << "Введена некорректное значение. Попробуйте ещё раз\n";
			}
			else flag = 2;
		}

		
		return true;
	}
	catch(...){
		return false;
	}
}

istream& operator>>(istream& stream, Client obj) {
	try {
		stream >> obj.ABC;
		stream >> obj.s_name;
		return stream;

	}
	catch (...) {
		if (!stream.goodbit)
			cout << "Ошибка чтения информации из потока.\n";
	}
}
ostream& operator<<(ostream& stream, Client obj) {
	try {
		stream << obj.ABC << " " << obj.s_name << '\n';
		return stream;

	}
	catch (...) {
		if (!stream.goodbit)
			cout << "Ошибка вывода из потока.\n";
	}

}

bool operator>(const Client& a, const Client& b) {
	return a.ABC > b.ABC;
}
bool operator<(const Client& a, const Client& b) {
	return a.ABC < b.ABC;
}
bool operator==(const Client& a, const Client& b) {
	return a.ABC == b.ABC;
}



Product::Product() {
	price = 0;
	quantity = 0;
	strcpy(name, "None");
}

bool Product::Add() {
	try {

		int flag = 0;
		while (flag == 1 || flag == 0)
		{
			cout << "Введите наименование для товара";
			cin >> this->name;
			if (!CheckLetters(this->name))
			{
				flag = 1;
				cout << "Введена некорректная строка. Попробуйте ещё раз\n";
			}
			else flag = 2;
		}

		quantity = SetNumbers(1,INT_MAX);
		price = SetNumbers(1, INT_MAX);
		return true;
	}
	catch (...) {
		return false;
	}
}

istream& operator>>(istream& stream, Product obj) {
	try {
		stream >> obj.name;
		stream >> obj.quantity;
		stream >> obj.price;
		return stream;

	}
	catch (...) {
		if (!stream.goodbit)
			cout << "Ошибка чтения информации из потока.\n";
	}
}
ostream& operator<<(ostream& stream, Product obj) {
	try {
		stream << obj.name << " " << obj.quantity << " " << obj.price << '\n';
		return stream;

	}
	catch (...) {
		if (!stream.goodbit)
			cout << "Ошибка вывода из потока.\n";
	}

}

bool operator>(const Product a, const Product b) {
	return a.quantity > b.quantity;
}
bool operator<(const Product a, const Product b) {
	return a.quantity < b.quantity;
}
bool operator==(const Product a, const Product b) {
	return a.quantity == b.quantity;
}

float Product::total_price() {
	return price * quantity;
}


bool CompareProductD::operator()(Product& a, Product& b)
{
	if (a.total_price() < b.total_price()) return true;
	else
		return false;
}

bool clients_add() {

	try {
		Client temp_obj;
		temp_obj.Add();
		client_queue.push(temp_obj);

		char* sent; strcpy(sent, "Добавлен элемент в client_queue");
		action_stack.push(sent);

		return true;
	}
	catch (...) {
			cout << "Ошибка добавления элемента.\n";
			return true;
	}
	
}
bool products_add() {
	try {
		Product temp_obj;
		temp_obj.Add();
		product_queue.push(temp_obj);

		char* sent; strcpy(sent, "Добавлен элемент в product_queue");
		action_stack.push(sent);

		return true;
	}
	catch (...) {
		cout << "Ошибка добавления элемента.\n";
		return true;
	}
	
}

bool clients_view() {
	int n = client_queue.size();
	if (n == 0) {
		cout << "Пустая очередь клиентов.\n";
		return false;
	}

	for (int i = 0; i < n; i++) {
		cout<<i+1<<" " << client_queue.top() << endl;
	}

	return true;
}
bool products_view() {
	int n = product_queue.size();
	if (n == 0) {
		cout << "Пустая очередь продуктов.\n";
		return false;
	}

	for (int i = 0; i < n; i++) {
		cout << i + 1 << " " << product_queue.back() << endl;
	}

	return true;
}
bool actions_view();

bool clients_delete(int* numbers_delete);
bool products_delete(int* numbers_delete);

bool clients_edit(int* numbers_edit);
bool products_edit(int* numbers_edit);

