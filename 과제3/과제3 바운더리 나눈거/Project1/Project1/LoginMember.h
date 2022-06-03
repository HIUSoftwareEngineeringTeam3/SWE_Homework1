#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Member;
class MemberCollection;

class LoginMemberUI;
class LoginMember {
private:
	LoginMemberUI* boundary;
	MemberCollection* memberCollection;
public:
	LoginMember(ofstream* outfp, ifstream* infp, MemberCollection* memList);
	LoginMemberUI* getBoundary();
	void checkID_PW(string id, string pwd);

};