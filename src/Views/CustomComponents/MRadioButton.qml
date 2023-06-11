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
    property string text
    property color textColor: Style.colorText
    property int fontWeight: Font.Normal
    property double fontSize: 20

    // Color
    property color backgroundColor: Style.colorMain
    property double opacityOnPressed: 0.8

    // Border
    property int borderWidth: 1
    property color borderColor: Style.colorButtonCorner
    property color borderColorOnPressed: Style.colorButtonCorner
    property int radius: 35

    // Content
    property bool centerContentVertically: true
    property bool centerContentHorizontally: true

    signal clicked()

    // Animation
    states: State {
        name: "clicked"; when: mouseArea.pressed
        PropertyChanges { target: container; color: Style.colorAccent }
        PropertyChanges { target: container; border.color: root.borderColorOnPressed }
        PropertyChanges { target: buttonText; color: Style.colorMain }
    }

    transitions: Transition {
        from: ""; to: "clicked"; reversible: true
        ParallelAnimation {
            ColorAnimation { duration: 100 }
        }
    }


    // View
    Rectangle {
        id: container
        anchors.fill: parent
        color: root.backgroundColor
        border.width: root.borderWidth
        border.color: root.borderColor
        radius: root.radius
        opacity: mouseArea.pressed ? root.opacityOnPressed : 1
        antialiasing: true


        Label {
            id: buttonText
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            Layout.preferredWidth: container.width

            visible: text.length > 0
            text: root.text
            font.weight: root.fontWeight
            font.pointSize: root.fontSize
            color: root.textColor
        }

        MouseArea {
            id: mouseArea
            anchors.fill: parent
            hoverEnabled: true

            onClicked: root.clicked()
        }
    }
}
