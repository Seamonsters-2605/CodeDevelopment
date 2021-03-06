#ifndef LARUL_VEC3_H
#define LARUL_VEC3_H

class Quaternion;

class Vector3
{
public:
	
	explicit Vector3 ( double X = 0.0, double Y = 0.0, double Z = 0.0 );
	~Vector3 ();
	
	static double DotProduct ( Vector3 & A, Vector3 & B );
	static void CrossProduct ( Vector3 & A, Vector3 & B, Vector3 & Result );
	static void CrossProduct ( Vector3 & A, Vector3 & B );
	
	static void Multiply ( Vector3 & A, double B );
	static void Multiply ( Vector3 & A, double B, Vector3 & Result );
	
	static void Add ( Vector3 & A, Vector3 & B, Vector3 & Result );
	static void Add ( Vector3 & A, Vector3 & B );
	static void Subtract ( Vector3 & A, Vector3 & B, Vector3 & Result );
	static void Subtract ( Vector3 & A, Vector3 & B );
	
	static void Normalize ( Vector3 & A );
	static void Normalize ( Vector3 & A, Vector3 & Result );
	
	static double Length ( Vector3 & A );
	static double LengthSquared ( Vector3 & A );
	
	static double AngleBetween ( Vector3 & A, Vector3 & B );
	
	static void Interpolate ( Vector3 & A, Vector3 & B, double Fraction );
	static void Interpolate ( Vector3 & A, Vector3 & B, double Fraction, Vector3 & Result );
	
	static void Rotate ( Vector3 & A, Quaternion & Rotation );
	static void Rotate ( Vector3 & A, Quaternion & Rotation, Vector3 & Result );
	
	double X;
	double Y;
	double Z;
	
	const static Vector3 UP;		// + Z
	const static Vector3 DOWN;		// - Z
	const static Vector3 RIGHT;		// + Y
	const static Vector3 LEFT;		// - Y
	const static Vector3 FORWARD;	// + X
	const static Vector3 BACKWARD;	// - X
	
	const static Vector3 IDENTITY;
	const static Vector3 ZERO;
	
};

#endif
