#include <iostream>
#include <vector>
#include <math.h>

using std:: cout;
using std:: cin;
using std:: endl;
using std:: vector;

int main()
{
	//kintamuju deklaracija
	vector<char> Skaicius {};
	vector<int> Skaicius1 {};
	int b = 0;
	int b1 = 0;
	
	//duomenu ivedimas
	cout << "Iveskite skaiciu: " << endl;
	char a {};
	do{
		cin.get(a);
		Skaicius.push_back(a);
	}while (a != '\n');
	int i = 0;
	cout << "Iveskite skaiciaus baze: " << endl;
	cin >> b;
	cout << "Iveskite, i kokia baze norite pakeisti: " << endl;
	cin >> b1;
	
	//duomenu transformavimas i desimtainius skaicius (max 36)
	for (int i = 0; i < Skaicius.size()-1; i++)
	{
		cout << "p: "<< (int)Skaicius[i] << endl;
		if ((int)Skaicius[i] >= 65 && (int)Skaicius[i] <= 90)
		{
			Skaicius1.push_back((int)Skaicius[i]-55);
			cout << "if   " << Skaicius1[i] << endl;
		} else if ((int)Skaicius[i] >= 97 && (int)Skaicius[i] <= 122)
		{
			Skaicius1.push_back((int)Skaicius[i]-87);
			cout << "if1  " << Skaicius1[i] << endl;
		} else
		{
			Skaicius1.push_back((int)Skaicius[i]-48);
			cout << "else " << Skaicius1[i] << endl;
		}
	}
	
	//konvertevimas i desimtaine sistema
	long long int n = 0;  	
	for (int i = 0; i < Skaicius1.size(); i++)
	{
		cout << "SK " << Skaicius1[i] << endl;
		cout << "PW " << pow(b, Skaicius1.size()-1) << endl;
		n = n + Skaicius1[i]*pow(b, Skaicius1.size()-1-i);
		cout << Skaicius1[i]*pow(b, Skaicius1.size()-1-i) << endl;
		cout << "n: " << n << endl;
	}
	
	
	
	
	
	
	
	/*while (i < Skaicius.size())
	{
		cout << Skaicius[i] << " ";
		i++;
	}*/
	return 0;
}
