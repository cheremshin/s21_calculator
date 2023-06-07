import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import S21Calculator.style


Item {
    id: root

    property bool active: false
    property bool currentlyHovered: mouseArea.containsMouse
    property bool currentlyPressed: mouseArea.pressed

    // Font
    property string topText
    property string leftText
    property string rightText
    property color activeTextColor: Style.colorAccent
    property color inactiveTextColor: Style.colorSwitchBackgroundText
    property int fontWeight: Font.Normal
    property double fontSize: 16

    // Color
    property color activeBackgroundColor: Style.colorMain
    property color inactiveBackgroundColor: Style.colorSwitchBackground

    // Border
    property int borderWidth: 1
    property color borderColor: Style.colorButtonCorner
    property color borderColorOnPressed: Style.colorButtonCorner
    property int radius: 50

    // Content
    property bool centerContentVertically: true
    property bool centerContentHorizontally: true

    // Position
    property int leftPosition: 0
    property int rightPosition: width / 2

    signal clicked()


    // Animation
    PropertyAnimation { id: animateRightSwitchRectangle; target: switchTop; properties: "x"; to: root.rightPosition; duration: 300 }
    PropertyAnimation { id: animateLeftSwitchRectangle; target: switchTop; properties: "x"; to: root.leftPosition; duration: 300 }
    PropertyAnimation { id: animateRightSwitchText; target: topTextLabel; properties: "text"; to: root.rightText; duration: 300 }
    PropertyAnimation { id: animateLeftSwitchText; target: topTextLabel; properties: "text"; to: root.leftText; duration: 300 }

    // View
    Rectangle {
        id: container
        anchors.fill: parent
        color: inactiveBackgroundColor
        border.width: root.borderWidth
        border.color: root.borderColor
        radius: root.radius
        antialiasing: true

        Rectangle {
            id: leftTextBox
            height: parent.height
            width: parent.width / 2
            color: root.inactiveBackgroundColor
            radius: root.radius

            Label {
                id: leftTextLabel
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter

                text: root.leftText
                color: root.inactiveTextColor
                font.pointSize: root.fontSize
            }
        }

        Rectangle {
            id: rightTextBox
            height: parent.height
            width: parent.width / 2
            anchors.left: leftTextBox.right;
            color: root.inactiveBackgroundColor
            radius: root.radius

            Label {
                id: rightTextLabel
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter

                text: root.rightText
                color: root.inactiveTextColor
                font.pointSize: root.fontSize
            }
        }

        Rectangle {
            id: switchTop
            width: parent.width / 2
            height: parent.height
            x: leftPosition
            color: root.activeBackgroundColor
            radius: root.radius

            Label {
                id: topTextLabel
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter

                text: root.leftText
                color: root.activeTextColor
                font.pointSize: root.fontSize
            }
        }

        MouseArea {
            id: mouseArea
            anchors.fill: parent
            hoverEnabled: true

            onClicked: {
                toggle();
                root.clicked();
            }
        }
    }

    function toggle() {
        if (root.active == false) {
            root.active = true;
            animateRightSwitchRectangle.start()
            animateRightSwitchText.start()
        } else {
            root.active = false;
            animateLeftSwitchRectangle.start()
            animateLeftSwitchText.start()
        }
    }
}