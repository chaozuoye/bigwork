#include "Star.h"
#include "Control.h"
#include <cmath>
#include <cstdio>
extern Control* now;

bool judge = false;

Star::Star() {
	randStar();
}
void Star::randStar() {//���������������
	this->x = ((now->rand()) % (960 - starP - 50)) + 25;
	this->y = ((now->rand()) % (640 - starP - 50)) + 25;
	this->time = ((now->rand()) % 170) + 30;//���time��ֵ����30~200֮��
}

int Star::levelJudge(int a, int b) {//�жϵ���ȼ�
	if (judge) {
		int distance = (int)sqrt((a - (this->x + starP / 2)) * (a - (this->x + starP / 2)) + (b - (this->y + starP / 2)) * (b - (this->y + starP / 2)));
		//	printf("p:%d %d star:%d %d d:%d\n",a,b,this->x + starP / 2,this->y + starP / 2,distance);
		if (distance <= (int)(starP / 3)) {
			level = 1;//perfect�ȼ�
			count = 0;//���ü���
			judge = false;//�رյȼ��ж�
			return 100;
		}
		else if (distance > (int)(starP / 3) && distance < starP / 2) {
			level = 2;//great�ȼ�
			count = 0;
			judge = false;
			return 50;
		}
		else {
			level = 3;//miss�ȼ�
			count = 0;
			judge = false;
			return -20;
		}
	}
	return 0;
}

int Star::drawStar() {//��������
	if (count < time) {//��������ʾ����
		count++;
	}
	if (count >= time && count < time + 150) {//������100����ʾ����
		now->putImage("./Pic/Star.png", this->x, this->y, starP, starP);
		count++;
		judge = true;
	}
	if (count == time + 150) {//һֱû�����������1000��ֱ��miss
		now->putImage("./Pic/miss.png", this->x, this->y, starP, starP);
		count = 0;
		judge = false;
		level = 3;
	}
	if (level != 0)countLevel++;
	if (1 == level) {//perfect
		now->putImage("./Pic/perfect.png", this->x, this->y, starP, starP);

	}
	else if (2 == level) {//great
		now->putImage("./Pic/great.png", this->x, this->y, starP, starP);

	}
	else if (3 == level) {//miss
		now->putImage("./Pic/miss.png", this->x, this->y, starP, starP);

	}
	if (countLevel == 60) {//���õȼ���ʾ����

		return 1;
	}
	return 0;

}

int Star::getScore()
{
	switch (level) {
	case 1:return 123;
	case 2:return 66;
	case 3:return -99;
	default:return 0;
	}
}
