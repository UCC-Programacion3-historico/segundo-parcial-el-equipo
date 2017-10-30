import QtQuick 2.6
import QtQuick.Window 2.2
import QtGraphicalEffects 1.0

Window {
    visible: true
    width: 1024
    height: 768

    //maximumHeight: height
    maximumWidth: width

    //minimumHeight: height
    minimumWidth: width

    title: qsTr("Mail Manager | PROGRAMACION III - PARCIAL 2")


    Rectangle {
        id: mailListContainer
        x: 0
        y: 0
        width: 347
        height: parent.height
        color: "#f8f5f5"
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.topMargin: 0
        anchors.top: parent.top
        layer.enabled: true
        layer.effect: DropShadow {
            transparentBorder: true
            horizontalOffset: 1
            verticalOffset: 0
            radius: 8.0
            color: "#80000000"

        }

        states: [
            State {
                name: 'addNewMail'

                PropertyChanges {
                    target: addMailBackgroundRectangle
                    opacity: 0.5
                }

                PropertyChanges {
                    target: addMailContainer
                    y: 768 - 400

                }

                PropertyChanges {
                    target: openCloseAddMailMenuImage
                    rotation: 180
                    source: "qrc:/img/ic_close_red_24px.svg"
                }

                PropertyChanges {
                    target: mailListView
                    enabled: false
                }

                PropertyChanges {
                    target: searchBoxContainer
                    enabled: false
                }

                PropertyChanges {
                    target: addMailButton
                    width: 25
                    height: 25
                    x: 10
                }

                PropertyChanges {
                    target: sendMailButton
                    enabled: true
                    opacity: 1
                }


            }
        ]

        transitions: [
            Transition {
                from: ""
                to: "addNewMail"
                //reversible: true

                ParallelAnimation {

                    NumberAnimation {
                        properties: "y, rotation"
                        easing {type: Easing.OutElastic; overshoot: 1; amplitude: 1; period: 0.7}
                        duration: 600
                    }

                    NumberAnimation {
                        properties: "x, opacity"
                        easing {type: Easing.Linear}
                        duration: 100
                    }

                    ScaleAnimator {
                        easing {type: Easing.Linear}
                        duration: 100
                    }
                }

            },
            Transition {
                from: "addNewMail"
                to: ""
                //reversible: true

                NumberAnimation {
                    properties: "y, opacity, rotation"
                    easing {type: Easing.OutCurve; overshoot: 100; }
                    duration: 200
                }

                ScaleAnimator {
                    easing {type: Easing.Linear}
                    duration: 200
                }

            }
        ]


        ListView {
            id: mailListView
            width: parent.width
            height: parent.height
            contentHeight: 0
            boundsBehavior: Flickable.DragAndOvershootBounds
            anchors.right: parent.right
            anchors.bottom: footer.top
            anchors.top: searchBoxContainer.bottom
            anchors.left: parent.left
            enabled: true
            model: ListModel {

                ListElement {
                    sender: "gabiparrello@gmail.com"
                    subject: "Algo va haciendo esto!"
                    readed: true
                    date: "28/10/17"
                    time: "21:47"
                }

                ListElement {
                    sender: "tuvieja@gmail.com"
                    subject: "Ponete una campera que esta fresco"
                    readed: true
                    date: "28/10/17"
                    time: "20:03"
                }

                ListElement {
                    sender: "marku@gmail.com"
                    subject: "El aulero para cuando muchachos"
                    readed: false
                    date: "12/07/17"
                    time: "14:40"
                }

                ListElement {
                    sender: "juanperez@gmail.com"
                    subject: "Ejemplo como siempre"
                    readed: false
                    date: "03/02/16"
                    time: "16:20"
                }
                ListElement {
                    sender: "gabiparrello@gmail.com"
                    subject: "Algo va haciendo esto!"
                    readed: false
                    date: "28/10/17"
                    time: "21:47"
                }

                ListElement {
                    sender: "tuvieja@gmail.com"
                    subject: "Ponete una campera que esta fresco"
                    readed: false
                    date: "28/10/17"
                    time: "20:03"
                }

                ListElement {
                    sender: "marku@gmail.com"
                    subject: "El aulero para cuando muchachos"
                    readed: false
                    date: "12/07/17"
                    time: "14:40"
                }

                ListElement {
                    sender: "juanperez@gmail.com"
                    subject: "Ejemplo como siempre"
                    readed: false
                    date: "03/02/16"
                    time: "16:20"
                }
                ListElement {
                    sender: "gabiparrello@gmail.com"
                    subject: "Algo va haciendo esto!"
                    readed: false
                    date: "28/10/17"
                    time: "21:47"
                }

                ListElement {
                    sender: "tuvieja@gmail.com"
                    subject: "Ponete una campera que esta fresco"
                    readed: true
                    date: "28/10/17"
                    time: "20:03"
                }

                ListElement {
                    sender: "marku@gmail.com"
                    subject: "El aulero para cuando muchachos"
                    readed: false
                    date: "12/07/17"
                    time: "14:40"
                }

                ListElement {
                    sender: "juanperez@gmail.com"
                    subject: "Ejemplo como siempre"
                    readed: false
                    date: "03/02/16"
                    time: "16:20"
                }
                ListElement {
                    sender: "gabiparrello@gmail.com"
                    subject: "Algo va haciendo esto!"
                    readed: false
                    date: "28/10/17"
                    time: "21:47"
                }

                ListElement {
                    sender: "tuvieja@gmail.com"
                    subject: "Ponete una campera que esta fresco"
                    readed: false
                    date: "28/10/17"
                    time: "20:03"
                }

                ListElement {
                    sender: "marku@gmail.com"
                    subject: "El aulero para cuando muchachos"
                    readed: false
                    date: "12/07/17"
                    time: "14:40"
                }

                ListElement {
                    sender: "juanperez@gmail.com"
                    subject: "Ejemplo como siempre"
                    readed: false
                    date: "03/02/16"
                    time: "16:20"
                }

            }
            delegate: Item {
                width: parent.width
                height: 70

                Rectangle {

                    width: parent.width
                    height: parent.height-1
                    anchors.verticalCenter: parent.verticalCenter
                    color: "#f8f5f5"

                    CustomBorder {

                        commonBorder: false
                        lBorderwidth: 0
                        rBorderwidth: 0
                        tBorderwidth: 0
                        bBorderwidth: 1
                        borderColor: "#eaeaea"
                    }

                    Rectangle {
                        id: readedDot
                        width: 10
                        height: 10
                        color: readed ? '#16aec0' : '#f8f5f5'
                        radius: 5
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: 15
                    }

                    Rectangle {

                        width: 245
                        height: childrenRect.height
                        color: "transparent"
                        //color: 'red'
                        anchors.left: readedDot.right
                        anchors.leftMargin: 15
                        anchors.verticalCenter: parent.verticalCenter

                        Text {
                            id: senderText
                            text: sender
                            font.pixelSize: 14
                            font.bold: true
                        }

                        Text {
                            text: subject
                            font.bold: false
                            color: '#616161'

                            anchors.top: senderText.bottom
                            anchors.topMargin: 3
                        }
                    }

                    Rectangle {

                        width: 100
                        height: childrenRect.height
                        color: "transparent"
                        //color: 'blue'
                        anchors.right: parent.right
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.rightMargin: 20

                        Text {
                            id: dateText
                            text: date
                            font.pixelSize: 10
                            color: '#212121'
                            anchors.right: parent.right
                        }

                        Text {
                            text: time
                            font.bold: false
                            font.pixelSize: 10
                            color: '#212121'
                            anchors.top: dateText.bottom
                            anchors.topMargin: 3
                            anchors.right: parent.right
                        }
                    }
                }
            }
        }


        Rectangle {
            id: searchBoxContainer
            x: 0
            y: 0
            width: 304
            height: 76
            color: "#ffffff"
            anchors.topMargin: 0
            anchors.top: parent.top
            anchors.rightMargin: 0
            anchors.leftMargin: 0
            anchors.right: parent.right
            anchors.left: parent.left
            enabled: true

            CustomBorder {

                commonBorder: false
                lBorderwidth: 0
                rBorderwidth: 0
                tBorderwidth: 0
                bBorderwidth: 2
                borderColor: "#bcbcbc"
            }



            Image {
                id: searchIcon
                x: 21
                y: 18
                width: 40
                height: 40
                fillMode: Image.Stretch
                source: "qrc:/img/search-icon.png"
            }

            TextInput {
                id: searchTextInput
                x: 67
                y: 29
                width: 235
                height: 18
                text: "Buscar"
                autoScroll: true
                cursorVisible: false
                renderType: Text.QtRendering
                topPadding: 0
                font.weight: Font.Light
                font.bold: false
                font.family: "Arial"
                color: "#4b4b4b"
                horizontalAlignment: Text.AlignLeft
                font.pixelSize: 15

                selectByMouse: true
                selectionColor: "#26C6DA"

                onFocusChanged: function() {
                    if (text.length > 0) {
                        if (focus) selectAll();
                    }
                    else {
                        text = "Buscar";
                    }
                }
            }

        }

        Rectangle {
            id: addMailBackgroundRectangle
            anchors.fill: parent
            color: "#000000"
            opacity: 0
        }

        Rectangle {
            id: addMailContainer
            x: 0
            y: 774
            width: 348
            height: 510
            color: "#ffffff"

            CustomBorder {

                commonBorder: false
                lBorderwidth: 0
                rBorderwidth: 0
                tBorderwidth: 4
                bBorderwidth: 0
                borderColor: "#00BCD4"
            }



            Rectangle {
                id: mailFromContainer
                anchors.top: parent.top
                width: parent.width
                height: 48
                color: "#ffffff"

                CustomBorder {

                    commonBorder: false
                    lBorderwidth: 0
                    rBorderwidth: 0
                    tBorderwidth: 0
                    bBorderwidth: 1
                    borderColor: "#bcbcbc"
                }

                Text {
                    id: mailFromLabel
                    x: 10
                    anchors.verticalCenter: parent.verticalCenter
                    color: "#4b4b4b"
                    text: qsTr("De")
                    font.pixelSize: 12
                }

                TextInput {
                    id: mailFromTextInput
                    leftPadding: mailFromLabel.width + 20
                    topPadding: 14
                    width: parent.width
                    height: parent.height
                    text: qsTr("")
                    font.pixelSize: 14

                    selectByMouse: true
                    selectionColor: "#26C6DA"

                    KeyNavigation.tab: mailToTextInput
                }
            }

            Rectangle {
                id: mailToContainer
                anchors.top: mailFromContainer.bottom
                anchors.topMargin: 1
                width: parent.width
                height: 48
                color: "#ffffff"

                CustomBorder {

                    commonBorder: false
                    lBorderwidth: 0
                    rBorderwidth: 0
                    tBorderwidth: 0
                    bBorderwidth: 1
                    borderColor: "#bcbcbc"
                }

                Text {
                    id: mailToLabel
                    x: 10
                    anchors.verticalCenter: parent.verticalCenter
                    color: "#4b4b4b"
                    text: qsTr("Para")
                    font.pixelSize: 12
                }

                TextInput {
                    id: mailToTextInput
                    leftPadding: mailToLabel.width + 20
                    topPadding: 14
                    width: parent.width
                    height: parent.height
                    text: qsTr("")
                    font.pixelSize: 14

                    selectByMouse: true
                    selectionColor: "#26C6DA"

                    KeyNavigation.tab: subjectTextInput
                    KeyNavigation.backtab: mailFromTextInput
                }
            }

            Rectangle {
                id: subjectContainer
                anchors.top: mailToContainer.bottom
                anchors.topMargin: 1
                width: parent.width
                height: 48
                color: "#ffffff"

                CustomBorder {

                    commonBorder: false
                    lBorderwidth: 0
                    rBorderwidth: 0
                    tBorderwidth: 0
                    bBorderwidth: 1
                    borderColor: "#bcbcbc"
                }

                Text {
                    id: subjectLabel
                    x: 10
                    anchors.verticalCenter: parent.verticalCenter
                    color: "#4b4b4b"
                    text: qsTr("Asunto")
                    font.pixelSize: 12
                }

                TextInput {
                    id: subjectTextInput
                    leftPadding: subjectLabel.width + 20
                    topPadding: 14
                    width: parent.width
                    height: parent.height
                    text: qsTr("")
                    horizontalAlignment: Text.AlignLeft
                    font.pixelSize: 14

                    selectByMouse: true
                    selectionColor: "#26C6DA"

                    KeyNavigation.tab: mailBodyTextEdit
                    KeyNavigation.backtab: mailToTextInput
                }
            }

            Text {
                id: mailBodyLabel
                x: 10
                anchors.top: subjectContainer.bottom
                anchors.topMargin: 10
                color: "#4b4b4b"
                text: qsTr("Mensaje")
                font.pixelSize: 12
            }

            TextEdit {
                id: mailBodyTextEdit
                width: parent.width
                anchors.top: subjectContainer.bottom
                anchors.bottom: parent.bottom
                leftPadding: 10
                topPadding: 33
                font.pixelSize: 12


                selectByMouse: true
                selectByKeyboard: true
                selectionColor: "#26C6DA"

                //KeyNavigation.tab:
                KeyNavigation.backtab: subjectTextInput
            }
        }

        Rectangle {
            id: footer
            anchors.left: parent.left
            anchors.bottom: parent.bottom
            width: parent.width
            height: 42
            color: "#ffffff"

            CustomBorder {

                commonBorder: false
                lBorderwidth: 0
                rBorderwidth: 0
                tBorderwidth: 2
                bBorderwidth: 0
                borderColor: "#bcbcbc"

            }

            Rectangle {
                id: addMailButton
                x: 12
                anchors.verticalCenter: parent.verticalCenter
                width: 20
                height: 20
                color: "#ffffff"
                radius: 7

                MouseArea {
                    id: addMailMouseArea
                    anchors.fill: parent

                    onClicked: {

                        mailListContainer.state = mailListContainer.state === "addNewMail" ? "" : "addNewMail"
                        mailFromTextInput.forceActiveFocus()

                    }
                }

                Image {
                    id: openCloseAddMailMenuImage
                    smooth: false
                    fillMode: Image.PreserveAspectFit
                    anchors.fill: parent
                    source: "qrc:/img/ic_close_lightblue_24px.svg"
                    rotation: 45
                }
            }

            Rectangle {

                id: sendMailButton
                anchors.right: parent.right
                anchors.rightMargin: 10
                anchors.verticalCenter: parent.verticalCenter
                width: 54
                height: 28
                enabled: false
                opacity: 0

                MouseArea {

                    id: sendMailMouseArea
                    anchors.fill: parent

                    onClicked: {

                        mailListContainer.state = ""

                        mailFromTextInput.text = ""
                        mailToTextInput.text = ""
                        subjectTextInput.text = ""
                        mailBodyTextEdit.text = ""
                    }
                }

                Text {
                    id: sendMailLabel
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    color: "#00acc1"
                    text: qsTr("Enviar")
                    font.bold: true
                    font.pixelSize: 14
                }
            }
        }
    }
}

