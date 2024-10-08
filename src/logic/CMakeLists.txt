qt_add_library(ModellingLogic
        asset.hpp
        fund.hpp
        market.hpp
        system.hpp
        currency.hpp
        asset.cpp
        fund.cpp
        market.cpp
        system.cpp
        currency.cpp depositors.cpp depositors.hpp)
target_include_directories(ModellingLogic INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
