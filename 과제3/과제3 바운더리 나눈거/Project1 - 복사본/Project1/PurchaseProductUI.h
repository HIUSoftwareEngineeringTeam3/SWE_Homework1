#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Member;
class MemberCollection;

class PurchaseProduct;
class PurchaseProductUI {
private:
	PurchaseProduct* control;
	ofstream* out_fp;
	ifstream* in_fp;
public:
	PurchaseProductUI(ofstream* outfp, ifstream* infp, PurchaseProduct* controlClass);
	void startInterface();
	void loginFailed();
	void productEmptyFailed();
	void notSearchedProductFailed();
	void purchaseSuccess(string sellerID, string productName);
	void purchaseButton();



};