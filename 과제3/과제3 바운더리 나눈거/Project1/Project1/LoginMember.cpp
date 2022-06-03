#include "LoginMember.h"
#include "LoginMemberUI.h"
#include "MemberCollection.h"
#include "ProductCollection.h"


LoginMember::LoginMember(ofstream* outfp, ifstream* infp, MemberCollection* memList) {
	boundary = new LoginMemberUI(outfp, infp,this);
	memberCollection = memList;
	boundary->startInterface();
}
void LoginMember::checkID_PW(string id, string pwd) {
	int checkType = memberCollection->checkValidID_PW(id, pwd);
	if (checkType==0) {
		memberCollection->loginMember(id, pwd);
		boundary->loginMemberSuccess(id,pwd);
	}
	else {
		boundary->loginMemberFail(checkType);
	}
}

LoginMemberUI* LoginMember::getBoundary() {
	return boundary;
}
