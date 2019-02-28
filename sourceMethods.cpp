// dirNameLister.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include "sourceMethods.h"
#include <filesystem>

using namespace std;


void printDir(string path)
{
	namespace fs = std::filesystem;
	for (const auto & entry : fs::directory_iterator(path))
		cout << entry.path() << endl;
}