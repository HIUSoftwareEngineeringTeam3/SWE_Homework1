#include "LoginMember.h"
#include "LoginMemberUI.h"
#include "MemberList.h"


LoginMember::LoginMember(ofstream* outfp, ifstream* infp, MemberList* memList) {
	boundary = new LoginMemberUI(outfp, infp);
	memberList = memList;
	boundary->startInterface();
}
void LoginMember::checkID_PW(string id, string pwd) {
	int checkType = memberList->checkValidID_PW(id, pwd);
	if (checkType==0) {
		memberList->loginMember(id, pwd);
		boundary->loginMemberSuccess(id,pwd);
	}
	else {
		boundary->loginMemberFail(checkType);
	}
}

LoginMemberUI* LoginMember::getBoundary() {
	return boundary;
}
