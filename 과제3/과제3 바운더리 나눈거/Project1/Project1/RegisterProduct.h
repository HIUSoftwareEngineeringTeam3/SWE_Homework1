#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Member;
class MemberList;

class RegisterProductUI;
class RegisterProduct {
private:
	RegisterProductUI* boundary;
	MemberList* memberList;

public:
	RegisterProduct(ofstream* outfp, ifstream* infp, MemberList* memList);
	void registerProduct(string productName, string companyName, int price, int quantity);
	RegisterProductUI* getBoundary();



};