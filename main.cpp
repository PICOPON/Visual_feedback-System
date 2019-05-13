#include "Visual_feedback_system.h"
#include <QtWidgets/QApplication>
#include <tchar.h>
#include <stdint.h>
#include <opencv2/opencv.hpp>//opencv api
extern "C"
{
#include "KSJApiBase.h"
}//camera api

int main(int argc, char* argv[])
{
		QApplication a(argc, argv);
		Visual_feedback_system w;
		w.show();
		return a.exec();

}

