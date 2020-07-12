#include <iostream>
#include "cui.h"
#include "filescomparator.h"

int main() 
{
	try
	{
		CUI cui;
		const auto[directoryPath1, directoryPath2] = cui.getPaths();
		const auto files = FilesComparator::getEqualFilesListSimple(directoryPath1, directoryPath2);
		cui.displayFiles(files);
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Undefined error" << std::endl;
	}

    return 0;
}
