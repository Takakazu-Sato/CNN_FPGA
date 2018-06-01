#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include "cnn.h"
#include "common.h"

/*CalcConvolution()�֐��t�B���^�̓K�p*/
double CalcConvolution(
	double *filter,	//�t�B���^
	int filter_size,	//�t�B���^�̃T�C�Y
	double *input_data,	//���̓f�[�^
	int input_width,	//���̓f�[�^�̕�
	int input_height	//���̓f�[�^�̍���
	int input_depth,	//���̓f�[�^�̐[��
	int x, int y	//�t�B���^�̌v�Z�ʒu
)
{
	int m=0;	//�J��Ԃ�����p
	int n=0;	//�J��Ԃ�����p
	int d=0;
	double sum=0;	//�����̒l
	int offset;
	int y_start=y-(filter_size/2); //�t�B���^�v�Z�̃X�^�[�g�ʒu
	int x_start=x-(filter_size/2); //�t�B���^�v�Z�̃X�^�[�g�ʒu

	for(d=0;d<input_depth;++d){
	 offset=(input_width*input_height*d);	//���̓f�[�^�̃I�t�Z�b�g
	 for(n=0;n<filter_size;++n){
          for(m=0;m<filter_size;++m){
	   sum += input_data[offset + ((y_start+n)*input_width]+(x_start+m)]*filter[(n*filter_size)+m];
	  }
	 }
	}
#if 1
//�ŏ��l�C�ő�l�̌v�Z
if(sum<0.0){
  sum=0.0;
}
if(sum>1.0){
  sum=1.0;
}
#endif

return sum;
}

/*Convolution()�֐���ݍ��݂̌v�Z*/
int Convolution
(
 double *filter,//�t�B���^
 int filter_size,//�t�B���^�̃T�C�Y
 double *input_data,//���̓f�[�^
 int input_width,//���̓f�[�^�̕�
 int input_height,//���̓f�[�^�̍���
 int input_depth,//���̓f�[�^�̐[��
 double *conv_out //��ݍ��݌���
)
{
 int x=0;//�J��Ԃ�����p
 int y=0;//�J��Ԃ�����p
 int start_point=filter_size/2;//��ݍ��ݔ͈͂̉����l
 int conv_width=input_width-2*(filter_size/2);//��ݍ��݌�̕�
 int conv_height=input_height-2*(filter_size/2);//��ݍ��݌�̍���

 for(y=0;y<conv_height;++y){
  for(x=0;x<conv_width;++x){
   conv_out[y*conv_width+x]=CalcConvolution(
	filter,
	filter_size,
	input_data,
	input_width,
	input_height,
	input_depth,
	(x+start_point),
	(y+start_point)
   );
  }
 }

 return 0;
}

/*MaxPooling()�֐��ő�l�v�[�����O*/
double MaxPooling(
		double *conv_out,//��ݍ��݃f�[�^�̏o��
		int pool_width,//�v�[�����O��̕�
		int pool_size,//�v�[�����O�̃T�C�Y
		int x,int y//�v�Z�ʒu
)
�o
	int m=0;
	int n=0;
	double max=-100.0;//�ő�l
	double calc=0;//�v�Z�l

	for (n=0;n<pool_size;++n){
		for(m=0;m<pool_size;++m){
			calc=conv_out[(y*pool_width*pool_size*pool_size)+
				(n*pool_width*pool_size)+(x*pool_size)+m];
			if(max<calc)max=calc;
		}
	}

#if 0
	if(max<0.0){
		max=0.0;
	}
	if(max>1.0){
		max=1.0;
	}
#endif
	return max;
	}

	/*Pooling()�֐��v�[�����O�̌v�Z*/

void Pooling(
		double *conv_out,//��ݍ��݃f�[�^�̓���
		int conv_width,//��ݍ��݃f�[�^�̕�
		int conv_height,//��ݍ��݃f�[�^�̍���
		double *pool_out,//�v�[�����O�o��
		int pool_size//�v�[�����O�T�C�Y
)
�o
int x=0;
int y=0;
int pool_width=conv_width/pool_size;//�v�[�����O��̕�
int pool_height=conv_height/pool_size;//�v�[�����O��̍���

for(y=0;y<pool_height;++y){
	for(x=0;x<pool_width;++x){
		pool_out[(y*pool_width)+x]=MaxPooling(conv_out,pool_width,pool_size,x,y);
	}
}
}

/*InitFilter()�֐��t�B���^������������*/
#if 0
/*�����t�B���^*/
void InitFilter(
		double *filter,//�t�B���^
		int filter_size,//�t�B���^�T�C�Y
		int filter_num//�t�B���^�̐�
)
{
	int x,y,d;
	int offset;
	for(d=0;d<filter_num;+;d){
		offset=d*filter_size*filter_size;
		for(y=0;y<filter_size;++y){
			for(x=0;x<filter_size;+;x){
				filter[offset+(y*filter_size)+x]=drnd();
			}
		}
	}
}
#else
/*�K�{�[���t�B���^*/
#define GAMMA(0.7)
#define SIGMA(0.3)
#define PI(3.141592654/180.0)

void InitFilter(
		double *filter,//�t�B���^
		int filter_size,//�t�B���^�T�C�Y
		int filter_num//�t�B���^�̐�
)
}
	int x,y,d;

	double nx,ny,xx,yy,w;
	double phai=0;
	double theta;
	double total;
	dobule calc;

	int offset;
	for(d=0;d<filter_num;++d){
		offset=d*filter_size*filter_size;
		total=0;
		theta=360.0*(((double)d/(double)filter_num)*PI);
		for(y=0;y<filter_size;++y){
			for(x=0;x<filter_size;++x){
				nx=x*2/(double)filter_size-1;
				ny=y*2/(double)filter_size-1;
				xx=nx*cos(theta)+ny*sin(theta);
				yy=-nx*sin(theta)+ny*cos(theta);
				w=exp(-(xx*xx+GAMMA*GAMMA*yy*yy)/(2*SIGMA*SIGMA));
				calc=w*cos(xx*PI*2.5+phai);
				filter[offset+(y*filter_size)+x]=calc;
				total+=calc;
			}
		}
		total/=filter_size*filter_size;
		for(y=0;y<filter_size;++y){
			for(x=0;filter_size;++x){
				filter[offset+(y*filter_size)+x]-=total;
			}
		}
	}
	}
#endif

		}
		}
	}
