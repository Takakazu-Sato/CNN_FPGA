#include<stdio.h>
#include<stdint.h>

#include<string.h>
#include<stdlib.h>
#include<math.h>
#include"perceptron.h"
#include"common.h"

/*Forward()�֐��������̌v�Z*/
double Forward(
	double *input_data, //���͑w�̃f�[�^
	int input_num,	//���͑w�̌�
	double *weight_hidden, //���ԑw�̏d��
	double *weight_out, //�o�͑w�̏d��
	double *hidden_out, //���ԑw�̏o��
	int hidden_num //���ԑw�̐�
)
{
	int i=0;
	int j=0;
	double sum; //�c�ݕt�������̒l
	double out; //�o�͒l

	//���ԑw�̌v�Z
	for(i=0;i<hidden_num;++i){
		sum=0.0;//�����̏�����
		for(j=0;j<input_num;++j){
			sum+=input_data[j]*weight_hidden[i*(input_num+1)]+j];
		}
		sum-=weight_hidden[i*(input_num+1)+j];//臒l�̏���
		hidden_out[i]=f(sum);
	}
	//�o�͑w�̌v�Z
	out=0.0;
	for(i=0;i<hidden_num;++i){
		out+=hidden_out[i]*weight_out[i];
	}
	out-=weight_out[i];//臒l�̏���

	return f(out);
}
/*HiddenLearn()�֐��@���ԑw�̏d�݊w�K*/
void HiddenLearn(
	double *weight_hidden, //���ԑw�̏d��
	double *hidden_out, //�o�͑w�̏o��
	int hidden_num //���ԑw�̐�
	double *input_data, //���͑w�̃f�[�^
	int input_num,	//���͑w�̌�
	double teachear, //���t�f�[�^
	double out //�o�͑��̏o��
)
{
	int i=0;
	int j=0;
	double dj;//���ԑw�̏d�݌v�Z�ɗ��p

	for(j=0;j<hidden_num;++j){//���ԑw�̊e�Z��j��Ώ�
		dj=hidden_out[j]*(1-hidden_out[j])*weight_out[j]*(teachear-out)*out*(1-out);
		for(i=0;i<input_num;++i){//i�Ԗڂ̏d�݂�����
			weight_hidden[(j*(input_num+1))+i]+=ALPHA*input_data[i]*dj;
		}
		weight_hidden[(j*(input_num+1))+i]+=ALPHA*(-1.0)*dj;/臒l�̊w�K
	}
}
/*OutLearn()�֐��@�o�͑w�̏d�݊w�K*/
void OutLearn(
	double *weight_out, //�o�͑w�̏d��
	double *hidden_out, //�o�͑w�̏o��
	int hidden_num //���ԑw�̐�
	double *input_data, //���͑w�̃f�[�^
	double teachear, //���t�f�[�^
	double out //�o�͑��̏o��
)
{
	int i=0;
	double d;//�d�݌v�Z�ɗ��p

	d=(teacher-out)*out*(1-out);//�덷�̌v�Z
	for(i=0;i<hidden_num;++i){
		weight_out[i]+=ALPHA*hidden_out[i]*d;//�d�݊w�K
	}
	weight_out[i]+=ALPHA*(-1.0)*d;//臒l�̊w�K
}
/*InitWeight_hidden()�֐�  ���ԑw�̏d�݂̏�����*/
void InitWeight_Hidden(
	double *weight_hidden,�@//���ԑw�̏d��
	int hidden_num //���ԑw�̐�)
	int input_num	//���͑w�̌�
)
{
	int i=0;
	int J=0;

	//�����ɂ��d�݂̌���
	for(i=0;i<hidden_num;++i){
		for(j=0;j<input_num+1;++j){
			weight_hidden[(i*(input_num+1))+j]=drnd();
		}
	}
}

/*Initweight_out()�֐�  �o�͑w�̏d�݂̏�����*/
void InitWeight_Out(
	double *weight_out,//�o�͑w�̏d��
	int hidden_num //���ԑw�̐�
)
{
	int i=0;
	//�����ɂ��d�݂̌���
	for(i=0;i<hidden_num+1;++i){
		weight_out[i]=drnd();
	}
}
