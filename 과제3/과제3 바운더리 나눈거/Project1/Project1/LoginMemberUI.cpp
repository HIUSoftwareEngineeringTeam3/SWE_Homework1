#include "LoginMember.h"
#include "LoginMemberUI.h"
#include "Member.h"

LoginMemberUI::LoginMemberUI(ofstream* outfp, ifstream* infp) {
	out_fp = outfp;
	in_fp = infp;
}
void LoginMemberUI::startInterface() {
	(*out_fp) << "2.1. �α���\n> ";
}

void LoginMemberUI::inputID_PW() {
	string id, pwd;
	(*in_fp) >> id >> pwd;
	control->checkID_PW(id, pwd);
}

void LoginMemberUI::loginMemberFail(int type) {
	switch (type) {
	case 1:
		(*out_fp) << "��й�ȣ�� Ʋ�Ƚ��ϴ�.\n\n";
		break;
	case 2:
		(*out_fp) << "��ȿ���� ���� ���̵��Դϴ�.\n\n";
		break;
	case 3:
		(*out_fp) << "�̹� �α��� ���Դϴ�.\n\n";
		break;

	}

}
void LoginMemberUI::loginMemberSuccess(string id, string pwd) {
	(*out_fp) << id << " " << pwd << "\n\n";
}