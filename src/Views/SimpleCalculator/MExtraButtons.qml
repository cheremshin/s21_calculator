import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import CustomComponents
import S21Calculator.style


Item {
    id: root

    // Color
    property color backgroundColor

    // Size
    property int radioButtonWidth: 120
    property int radioButtonHeight: 67

    Rectangle {
        id: container
        anchors.fill: parent
        color: root.backgroundColor

        ColumnLayout {
            id: buttonsLayout
            width: parent.width
            height: parent.height
            spacing: 8

            RowLayout {
                id: firstRowLayout
                Layout.alignment: Qt.AlignCenter
                spacing: 20

                MRadioButton { width: root.radioButtonWidth; height: root.radioButtonHeight; text: "exp"; textColor: Style.colorAccent }
                MRadioButton { width: root.radioButtonWidth; height: root.radioButtonHeight; text: "RAD"; textColor: Style.colorAccent }
                MRadioButton { width: root.radioButtonWidth; height: root.radioButtonHeight; text: "DEG"; }
            }

            RowLayout {
                id: secondRowLayout
                Layout.alignment: Qt.AlignCenter
                spacing: 20

                MRadioButton { width: root.radioButtonWidth; height: root.radioButtonHeight; text: "sin"; textColor: Style.colorAccent }
                MRadioButton { width: root.radioButtonWidth; height: root.radioButtonHeight; text: "cos"; textColor: Style.colorAccent }
                MRadioButton { width: root.radioButtonWidth; height: root.radioButtonHeight; text: "tan"; textColor: Style.colorAccent }
            }

            RowLayout {
                id: thirdRowLayout
                Layout.alignment: Qt.AlignCenter
                spacing: 20

                MRadioButton { width: root.radioButtonWidth; height: root.radioButtonHeight; text: "asin"; textColor: Style.colorAccent }
                MRadioButton { width: root.radioButtonWidth; height: root.radioButtonHeight; text: "acos"; textColor: Style.colorAccent }
                MRadioButton { width: root.radioButtonWidth; height: root.radioButtonHeight; text: "atan"; textColor: Style.colorAccent }
            }

            RowLayout {
                id: fourthRowLayout
                Layout.alignment: Qt.AlignCenter
                spacing: 20

                MRadioButton { width: root.radioButtonWidth; height: root.radioButtonHeight; text: "log"; textColor: Style.colorAccent }
                MRadioButton { width: root.radioButtonWidth; height: root.radioButtonHeight; text: "lg"; textColor: Style.colorAccent }
                MRadioButton { width: root.radioButtonWidth; height: root.radioButtonHeight; text: "mod"; textColor: Style.colorAccent }
            }

            RowLayout {
                id: fifthRowLayout
                Layout.alignment: Qt.AlignCenter
                spacing: 20

                MRadioButton { width: root.radioButtonWidth; height: root.radioButtonHeight; text: "e" }
                MRadioButton { width: root.radioButtonWidth; height: root.radioButtonHeight; text: "pi" }
                MRadioButton { width: root.radioButtonWidth; height: root.radioButtonHeight; text: "RND" }
            }
        }
    }
}