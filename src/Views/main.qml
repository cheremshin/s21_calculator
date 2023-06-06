import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window

import SimpleCalculator


ApplicationWindow {
    id: baseRoot
    property int defaultWidth:  455
    property int defaultHeight: 770



    maximumWidth:  defaultWidth
    maximumHeight: defaultHeight

    minimumWidth:  defaultWidth
    minimumHeight: defaultHeight

    visible: true
    title: qsTr("Calculator")


    StackView {
        id: pageManager
        anchors.fill : parent
        initialItem: simpleCalculator
    }

    
    // Pages
    Component { id: simpleCalculator; MSimpleCalculator {} }
}