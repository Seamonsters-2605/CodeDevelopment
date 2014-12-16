#ifndef LARUL_ISCALARINPUT_H
#define LARUL_ISCALARINPUT_H

#include "../CPP/Virtual.h"

class IScalarInput
{
public:
	
	typedef enum
	{
		
		kScalarLimit_None,
		kScalarLimit_Incremental,
		kScalarLimit_High,
		kScalarLimit_Low,
		kScalarLimit_Range,
		kScalarLimit_LowIncremental,
		kScalarLimit_HighIncremental,
		kScalarLimit_RangeIncremental
		
	} ScalarLimit;
	
	typedef enum
	{
		
		kScalarLimitParam_LowLimit,
		kScalarLimitParam_HighLimit,
		kScalarLimitParam_Increment
		
	} ScalarLimitParam;
	
	VIRTUAL_CLASS ( IScalarInput );
	
	virtual double GetScalar () = 0;
	
	virtual ScalarLimit GetScalarLimitType () = 0;
	virtual double GetLimitParam ( ScalarLimitParam Param );
	
};

#endif