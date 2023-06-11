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

        ColumnLayout {
            id: inputLayout
            anchors.fill: parent

            Rectangle {
                id: menuBox
                width: parent.width
                height: parent.height / 10 * 3

                MRadioButton {
                    width: 130
                    height: 30

                    x: 20
                    y: parent.height / 2 - height / 2

                    text: "Simple"
                    textColor: Style.colorTitle
                    fontSize: 14
                }
            }

            RowLayout {
                Layout.alignment: Qt.AlignRight

                ColumnLayout {
                    height: parent.height;
                    width: parent.width;

                    Rectangle { height: 36; width: parent.width; color: Style.colorMain }

                    Rectangle {
                        id: oldExpressionBlock

                        width: parent.width
                        height: 42

                        Label {
                            anchors.right: parent.right
                            
                            text: "273.5 + 57"
                            color: Style.colorSecondaryTitle
                            font.pointSize: 24
                        }
                    }

                    Rectangle {
                        id: newExpressionBlock
                        
                        width: parent.width
                        height: 60

                        Label {
                            anchors.right: parent.right

                            text: "330.5"
                            color: Style.colorAccent
                            font.pointSize: 30
                        }
                    }

                    Rectangle { height: 28; width: parent.width; color: Style.colorMain }
                }

                Rectangle { height: parent.height; width: 42; color: Style.colorMain }
            }
        }
    }

    Rectangle {
        id: buttonsBlock

        width: parent.width
        height: parent.height - inputBlock.height

        color: Style.colorBackground

        anchors.top: inputBlock.bottom

        MHeavySwitch {
            id: modeSwitch
            width: 288; height: 68
            y: 20; x: buttonsBlock.width / 2 - width / 2
            Layout.alignment: Qt.AlignCenter

            stackView: buttonsManager

            leftText: "Simple"
            leftPage: simpleButtons
            rightText: "Extra"
            rightPage: extraButtons
        }

        Rectangle {
            id: placeHolder
            height: 20
            color: Style.colorMain
            anchors.top: modeSwitch.bottom
        }



        StackView {
            id: buttonsManager
            width: parent.width
            height: parent.height - 133
            anchors.top: placeHolder.bottom
            initialItem: simpleButtons
        }

        Component {
            id: simpleButtons
            MSimpleButtons {
                width: buttonsManager.width
                height: buttonsManager.height
                backgroundColor: buttonsBlock.color
            }
        }

        Component {
            id: extraButtons
            MExtraButtons {
                width: buttonsManager.width
                height: buttonsManager.height
                backgroundColor: buttonsBlock.color
            }
        }
    }
}
