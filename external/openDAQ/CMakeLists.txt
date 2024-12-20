set(OPENDAQ_ENABLE_TESTS false)

FetchContent_Declare(
    openDAQ
    GIT_REPOSITORY https://github.com/openDAQ/openDAQ.git
    GIT_TAG v3.10.2
    GIT_PROGRESS   ON
    SYSTEM
    FIND_PACKAGE_ARGS 3.10.2 GLOBAL
)

FetchContent_MakeAvailable(openDAQ)
