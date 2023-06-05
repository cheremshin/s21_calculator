#include <QtGui>
#include <QQmlApplicationEngine>
#include <QQuickView>


int main(int argc, char *argv[]) {
    // App
    QGuiApplication app(argc, argv);

    // Startup
    QQmlApplicationEngine engine;

    const QUrl url("qrc:/main.qml");
    engine.load(url);

    return app.exec();
}
