// Copyright 2020 Maxim Nasachenko <maximka5406@gmail.com>

#include <Broker.hpp>

Broker::Broker(const std::string& ArgName, const AccFilesMap& ArgFiles)
    : name(ArgName), accFiles(ArgFiles) {}
std::string Broker::GetName() const { return name; }
AccFilesMap Broker::GetFiles() const { return accFiles; }
bool Broker::Valid() const { return !name.empty() && !accFiles.empty(); }
