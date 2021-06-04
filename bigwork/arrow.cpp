#define _CRT_SECURE_NO_WARNINGS
#include"arrow.h"
extern Control* now;

arrow::arrow(int x, int code) {
	this->x = x;
	this->code = code;
}
arrow::arrow(int x, int y, int code) {
	this->x = x;
	this->y = y;
	this->code = code;
}
int ArrowLine::getInput(int code) {
	if (0 == darrow.size()) {
		return -10;//û��ʼ
	}
	for (auto itr = darrow.rbegin(); itr != darrow.rend() && false == ((*itr)->flag); itr++) {////ѭ����{!(itr->flag}û��"judge"�ļ�ͷ
		//�ҵ��˾ͷ����˳�
		//flagΪ�ٰ�
		int distance = abs((*itr)->y - staY);//
		if (distance <= 25 && false == (*itr)->flag) {//����0��25Ϊperfect
			(*itr)->flag = true;//judge��
			delete* itr;
			darrow.pop_back();
			level = 1;
			count++;
			return 100;
		}
		else if (distance > 25 && distance < 50 && (false == (*itr)->flag)) {//����25��50��great
			(*itr)->flag = true;
			delete* itr;
			darrow.pop_back();
			level = 2;
			count++;
			return 60;
		}
		else if ((false == (*itr)->flag)) {//����40����Ϊmiss
			(*itr)->flag = true;
			delete* itr;
			darrow.pop_back();
			level = 3;
			count++;
			return -60;
		}
		return 0;
	}
	return 0;//û��ʼ
}

ArrowLine::ArrowLine(int x, int staCode_) :lineX{ x }, staCode{ staCode_ }{//��ס
};

void ArrowLine::drawStaticArrow() {
	int y = this->staY;
	int code = this->staCode;

	char* fileName = new char[50];
	if (0 == code) {
		sprintf(fileName, "./Pic/AQuiver.png");//left
		now->putImage(fileName, lineX, y, 100, 100);
	}
	else if (1 == code) {
		sprintf(fileName, "./Pic/DQuiver.png");//��
		now->putImage(fileName, lineX, y, 100, 100);
	}
	else if (2 == code) {
		sprintf(fileName, "./Pic/SQuiver.png");//��
		now->putImage(fileName, lineX, y, 100, 100);
	}
	else {
		//tishi
	}
	delete[] fileName;
}
void arrow::drawArrow() {//��0��1
	if (0 == code) {
		char* fileName = new char[50];
		y = y - dy;
		sprintf(fileName, "./Pic/AKey.png");//��
		now->putImage(fileName, x, y, 100, 100);
		delete[] fileName;
	}
	else if (1 == code) {
		char* fileName = new char[50];
		y = y - dy;
		sprintf(fileName, "./Pic/DKey.png");//��
		now->putImage(fileName, x, y, 100, 100);
		delete[] fileName;
	}
	else if (2 == code) {
		char* fileName = new char[50];
		y = y - dy;
		sprintf(fileName, "./Pic/SKey.png");//��
		now->putImage(fileName, x, y, 100, 100);
		delete[] fileName;
	}
}
void ArrowLine::lineClear() {//��ϴ����
	darrow.clear();
}
//��0��1��3
void ArrowLine::add() {//��0��1��3
	darrow.push_front(new arrow(lineX, staCode));
}
int ArrowLine::drawLine() {
	//xyprintf(222, 222, "asasfdasdfasdfdfadsf");
	drawStaticArrow();
	for (auto every : darrow) {
		every->drawArrow();
	}
	if (1 == level) {//perfect
		now->putImage("./Pic/perfect.png", lineX, 120, 100, 100);
		count++;
	}
	else if (2 == level) {//great
		now->putImage("./Pic/great.png", lineX, 120, 100, 100);
		count++;
	}
	else if (3 == level) {//miss
		now->putImage("./Pic/miss.png", lineX, 120, 100, 100);
		count++;
	}
	if (40 == count) {
		count = 0;
		level = 0;
	}
	int sum = 0;
	while (darrow.size() && (darrow.back()->y) < -20) {
		level = 3;
		delete darrow.back();
		darrow.pop_back();
		sum -= 60;
	}
	return sum;
}