#ifndef ILU_DRIVETRAIN_H
#define ILU_DRIVETRAIN_H

#include "../HWSystem.h"

class IDriveTrain : public HWSystem
{
public:
	
	virtual ~IDriveTrain () {};
	
	virtual void Update () = 0;
	
};

#endif
