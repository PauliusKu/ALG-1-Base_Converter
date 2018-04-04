#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


const int max = 10000;

using std:: cout;
using std:: cin;
using std:: endl;
using std:: vector;
using std:: string;

void Sumatorius(vector<int> &A, vector<int> &B, unsigned int b); //prie A prideda B
void Skirtumatorius(vector<int> &A, vector<int> &B, unsigned int b); //is A atima B
bool Palyginti (vector<int> &A, vector<int> &B); //grazina true jei A >= B
void Generavimas(vector <vector<int>> &V1, int b); //generuoja 2^max nustatytoje bazeje
void iDvejetaine(vector<int> &A, unsigned int b); //vercia i dvejetaine
void isDvejetaines(vector<int> &A, unsigned int b); //vervia is dvejetaines
void Ivestis(vector<int> &A, unsigned int &b, unsigned int&b1); //ivedimas
unsigned int ivestSk(unsigned int b); //vieno skaiciaus ivedimas
void StringiVec(vector<int> &A, unsigned int b); //Nuskaito string ir pavercia i vector
void Rezultatas(vector<int> A, unsigned int b, unsigned int b1); //rezultatu isvedimas

int main()
{
	vector <vector <int> > V1;
	
	vector <int> P{};
	unsigned int b{};
	unsigned int b1{};
	
	try{
		Ivestis(P, b, b1);
		iDvejetaine(P, b);
		Rezultatas(P, b, b1);
		isDvejetaines(P, b1);
		Rezultatas(P, b, b1);
	} catch (const char* msg) {
    	std::cerr << msg << endl;
   	}
   	
	cout << endl << "Programos veikimo pabaiga." << endl;
	
	return 0;
}
//-----------------------------------------------------------------------------------------------------------
void Ivestis(vector<int> &A, unsigned int &b, unsigned int&b1)
{
	cout << "Max reksme: 2^" << max << endl;
	cout <<  "1 - iprasta ivestis, 0 - iseiti" << endl;
	switch(ivestSk(2))
	{
		case 0:{
			cout << "Programa baigta" << endl;
			break;
		}
		case 1:{
			cout << "Is kokios bazes norite paversti? ";
			do{
				b = ivestSk(10);
			}while(b > 36 || b <= 1);
			cout << "verciama is " << b << " bazes" << endl;
			cout << "I kokia baze norite paversti? ";
			do{
				b1 = ivestSk(10);
			}while(b1 > 36 || b1 <= 1);
			cout << "verciama i " << b1 << " baze" << endl;
			cout << "Iveskite skaiciu: " << endl;
			StringiVec(A, b);
			break;
		}
		default:{
			throw "Ivesta klaidingai";
			break;
		}
	}
}
//-----------------------------------------------------------------------------------------------------------
unsigned int ivestSk( unsigned int b)
{
	unsigned int sk{};
	string Sk{};
	do{
		getline (cin, Sk);
	}while(!(Sk.find_first_not_of("0123456789") == string::npos));
	return std::stoi(Sk);
}
//-----------------------------------------------------------------------------------------------------------
void StringiVec(vector<int> &A, unsigned int b)
{
	string Sk{};
	cin >> Sk;
	char c{};
	for(int i = 0; i < Sk.size(); i++)
	{
		c = Sk.at(i);
		if (int(c) >= 48 &&  int(c) <= 57)
		{
			A.push_back((c)-48);
		} else if (int(c) >= 65 &&  int(c) <= 90)
		{
			A.push_back((c)-55);
		}
		if (A[i] >= b)
		{
			throw "Netinkamas zenklas.";
		}
	}
	std::reverse(A.begin(), A.end());
}
//-----------------------------------------------------------------------------------------------------------
void iDvejetaine(vector<int> &A, unsigned int b)
{
	vector <vector <int> > V1;
	vector <int> Papild{};
	Generavimas(V1, b);
	for (unsigned int i = 0; i < 1; i++)
	{
		int j = 0;
		bool b = true;
		while(b)
		{
			if (Palyginti(A, V1[j])) //jei P daugiau arba lygu
			{
				j++;
			} else {
				j--;
				if (Palyginti(A, V1[j]))
				{
					Skirtumatorius(A, V1[j], b);
					Papild.push_back(1);
				} else Papild.push_back(0);
				if (j == 0)
				{
					b = false;
				}
			}
		}
	}
	A = Papild;
}
//-----------------------------------------------------------------------------------------------------------
void isDvejetaines(vector<int> &A, unsigned int b)
{
	vector <vector <int> > V1;
	vector <int> Papild{0};
	Generavimas(V1, b);
	const unsigned int a = A.size();
	for (int i = 0; i < a; i++)
	{
		if (A[i] == 1)
		{
			Sumatorius(Papild, V1[a-i-1], b);
		}
	}
	A = Papild;
	
	std::reverse(A.begin(), A.end());
}

//-----------------------------------------------------------------------------------------------------------
void Generavimas(vector <vector<int>> &V1, int b)
{
	vector <int> Sk1{1};
	vector <int> Sk2{}; // papildomas
	V1.push_back(Sk1);
	for (unsigned int i = 0; i < max; i++)
	{
		Sk2 = Sk1;
		Sumatorius(Sk1, Sk2, b);
		V1.push_back(Sk1);
	}
	
}
//-----------------------------------------------------------------------------------------------------------
void Sumatorius(vector<int> &A, vector<int> &B, unsigned int b)
{
	unsigned int dyd{};
	if(A.size() > B.size())
	{
		dyd = A.size();
	} else dyd = B.size();
	for (unsigned int i = 0; i < dyd; i++)
	{
		if (A.size() == i)
		{
			A.push_back(0);
		}
		if (B.size() == i)
		{
			B.push_back(0);
		}
		if(A[i] + B[i] >= b)
		{
			if(i == A.size()-1)
			{
				A.push_back(1);
			} else A[i+1]++;
			A[i] = A[i] + B[i] - b;
		} else{
			A[i] = A[i] + B[i];
		}
	}
}
//-----------------------------------------------------------------------------------------------------------
void Skirtumatorius(vector<int> &A, vector<int> &B, unsigned int b)
{
	unsigned int dyd{};
	if(A.size() < B.size())
	{
		dyd = A.size();
	} else dyd = B.size();
	for (unsigned int i = 0; i < dyd; i++)
	{
		if(A[i] - B[i] < 0)
		{
			A[i+1]--;
			A[i] = A[i] - B[i] + b;
		} else{
			A[i] = A[i] - B[i];
		}
	}
	for (int i = A.size()-1; i >= 0; i--)
	{
		if (A[i] == 0)
		{
			A.pop_back();
		} else i = -1;
	}
}
//-----------------------------------------------------------------------------------------------------------
bool Palyginti (vector<int> &A, vector<int> &B)
{
	if (A.size() > B.size())
	{
		return true;
	} else if (A.size() < B.size())
	{
		return false;
	} else {
		for ( int i = A.size()-1; i >= 0; i--)
		{
			if (A[i] > B[i])
			{
				return true;
			} else if (A[i] < B[i])
			{
				return false;
			}
		}
		return true; //lygus
	}
}
//-----------------------------------------------------------------------------------------------------------
void Rezultatas(vector<int> A, unsigned int b, unsigned int b1)
{
	cout << "Rezultatas(" <<b<<"->"<<b1<<"): " << endl;
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] >= 10)
		{
			cout << char(A[i]+55);
		} else{
			cout << A[i];
		}
	}
	cout << endl;
}
