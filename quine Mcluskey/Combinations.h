#include<iostream>

using namespace std;

#ifndef COMBINATIONS_H
#define COMBINATIONS_H
class Combinations//used to define all the combinations of the variables
{
	char  *Combin;
	int NoOfVars;
public:
	Combinations()
	{
		NoOfVars = 0;
	}
	void SetCombin(int NOV, int a)//sets number of variables to NOV and sets the Minterm
	{
		NoOfVars = NOV;
		Combin = new char[NoOfVars];
		int i = 0;
		while (i <= a)
		{
			int j = 0;
			while (j < NoOfVars)
			{
				setWeightsPlace(j, a);
				j++;
			}
			i++;
		}
	}
	int getNoOfCombin(int a)//to get numberofpossible combinations
	{
		int NOC = 1;
		int i = 0;
		while (i < a)
		{
			NOC = 2 * NOC;
			i++;
		}
		return NOC;
	}
	void setWeightsPlace(int Weight, int CombinNo)//set a place of wieght "Weight" to the boolean value it is supposed to have
	{
		bool B = true;
		int WhentoSwitch = getNoOfCombin(Weight);
		int i = 0;
		while (i <= CombinNo)
		{
			if (i%WhentoSwitch == 0)
			{
				B = !B;
			}
			if (B == true)
			{
				Combin[Weight] = '1';
			}
			else
			{
				Combin[Weight] = '0';
			}
			i++;
		}
	}
	void display()
	{
		int i = NoOfVars-1;
		while (i >=0 )
		{
			cout << Combin[i];
			i--;
		}
	}
	char getPlaceValue(int a)
	{
		return Combin[a];
	}
	void setNOV(int NOV)
	{
		NoOfVars = NOV;
		Combin = new char[NOV];
	}
	void setPlaceValue(int i,char c)
	{
		Combin[i] = c;
	}
	char* getBool()
	{
		return Combin;
	}
};
#endif