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
            Text {
                text: userObject.name
                color: "blue"
            }
        }
    }

    Component {
        id: homeListViewDelegate
        Row {
            spacing: 2
            /*Image {
                id: userImage
                source: "v"
            }*/
            Text {
                height: 40
                text: fbid
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
