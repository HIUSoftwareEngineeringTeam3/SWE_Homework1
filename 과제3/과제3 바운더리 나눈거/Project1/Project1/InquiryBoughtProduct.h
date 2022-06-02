#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Member;
class MemberList;

class InquiryBoughtProductUI;
class InquiryBoughtProduct {
private:
	InquiryBoughtProductUI* boundary;
	MemberList* memberList;

public:
	InquiryBoughtProduct(ofstream* outfp, ifstream* infp, MemberList* memList);
	void showProduct();
	InquiryBoughtProductUI* getBoundary();



};