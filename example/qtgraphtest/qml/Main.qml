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
                    "https://graph.facebook.com/oauth/authorize?client_id=113759468684478&" +
                                                                                            "redirect_uri=http://www.facebook.com/connect/login_success.html&" +
                                                                                            "type=user_agent&display=touch"
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
            width: view.width; height: view.height
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
                    }
                }
            }
        }
    }

    Component {
        id: homeListViewDelegate
        Row {
            spacing: 10
            /*Image {
                id: userImage
                source: "v"
            }*/
            Text {
                height: 40
                text: "User id: " +  fromFbid
                font.bold: true
            }
            Text {
                height: 40
                text: fromName
                font.bold: false
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
