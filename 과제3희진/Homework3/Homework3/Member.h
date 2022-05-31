#pragma once
#include "Product.h"

class Member {
private:
	string memberName;
	string memberNumber;
	string memberID;
	string memberPWD;
	vector<Product*> sellingProductVector;
	vector<Product*> selledProductVector;
	vector<Product*> boughtProductVector;
	static ofstream* out_fp;
public:
	Member(ofstream* fp);
	Member(string name, string number, string id, string pwd);
	string getMemberName();
	string getMemberNumber();
	string getMemberID();
	string getMemberPWD();
	Product* searchingProduct;
	void myProductList();
	void boughtProductList();
	void registerProduct(string productName, string madeCompanyName, int productPrice, int productQuantity);
	void printSelledProductStatistics();
	void evaluateSatisfaction(string productName, int evaluateNum);
	void inquirySoldProductList();
	void searchProductDetail(string productName);
	void purchaseProduct();
};
