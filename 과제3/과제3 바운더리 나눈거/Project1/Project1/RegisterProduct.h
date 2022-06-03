#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Member;
class MemberCollection;

class RegisterProductUI;
class RegisterProduct {
private:
	RegisterProductUI* boundary;
	MemberCollection* memberCollection;

public:
	RegisterProduct(ofstream* outfp, ifstream* infp, MemberCollection* memList);
	void registerProduct(string productName, string companyName, int price, int quantity);
	RegisterProductUI* getBoundary();



};