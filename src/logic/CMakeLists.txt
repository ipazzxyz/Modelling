add_library(ModellingLogic
    fund.hpp
    market.hpp
    system.hpp
    currency.hpp
    fund.cpp
    market.cpp
    system.cpp
    currency.cpp
)
target_include_directories(ModellingLogic INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
