pragma Singleton
import QtQuick
import Qt.labs.settings


Item {
    id: styleSheet

    // Theme
    property color colorMain
    property color colorAccent
    property color colorBackground

    // Texts
    property color colorText
    property color colorTitle
    property color colorSecondaryTitle

    // Buttons
    property color colorFocusedButtonText
    property color colorUnfocusedButtonText

    // Corners
    property color colorButtonCorner
    property color colorAlternativeButtonCorner



    state: lastRunSettings.theme

    states: [
        State {
            name: "Light"

            // Theme
            PropertyChanges { target: styleSheet; colorMain: "#FFFFFF" }
            PropertyChanges { target: styleSheet; colorAccent: "#28D1D1" }
            PropertyChanges { target: styleSheet; colorBackground: "#F5F5F5" }

            // Texts
            PropertyChanges { target: styleSheet; colorText: "#8B8B8B" }
            PropertyChanges { target: styleSheet; colorTitle: "#565656" }
            PropertyChanges { target: styleSheet; colorSecondaryTitle: "#898989" }

            // Buttons

            // Corners
            PropertyChanges { target: styleSheet; colorButtonCorner: "#EBEBEB" }
            PropertyChanges { target: styleSheet; colorAlternativeButtonCorner: "#28BABA" }
        }
    ]

    Settings {
        id: lastRunSettings
        fileName: config + "/last_run_settings"

        property string theme: "Light"
    }

    Component.onDestruction: {
        lastRunSettings.theme = styleSheet.state
    }
}