#pragma once
#include <string>
#include <iostream>
#include <stdio.h>
#include <filesystem>
#include <vector>

void printDir(std::string path);
std::vector<std::string> generateSource(std::string path, bool onlyName, bool keepExt);
void createTXT(std::vector<std::string> source, std::string name);
