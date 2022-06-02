#include "LogOutMember.h"
#include "LogOutMemberUI.h"
#include "Member.h"

LogOutMemberUI::LogOutMemberUI(ofstream* outfp, ifstream* infp) {
	out_fp = outfp;
	in_fp = infp;
}
void LogOutMemberUI::startInterface() {
	(*out_fp) << "2.2. �α׾ƿ�\n> ";
}
void LogOutMemberUI::clickLogOutMember() {
	control->checkLogoutMember();

}
void LogOutMemberUI::logOutMemberSuccess(string id) {
	(*out_fp) <<id << "\n\n";
}

void LogOutMemberUI::logOutMemberFail() {
	(*out_fp) << "�α������� �ƴմϴ�.\n\n";
}