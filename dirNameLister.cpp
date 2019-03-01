// dirNameLister.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include "CLI11.hpp"
#include <stdio.h>
#include "sourceMethods.h"

using namespace std;

string dirname;

int main(int charc, char** argv)
{
	CLI::App listcmd{ "An application that creates a list of files in a directory. Multiple options available." };
	try
	{
		listcmd.add_option("dirname", dirname, "The path of the directory")
			->required();
		CLI11_PARSE(listcmd, charc, argv);
		cout << dirname << endl;
		vector< vector<string> > arraySource = generateSource(dirname, false);
		for (auto it : arraySource)
			for (auto it2 : it)
				cout << it2 << endl;
		
	}
	catch(CLI::Error &e)
	{
		return listcmd.exit(e);
	}

    return 0;
}

