#include "RemoveMember.h"
#include "RemoveMemberUI.h"
#include "Member.h"
RemoveMemberUI::RemoveMemberUI(ofstream* outfp, ifstream* infp) {
	out_fp = outfp;
	in_fp = infp;
}
void RemoveMemberUI::startInterface() {
	(*out_fp) << "1.2. ȸ��Ż��\n> ";
}
void RemoveMemberUI::clickRemoveMember() {
	control->removeMember();
	
}
void RemoveMemberUI::removeMemberSuccess(Member* member) {
	(*out_fp) << member->getMemberID()<<"\n\n";
}

void RemoveMemberUI::removeMemberFail() {
	(*out_fp) << "�������� �ʴ� ȸ���Դϴ�\n\n ";
}