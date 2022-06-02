#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Member;
class MemberList;

class LogOutMember;
class LogOutMemberUI {
private:
	LogOutMember* control;
	ofstream* out_fp;
	ifstream* in_fp;
public:
	LogOutMemberUI(ofstream* outfp, ifstream* infp);
	void startInterface();
	void clickLogOutMember();
	void logOutMemberFail();
	void logOutMemberSuccess(string id);



};