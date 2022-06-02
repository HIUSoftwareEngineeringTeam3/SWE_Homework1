#include "LoginMember.h"
#include "LoginMemberUI.h"
#include "Member.h"

LoginMemberUI::LoginMemberUI(ofstream* outfp, ifstream* infp) {
	out_fp = outfp;
	in_fp = infp;
}
void LoginMemberUI::startInterface() {
	(*out_fp) << "2.1. 로그인\n> ";
}

void LoginMemberUI::inputID_PW() {
	string id, pwd;
	(*in_fp) >> id >> pwd;
	control->checkID_PW(id, pwd);
}

void LoginMemberUI::loginMemberFail(int type) {
	switch (type) {
	case 1:
		(*out_fp) << "비밀번호가 틀렸습니다.\n\n";
		break;
	case 2:
		(*out_fp) << "유효하지 않은 아이디입니다.\n\n";
		break;
	case 3:
		(*out_fp) << "이미 로그인 중입니다.\n\n";
		break;

	}

}
void LoginMemberUI::loginMemberSuccess(string id, string pwd) {
	(*out_fp) << id << " " << pwd << "\n\n";
}