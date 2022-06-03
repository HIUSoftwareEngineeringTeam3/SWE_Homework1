#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>



using namespace std;
class Product;
class Member;
class ProductCollection {
private:
	vector<Product*> productVector;
public:
	void pushProduct(Product* product);
	void eraseProdcut(Product* prodcut);
	void deleteMemory();
	vector<Product*>* getProductVector();
};
