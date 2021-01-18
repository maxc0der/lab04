// Copyright 2020 Maxim Nasachenko <maximka5406@gmail.com>

#include <Broker.hpp>
#include <FinFile.hpp>
#include <Inspector.hpp>

int main(int argc, char *argv[]) {
  std::string directoryToInspect;
  if (argc == 1) {
    directoryToInspect = ".";
  } else {
    directoryToInspect = argv[1];
  }

  Inspector inspector("../misc/ftp");
  // Inspector inspector(directoryToInspect);
  inspector.InspectBrokers();
  inspector.PrintResult();
  return 0;
}
