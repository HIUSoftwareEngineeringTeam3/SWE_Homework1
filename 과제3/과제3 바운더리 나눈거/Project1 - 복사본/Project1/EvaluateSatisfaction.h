#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Member;
class MemberCollection;

class EvaluateSatisfactionUI;
class EvaluateSatisfaction {
private:
	EvaluateSatisfactionUI* boundary;
	MemberCollection* memberCollection;

public:
	EvaluateSatisfaction(ofstream* outfp, ifstream* infp, MemberCollection* memList);
	EvaluateSatisfactionUI* getBoundary();
	

	void confirmScore(string productName, int evaluateNum);

};