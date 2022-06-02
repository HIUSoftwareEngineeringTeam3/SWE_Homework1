#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Member;
class MemberList;

class InquirySellingProductUI;
class InquirySellingProduct {
private:
	InquirySellingProductUI* boundary;
	MemberList* memberList;

public:
	InquirySellingProduct(ofstream* outfp, ifstream* infp, MemberList* memList);
	void showProduct();
	InquirySellingProductUI* getBoundary();



};