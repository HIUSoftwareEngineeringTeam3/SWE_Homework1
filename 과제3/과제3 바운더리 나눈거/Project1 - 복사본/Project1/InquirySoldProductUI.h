#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Member;
class MemberCollection;

class InquirySoldProduct;
class InquirySoldProductUI {
private:
	InquirySoldProduct* control;
	ofstream* out_fp;
	ifstream* in_fp;
public:
	InquirySoldProductUI(ofstream* outfp, ifstream* infp, InquirySoldProduct* controlClass);
	void startInterface();
	void loginFailed();
	void clickInquirySoldProductButton();
	void inquirySoldOutProductFailed();
	void inquirySoldOutProductSuccess(string productName, string companyName, int price, int quantity,float averageSatisfaction);
	void endOfLine();


};