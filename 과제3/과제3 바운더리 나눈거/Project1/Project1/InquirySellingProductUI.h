#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Member;
class MemberCollection;

class InquirySellingProduct;
class InquirySellingProductUI {
private:
	InquirySellingProduct* control;
	ofstream* out_fp;
	ifstream* in_fp;
public:
	InquirySellingProductUI(ofstream* outfp, ifstream* infp, InquirySellingProduct* controlClass);
	void startInterface();
	void clickInquiryProduct();
	void inquiryProductFailed();
	void loginFailed();
	void inquiryProductSuccess(string productName, string companyName, int price, int quantity);
	void endOfLine();


};