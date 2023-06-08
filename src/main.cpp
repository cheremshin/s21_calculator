#include <QtGui>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickView>


void loadFonts();

int main(int argc, char *argv[]) {
    // App
    QGuiApplication app(argc, argv);

    loadFonts();

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

void loadFonts() {
    QString fontsPath = QGuiApplication::applicationDirPath() + "/resources/fonts/";
    QDir fontsDir(fontsPath);
    if (!fontsDir.isEmpty() && fontsDir.exists()) {
        QDirIterator it(fontsPath, QDir::Files);

        while (it.hasNext()) {
            int res = QFontDatabase::addApplicationFont(it.next());
            if (res == -1) {
                qWarning() << QString("Loading font file: %1 failed.").arg(it.fileName());
            }
        }
    } else {
        qWarning() << QString("Unable to load application fonts from %1").arg(fontsPath);
    }

    QFont defaultFont("Inter");
    QGuiApplication::setFont(defaultFont);
}
