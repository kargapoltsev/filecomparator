#pragma once

#include <filesystem>
#include <utility>

class IUI
{
public:
	virtual ~IUI() {}

	// ��������� ����� ������� ���������� ��� ��������� ������
	virtual std::pair<std::filesystem::path, std::filesystem::path> getPaths() = 0;

	// ����������� ������������� ������
	virtual void displayFiles(const std::vector<std::pair<std::string, std::string>> &files) = 0;
};
