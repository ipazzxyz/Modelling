qt_add_executable(Modelling
    main.cpp
    app.cpp app.hpp
    setupform.cpp setupform.hpp setupform.ui
    gamewindow.cpp gamewindow.hpp gamewindow.ui
)
target_link_libraries(Modelling PRIVATE
    ModellingLogic
    Qt::Core
    Qt::Gui
    Qt::Widgets
)
set_target_properties(Modelling PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)
