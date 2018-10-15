#include "Static.h"
#include "ui_static.h"

StaticImage::StaticImage(QWidget *parent) : QWidget(parent) {
	Ui::Static Static;
	Static.setupUi(this);
}

