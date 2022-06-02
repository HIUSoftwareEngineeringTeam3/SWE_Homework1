#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Member;
class MemberList;

class EvaluateSatisfaction;
class EvaluateSatisfactionUI {
private:
	EvaluateSatisfaction* control;
	ofstream* out_fp;
	ifstream* in_fp;
public:
	EvaluateSatisfactionUI(ofstream* outfp, ifstream* infp);
	void startInterface();
	void loginFailed();
	void productNotFoundFailed();
	void evaluateSuccess(string sellerName, string productName, float averageSatisfaction);
	void inputScore();



};