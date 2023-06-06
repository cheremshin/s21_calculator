import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import S21Calculator.style


Page {
    id: root
    background: Rectangle { anchors.fill: parent; color : Style.colorBackground }


    Rectangle {
        id: inputBlock

        width: parent.width
        height: 235

        color: Style.colorMain
    }

    Rectangle {
        id: buttonsBlock

        width: parent.width
        height: parent.height - 235

        color: Style.colorBackground

        anchors.top: inputBlock.bottom
    }
}
