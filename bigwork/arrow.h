#pragma once
#include<iostream>
#include<cstring>
#include<deque>
#include"Control.h"
extern Control* now;
using std::cout;
using std::cin;
using std::endl;
using std::deque;
class arrow {
public:
	int x, y = 600, code;//left 0 right 1
	int dy = 4;
	bool flag = 0;////////////////////////
	//x������ code����ͷ������0��1��3
	arrow() = default;//
	arrow(int x, int code);//
	arrow(int x, int y, int code);
	void drawArrow();
	//void drawStaicArrow();
};
class ArrowLine {
private:
	int level = 0;
	int count = 0;
	int staY = 50;//��ַ��ͷY
	int staCode;//��ͷ����
	deque<arrow*> darrow;
	int arrowY = 0;
	int lineX = 40;
public:
	ArrowLine(int x, int staCode_);
	//���� 0���� 1 miss 2 good 3 great
	int getInput(int code);//�û������y   //code ��0��1��3 �û�����ʲô��Ӧ��ͷ
	void drawStaticArrow();
	void lineClear();
	void add();//��0��1��3
	int drawLine();
};