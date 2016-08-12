#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string> & strVect)
{
	string result;
	
	if( strVect.size() > 0 ) 
		result = strVect[0]; 
	int i,j;
	//in each iteration try to match the whole prefix; if not matching reduce it
	for( i = 1; i < strVect.size(); i++ )
	{
		int m = min( result.size(), strVect[i].size() );
		for( j = 0; j < m; j++ )
		{
			if( result[j] != strVect[i][j] )
				break;
		}
		result = result.substr(0,j);
		if( result.empty() )
			break;
	}
	return result;
}
void TestCase1()
{
	vector<string> strs;
	strs.push_back("Anamoly");
	strs.push_back("Anatomy");
	strs.push_back("Analog");
	strs.push_back("Angry");
	cout << longestCommonPrefix(strs) << endl;
}
void TestCase2()
{
	vector<string> strs;
	strs.push_back("test");
	strs.push_back("test");
	strs.push_back("test");
	cout << longestCommonPrefix(strs) << endl;
}
void TestCase3()
{
	vector<string> strs;
	cout << longestCommonPrefix(strs) << endl;
}
void TestCase4()
{
	vector<string> strs;
	strs.push_back("test");
	cout << longestCommonPrefix(strs) << endl;
}
int main()
{
	TestCase1();
	TestCase2();
	TestCase3();
	TestCase4();
	return 0;
}