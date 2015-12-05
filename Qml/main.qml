import QtQuick 2.1
import QtQuick.Controls 1.0
import QtQuick.Window 2.0

ApplicationWindow {
    id: applicationwindow1
    title: qsTr("Converter")
    width: 500
    height: 600
//    menuBar: MenuBar {
  //  }


    Rectangle {
        width: 360
        height: 360

        ListModel {
            id: dataModel

            ListElement {
                color: "orange"
                text: "first"
                descr: "denis"
            }
            ListElement {
                color: "lightgreen"
                text: "second"
                descr: "artem"
            }
            ListElement {
                color: "orchid"
                text: "third"
            }
            ListElement {
                color: "tomato"
                text: "fourth"
                descr: "fedeor"
            }
        }

        ListView {
            id: view

            anchors.margins: 10
            anchors.fill: parent
            spacing: 10
            model: dataModel
            clip: true

            highlight: Rectangle {
                color: "skyblue"
            }
            highlightFollowsCurrentItem: true

            delegate: Item {
                property var view: ListView.view
                property var isCurrent: ListView.isCurrentItem

                width: view.width
                height: 40

                Rectangle {
                    anchors.margins: 5
                    anchors.fill: parent
                    radius: height / 2
                    color: model.color
                    border {
                        color: "black"
                        width: 3
                    }

                    Text {
                        anchors.centerIn: parent
                        renderType: Text.NativeRendering
                        text: "%1%2(%3)".arg(model.text).arg(isCurrent ? " * " : "").arg(model.descr)
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

}
