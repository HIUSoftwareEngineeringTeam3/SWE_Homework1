#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>

class Member;

using namespace std;

class Product {
private:
	Member* sellingMember;
	string productName;
	string madeCompanyName;
	int productPrice;
	int productQuantity;
	int selledProductQuantity;

	int satisfactionNumber;
	int satisfactionQuantity;
	bool nowSelling;
	static ofstream* out_fp;
public:
	Product(ofstream* fp);
	Product(Member* seller, string pName, string companyName, int price, int quantity);
	string getProductName();
	string getmadeCompanyName();
	int getproductPrice();
	Member* getSellingMember();
	void printMyProducts();
	void printBoughtProducts();
	void evaluateSatisfaction(int evaluateNum);
	void printStatistics();
	float getAverageSatisfaction();
	void printSoldProductList();
	int remainProductQuantity();
	void buyProduct();
	bool getNowSelling();
	int getSelledProductQuantity();

};
