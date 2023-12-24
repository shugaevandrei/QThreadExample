import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import MainThread 1.0

Window {
    width: 160
    height: 80
    visible: true
    title: qsTr("threader")
    RowLayout {
        anchors.fill: parent
        Button {
            Layout.fillWidth: true
            text: "start"
            onClicked: thr.start()
        }
        Button {
            Layout.fillWidth: true
            text: "stop"
            onClicked: thr.stop()
        }
    }
    MainThread {
        id: thr
    }
}
