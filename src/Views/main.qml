import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15


ApplicationWindow
{
    id: baseRoot
    property int defaultWidth:  455
    property int defaultHeight: 770



    maximumWidth:  defaultWidth
    maximumHeight: defaultHeight

    minimumWidth:  defaultWidth
    minimumHeight: defaultHeight

    visible: true
    title: qsTr("Calculator")
}