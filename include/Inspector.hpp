//
// Created by ubuntu on 18.01.2021.
//

#ifndef LAB4_INSPECTOR_HPP
#define LAB4_INSPECTOR_HPP

class Inspector {
 public:
  Inspector(const std::string &PathToInspect);
  void InspectBrokers();
  void PrintResult();

 private:
  std::vector<broker> brokers;
  std::string brokersDirectory;
};

#endif  // LAB4_INSPECTOR_HPP
