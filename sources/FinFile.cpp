//
// Created by ubuntu on 18.01.2021.
//
#include <FinFile.hpp>

FinFile::FinFile(const std::string& ArgName, const std::string& ArgDate)
    : name(ArgName), date(ArgDate) {

}
std::string FinFile::GetName() const { return name; }
std::string FinFile::GetDate() const { return date; }
