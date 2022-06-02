#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Member;
class MemberList;

class InquirySoldProductUI;
class InquirySoldProduct {
private:
	InquirySoldProductUI* boundary;
	MemberList* memberList;

public:
	InquirySoldProduct(ofstream* outfp, ifstream* infp, MemberList* memList);
	void showProduct();
	InquirySoldProductUI* getBoundary();



};