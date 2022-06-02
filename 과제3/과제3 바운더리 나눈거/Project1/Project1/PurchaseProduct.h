#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Member;
class MemberList;

class PurchaseProductUI;
class PurchaseProduct {
private:
	PurchaseProductUI* boundary;
	MemberList* memberList;

public:
	PurchaseProduct(ofstream* outfp, ifstream* infp, MemberList* memList);
	PurchaseProductUI* getBoundary();
	void purchaseProduct();

};