#ifndef __PERCEPTRON_HEADER__
#define __PERCEPTRON_HEADER__

//�W���Ȃ�
#ifdef SEED 65535 /*�����̃V�[�h*/
#define LIMIT 0.001 /*�덷�̏���l*/
#define BIGNUM 100 /*�덷�̏����l*/
#define HIDDENNO 3 /*���ԑw�̃Z����*/
#define ALPHA 0.3 /*�w�K�W��*/

double Forward(
	double *input_data, //���͑w�̃f�[�^
	int input_num,	//���͑w�̌�
	double *weight_hidden, //���ԑw�̏d��
	double *weight_out, //�o�͑w�̏d��
	double *hidden_out, //���ԑw�̏o��
	int hidden_num //���ԑw�̐�
);

void HiddenLearn(
	double *weight_hidden, //���ԑw�̏d��
	double *weight_out, //�o�͑w�̏d��
	double *hidden_out, //�o�͑w�̏o��
	int hidden_num //���ԑw�̐�
	double *input_data, //���͑w�̃f�[�^
	int input_num,	//���͑w�̌�
	double teachear, //���t�f�[�^
	double out //�o�͑��̏o��
);

void OutLearn(
    double *weight_out, //���ԑw�̏d��
	double *hidden_out, //�o�͑w�̏o��
	int hidden_num //���ԑw�̐�
	double teachear, //���t�f�[�^
	double out //�o�͑��̏o��
);

void InitWeight_Hidden(
	double *weight_hidden, //���ԑw�̏d��
	int hidden_num //���ԑw�̐�)
	int input_num	//���͑w�̌�
);

void InitWeight_Out(
	double *weight_out,//�o�͑w�̏d��
	int hidden_num //���ԑw�̐�
);



