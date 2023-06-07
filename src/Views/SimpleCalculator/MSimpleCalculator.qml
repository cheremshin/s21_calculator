import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import CustomComponents
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

        ColumnLayout {
            id: buttonsLayout
            anchors.fill: parent
            spacing: 8

            property int radioButtonWidth: 67
            property int radioButtonHeight: 67


            Rectangle { height: 20; color: Style.colorMain } // Placeholder

            MHeavySwitch {
                width: 288; height: 68
                Layout.alignment: Qt.AlignCenter
                leftText: "Simple"
                rightText: "Extra"
            }

            Rectangle { height: 12; color: Style.colorMain } // Placeholder

            RowLayout {
                id: firstRowLayout
                Layout.alignment: Qt.AlignCenter
                spacing: 8

                MRadioButton { width: buttonsLayout.radioButtonWidth; height: buttonsLayout.radioButtonHeight; text: "("; textColor: Style.colorAccent }
                MRadioButton { width: buttonsLayout.radioButtonWidth; height: buttonsLayout.radioButtonHeight; text: ")"; textColor: Style.colorAccent }
                MRadioButton { width: buttonsLayout.radioButtonWidth; height: buttonsLayout.radioButtonHeight; text: "%"; textColor: Style.colorAccent }
                MRadioButton { width: buttonsLayout.radioButtonWidth; height: buttonsLayout.radioButtonHeight; text: "+-"; textColor: Style.colorAccent }
                MRadioButton { width: buttonsLayout.radioButtonWidth; height: buttonsLayout.radioButtonHeight; text: "/"; textColor: Style.colorAccent }
            }

            RowLayout {
                id: secondRowLayout
                Layout.alignment: Qt.AlignCenter
                spacing: 8

                MRadioButton { width: buttonsLayout.radioButtonWidth; height: buttonsLayout.radioButtonHeight; text: "C"; textColor: Style.colorAccent }
                MRadioButton { width: buttonsLayout.radioButtonWidth; height: buttonsLayout.radioButtonHeight; text: "7" }
                MRadioButton { width: buttonsLayout.radioButtonWidth; height: buttonsLayout.radioButtonHeight; text: "8" }
                MRadioButton { width: buttonsLayout.radioButtonWidth; height: buttonsLayout.radioButtonHeight; text: "9" }
                MRadioButton { width: buttonsLayout.radioButtonWidth; height: buttonsLayout.radioButtonHeight; text: "*"; textColor: Style.colorAccent }
            }

            RowLayout {
                id: thirdRowLayout
                Layout.alignment: Qt.AlignCenter
                spacing: 8

                MRadioButton { width: buttonsLayout.radioButtonWidth; height: buttonsLayout.radioButtonHeight; text: "X^"; textColor: Style.colorAccent }
                MRadioButton { width: buttonsLayout.radioButtonWidth; height: buttonsLayout.radioButtonHeight; text: "4" }
                MRadioButton { width: buttonsLayout.radioButtonWidth; height: buttonsLayout.radioButtonHeight; text: "5" }
                MRadioButton { width: buttonsLayout.radioButtonWidth; height: buttonsLayout.radioButtonHeight; text: "6" }
                MRadioButton { width: buttonsLayout.radioButtonWidth; height: buttonsLayout.radioButtonHeight; text: "-"; textColor: Style.colorAccent }
            }

            RowLayout {
                id: fourthRowLayout
                Layout.alignment: Qt.AlignCenter
                spacing: 8

                MRadioButton { width: buttonsLayout.radioButtonWidth; height: buttonsLayout.radioButtonHeight; text: "sqrt"; textColor: Style.colorAccent }
                MRadioButton { width: buttonsLayout.radioButtonWidth; height: buttonsLayout.radioButtonHeight; text: "1" }
                MRadioButton { width: buttonsLayout.radioButtonWidth; height: buttonsLayout.radioButtonHeight; text: "2" }
                MRadioButton { width: buttonsLayout.radioButtonWidth; height: buttonsLayout.radioButtonHeight; text: "3" }
                MRadioButton { width: buttonsLayout.radioButtonWidth; height: buttonsLayout.radioButtonHeight; text: "+"; textColor: Style.colorAccent }
            }

            RowLayout {
                id: fifthRowLayout
                Layout.alignment: Qt.AlignCenter
                spacing: 8

                MRadioButton { width: buttonsLayout.radioButtonWidth; height: buttonsLayout.radioButtonHeight; text: "X"; textColor: Style.colorAccent }
                MRadioButton { width: buttonsLayout.radioButtonWidth; height: buttonsLayout.radioButtonHeight; text: "0" }
                MRadioButton { width: buttonsLayout.radioButtonWidth; height: buttonsLayout.radioButtonHeight; text: "." }
                MRadioButton { width: buttonsLayout.radioButtonWidth; height: buttonsLayout.radioButtonHeight; text: "b" }
                MRadioButton { width: buttonsLayout.radioButtonWidth; height: buttonsLayout.radioButtonHeight; text: "="; textColor: Style.colorMain; backgroundColor: Style.colorAccent }
            }

            Rectangle { height: 33; color: Style.colorMain } // Placeholder
        }
    }
}
