#ifndef __CNN_HEADER__
#define __CNN_HEADER__

int Convolution
(
		double *filter,
		int filter_size,
		double *input_data,
		int input_width,
		int input_height,
		int input_depth,
		double *conv_out
);

void Pooling(
		double *conv_out,
		int conv_width,
		int conv_height,
		double *pool_out,
		int pool_size
		);

void InitFilter(
		double *filter,
		int filter_size,
		int input_depth
);

#endif
