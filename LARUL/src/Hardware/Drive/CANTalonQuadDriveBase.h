#ifndef LARUL_CANTALONMECANUMDRIVEBASE_H
#define LARUL_CANTALONMECANUMDRIVEBASE_H

#include "../../LARULTuning.h"

#ifndef NO_WPILIB
#include <WPILib.h>

#include "../Motors/CANTalonConfiguration.h"

#include "IQuadRectangularCANTalonDriveBase.h"

#include "../Power/PowerUsageSpec.h"
#include "../Power/PowerProfile.h"

class CANTalonQuadDriveBase : public IQuadRectangularCANTalonDriveBase
{
public:
	
	CANTalonQuadDriveBase ( uint8_t CAN_ID_FL, uint8_t PDPChannelFL, uint8_t CAN_ID_FR, uint8_t PDPChannelFR, uint8_t CAN_ID_RL, uint8_t PDPChannelRL, uint8_t CAN_ID_RR, uint8_t PDPChannelRR, CANTalonConfiguration Config, double MotorDrawAverage, double MotorDrawMax );
	~CANTalonQuadDriveBase ();
	
	void SetInversion ( bool Fl, bool FR, bool RL, bool RR );
	void SetSensorInversion ( bool Fl, bool FR, bool RL, bool RR );
	
	void SetWheelConfig ( CANTalonConfiguration Config );
	
	void Update ();
	
	// HWSystem interface
	void Enable ();
	void Disable ();
	
	bool GetEnabled ();
	
	// IPowerScalable interface
	PowerProfile * GetProfile ();
	PowerUsageSpec * GetSpec ();
		
	void SetPowerScale ( double Scale );
	
	// IQuadRectangularDriveBase interace
	void SetMotor ( MotorPosition Motor, double Value );
	
	// IQuadRectangularCANTalonDriveBase interface
	CANTalon * GetCANTalon ( MotorPosition Motor );

private:
	
	typedef struct
	{
		
		bool SensorInverted;
		bool MotorInverted;
		
		double SetPoint;
		
	} MotorInfo;
	
	CANTalon WheelFL;
	CANTalon WheelFR;
	CANTalon WheelRL;
	CANTalon WheelRR;
	
	MotorInfo MInfoFL;
	MotorInfo MInfoFR;
	MotorInfo MInfoRL;
	MotorInfo MInfoRR;
	
	CANTalonConfiguration UnInvertedConfig;
	CANTalonConfiguration InvertedConfig;
	
	bool Enabled;
	
	PowerProfile MotorProfile;
	PowerUsageSpec MotorSpec;
	
	double PowerScale;
	
};

#endif
#endif
