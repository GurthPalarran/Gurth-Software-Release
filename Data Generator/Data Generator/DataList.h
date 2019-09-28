#pragma once

#ifndef _MESUREDATA_
#define _MEAUREDATA_
struct MeasureData
{
	double Time = 0;
	double Voltage = 0;
	double Deciation = 0;
	double Charge = 0;
	double EleCharge = 0;
    int Electronic = 0;
	int Index = 0;
	int Index2 = 0;
	int Iteration = 10;
	double max_Voltage = 30.0;
	int max_Electronic = 12;
};
typedef struct MeasureData MeasureData;
#endif // !_MESUREDATA_


class DataList
{
public:
	DataList();
	~DataList();
	MeasureData InverseOperation(MeasureData Data);
	MeasureData ForwardOperation(MeasureData Data);
	double MidOperation(MeasureData Data);

public:
	const double StdValue = 0.0001602;

	int Density = 981;
	double Gravity = 9.79;
	double Viscosity = 1.83;  // (x10^-5)
	double Length = 1.00;
	double Correction = 6.17; // (x10^-6)
	double AtmosphericPressure = 76.0;
	double Distance = 5.00;  //(x10^-3)

private:

};


