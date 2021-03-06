#include "IntervalTimer.h"

#include <math.h>

IntervalTimer :: IntervalTimer ( TimeMode Mode ):
	Time ( 0 ),
	Offset ( 0 ),
	Running ( false ),
	Mode ( Mode ),
	SIUnit ( kScalarInputUnit_Seconds )
{
};

IntervalTimer :: ~IntervalTimer ()
{
};

void IntervalTimer :: Start ()
{
	
	if ( Running )
		return;
	
	switch ( Mode )
	{
		
	case kTimeMode_Monotonic:
	
		Offset = Clock :: GetTimeMonotonicMS ();
		
		break;
	
	case kTimeMode_System:
	
		Offset = Clock :: GetTimeSystemMS ();
		
		break;
		
	}
	
	Running = true;
	
};

void IntervalTimer :: Stop ()
{
	
	uint64_t Current;
	
	switch ( Mode )
	{
		
	case kTimeMode_Monotonic:
	
		Current = Clock :: GetTimeMonotonicMS ();
		
		break;
	
	case kTimeMode_System:
	
		Current = Clock :: GetTimeSystemMS ();
		
		break;
		
	}
	
	if ( ! Running )
		return;
	
	Offset = Current - Offset;
	Time += Offset;
	
	Running = false;
	
};

void IntervalTimer :: Reset ()
{
	
	Running = false;
	Time = 0;
	
};

void IntervalTimer :: Restart ()
{
	
	switch ( Mode )
	{
		
	case kTimeMode_Monotonic:
	
		Offset = Clock :: GetTimeMonotonicMS ();
		
		break;
	
	case kTimeMode_System:
	
		Offset = Clock :: GetTimeSystemMS ();
		
		break;
		
	}
	
	Time = 0.0;
	Running = true;
	
};

double IntervalTimer :: GetTimeMS ()
{
	
	uint64_t Current;
	
	switch ( Mode )
	{
		
	case kTimeMode_Monotonic:
	
		Current = Clock :: GetTimeMonotonicMS ();
		
		break;
	
	case kTimeMode_System:
	
		Current = Clock :: GetTimeSystemMS ();
		
		break;
		
	}
	
	Current = Current - Offset;
	Current += Time;
	
	return (double) Current;
	
};

double IntervalTimer :: GetTimeS ()
{
	
	uint64_t Current;
	
	switch ( Mode )
	{
		
	case kTimeMode_Monotonic:
	
		Current = Clock :: GetTimeMonotonicMS ();
		
		break;
	
	case kTimeMode_System:
	
		Current = Clock :: GetTimeSystemMS ();
		
		break;
		
	}
	
	Current = Current - Offset;
	Current += Time;
	
	return ( (double) Current ) / 1000.0;
	
};

void IntervalTimer :: SetTimeMode ( TimeMode Mode )
{
	
	bool Resume = Running;
	
	uint64_t Current;
	
	switch ( Mode )
	{
		
	case kTimeMode_Monotonic:
	
		Current = Clock :: GetTimeMonotonicMS ();
		
		break;
	
	case kTimeMode_System:
	
		Current = Clock :: GetTimeSystemMS ();
		
		break;
		
	}
	
	if ( ! Running )
		return;
	
	Offset = Current - Offset;
	Time += Offset;
	
	Running = false;
	
	this -> Mode = Mode;
	
	if ( Resume )
	{
		
		switch ( Mode )
		{
			
		case kTimeMode_Monotonic:
		
			Offset = Clock :: GetTimeMonotonicMS ();
			
			break;
		
		case kTimeMode_System:
		
			Offset = Clock :: GetTimeSystemMS ();
			
			break;
			
		}
		
		Running = true;
	
	}
	
};

void IntervalTimer :: SetScalarInputUnits ( ScalarInputUnit Unit )
{
	
	SIUnit = Unit;
	
};

double IntervalTimer :: GetScalar ()
{
	
	switch ( SIUnit )
	{
	
	case kScalarInputUnit_Seconds:
		
		return GetTimeS ();
		
	case kScalarInputUnit_Milliseconds:
		
		return GetTimeMS ();
	
	}
	
	return 0.0;
	
};

IScalarInput :: ScalarLimit IntervalTimer :: GetScalarLimitType ()
{
	
	return kScalarLimit_Low;
	
};

double IntervalTimer :: GetLimitParam ( ScalarLimitParam Param )
{
	
	if ( Param == kScalarLimitParam_LowLimit )
		return 0.0;
	
	return NAN;
	
};
