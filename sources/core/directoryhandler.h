#pragma once

#include <list>
#include <map>
#include <filesystem>

// ����� ������������ ���������� ����� �� ������ � ������� ����������. 
// ������ ������ ��������� ��������� ��������� �� ������ ����������� ����
// � ������� ����������� ������� ������, ������������� ����� �� �����������.
class DirectoryHandler 
{
public:
	using Group = std::list<std::filesystem::path>;
	using Groups = std::list<Group>;
	using Collection = std::map<std::size_t, Groups>;

	// ��������� ��������� ����������
	void handleDirectory(const std::filesystem::path &directoryPath);

	auto begin() { return m_collection.begin(); }
	auto end() { return m_collection.end(); }
	
	// ����� ����� ������ �� �������
	auto find(std::size_t size) { return m_collection.find(size); }
	
	// ������� ������� ����� ������ ��������� �������
	bool has(std::size_t size);

private:
	// ������������ �������� ��������� ����� ������ ������� ����������
	void fill();
	
	// ����������� ����� �� ������ �� �����������
	void group();

	// ���� �� ������� ����������
	std::filesystem::path m_directoryPath;

	// ��������� �����
	Collection m_collection;
};
