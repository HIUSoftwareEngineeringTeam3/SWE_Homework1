#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Member;
class MemberCollection;

class RemoveMemberUI;
class RemoveMember {
private:
	RemoveMemberUI* boundary;
	MemberCollection* memberCollection;

public:
	RemoveMember(ofstream* outfp, ifstream* infp, MemberCollection* memList);
	RemoveMemberUI* getBoundary();
	void removeMember();


};