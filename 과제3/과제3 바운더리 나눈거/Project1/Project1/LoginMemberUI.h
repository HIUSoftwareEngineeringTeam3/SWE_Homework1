#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Member;
class MemberCollection;

class LoginMember;
class LoginMemberUI {
private:
	LoginMember* control;
	ofstream* out_fp;
	ifstream* in_fp;
public:
	LoginMemberUI(ofstream* outfp, ifstream* infp, LoginMember* controller);
	void startInterface();
	void inputID_PW();
	void loginMemberFail(int type);
	void loginMemberSuccess(string id, string pwd);
};