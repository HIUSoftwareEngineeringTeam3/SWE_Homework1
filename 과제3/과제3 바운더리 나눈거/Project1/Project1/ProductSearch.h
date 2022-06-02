#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Member;
class MemberList;

class ProductSearchUI;
class ProductSearch {
private:
	ProductSearchUI* boundary;
	MemberList* memberList;

public:
	ProductSearch(ofstream* outfp, ifstream* infp, MemberList* memList);
	ProductSearchUI* getBoundary();

	void showProductList(string name);

};