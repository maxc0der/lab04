// Copyright 2020 Maxim Nasachenko <maximka5406@gmail.com>

#include <Inspector.hpp>
#include <algorithm>
#include <boost/filesystem.hpp>
#include <iostream>
#include <string>
#include <vector>

inline bool is_separator(char c) { return c == '_'; }
inline bool not_separator(char c) { return !is_separator(c); }

std::vector<std::string> splitString(const std::string &text) {
  std::vector<std::string> ret;
  for (auto i = text.cbegin(); i != text.cend();) {
    i = std::find_if(i, text.end(), not_separator);
    auto j = std::find_if(i, text.end(), is_separator);
    ret.emplace_back(i, j);
    i = j;
  }
  return ret;
}

std::string lastDate(const std::vector<FinFile> &files) {
  std::string res;
  for (const auto &file : files) {
    res = std::max(res, file.GetDate());
  }
  return res;
}

Inspector::Inspector(const std::string &path_to_inspect)
    : brokersDirectory(path_to_inspect), brokers() {}

void Inspector::InspectBrokers() {
  for (const auto &entry :
       boost::filesystem::directory_iterator{brokersDirectory}) {
    auto brok = inspectSingleBroker(entry.path());
    if (brok.Valid()) brokers.push_back(brok);
  }
}

Broker Inspector::inspectSingleBroker(const boost::filesystem::path &path) {
  std::string name;
  AccFilesMap files;
  if (!boost::filesystem::is_directory(path))
    throw std::runtime_error(
        "argument must be path to Broker directory, not file");

  name = path.filename().string();

  for (const auto &entry : boost::filesystem::directory_iterator{path}) {
    if (boost::filesystem::is_directory(entry) ||
        !entry.path().stem().extension().empty() ||
        entry.path().extension().string() != ".txt")
      continue;

    auto filenameTokens = splitString(entry.path().stem().string());
    if (filenameTokens.size() != FilenameTokenCount) continue;

    auto type = filenameTokens[0];
    auto account = filenameTokens[1];
    auto date = filenameTokens[2];

    if (type != FileType) continue;                   // type
    if (account.length() != AccountLength) continue;  // account
    if (date.length() != DateLength) continue;        // date

    files[account].emplace_back(entry.path().filename().string(), date);
  }
  return Broker(name, files);
}

void Inspector::PrintResult() {
  std::cout << "total brokers: " << brokers.size() << std::endl;
  for (const auto &Broker : brokers) {
    for (const auto &af_pair : Broker.GetFiles()) {
      std::cout << "broker:" << Broker.GetName() << " account:" << af_pair.first
                << " files:" << af_pair.second.size()
                << " lastdate:" << lastDate(af_pair.second) << std::endl;
    }
  }

  std::cout << std::endl;

  for (const auto &Broker : brokers) {
    for (const auto &af_pair : Broker.GetFiles()) {
      for (const auto &file : af_pair.second) {
        std::cout << Broker.GetName() << " " << file.GetName() << std::endl;
      }
    }
  }
}
