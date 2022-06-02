#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Member;
class MemberList;

class InquiryBoughtProduct;
class InquiryBoughtProductUI {
private:
	InquiryBoughtProduct* control;
	ofstream* out_fp;
	ifstream* in_fp;
public:
	InquiryBoughtProductUI(ofstream* outfp, ifstream* infp);
	void startInterface();
	void clickInquiryBoughtProduct();
	void inquiryBoughtProductFailed();
	void loginFailed();
	void inquiryBoughtProductSuccess(string sellerID, string productName, string companyName, int price, int quantity, float averageSatisfaction);
	void endOfLine();


};