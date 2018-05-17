/*1751367 ��2 ������*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

class TString {
private:
	char *content;		//ָ���ַ�����ָ��
	int   len;			//�ַ����ĳ��ȣ�����β��
public:
	TString(const char *s = NULL);
	~TString();
	char *get_content();
	/* ������Ҫ���������ĳ�Ա�����Ķ��� */
	TString(TString &str);
	void set(const char *);
	void set(TString &);
	int length();
};
/* �ڴ˸���������Ա����������ʵ�ֲ��� */
void TString::set(TString &str)
{
	if (str.content == NULL)
	{
		if (content)
		{
			delete[] content;
		}
		content = NULL;
		len = 0;
	}
	else
	{
		if (content)
		{
			delete[] content;
		}
		len = str.len;
		content = new char[len + 1];
		strcpy(content, str.content);
	}
}

int TString::length()
{
	return len;
}

void TString::set(const char *str)
{
	if (str == NULL || strlen(str) == 0) {
		if (content)
		{
			delete[] content;
		}
		content = NULL;
		len = 0;
	}
	else
	{
		if (content)
		{
			delete[] content;
		}
		len = strlen(str);
		content = new char[len + 1];
		strcpy(content, str);
	}
}

TString::TString(const char *s)
{
	if (s == NULL || strlen(s) == 0) {
		content = NULL;
		len = 0;
	}
	else {
		len = strlen(s);
		content = new char[len + 1];
		strcpy(content, s);
	}
}

TString::TString(TString &str)
{
	if (str.content == NULL || str.len == 0) {
		content = NULL;
		len = 0;
	}
	else
	{
		len = str.len;
		content = new char[len + 1];
		strcpy(content, str.content);
	}
}

TString::~TString()
{
	if (content)
		delete[]content;
}

char *TString::get_content()
{
	if (content == NULL)
		return (char *)"<NULL>";
	else
		return content;
}

/* main������׼�� */
int main()
{
	if (1) {
		TString s1;                  //s1ΪNULL
		TString s2("teststr2");      //s2Ϊ"teststr2"
		TString s3 = "teststr3";       //s3Ϊ"teststr3"
		TString s4 = NULL;             //s4ΪNULL
		TString s5 = "";               //s5ΪNULL

		cout << "������󲢳�ʼ������(NULL���ַ���������ʼ��)" << endl;

		cout << "s1Ӧ����<NULL>��  ʵ�������" << s1.get_content() << endl;
		cout << "s2Ӧ����teststr2��ʵ�������" << s2.get_content() << endl;
		cout << "s3Ӧ����teststr3��ʵ�������" << s3.get_content() << endl;
		cout << "s4Ӧ����<NULL>��  ʵ�������" << s4.get_content() << endl;
		cout << "s5Ӧ����<NULL>��  ʵ�������" << s5.get_content() << endl;

		cout << endl << "���������..." << endl;
		getchar();
	}

	if (1) {
		TString s0 = "teststr1";
		const char *str1 = "teststr2";
		char  str2[] = "teststr3";
		char *str3 = NULL;
		char  str4[] = "";
		TString s1 = s0, s2 = str1, s3 = str2, s4 = str3, s5 = str4;

		cout << "������󲢳�ʼ������(TString�����ַ�ָ�롢�ַ�����)" << endl;

		cout << "s1Ӧ����teststr1��ʵ�������" << s1.get_content() << endl;
		cout << "s2Ӧ����teststr2��ʵ�������" << s2.get_content() << endl;
		cout << "s3Ӧ����teststr3��ʵ�������" << s3.get_content() << endl;
		cout << "s4Ӧ����<NULL>��  ʵ�������" << s4.get_content() << endl;
		cout << "s5Ӧ����<NULL>��  ʵ�������" << s5.get_content() << endl;

		cout << endl << "���������..." << endl;
		getchar();
	}

	if (1) {
		TString s0 = "hello";
		char    str1[] = "tong\0\0\0\0";
		const char   *str2 = "ji";
		char   *str3 = NULL;
		const char   *str4 = "";

		cout << "ͨ��set�������ַ�����ֵ������Ĳ���" << endl;

		cout << "s0ӦΪhello�� ʵ�������" << s0.get_content() << endl;

		s0.set(str1);
		cout << "s0ӦΪtong��  ʵ�������" << s0.get_content() << endl;

		s0.set(str2);
		cout << "s0ӦΪji��    ʵ�������" << s0.get_content() << endl;

		s0.set(str3);
		cout << "s0ӦΪ<NULL>��ʵ�������" << s0.get_content() << endl;

		s0.set(str4);
		cout << "s0ӦΪ<NULL>��ʵ�������" << s0.get_content() << endl;

		s0.set(strcat(str1, str2));
		cout << "s0ӦΪtongji��ʵ�������" << s0.get_content() << endl;

		s0.set(strcpy(str1, str2));
		cout << "s0ӦΪji��    ʵ�������" << s0.get_content() << endl;

		cout << endl << "���������..." << endl;
		getchar();
	}

	if (1) {
		TString s0 = "hello";
		TString s1 = "tongji";
		TString s2;
		TString s3(s2);

		cout << "ͨ��set������һ��������ַ�����ֵ����һ������Ĳ���" << endl;

		cout << "s0ӦΪhello�� ʵ�������" << s0.get_content() << endl;

		s0.set(s1);
		cout << "s0ӦΪtongji��ʵ�������" << s0.get_content() << endl;

		s0.set(s2);
		cout << "s0ӦΪ<NULL>��ʵ�������" << s0.get_content() << endl;

		s0.set(s3);
		cout << "s0ӦΪ<NULL>��ʵ�������" << s0.get_content() << endl;

		cout << endl << "���������..." << endl;
		getchar();
	}

	if (1) {
		TString s1 = "hello";
		TString s2;
		char str1[] = "tong\0\0\0\0";
		const char *str2 = "ji";

		cout << "�󳤶Ȳ���(length()����)" << endl;

		cout << "s1Ϊhello�� ����ӦΪ5��ʵ�ʣ�" << s1.length() << endl;
		cout << "s2Ϊ<NULL>������ӦΪ0��ʵ�ʣ�" << s2.length() << endl;

		s2.set(strcat(str1, str2));
		cout << "s2Ϊtongji������ӦΪ6��ʵ�ʣ�" << s2.length() << endl;

		cout << endl << "���������..." << endl;
		getchar();
	}

	return 0;
}