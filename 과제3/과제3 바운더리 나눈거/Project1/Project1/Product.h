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
public:
	Product(Member* seller, string pName, string companyName, int price, int quantity);
	string getProductName();
	string getMadeCompanyName();
	int getProductPrice();
	Member* getSellingMember();


	void evaluateSatisfaction(int evaluateNum);

	float getAverageSatisfaction();

	int remainProductQuantity();
	void buyProduct();
	bool getNowSelling();
	int getSelledProductQuantity();

};
