#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Member;
class MemberList;

class EvaluateSatisfactionUI;
class EvaluateSatisfaction {
private:
	EvaluateSatisfactionUI* boundary;
	MemberList* memberList;

public:
	EvaluateSatisfaction(ofstream* outfp, ifstream* infp, MemberList* memList);
	EvaluateSatisfactionUI* getBoundary();
	

	void confirmScore(string productName, int evaluateNum);

};