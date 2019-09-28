#include "pch.h"
#include "DataList.h"
#include <math.h>
#include <cstdlib>
#include <ctime>

DataList::DataList()
{
}

DataList::~DataList()
{
}

MeasureData DataList::InverseOperation(MeasureData Data)
{
	static unsigned int seed = 0;
	seed ++;
	srand((UINT)time(0) + seed * seed); 
	if (Data.Deciation == 0)
	{
		return Data;
	}
	Data.EleCharge = (Data.Deciation / 100.0) * StdValue + StdValue;
	if (Data.Electronic == 0)
	{
		Data.Electronic = rand() % (Data.max_Electronic - 1) + 2;
	}
	Data.Charge = Data.Electronic * Data.EleCharge;
	Data.Index = (int)log10(Data.Charge) - 1;
	Data.Index2 = (int)log10(Data.EleCharge) - 1;
	Data.Voltage = rand() % ((int)Data.max_Voltage - 1) + 2;
	Data.Time = Viscosity*Length /( pow((Data.Charge * sqrt(2 * Density * Gravity) * Data.Voltage / (18 * 3.14 * Distance)), 2.0/3.0));
	double r2 = MidOperation(Data);
	double Correct = 1.0 + 0.01 * Correction / (AtmosphericPressure * r2);
	Data.Time = Data.Time / Correct;
	
	for (int i = 0; i <= Data.Iteration; i++)
	{
		r2 = MidOperation(Data);
		Correct = 1.0 + 0.01 * Correction / (AtmosphericPressure * r2);
		Data.Time = Data.Time / Correct;
	}

	Data.Charge = Data.Charge * pow(10.0, (double)(-Data.Index));
	Data.EleCharge = Data.EleCharge * pow(10.0, (double)(-Data.Index2));

	Data.Index = Data.Index + (-15);
	Data.Index2 = Data.Index2 + (-15);
	return Data;
}

MeasureData DataList::ForwardOperation(MeasureData Data)
{
	if (Data.Time == 0 || Data.Voltage == 0 )
	{
		return Data;
	}
	//double Velocity = 0;
	//Velocity = Length / Data.Time;
	///double r1 = sqrt((9.0 * Viscosity * Velocity) / (2.0 * Density * Gravity)); //(x10^-4)
	double r2 = MidOperation(Data);//sqrt((9.0 * Viscosity * Velocity) / ((2.0 * Density * Gravity) * (1.0 + 0.01 * Correction / (AtmosphericPressure * r1))));  //(x10^-4)
	Data.Charge = (4.0 * 3.14 * Distance * pow(r2, 3) * Density * Gravity) / (3.0 * Data.Voltage); //(x10^-15)
	Data.Electronic = (int)round(Data.Charge / StdValue);
	Data.EleCharge = Data.Charge / Data.Electronic;
	Data.Deciation = 100.0 * (Data.EleCharge - StdValue) / StdValue;
	Data.Index2 = (int)log10(Data.EleCharge) - 1;
	Data.EleCharge = Data.EleCharge * pow(10.0, (double)(-Data.Index2));
	Data.Index = (int)log10(Data.Charge) - 1;
	Data.Charge = Data.Charge * pow(10.0, (double)(-Data.Index));


	Data.Index = Data.Index + (-15);
	Data.Index2 = Data.Index2 + (-15);
	
	return Data;
}

double DataList::MidOperation(MeasureData Data)
{
	double Velocity = Length / Data.Time;
	double r1 = sqrt((9.0 * Viscosity * Velocity) / (2.0 * Density * Gravity));
	double r2 = sqrt((9.0 * Viscosity * Velocity) / ((2.0 * Density * Gravity) * (1.0 + 0.01 * Correction / (AtmosphericPressure * r1))));
	return r2;
}
