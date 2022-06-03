#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Member;
class MemberCollection;

class InquiryBoughtProductUI;
class InquiryBoughtProduct {
private:
	InquiryBoughtProductUI* boundary;
	MemberCollection* memberCollection;

public:
	InquiryBoughtProduct(ofstream* outfp, ifstream* infp, MemberCollection* memList);
	void showProduct();
	InquiryBoughtProductUI* getBoundary();



};