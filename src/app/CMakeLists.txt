qt_add_executable(Modelling main.cpp)
target_link_libraries(Modelling PRIVATE
    ModellingLogic
    Qt6::Widgets
)
