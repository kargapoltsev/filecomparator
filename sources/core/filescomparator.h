#pragma once

#include <filesystem>
#include <memory>

using namespace std;

// ����� ��������� ������ ��������� ������ � ����������
class FilesComparator
{
public:
	
	// ��������� ������ ������������� ������ � ���� �����������, ��������� ����� ������� ��������
	static std::vector<std::pair<std::string, std::string>> getEqualFilesListSimple(
		const std::filesystem::path &directoryPath1, const std::filesystem::path &directoryPath2);
	
	// ��������� ������ ������������� ������ � ���� �����������, ��������� ��������������� ����������� 
	// ������ �� ����������� � ���������� ����� �� ������� ������
	static std::vector<std::pair<std::string, std::string>> getEqualFilesList(
		const std::filesystem::path &directoryPath1, const std::filesystem::path &directoryPath2);

	// ��������� ���� ������ �� �������
	static bool isFilesSizeEqual(const std::filesystem::path &filePath1, const std::filesystem::path &filePath2);
	
	// ���������� ��������� ���� ������ �� �����������
	static bool isFilesDataEqual(const std::filesystem::path &filePath1, const std::filesystem::path &filePath2);
};
