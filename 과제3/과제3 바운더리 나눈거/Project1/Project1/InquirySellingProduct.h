#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Member;
class MemberCollection;

class InquirySellingProductUI;
class InquirySellingProduct {
private:
	InquirySellingProductUI* boundary;
	MemberCollection* memberCollection;

public:
	InquirySellingProduct(ofstream* outfp, ifstream* infp, MemberCollection* memList);
	void showProduct();
	InquirySellingProductUI* getBoundary();



};