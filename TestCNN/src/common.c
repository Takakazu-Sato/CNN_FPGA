/*���ʂ̊֐�*/
#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<sys/resource.h>
#include"common.h"

/*drnd()�֐��@�����̐���*/
double drnd(void){
	double rndno; //������������

	while((rndno=(double)rand()/RAND_MAX)==1.0);
	rndno=rndno*2-1;//-1�`1�̊Ԃ̎Z���𐶐�
	return rndno;
}

/*f()�֐��@�`�B�֐�(�V�O���C�h�֐�)*/
double f(double u){
	return 1.0/(1.0+exp(-u));
}

double getusage(){
	struct rusage usage;
	struct timeval ut;

	getrusage(RUSAGE_SELF,&usage);
	ut=usage.ru_utime;

	return ((double)(ut.tv_sec)*1000+(double)(ut.tv_usec)*0.001);
}
