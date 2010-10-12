/*
 * Copyright 2010 Helio Chissini de Castro <helio@collabora.co.uk>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0

 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/

#include <QtGui/QApplication>
#include <QtDeclarative/QDeclarativeView>
#include <QtDeclarative/QDeclarativeEngine>
#include <QtDeclarative/QDeclarativeContext>
#include "qtgraphtest.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QDeclarativeView view;
    QtGraphTest *graphTest = new QtGraphTest( &view );

    view.setSource( QUrl::fromLocalFile("qml/Main.qml") );
    view.setResizeMode( QDeclarativeView::SizeViewToRootObject );
    QObject::connect(view.engine(), SIGNAL(quit()), qApp, SLOT(quit()));

    //view.setWindowFlags( flags );
    view.show();
    return app.exec();
}
