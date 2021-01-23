/***************************************************
Sulaimon Yussuf
Comp 376 Programming Assignment 3

This program will encrypt a text file and can also
decrypt a file that has been encrypted in this way.

****************************************************/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void readData(ifstream &in, char **&data, int n);
//Post: Read n2 characters from the file into the n rows and
//n columns of a 2-dimensional array

void transpose( char **arr, int n );
//Post: Transpose the array

void writeData( ofstream &out, char **data, int n );
//Post: Write the characters from the array to an output file

int main()
{
	string inputFileName, outputFileName;
	int n;
	
	//Prompt the user for the name of the original file
	cout << "Enter input file name: ";
	cin >> inputFileName;
	cout << endl;
	
	//Prompt the user for the name of the output file
	cout << "Enter output file name: ";
	cin >> outputFileName;
	cout << endl;
	
	//Prompt the user for the encryption key, n
	cout << "Enter key: ";
	cin >> n;
	cout << endl;
	
	char** data = new char*[n];
	for( int a = 0; a < n; ++a )
	{
		data[a] = new char[n];
	}
	ifstream in(inputFileName.c_str());
	ofstream out(outputFileName.c_str());
	if(in.is_open() && out.is_open())
	{
		
		//eof-controlled loop to process the file
		while (!in.eof())
		{
			
			readData(in, data, n);
			transpose(data, n);
			writeData(out, data, n);

		}
	}
	else
	{
		cout << "Chosen File cannot be opened" << endl;
	}
	
	//Close file
	in.close();
	
	//Output file
	out.close();
	
	cout << " Thank you and Goodbye " ;
	cout << endl;

	return EXIT_SUCCESS;
}


//Reading the characters from the file into the array
void readData(ifstream &in, char **&data, int n)
{

	for( int a = 0; a < n && !in.eof(); ++a )
	{
		for( int b = 0; b < n && !in.eof(); ++b )
		{
			in.get( data[a][b] );
		}
	}
}
//Transposing the array
void transpose( char **arr, int n )
{
	char Temp;

	for( int a = 0; a < n; ++a )
	{
		for( int b = a + 1; b < n; ++b )
		{
			Temp = arr[b][a];
			arr[b][a] = arr[a][b];
			arr[a][b] = Temp;
		}
	}
}
//Writing the characters from the array to the file
void writeData( ofstream &out, char **data, int n )
{
	for( int a = 0; a < n; ++a )
	{
		for( int b = 0; b < n; ++b )
		{
			out << data[a][b];
			data[a][b]= '\0';
		}
	}
}

