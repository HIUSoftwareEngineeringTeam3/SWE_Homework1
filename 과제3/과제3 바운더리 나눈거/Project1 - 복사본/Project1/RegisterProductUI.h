#pragma once
#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Member;
class MemberCollection;

class RegisterProduct;
class RegisterProductUI {
private:
	RegisterProduct* control;
	ofstream* out_fp;
	ifstream* in_fp;
public:
	RegisterProductUI(ofstream* outfp, ifstream* infp, RegisterProduct* controlClass);
	void startInterface();
	void inputInformation();
	void registerProductFailed();
	void registerProductSuccess(string productName, string companyName, int price, int quantity);



};