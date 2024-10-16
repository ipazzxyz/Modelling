qt_add_library(ModellingLogic
    asset.cpp asset.hpp
    fund.cpp fund.hpp
    market.cpp market.hpp
    system.cpp system.hpp
    currency.cpp currency.hpp
    depositor.cpp depositor.hpp
)
target_include_directories(ModellingLogic INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
