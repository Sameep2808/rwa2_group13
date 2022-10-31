#include <iostream>
#include <string>
#include <unistd.h>
#include <memory>

#include "simulator/simulator.h"
#include "algorithm/algorithm.h"

int main(int argc, char *argv[])
{
    auto algo = std::make_unique<rwagroup12::Algorithm>();
    algo->run();
}