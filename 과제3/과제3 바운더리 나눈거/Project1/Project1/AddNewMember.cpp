#include "AddNewMember.h"
#include "AddNewMemberUI.h"
#include "Member.h"
#include "MemberCollection.h"
#include "ProductCollection.h"
#include "Product.h"

AddNewMember::AddNewMember(ofstream* outfp, ifstream* infp, MemberCollection* memList) {
	memberCollection = memList;
	boundary = new AddNewMemberUI(outfp, infp, this);
	boundary->startInterface();
}

void AddNewMember::addNewMember(string name, string ssn, string id, string pwd) {
	
	if (checkMemberID(name, ssn, id, pwd)==true) {
		
		Member* nowMember = new Member(name, ssn, id, pwd);
		boundary->addMemberSuccess(name, ssn, id, pwd);
		memberCollection->addNewMember(nowMember);
	}
	else {
		boundary->memberCheckFailPrint();
	}


}

AddNewMemberUI* AddNewMember::getBoundary() {
	return boundary;
}

bool AddNewMember::checkMemberID(string name, string ssn, string id, string pwd) {
	
	//cout << "1.1. 회원가입\n> ";
	vector<Member*>* memberVector = memberCollection->getMemberVector();
	for (int i = 0; i < memberVector->size(); i++)
	{
		if (id == (*memberVector)[i]->getMemberID())
		{

			//			cout << "중복된 아이디입니다.\n\n";
			boundary->memberCheckFailPrint();
			return false;
		}
	}
	return true;
}
