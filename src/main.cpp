#include <QtGui>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickView>


int main(int argc, char *argv[]) {
    // App
    QGuiApplication app(argc, argv);


    // Register types
    qmlRegisterSingletonType(QUrl("qrc:/StyleSheet.qml"), "S21Calculator.style", 1, 0, "Style");


    // Startup
    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("appDir", qApp->applicationDirPath());
    engine.rootContext()->setContextProperty("config", qApp->applicationDirPath() + "/config");

    engine.addImportPath("qrc:/");

    const QUrl url("qrc:/main.qml");
    engine.load(url);

    return app.exec();
}
