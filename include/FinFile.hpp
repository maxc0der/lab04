//
// Created by ubuntu on 18.01.2021.
//

#ifndef LAB4_FINFILE_HPP
#define LAB4_FINFILE_HPP
#include <string>

class FinFile {
 public:
  FinFile(const std::string& name, const std::string& date);

  std::string GetName() const;
  std::string GetDate() const;

 private:
  std::string name;
  std::string date;
};

#endif  // LAB4_FINFILE_HPP
