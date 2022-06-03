#pragma once
#include "ProductCollection.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Product;
//class ProductCollection;

class Member {
private:
	string memberName;
	string memberNumber;
	string memberID;
	string memberPWD;
	//vector<Product*> sellingProductCollection;
	//vector<Product*> soldOutProdcutCollection;
	//vector<Product*> boughtProductCollection;
	ProductCollection sellingProductCollection;
	ProductCollection soldOutProductCollection;
	ProductCollection boughtProductCollection;
public:
	//Member(ofstream* fp,vector<Member*>* memberVector);
	Member(string name, string number, string id, string pwd);
	string getMemberName();
	string getMemberNumber();
	string getMemberID();
	string getMemberPWD();
	Product* searchingProduct;
	//vector<Product*>*  getSellingProductCollection();
	//vector<Product*>*  getSoldOutProductCollection();
	//vector<Product*>*  getBoughtProductCollection();

	ProductCollection*  getSellingProductCollection();
	ProductCollection*  getSoldOutProductCollection();
	ProductCollection*  getBoughtProductCollection();

	void registerProduct(string productName, string madeCompanyName, int productPrice, int productQuantity);

	void productSoldOut(Product* product);
	void deleteMemory();
};