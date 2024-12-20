/**
 * Server application
 */

#include <iostream>
#include <opendaq/opendaq.h>

using namespace daq;

int main(int /*argc*/, const char* /*argv*/[])
{
    const auto instance = InstanceBuilder().setRootDevice("example://").addDiscoveryServer("mdns").build();
    instance.addServer("OpenDAQNativeStreaming", nullptr).enableDiscovery();

    std::cout << "Press \"enter\" to exit the application..." << std::endl;
    std::cin.get();
    return 0;
}
