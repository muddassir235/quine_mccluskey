#include<iostream>
#include"Combinations.h"

using namespace std;
#ifndef FUNCTION_H
#define FUNCTION_H
class Function
{
	Combinations *Minterms;
	bool *flags;
	int NoOfMinterms;
	int NoOfVariables;
public:
	Function()//sets the number of Variables and Minterms Selected
	{
		cout << "Enter the NumberofVariables:";
		cin >> NoOfVariables;
		Minterms = new Combinations[getNoOfCombin(NoOfVariables)];//a new array of combinations is formed in which all possible combinations can be accomodated
		flags = new bool[getNoOfCombin(NoOfVariables)];//an array of flags for all the possible minterms/comnbinations
		int i = 0;
		bool end=false;
		while (end == false&&i<getNoOfCombin(NoOfVariables))
		{
			if (i == 0)
			{
				cout << "Select A Minterm:";
			}
			else
			{
				cout << "Select Another Minterm:";
			}
			int a;
			cin >> a;
			Minterms[a].SetCombin(NoOfVariables, a);//The Combination is set A represents the minterm
			flags[a] = true;//The flag of the minterm which is present is set to true
			cout << "To End enter \"1\":";
			cin >> end;
			i++;
		}
		NoOfMinterms = i;//Number of minterms is saves for Further use
	}
	int getNoOfCombin(int a)//to get numberofpossible combinations for gien variables
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
	void display()//displays all the minterms of the Function(e.g. 0000,0001,0101,1101,1111,e.t.c)
	{
		int i = 0;
		while (i < getNoOfCombin(NoOfVariables))
		{
			if (flags[i] == true)
			{
				Minterms[i].display();
				cout << endl;
			}
			i++;
		}
	}
	void displayfunction()//displays the minimized function
	{
		/*
		int No1 = 0;//desired number of ones
		int *arraycontainingnumberofmintermintofspecificNumberofOnes = new int[NoOfVariables+1];//this array stores the value of the minterms which contain specific Number of 1's
		int **a=new int*[NoOfVariables+1];//a 2d array which stores the minterms of specific Number of 1's (e.g. 0 1's: 0, 1 1's:1 2 4, 2 1's: 3 5 6    e.t.c.)
		while (No1 <= NoOfVariables)//So that all the possible number of 1's are caterd for
		{
		int NumberOfMinterms = 0;//Numbrer of Minterms that have the desired Number of 1's
		int j = 0;//integer used to iterate over all the minterms
		while (j < getNoOfCombin(NoOfVariables))
		{
		int NoOfOnes = 0;//Checks the Number of One's in the Minterm under Obervation
		if (flags[j] == true)
		{
		int k = 0;
		while (k < NoOfVariables)
		{
		if (Minterms[j].getPlaceValue(k) == '1')
		{
		NoOfOnes++;
		}
		k++;
		}
		}
		if (NoOfOnes == No1&&flags[j]==true)//if the Minterm has the desired Number of 1's Then the Number minterms having the desired number of 1's is incremented
		{
		NumberOfMinterms++;
		}
		j++;
		}
		a[No1] = new int[NumberOfMinterms];//the array of Minterms having "No1" number of 1's is initialized to a size that can fit the number of minterms found
		arraycontainingnumberofmintermintofspecificNumberofOnes[No1] = NumberOfMinterms;//There are "NumberofMinterms" Minterms that have "No1" Number of 1's
		int b = 0;
		while (b < NumberOfMinterms)
		{
		int j = 0;
		while (j < getNoOfCombin(NoOfVariables))
		{
		int NoOfOnes = 0;
		if (flags[j] == true)
		{
		int k = 0;
		while (k < NoOfVariables)
		{
		if (Minterms[j].getPlaceValue(k) == '1')
		{
		NoOfOnes++;
		}
		k++;
		}
		}
		if (NoOfOnes == No1)
		{
		a[No1][b] = j;
		b++;
		if (b >= NumberOfMinterms)
		{
		break;
		}
		}
		j++;
		}
		}
		No1++;
		}
		int l = 0;
		while (l <= NoOfVariables)
		{
		int m = 0;
		while (m < arraycontainingnumberofmintermintofspecificNumberofOnes[l])
		{
		cout << " " <<a[l][m];
		m++;
		}
		cout << endl;
		cout << endl;
		l++;
		}
		l = 0;
		Combinations *ChangedMinterms;
		bool *mintermschecked = new bool[getNoOfCombin(NoOfVariables)];
		for (int k = 0; k < getNoOfCombin(NoOfVariables); k++)
		{
		mintermschecked[k] = false;
		}
		int sizeofChangedMinterms = 0;
		while (l < NoOfVariables)
		{
		int m = l+1;
		while (m <= NoOfVariables)
		{
		int n = 0;
		while (n < arraycontainingnumberofmintermintofspecificNumberofOnes[l])
		{
		int p = 0;
		while (p < arraycontainingnumberofmintermintofspecificNumberofOnes[m])
		{
		int Minterm1 = a[l][n];
		int Minterm2 = a[m][p];
		int Changeinbits = 0;
		int q = 0;
		while (q < NoOfVariables)
		{
		if (Minterms[Minterm1].getPlaceValue(q) != Minterms[Minterm2].getPlaceValue(q))
		{
		Changeinbits++;
		}
		q++;
		}
		if (Changeinbits == 1)
		{
		mintermschecked[Minterm1] = true;
		mintermschecked[Minterm2] = true;
		if (sizeofChangedMinterms == 0)
		{
		sizeofChangedMinterms++;
		ChangedMinterms = new Combinations[sizeofChangedMinterms];
		}
		else
		{
		Combinations *temp = new Combinations[sizeofChangedMinterms];
		int r = 0;
		while (r < sizeofChangedMinterms)
		{
		temp[r] = ChangedMinterms[r];
		r++;
		}
		int prevSOCM = sizeofChangedMinterms;
		sizeofChangedMinterms++;
		ChangedMinterms = new Combinations[sizeofChangedMinterms];
		r = 0;
		while (r<prevSOCM)
		{
		ChangedMinterms[r] = temp[r];
		r++;
		}
		}
		ChangedMinterms[sizeofChangedMinterms - 1].setNOV(NoOfVariables);
		q = 0;
		while (q < NoOfVariables)
		{
		if (Minterms[Minterm1].getPlaceValue(q) != Minterms[Minterm2].getPlaceValue(q))
		{
		ChangedMinterms[sizeofChangedMinterms - 1].setPlaceValue(q,'_');
		}
		else
		{
		ChangedMinterms[sizeofChangedMinterms - 1].setPlaceValue(q, Minterms[Minterm1].getPlaceValue(q));
		}
		q++;
		}

		}
		p++;
		}
		n++;
		}
		m++;
		}
		l++;
		}
		int s = 0;
		while (s < sizeofChangedMinterms)
		{
		ChangedMinterms[s].display();
		cout << endl;
		s++;
		}
		int t = 0;
		while (t < getNoOfCombin(NoOfVariables))
		{
		if (flags[t] == true && mintermschecked[t] == false)
		{
		Minterms[t].display();
		cout << endl;
		}
		t++;

		}
		*/






		int **a;
		int sizeofa=0;
		int *ArrayofSizes;
    	Combinations *Arr = new Combinations[getNoOfCombin(NoOfVariables)];//array for Storing Combination of Colomns
		int sizeofArr = getNoOfCombin(NoOfVariables);
		Arr = Minterms;
		bool *flagArr = new bool[sizeofArr];//The Array that gives the flags where the Minterms are present
		flagArr = flags;
		int desiredCorrelations;//THe Number of one bit changes found in the ARR
		do{

			Combinations *ChangedMinterms;//Will Store the Next Cololmn
			int sizeofChangedMinterms = 0;

			bool *mintermschecked = new bool[sizeofArr];//Used to Store the index of the Minterms that haven't been ticked
			for (int k = 0; k < sizeofArr; k++)
			{
				mintermschecked[k] = false;
			}

			desiredCorrelations = 0;
			int i = 0;
			while (i < (sizeofArr - 1))
			{
				int j = i + 1;
				while (j < sizeofArr)
				{
					if (flagArr[i] == true && flagArr[j] == true)
					{
						int Changeinbits = 0;
						int k = 0;
						while (k < NoOfVariables)
						{
							if (Arr[i].getPlaceValue(k) != Arr[j].getPlaceValue(k)) 
							{
								Changeinbits++;
							}
							k++;
						}
						if (Changeinbits == 1)
						{
							desiredCorrelations++;
							mintermschecked[i] = true;
							mintermschecked[j] = true;
							if (sizeofChangedMinterms == 0)
							{
								sizeofChangedMinterms++;
								ChangedMinterms = new Combinations[sizeofChangedMinterms];
							}
							else
							{
								Combinations *temp = new Combinations[sizeofChangedMinterms];
								int r = 0;
								while (r < sizeofChangedMinterms)
								{
									temp[r] = ChangedMinterms[r];
									r++;
								}
								int prevSOCM = sizeofChangedMinterms;
								sizeofChangedMinterms++;
								ChangedMinterms = new Combinations[sizeofChangedMinterms];
								r = 0;
								while (r < prevSOCM)
								{
									ChangedMinterms[r] = temp[r];
									r++;
								}
								delete[] temp;
							}
							ChangedMinterms[sizeofChangedMinterms - 1].setNOV(NoOfVariables);
							k = 0;
							while (k < NoOfVariables)
							{
								if (Arr[i].getPlaceValue(k) != Arr[j].getPlaceValue(k))
								{
									ChangedMinterms[sizeofChangedMinterms - 1].setPlaceValue(k, '_');
								}
								else
								{
									ChangedMinterms[sizeofChangedMinterms - 1].setPlaceValue(k, Arr[i].getPlaceValue(k));
								}
								k++;
							}
						}

					}
					j++;

				}
				i++;
			}

			int s = 0;
			while (s < sizeofChangedMinterms)
			{
				ChangedMinterms[s].display();
				cout << endl;
				s++;
			}
			cout << endl;
			int NoOfmintermsUnchecked = 0;
			for (int j = 0; j<sizeofArr; j++)
			{
				if (flagArr[j] == true && mintermschecked[j] == false)
				{
					NoOfmintermsUnchecked++;
				}
			}
			int NumberofPIs = sizeofa;
			if (sizeofa == 0&&NoOfmintermsUnchecked>0)
			{
				sizeofa = NoOfmintermsUnchecked;
				a = new int*[sizeofa];
				ArrayofSizes = new int[sizeofa];
			}
			else if (NoOfmintermsUnchecked > 0)
			{
				int prevSize = sizeofa;
				sizeofa = sizeofa + NoOfmintermsUnchecked;
				int *temp1;
				temp1 = ArrayofSizes;
				ArrayofSizes = new int[sizeofa];
				for (int y = 0; y < prevSize; y++)
				{
					ArrayofSizes[y] = temp1[y];
				}
				delete[] temp1;
				int **temp;
				temp = a;
				a = new int*[sizeofa];
				for (int u = 0; u < prevSize; u++)
				{
					a[u] = new int[ArrayofSizes[u]];
					for (int v = 0; v < ArrayofSizes[u]; v++)
					{
						a[u][v] = temp[u][v];
					}
				}
				delete[] temp;
			}
			for (int j = 0; j<sizeofArr; j++)
			{
				if (flagArr[j] == true && mintermschecked[j] == false)
				{
					int numberofDashes = 0;
					for (int k = 0; k<NoOfVariables; k++)
					{
						if (Arr[j].getPlaceValue(k) == '_')
						{
							numberofDashes++;
						}
					}
					if (numberofDashes == 0)
					{
						a[NumberofPIs] = new int[1];
						a[NumberofPIs][0] = j;
						ArrayofSizes[NumberofPIs] = 1;
						NumberofPIs++;
					}
					else
					{
						a[NumberofPIs] = new int[getNoOfCombin(numberofDashes)];
						ArrayofSizes[NumberofPIs] = getNoOfCombin(numberofDashes);
						char *PI;
						PI = Arr[j].getBool();

						for (int k = 0; k<getNoOfCombin(numberofDashes); k++)
						{
							char *Bin = new char[NoOfVariables];
							char *Binfill;
							int indexofBinfill = 0;
							Binfill = ConvetinttoBool(k,numberofDashes);
							int t = 0;
							while (t < NoOfVariables)
							{
								if (PI[t] != '_')
								{
									Bin[t] = PI[t];
								}
								else
								{
									Bin[t] = Binfill[indexofBinfill];
									indexofBinfill++;
								}
								t++;
							}
							a[NumberofPIs][k] = Convertbooltoint(Bin,NoOfVariables);
						}
						NumberofPIs++;
					}
				}
			}
			if (desiredCorrelations>0)
			{
				Arr = ChangedMinterms;
				sizeofArr = sizeofChangedMinterms;
				flagArr = new bool[sizeofArr];
				for (int z = 0; z<sizeofArr; z++)
				{
					flagArr[z] = true;
				}
			}
		} while (desiredCorrelations > 0);
		for (int w = 0; w < sizeofa; w++)
		{
			for (int x = w+1; x < sizeofa; x++)
			{
				if (ArrayofSizes[w] == ArrayofSizes[x])
				{
					bool theyAreEqual = true;
					for (int y = 0; y < ArrayofSizes[w]; y++)
					{
						if (a[w][y] != a[x][y])
						{
							theyAreEqual = false;
						}
					}
					if (theyAreEqual == true)
					{
						int m = x;
						int n = x + 1;
						while (n < sizeofa)
						{
							a[m] = a[n];
							ArrayofSizes[m] = ArrayofSizes[n];
							m++;
							n++;
						}
						sizeofa--;
						x--;
					}
				}
			}
			cout << endl;
		}
		////%%%%%%%%%%%%% WE NOW HAVE THE PI TABLE %%%%%%%%%%%%///////
		bool *EssentialPI = new bool[sizeofa];
		/*for (int w = 0; w < sizeofa; w++)
		{
			selectionsort(a[w], ArrayofSizes[w]);
		}*/
		bool **PITable = new bool*[sizeofa];
		for (int w = 0; w < sizeofa; w++)
		{
			PITable[w] = new bool[getNoOfCombin(NoOfVariables)];
		}
		for (int w = 0; w < sizeofa; w++)
		{
			for (int x = 0; x < getNoOfCombin(NoOfVariables); x++)
			{
				PITable[w][x] = false;
			}
		}
		for (int w = 0; w < sizeofa; w++)
		{
			int y = 0;
			for (int x = 0; ((x < getNoOfCombin(NoOfVariables))&&(y<ArrayofSizes[w])); x++)
			{
				if (a[w][y] == x)
				{
					PITable[w][x] = true;
					y++;
				}
			}
		}
		for (int w = 0; w < sizeofa; w++)
		{
			for (int x = 0; x < getNoOfCombin(NoOfVariables); x++)
			{
				cout << PITable[w][x] << " ";
			}
			cout << endl;
		}
		cout << "\n" << endl;
		for (int w = 0; w < sizeofa; w++)
		{
			for (int x = 0; x < ArrayofSizes[w]; x++)
			{
				cout << a[w][x] << " ";
			}
			cout << endl;
		}
		for (int w = 0; w < sizeofa; w++)
		{
			for (int x = 0; x < getNoOfCombin(NoOfVariables); x++)
			{
				int NumberofOnesinColumn = 0;
				for (int y = 0; y < sizeofa; y++)
				{
					if (PITable[y][x] == true)
					{
						NumberofOnesinColumn++;
					}
				}
				if (NumberofOnesinColumn == 1 && PITable[w][x] == true)
				{
					EssentialPI[w] = true;
				}
			}
			cout << endl;
		}
		cout << "Essential Prime Implicants:\n";
		for (int w = 0; w < sizeofa; w++)
		{
			if (EssentialPI[w] == true)
			{
				for (int x = 0; x < ArrayofSizes[w]; x++)
				{
					cout << a[w][x] << " ";
				}
				cout << endl;
			}
		}
		for (int w = 0; w < sizeofa; w++)
		{
			if (EssentialPI[w] == true)
			{
				cout << getTERM(a[w], ArrayofSizes[w], NoOfVariables)<<endl;
			}
		}
		
		
	}
	int Convertbooltoint(char *c, int size)
	{
		int a = 0;
		int index = 0;
		while (index < size)
		{
			int power = index;
			int b = 1;
			for (int i = 0; i < (power); i++)
			{
				b = 2 * b;
			}
			if (c[index] == '1')
			{
				a = a + b;
			}
			else
			{

			}
			index++;
		}
		return a;
	}
	char* ConvetinttoBool(int a,int NODASH)
	{
		char *Binary = new char[NODASH];
		int index = 0;
		int sizeofBin = NODASH;
		while (index < NODASH)
		{
			if (a % 2 == 0)
			{
				Binary[index] = '0';
			}
			else
			{
				Binary[index] = '1';
			}
			a = a / 2;
			index++;
		}
		return Binary;
	}
	int getSizeofBdig(int a)
	{
		int N = 1;
		while (a / 2 != 0)
		{
			a = a / 2;
			N++;
		}
		return N;
	}
	void selectionsort(int a[], int size)
	{
		int highest = 0;
		int temp;
		for (int i = 0; i<size; i++)
		{
			for (int j = 0; j<size - i; j++)
			{
				if (a[highest] < a[j])
				{
					highest = j;
				}
			}
			swap(a[highest], a[size-i-1]);
		}
	}
	char* getTERM(int *a, int size,int NOVar)
	{
		char c = 'A';
		char *TERM = new char[2 * NOVar];
		char** BOOLS = new char*[size];
		for (int i = 0; i < size; i++)
		{
			BOOLS[i] = new char[NOVar];
			BOOLS[i] = ConvetinttoBool(a[i], NOVar);
		}
		bool *VarPresent = new bool[NOVar];
		for (int i = 0; i < NOVar; i++)
		{
			bool Remainsame = true;
			char Reference = BOOLS[0][i];
			for (int j = 1; j < size; j++)
			{
				if (BOOLS[j][i] != Reference)
				{
					Remainsame = false;
				}
			}
			if (Remainsame == true)
			{
				VarPresent[i] = true;
			}
		}
		int index = NOVar - 1;
		int TermIndex = 0;
		for (int i = index; i >= 0; i--)
		{
			if (VarPresent[i] == true)
			{
				if (BOOLS[0][i] == '1')
				{
					TERM[TermIndex] = c+index-i;
					TermIndex++;
				}
				else
				{
					TERM[TermIndex] = c+index-i;
					TERM[TermIndex + 1] = '\'';
					TermIndex = TermIndex + 2;
				}
			}
		}
		char *FinalTerm = new char[TermIndex+1];
		for (int i = 0; i < TermIndex; i++)
		{
			FinalTerm[i] = TERM[i];
		}
		FinalTerm[TermIndex] = '\0';
		return FinalTerm;
	}
};
#endif