// Copyright 2020 Maxim Nasachenko <maximka5406@gmail.com>

#ifndef INCLUDE_INSPECTOR_HPP_
#define INCLUDE_INSPECTOR_HPP_
#include <Broker.hpp>
#include <FinFile.hpp>
#include <boost/filesystem.hpp>
#include <string>
#include <vector>

const int AccountLength = 8;
const int DateLength = 8;
const int FilenameTokenCount = 3;
const char FileType[] = "balance";

class Inspector {
 public:
  Inspector(const std::string &PathToInspect);
  void InspectBrokers();
  void PrintResult();

 private:
  std::string brokersDirectory;
  std::vector<Broker> brokers;
  Broker inspectSingleBroker(const boost::filesystem::path &path);
};

#endif  // INCLUDE_INSPECTOR_HPP_
