#include "PrintStatisticsUI.h"
#include "PrintStatistics.h"
PrintStatisticsUI::PrintStatisticsUI(ofstream* outfp, ifstream* infp) {
	out_fp = outfp;
	in_fp = infp;
}
void PrintStatisticsUI::startInterface() {
	(*out_fp) << "3.3. 판매 완료 상품 조회\n";
}

void PrintStatisticsUI::loginFailed() {
	(*out_fp) << "> " << "로그인을 먼저 해주세요.\n\n";
}


void PrintStatisticsUI::inquirySoldOutProductFailed() {
	(*out_fp) << "> 판매 완료된 상품이 없습니다.\n";
}

void PrintStatisticsUI::inquirySoldOutProductSuccess(string productName, string companyName, int price, int quantity, float averageSatisfaction) {
	(*out_fp) << "> " << productName << " " << companyName << " " << price << " " << quantity << " " << averageSatisfaction << "\n";
}

void PrintStatisticsUI::endOfLine() {
	(*out_fp) << "\n";
}
