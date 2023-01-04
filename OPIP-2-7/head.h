#include"tools.h"

class Client {
	

public:
	char ABC;
	char* s_name;

	Client();

	bool Add();

	friend istream& operator>>(istream& stream, Client obj);
	friend ostream& operator<<(ostream& stream, Client obj);

	friend bool operator>(const Client& a, const Client b);
	friend bool operator<(const Client& a, const Client b);
	friend bool operator==(const Client& a, const Client b);

};


class Product {
	

public:
	int quantity;
	int price;
	char* name;

	Product();

	bool Add();

	friend istream& operator>>(istream& stream, Product obj);
	friend ostream& operator<<(ostream& stream, Product obj);

	friend bool operator>(const Product& a, const Product b);
	friend bool operator<(const Product& a, const Product b);
	friend bool operator==(const Product& a, const Product b);

	float total_price();
};

class CompareProductD { // Descending sort
public:
	bool operator()(Product& a, Product& b);
};

static priority_queue<Client,vector<Client>,CompareProductD> client_queue; // descending
static queue< Product,vector<Product>> product_queue; // descending 
static stack<char*> action_stack;

bool clients_add();
bool products_add();
bool actions_add();

bool clients_view();
bool products_view();
bool actions_view();

bool clients_delete(int* numbers_delete);
bool products_delete(int* numbers_delete);

bool clients_edit(int* numbers_edit);
bool products_edit(int* numbers_edit);
