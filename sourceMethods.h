#pragma once
#include <string>
#include <iostream>
#include <stdio.h>
#include <filesystem>
#include <vector>

void printDir(std::string path);
std::vector<std::vector<std::string>> generateSource(std::string path, bool onlyName);