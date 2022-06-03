#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Member;
class MemberCollection;

class InquirySoldProductUI;
class InquirySoldProduct {
private:
	InquirySoldProductUI* boundary;
	MemberCollection* memberCollection;

public:
	InquirySoldProduct(ofstream* outfp, ifstream* infp, MemberCollection* memList);
	void showProduct();
	InquirySoldProductUI* getBoundary();



};