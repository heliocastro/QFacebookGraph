import Qt 4.7
import QtWebKit 1.0


Rectangle {
    id: mainWindow
    color: "gray"
    width : 864
    height : 480

    Keys.onPressed : {
        if ( event.key == Qt.Key_Q ) {
            Qt.quit()
        }
    }


    VisualItemModel {
        id: itemModel


        WebView {
            id: loginWebView
            width: view.width; height: view.height
            url: {
                if( !test.hasValidToken() )
                {
                    loginUrlAccess
                }
                else
                {
                    view.currentIndex = 1
                    "file:///tmp"
                }
            }
            onLoadFinished: {
                test.testUrl( url )
                if( test.hasValidToken() ) {
                    view.currentIndex = 1
                }
            }
            onLoadFailed: {
                test.testUrl( url )
            }
        }

        ListView {
            id: homeListView
            width: view.width; height: view.height - 30
            model: homeModel
            delegate: homeListViewDelegate
        }

        Rectangle {
            id: userListView
            width: view.width; height: view.height
            color:  "white"
            Column {
                spacing: 4
                Rectangle {
                    width: view.width
                    height: 30
                    border.width: 1
                    border.color: "gray"
                    Text {
                        text: "About me"
                        font.bold: true
                        anchors { left: parent.left; leftMargin: 4; verticalCenter: parent.verticalCenter }
                    }
                }

                Row {
                    spacing: 10

                    Text {
                        width: 100
                        text: "Basic Information"
                        color: "gray"
                        font.bold: true
                    }
                    Column {
                        spacing: 20
                        Row {
                            spacing: 2
                            Text {
                                width: 100
                                text: "Gender:"
                                font.weight: Font.Light
                                color: "gray"
                            }
                            Text {
                                text: userObject.gender
                            }
                        }
                        Row {
                            Text {
                                width: 100
                                text: "Birth date:"
                                font.weight: Font.Light
                                color: "gray"
                            }
                            Text {
                                text: userObject.birthday
                            }
                        }
                        ListView {
                            width: 200
                            height: 100
                            model: userEducationModel
                            delegate:
                                Column {
                                spacing: 2
                                Text { font.bold: true; text: school.name  }
                                Text { text: year.name }
                                Text { text: type }
                            }
                        }
                        ListView {
                            width: 200
                            height: 100
                            model: userWorkModel
                            delegate:
                                Column {
                                spacing: 2
                                Text { font.bold: true; text: employer.name  }
                                Text { text: position.name }
                                Text { text: description }
                            }
                        }
                    }
                }
            }
        }
    }

    Component {
        id: homeListViewDelegate
        Rectangle {
            id: listItem
            border.color: "black"
            border.width: 2
            radius: 10
            color: "white"
            height: 110; width: view.width

            Row {
                spacing: 10
                Rectangle {
                    width: 75; height: 75
                    color: "transparent"
                    Image {
                        id: userImage
                        anchors { left: parent.left; leftMargin: 10; verticalCenter: parent.verticalCenter }
                        source: "http://graph.facebook.com/" + from.id + "/picture"
                    }
                }
                Column {
                    Row {
                        spacing: 10
                        Text {
                            height: 30
                            text: "User id: "
                            font.bold: true
                        }
                        Text {
                            height: 30
                            text: from.name
                            font.bold: false
                        }
                    }
                    Text {
                        height: 50
                        width: view.width - 100
                        wrapMode: Text.WordWrap
                        text: message
                    }
                }
            }
        }
    }

    ListView {
        id: view
        anchors { fill: parent; bottomMargin: 30 }
        model: itemModel
        preferredHighlightBegin: 0; preferredHighlightEnd: 0
        highlightRangeMode: ListView.StrictlyEnforceRange
        orientation: ListView.Horizontal
        snapMode: ListView.SnapOneItem; flickDeceleration: 2000
    }
}
