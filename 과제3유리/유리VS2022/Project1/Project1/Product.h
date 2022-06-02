#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Member.h"
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
	static ofstream* out_fp;
public:
	Product(ofstream* fp);
	Product(string pName,string companyName,int price, int quantity);
	string getProductName();
	Member* getSellingMember();
	void printMyProducts();
	void printBoughtProducts();
	void evaluateSatisfaction(int evaluateNum);
	void printStatistics();
	float getAverageSatisfaction();
};
