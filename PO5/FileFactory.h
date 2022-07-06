#pragma once
#include <iostream>
#include <string>
#include "IFile.h"

class FileFactory
{
public:
	static IFile* OpenFile(std::string path, std::ios openMode);
};

