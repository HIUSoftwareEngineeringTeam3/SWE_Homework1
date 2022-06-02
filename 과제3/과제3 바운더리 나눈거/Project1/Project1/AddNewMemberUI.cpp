#include "AddNewMember.h"
#include "AddNewMemberUI.h"
#include "Member.h"
#include "MemberList.h"
#include "Product.h"


AddNewMemberUI::AddNewMemberUI(ofstream* outfp, ifstream* infp, AddNewMember* controlClass) {
	out_fp = outfp;
	in_fp = infp;
	control = controlClass;
}
void AddNewMemberUI::inputInformation() {
	(*in_fp) >> name >> ssn >> id >> pwd;
	control->addNewMember(name, ssn, id, pwd);
}

void AddNewMemberUI::addMemberSuccess(string name, string ssn, string id, string pwd) {
	(*out_fp) << name << " " << ssn << " " << id << " " << pwd << "\n\n";
}

void AddNewMemberUI::memberCheckFailPrint() {
	(*out_fp) << "중복된 아이디입니다.\n\n";
}

void AddNewMemberUI::startInterface() {
	(*out_fp) << "1.1. 회원가입\n> ";
}
