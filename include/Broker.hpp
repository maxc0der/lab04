//
// Created by ubuntu on 27.12.2020.
//

#ifndef LAB4_BROKER_HPP
#define LAB4_BROKER_HPP

#include <FinFile.hpp>
#include <map>
#include <string>
#include <vector>

typedef std::map<std::string, std::vector<FinFile>> AccFilesMap;

class Broker {
 public:
  Broker(const std::string& name, const AccFilesMap& files);
  std::string GetName() const;
  AccFilesMap GetFiles() const;
  bool Valid() const;

 private:
  std::string name;
  AccFilesMap accFiles;
};

#endif  // LAB4_BROKER_HPP
