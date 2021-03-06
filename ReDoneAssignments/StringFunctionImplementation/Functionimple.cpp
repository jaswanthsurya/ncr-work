#include<iostream>
#include<string>

using namespace std;

/*function to reverse the contents of the string this function return the reversed string 
by taking the string and its length as input and swapping the elements of string*/
string StringRev(string str, int len)
{
	int counter = 0;
	char temp = 0;
	for (counter = 0; counter <= len/2; counter++)
	{
		temp = str[counter];
		str[counter] = str[len - counter];
		str[len - counter] = temp;
	}
	return str;
}
/*this function concatinates two given string
it takes the two strings as input and the output charater array is the first parameter which is modified and returned
by the function*/
char * StringConcat(char *res,char*src)
{
	int counter = 0, res_count = strlen(res);
	char *res1=NULL;
	res1 = new char[strlen(res) + strlen(src) + 1];
	for (counter = 0; res[counter] != '\0'; counter++)
	{
		res1[counter] = res[counter];
	}
	res_count = counter;
	for (counter = 0; src[counter] != '\0'; counter++)
	{
		res1[res_count] = src[counter];
		res_count++;
	}
	res1[res_count] = '\0';
	res = new char[strlen(res1) + 1];
	for (counter = 0; res1[counter] != '\0'; counter++)
	{
		res[counter] = res1[counter];
	}
	res[counter] = '\0';
	return res;
}

/*this function copies string from one location to other
it takes the string as the input and the destination string as the input and modifes the destination string and returns*/
char * StringCpy(string str,char *res)
{
	int count = 0;
	while (str[count] != '\0')
	{
		res[count] = str[count];
		count++;
	}
	return res;
}

int StringComp(string str, string str1)
{
	bool flag = 0;
	int i = 0;
	while (str[i]!='\0'||str1[i]!='\0')//traverse until any one of the string reaches the end
	{
		if (str[i] != str1[i])
		{
			flag = 1;
			if (str[i] > str1[i])
				return 1;
			break;
		}
		i++;
	}
	if (str1[i]=='\0'&&str[i]=='\0'&&flag==0)//if both the strings reach the end and all the elements are equal
		return 0;
	else
		return -1;
}

int main()
{
	int choice;
	while (1)
	{
		cout << "enter your choice: " << endl;
		cout << "1.String Reverse" << endl << "2.String concatination" << endl << "3.string copy" << endl << "4.string compare" <<endl<<"5.exit"<< endl;
		cin >> choice;
		if (choice == 1 && sizeof(choice) == 4)//condition to check wether input entered is integer or not
		{
			string str;
			int Len_String = 0;
			cin.ignore();//ignore the character entered during giving the choice
			cout << "enter the string: ";
			getline(cin, str);//function to read string from console
			cout << "you have entered: " << str << endl << endl;
			for (Len_String = 0; str[Len_String] != '\0'; Len_String++);//find out length of string
			str = StringRev(str, Len_String - 1);//callback function
			cout << "the reversed string is: ";
			cout << str;
		}
		else if (choice == 2 && sizeof(choice) == 4)//condition to check wether input entered is integer or not
		{
			cin.ignore();//ignore the character entered during giving the choice
			string str, str1;
			int counter = 0;
			cout << "enter the first string : ";
			getline(cin, str);
			cout << "enter the second string  : ";//get the two strings
			getline(cin, str1);
			char *res = NULL, *src = NULL;
			for (counter = 0; str[counter] != '\0'; counter++);
			res = new char[counter + 1];
			for (counter = 0; str[counter] != '\0'; counter++)
			{
				res[counter] = str[counter];
			}
			res[counter] = '\0';
			for (counter = 0; str1[counter] != '\0'; counter++);
			src = new char[counter + 1];
			for (counter = 0; str1[counter] != '\0'; counter++)
			{
				src[counter] = str1[counter];
			}
			src[counter] = '\0';
			res=StringConcat(res, src);
			cout << "the resultant string after concatinating  is: ";
			cout << res << endl;
			cout << "strings concatinated......" << endl;
			delete(res);//deallocate the assigned memory
			delete(src);
		}
		else if (choice == 3 && sizeof(choice) == 4)//condition to check wether input entered is integer or not
		{
			cin.ignore();//ignore the character entered during giving the choice
			string str;
			char * res = NULL;//output buffer
			int res_count = 0;
			cout << "enter the string : ";
			getline(cin, str);
			for (res_count = 0; str[res_count] != '\0'; res_count++);
			res = new char[res_count];
			res = StringCpy(str, res);//call back function
			cout << "the string " << "{" << str << "}" << " at location " << &str << " is copied to address " << &res << endl;
			delete(res);//deallocate assigned memory
		}
		else if (choice == 4 && sizeof(choice) == 4)
		{
			cin.ignore();//ignore the enter character entered during giving choice
			string str, str1;
			cout << "enter the first string : ";
			getline(cin, str);
			cout << "enter the second string  : ";//get the two strings
			getline(cin, str1);
			int Result;
			Result = StringComp(str, str1);//callback function
			if (Result == 0)
			{
				cout << Result << endl;
				cout << "strings are equal" << endl;
			}
			else if (Result == -1)
			{
				cout << Result << endl;
				cout << "strings are not equal" << endl;
			}
			else
			{
				cout << Result << endl;
				cout << "strings are not equal" << endl;
			}
		}
		else
		{
			cout << "invalid choice " << endl;
			cout << "enter input again.." << endl;
			return 0;
		}
		cout << endl << endl;
	}
}