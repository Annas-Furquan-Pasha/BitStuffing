#include <iostream>
using namespace std;

// function used to stuff the bit
string bitStuffing(string temporaryData, string bitToBeStuffed)
{
	string flag = "011111"; //default flag
	string Buffer = "";

	for(int i=0; i<temporaryData.size(); i++)
	{
		Buffer = Buffer + temporaryData[i];

		if(Buffer == flag)
		{
			temporaryData = temporaryData.substr(0, i+1) + bitToBeStuffed + temporaryData.substr(i+1, temporaryData.size()-i);
			i--;
		}

		if(Buffer.size() == flag.size())
		{
			Buffer = Buffer.substr(1, Buffer.size()-1);
		}
	}

	return temporaryData;
}

// driver code
int main()
{
	string data ;

	cout << "Enter data to be stuffed : ";
	cin >> data;

	string bitToBeStuffed =  "0"; //default bit stuff

	data = bitStuffing(data, bitToBeStuffed);

	cout << "The data after BitStuffing is : " << data << endl;
}