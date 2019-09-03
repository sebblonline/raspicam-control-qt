/*! \mainpage
 *
 * \section intro_sec Introduction
 *
 * This is the introduction.
 *
 * \section install_sec Project structure
 * Code: source code of the Qt GUI app.
 * Doxygen: Contains Doxyfile.
 * Documentation: Output folder for doxygen.
 * rpi: Contains rpicam-video-daemon the daemon software running on the Raspberry Pi.
 *
 * \section install_sec Development
 * \subsection Build using CMake
 * mkdir build
 * cd build
 * cmake ..
 * make
 *
 * \subsection Qt Creator project
 *
 */

#include "MainWindow.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
