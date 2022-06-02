#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Member;
class MemberList;

class InquirySellingProduct;
class InquirySellingProductUI {
private:
	InquirySellingProduct* control;
	ofstream* out_fp;
	ifstream* in_fp;
public:
	InquirySellingProductUI(ofstream* outfp, ifstream* infp);
	void startInterface();
	void clickInquiryProduct();
	void inquiryProductFailed();
	void loginFailed();
	void inquiryProductSuccess(string productName, string companyName, int price, int quantity);
	void endOfLine();


};