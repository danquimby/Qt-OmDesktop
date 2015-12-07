import QtQuick 2.1
import QtQuick.Controls 1.0
import QtQuick.Window 2.0

ApplicationWindow {
    id: applicationwindow1
    title: qsTr("Converter")
    width: 500
    height: 600
    ListView {
        id: view

        anchors.margins: 10
        anchors.fill: parent
        spacing: 10
        model: myModel
        highlightMoveDuration: 300
        clip: true

        highlight: Rectangle {
            color: "skyblue"
        }
        highlightFollowsCurrentItem: true

        delegate: Item {
            property var view: ListView.view
            property bool isCurrent: view.currentIndex == model.index

            width: view.width
            height: 40

            Rectangle {
                anchors.margins: 5
                anchors.fill: parent
                radius: height / 2
                color: "yellow" //model.color
                border {
                    color: "black"
                    width: 3
                }
                Image {
                    cache: false
                    id: idImage
                    source: "image://images/red"
                }
                Text {
                    anchors.centerIn: parent
                    renderType: Text.NativeRendering
                    text: "%1-%2 (%3)".arg(model.value).arg(model.value1).arg(isCurrent ? " * " : "")
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        console.log(model.index)
                        view.currentIndex = model.index
                        }
                }
            }
        }
    }
}
