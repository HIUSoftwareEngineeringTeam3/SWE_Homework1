#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Member;
class MemberList;

class ProductSearch;
class ProductSearchUI {
private:
	ProductSearch* control;
	ofstream* out_fp;
	ifstream* in_fp;
public:
	ProductSearchUI(ofstream* outfp, ifstream* infp, ProductSearch* controlClass);
	void startInterface();
	void productListFailed();
	void productListSuccess(string sellerID, string productName, string companyName, int price, int quantity, float averageSatisfaction);
	void inputProductName();



};