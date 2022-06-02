#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Product;

class Member {
private:
	string memberName;
	string memberNumber;
	string memberID;
	string memberPWD;
	vector<Product*> sellingProductVector;
	vector<Product*> soldOutProductVector;
	vector<Product*> boughtProductVector;
	static vector<Member*>* wholeMemberVector;
	static ofstream* out_fp;
public:
	Member(ofstream* fp,vector<Member*>* memberVector);
	Member(string name, string number, string id, string pwd);
	string getMemberName();
	string getMemberNumber();
	string getMemberID();
	string getMemberPWD();
	Product* searchingProduct;
	vector<Product*>*  getSellingProductVector();
	vector<Product*>*  getSoldOutProductVector();
	vector<Product*>*  getBoughtProductVector();
	void boughtProductList();
	void registerProduct(string productName, string madeCompanyName, int productPrice, int productQuantity);
	void printSelledProductStatistics();
	void evaluateSatisfaction(string productName, int evaluateNum);
	void inquirySoldProductList();
	void searchProductDetail(string productName);
	void purchaseProduct();
	void productSoldOut(Product* product);
	void deleteMemory();
};