#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char      	  u8, uint8_t;
typedef unsigned short int 	  u16;            /*short keyword for any compiler to know that a variable's size is 2 bytes */
typedef unsigned long int  	  u32;			  /*short keyword for any compiler to know that a variable's size is 4 bytes */
typedef unsigned long long 	  u64, uint64_t;

typedef signed char 		  s8, sint8_t;
typedef signed short int 	  s16, sint16_t;
typedef signed long int		  s32, sint32_t;
typedef signed long long 	  s64, sint64_t;

typedef  float        f32, float32_t;
typedef  double    	  f64, float64_t;
typedef  long double  f128, float128_t;       /* 128 bits on my machine*/

typedef u8*			pu8;
typedef void(*pfunc_t)(void);


typedef enum
 {
	 OK,
	 NOK,
	 INVALID_ARGUMENT,
	 NULL_PTR,
	 PENDING,
	 TIME_OUT
	 
}STD_Error_t;

#define 	NULL 	((void*)0)



#endif







