#pragma once

#include "iui.h"

class CUI : public IUI
{
public:
	// ������������ ����� IUI
	virtual std::pair<std::filesystem::path, std::filesystem::path> getPaths() override;
	virtual void displayFiles(const std::vector<std::pair<std::string, std::string>>& files) override;

private:
	std::filesystem::path getDirectoryPath(const std::string &message);
};
