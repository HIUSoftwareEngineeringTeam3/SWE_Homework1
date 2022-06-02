#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Member;
class MemberList;

class RemoveMember;
class RemoveMemberUI {
private:
	RemoveMember* control;
	ofstream* out_fp;
	ifstream* in_fp;
public:
	RemoveMemberUI(ofstream* outfp, ifstream* infp, RemoveMember* controlClass);
	void startInterface();
	void clickRemoveMember();
	void removeMemberFail();
	void removeMemberSuccess(Member* member);



};