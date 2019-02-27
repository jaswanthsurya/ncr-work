#include<iostream>
#include<string>

using namespace std;

char * ExpandShortNotation(string Sen,int SenSize, int OSenSize)
{
	char *outp;//output character array pointer
	outp = new char[OSenSize];//allocate the required memory necessary for the output character type by using the calculated size
	int indicator = 0;
	for (int counter = 0; counter < SenSize; counter++)
	{
		if (Sen[counter + 1] != '-'&&Sen[counter] != '-')//copy the content of string is the character are not neighbours of -
		{
			outp[indicator] = Sen[counter];
			indicator++;
		}
		if (Sen[counter] == '-')//if an - is encountered add the characters that are present in between them
		{
			if ((Sen[counter + 1] - Sen[counter - 1]) > 0)//if the left hand character asci value is lesser than the ascii value  of the right hand character
			{
				outp[indicator++] = Sen[counter - 1];
				for (int i = 0; i < (Sen[counter + 1] - Sen[counter - 1] - 1); i++)
				{
					outp[indicator++] = Sen[counter - 1] + i + 1;
				}
			}
			else
			{
				outp[indicator++] = Sen[counter - 1];//if the left hand character asci value is greater than the ascii value  of the right hand character
				for (int i = 0; i < (-Sen[counter + 1] +Sen[counter - 1] - 1); i++)
				{
					outp[indicator++] = Sen[counter - 1] -( i + 1);
				}
			}

		}
	}
	return outp;
}

int main()
{
	cout << "-------------program to expand the short hand notation in the given string--------------------" << endl;
	cout << "ex: 1-5 will be interpreted as 12345" << endl << endl << endl;
	string Sen;//character pointer to point to the scentence
	cout << "enter the sentence without spaces" << endl;
	getline(cin,Sen);
	cout << "you entered: " << Sen << endl;
	cout << "computing the output....." << endl;
	int SenSize;//size of sentence
	int counter = 0;//counter to count until the size is reached and take the inputs from user
	for (counter = 0; Sen[counter] != '\0'; counter++);
	SenSize = counter;
	cout << endl;
	if (Sen[0] == '-' || Sen[SenSize - 1] == '-')//condition to check if the first or last character is - so that invalid inputs are neglected
	{
		cout << "invalid sentence entered " << endl;
		cout << "entered sentence is :";
		for (counter = 0; counter < SenSize; counter++)//print the entered sentence and exit
		{
			cout << Sen[counter];
		}
		cout << endl << endl;
		cout << "process terminated" << endl<<endl;
		return 0;
	}
	int OSenSize = 0,indicator=0;//output Sentence size
	for (counter = 0; counter < SenSize; counter++)//for loop to check if any double - are present it means the input is invalid
	{
		if (Sen[counter] == '-')
		{
			if (Sen[counter + 1] == '-')
			{
				cout << "invalid sentence entered" << endl;
				cout << "entered sentence is :";
				for (int counter1 = 0; counter1 < SenSize; counter1++)//print the entered sentence and exit
				{
					cout << Sen[counter1];
				}
				cout << endl << endl;
				cout << "process terminated" << endl;
				return 0;
			}
			else
			{
				if((Sen[counter + 1] - Sen[counter - 1])>0)
					OSenSize = OSenSize + (int)(Sen[counter + 1] - Sen[counter - 1]);//calculate the elements between the characters present at the neighbour of -
				else 
					OSenSize = OSenSize + (int)(-1*(Sen[counter + 1] - Sen[counter - 1]));//calculate the elements in between the characters present between -
				indicator++;//count of - present in the sentence
			}
		}
	}
	OSenSize = SenSize + OSenSize - (2 * indicator);//calculate the output size using the count of - present
	char *outp;
	outp = new char[OSenSize];
	outp = ExpandShortNotation(Sen, SenSize, OSenSize);//function for expanding the short hand notation in the given sentence
	cout << "the expanded short hand notation of given string is: ";
	for (counter = 0; counter < OSenSize; counter++)
	{
		cout << outp[counter];
	}
	return 0;
}