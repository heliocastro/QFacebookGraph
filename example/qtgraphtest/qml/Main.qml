import Qt 4.7
import QtWebKit 1.0


Rectangle {

    /*-----------------------------------------------------------------------------*/

    width : 864
    height : 480
    color : 'white'

    /*-----------------------------------------------------------------------------*/

    Keys.onPressed : {
        if ( event.key == Qt.Key_Q ) {
            Qt.quit()
        }
    }

    focus : true

    /*-----------------------------------------------------------------------------*/

    WebView {
                id: "qtGraphTest"
                url: "https://graph.facebook.com/oauth/authorize?client_id=113759468684478&" +
                "redirect_uri=http://www.facebook.com/connect/login_success.html&" +
                     "type=user_agent&display=touch"
                anchors.fill: parent
                onLoadFinished: {
                    test.testUrl( url )
                    //console.log( url )
                    //console.log( "---- FINISH ----" )
                }
    }

    /*-----------------------------------------------------------------------------*/

}
