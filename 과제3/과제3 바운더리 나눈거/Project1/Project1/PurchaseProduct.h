#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Member;
class MemberCollection;

class PurchaseProductUI;
class PurchaseProduct {
private:
	PurchaseProductUI* boundary;
	MemberCollection* memberCollection;

public:
	PurchaseProduct(ofstream* outfp, ifstream* infp, MemberCollection* memList);
	PurchaseProductUI* getBoundary();
	void purchaseProduct();

};