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
bool eFlag; //flag for extension
bool remFlag; //flag for extension on safe path
bool absFlag; //flag for absolute path

int main(int charc, char** argv)
{
	CLI::App listcmd{ "An application that creates a list of files in a directory. Multiple options available." };
	try
	{
		listcmd.add_option("dirname", dirname, "The path of the directory")
			->required();
		listcmd.add_flag("-e,--extension", eFlag, "Add extension entry to file.");
		listcmd.add_flag("--remext", remFlag, "Remove extension from starting entry. --SAFE PATH ONLY--");
		listcmd.add_flag("-a, --absolute", absFlag, "Make the files have the absolute path. ex: C:/Users/person/pictures/hey.jpg - Defaultly have a safe path");
		CLI11_PARSE(listcmd, charc, argv);
		cout << dirname << endl;
		vector<string> arraySource = generateSource(dirname, absFlag, remFlag);
		for (auto it : arraySource)
			cout << it << endl;
		cout << (eFlag) << endl;
		createTXT(arraySource, dirname);
		
	}
	catch(CLI::Error &e)
	{
		return listcmd.exit(e);
	}

    return 0;
}

