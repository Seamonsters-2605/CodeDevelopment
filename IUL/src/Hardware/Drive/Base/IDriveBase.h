#ifndef LARUL_DRIVEBASE_H
#define LARUL_DRIVEBASE_H

#include "../../HWSystem.h"

class IDriveBase : public HWSystem
{
public:
	
	virtual ~IDriveBase () {};
	
	virtual void Update () = 0;
	
};

#endif
