#pragma once

class Star {
private:
	int x{ 0 }, y{ 0 };//�����������ĵ�����
	int starP{ 100 };//����ͼƬ�ı߳�
	int count{ 0 };//������ʾ����
	int level{ 0 };//�ȼ��ֱ�
	int countLevel{ 0 };//�жϵȼ���ʾ����
	int time{ 0 };//��������ʱ����
public:
	void randStar();//����������ǣ����ꡢ����ʱ����
	int levelJudge(int a, int b);//�жϵ���ȼ�,���ط���
	int drawStar();//��������
	int getScore();
	Star();
};