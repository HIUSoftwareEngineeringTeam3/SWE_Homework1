

// ��� ����
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Product.h"
// ��� ����
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"




// �Լ� ����
void doTask();
void join();
void login();
void programExit();
void registerProduct();
void evaluateSatisfaction();
void printStatistics();

// ���� ����
vector<Member*> memberVector;
Member* nowLoginMember;
Product* nowSelectedProduct;
ifstream in_fp;
ofstream out_fp;
int main()
{ // ���� ������� ���� �ʱ�ȭ
	in_fp.open(INPUT_FILE_NAME);
	out_fp.open(OUTPUT_FILE_NAME);
	Member memberFpTaker(&out_fp);
	Product productFpTaker(&out_fp);

	
	doTask();
	return 0;
}

void doTask()
{ // �޴� �Ľ��� ���� level ������ ���� ����
	int menu_level_1 = 0, menu_level_2 = 0;
	int is_program_exit = 0;
	
	while (!is_program_exit)
	{ // �Է����Ͽ��� �޴� ���� 2���� �б�
		in_fp >> menu_level_1 >> menu_level_2;

		// �޴� ���� �� �ش� ���� ����
		switch (menu_level_1)
		{
			case 1:
				switch (menu_level_2)
				{
					case 1:
						//ȸ������
						join();
						break;
					case 2:
						//ȸ��Ż��
						break;
				}
				break;
			case 2:
				switch (menu_level_2)
				{
					case 1:
						//�α���
						login();
						break;
					case 2:
						//�α׾ƿ�
						break;
				}
				break;
			case 3:
				switch (menu_level_2)
				{
					case 1:
						//�Ǹ� �Ƿ� ���
						registerProduct();
						break;
					case 2:
						//��� ��ǰ ��ȸ
						break;
					case 3:
						//�Ǹ� �Ϸ� ��ǰ ��ȸ
						break;
				}
				break;
			case 4:
				switch (menu_level_2)
				{
					case 1:
						//��ǰ ���� �˻�
						break;
					case 2:
						//��ǰ ����
						break;
					case 3:
						//��ǰ ���� ���� ��ȸ
						break;
					case 4:
						//��ǰ ���Ÿ����� ��
						evaluateSatisfaction();
						break;

				}
				break;
			case 5:
				switch (menu_level_2)
				{
					case 1:
						//�Ǹ� ��ǰ ���
						printStatistics();
						break;
				}
				break;
			case 6:
				switch (menu_level_2)
				{
					case 1: // "6.1. ���ᡰ �޴� �κ�
						programExit();
						is_program_exit = 1;
						break;
				}
				break;
		}
	}
}
void join()
{
	string name, ssn, id, pwd;
	in_fp >> name >> ssn >> id >> pwd;
	Member* nowMember = new Member(name,ssn,id, pwd);
	memberVector.push_back(nowMember);
}

void login() 
{
	nowLoginMember = memberVector[0];
}

void registerProduct() 
{
	string productName, companyName;
	int price, quantity;
	in_fp >> productName >> companyName >> price >> quantity;
	nowLoginMember->registerProduct(productName, companyName, price, quantity);
}

void evaluateSatisfaction() 
{
	int evaluateNum;
	in_fp >> evaluateNum;
	nowSelectedProduct->evaluateSatisfaction(evaluateNum);
}

void printStatistics() 
{
	nowLoginMember->printSelledProductStatistics();
}

void programExit()
{

}

