#ifndef ILU_CANTALONCONFIGURATION_H
#define ILU_CANTALONCONFIGURATION_H

#include "../../Tuning.h"

#ifndef NO_WPILIB
#include <WPILib.h>

class CANTalonConfiguration
{
public:
	
	typedef enum
	{
		
		kFeedbackType_AnalogEncoder,
		kFeedbackType_Potentiometer,
		kFeedbackType_EncoderRising,
		kFeedbackType_EncoderFalling,
		kFeedbackType_QuadratureEncoder,
		kFeedbackType_None
			
	} FeedbackType;
	
	CANTalonConfiguration ( CANSpeedController ::ControlMode Mode, FeedbackType Feedback = kFeedbackType_None );
	~CANTalonConfiguration ();

	void SetRampRates ( double Motor = 0.0, double ClosedLoop = 0.0 );
	
	void SetControlSlot ( int Slot = -1 );
	
	void SetPIDF ( double P = 0.0, double I = 0.0, double D = 0.0, double F = 0.0 );
	void SetIZone ( double IZone = 0.0 );
	
	void SetNeutralMode ( CANTalon :: NeutralMode Neutral );
	
	void Configure ( CANTalon * ToConfig );
	
private:
	
	CANSpeedController ::ControlMode Mode;
	FeedbackType Feedback;
	
	int ControlSlot;
	
	double P;
	double I;
	double D;
	double F;
	double IZone;
	
	double ClosedLoopRamp;
	double MotorRamp;
	
	CANTalon :: NeutralMode Neutral;
	
};

#endif
#endif
