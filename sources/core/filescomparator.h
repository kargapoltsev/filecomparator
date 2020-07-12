#pragma once

#include <filesystem>
#include <memory>

using namespace std;

// Класс реализует методы сравнения файлов и деректорий
class FilesComparator
{
public:
	
	// Получение списка эквивалентных файлов в двух директориях, используя метод полного перебора
	static std::vector<std::pair<std::string, std::string>> getEqualFilesListSimple(
		const std::filesystem::path &directoryPath1, const std::filesystem::path &directoryPath2);
	
	// Получение списка эквивалентных файлов в двух директориях, используя предварительную группировку 
	// файлов по содержимому и сортировку групп по размеру файлов
	static std::vector<std::pair<std::string, std::string>> getEqualFilesList(
		const std::filesystem::path &directoryPath1, const std::filesystem::path &directoryPath2);

	// Сравнение двух файлов по размеру
	static bool isFilesSizeEqual(const std::filesystem::path &filePath1, const std::filesystem::path &filePath2);
	
	// Побайтовое сравнение двух файлов по содержимому
	static bool isFilesDataEqual(const std::filesystem::path &filePath1, const std::filesystem::path &filePath2);
};
