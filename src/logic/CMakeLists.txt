qt_add_library(ModellingLogic
        asset.cpp asset.hpp
        stock.cpp stock.hpp bond.cpp bond.hpp unique_bond.cpp unique_bond.hpp depositor.cpp depositor.hpp fund.cpp fund.hpp market.cpp market.hpp system.cpp system.hpp)
target_include_directories(ModellingLogic INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
