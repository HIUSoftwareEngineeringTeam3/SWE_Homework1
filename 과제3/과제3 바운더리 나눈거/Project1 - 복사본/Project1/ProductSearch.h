#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Member;
class MemberCollection;

class ProductSearchUI;
class ProductSearch {
private:
	ProductSearchUI* boundary;
	MemberCollection* memberCollection;

public:
	ProductSearch(ofstream* outfp, ifstream* infp, MemberCollection* memList);
	ProductSearchUI* getBoundary();

	void showProductList(string name);

};