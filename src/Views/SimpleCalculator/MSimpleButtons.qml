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
    property int radioButtonWidth: 67
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
                spacing: 8

                MRadioButton { width: root.radioButtonWidth; height: root.radioButtonHeight; text: "("; textColor: Style.colorAccent }
                MRadioButton { width: root.radioButtonWidth; height: root.radioButtonHeight; text: ")"; textColor: Style.colorAccent }
                MRadioButton { width: root.radioButtonWidth; height: root.radioButtonHeight; text: "%"; textColor: Style.colorAccent }
                MRadioButton { width: root.radioButtonWidth; height: root.radioButtonHeight; text: "+-"; textColor: Style.colorAccent }
                MRadioButton { width: root.radioButtonWidth; height: root.radioButtonHeight; text: "/"; textColor: Style.colorAccent }
            }

            RowLayout {
                id: secondRowLayout
                Layout.alignment: Qt.AlignCenter
                spacing: 8

                MRadioButton { width: root.radioButtonWidth; height: root.radioButtonHeight; text: "C"; textColor: Style.colorAccent }
                MRadioButton { width: root.radioButtonWidth; height: root.radioButtonHeight; text: "7" }
                MRadioButton { width: root.radioButtonWidth; height: root.radioButtonHeight; text: "8" }
                MRadioButton { width: root.radioButtonWidth; height: root.radioButtonHeight; text: "9" }
                MRadioButton { width: root.radioButtonWidth; height: root.radioButtonHeight; text: "*"; textColor: Style.colorAccent }
            }

            RowLayout {
                id: thirdRowLayout
                Layout.alignment: Qt.AlignCenter
                spacing: 8

                MRadioButton { width: root.radioButtonWidth; height: root.radioButtonHeight; text: "X^"; textColor: Style.colorAccent }
                MRadioButton { width: root.radioButtonWidth; height: root.radioButtonHeight; text: "4" }
                MRadioButton { width: root.radioButtonWidth; height: root.radioButtonHeight; text: "5" }
                MRadioButton { width: root.radioButtonWidth; height: root.radioButtonHeight; text: "6" }
                MRadioButton { width: root.radioButtonWidth; height: root.radioButtonHeight; text: "-"; textColor: Style.colorAccent }
            }

            RowLayout {
                id: fourthRowLayout
                Layout.alignment: Qt.AlignCenter
                spacing: 8

                MRadioButton { width: root.radioButtonWidth; height: root.radioButtonHeight; text: "sqrt"; textColor: Style.colorAccent }
                MRadioButton { width: root.radioButtonWidth; height: root.radioButtonHeight; text: "1" }
                MRadioButton { width: root.radioButtonWidth; height: root.radioButtonHeight; text: "2" }
                MRadioButton { width: root.radioButtonWidth; height: root.radioButtonHeight; text: "3" }
                MRadioButton { width: root.radioButtonWidth; height: root.radioButtonHeight; text: "+"; textColor: Style.colorAccent }
            }

            RowLayout {
                id: fifthRowLayout
                Layout.alignment: Qt.AlignCenter
                spacing: 8

                MRadioButton { width: root.radioButtonWidth; height: root.radioButtonHeight; text: "X"; textColor: Style.colorAccent }
                MRadioButton { width: root.radioButtonWidth; height: root.radioButtonHeight; text: "0" }
                MRadioButton { width: root.radioButtonWidth; height: root.radioButtonHeight; text: "." }
                MRadioButton { width: root.radioButtonWidth; height: root.radioButtonHeight; text: "b" }
                MRadioButton { width: root.radioButtonWidth; height: root.radioButtonHeight; text: "="; textColor: Style.colorMain; backgroundColor: Style.colorAccent }
            }
        }
    }
}