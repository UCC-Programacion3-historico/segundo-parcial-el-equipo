import QtQuick 2.6
import QtQuick.Window 2.2
import QtGraphicalEffects 1.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.1

Window {
    visible: true
    width: 1024
    height: 768

    minimumHeight: 500
    minimumWidth: 700

    title: qsTr("Mail Manager | PROGRAMACION III - PARCIAL 2")


    // SIGNAL FUNCTIONS

    signal addNewMailQMLSignal(string from, string to, string date, string subject, string content, bool sortedByDate);


    // SLOT FUNCTIONS

    function clearListQMLSlot() {
        mailListModel.clear()
    }

    function updateListQMLSlot(id, from, to, date, subject, content, isRead) {

        var year = date.substring(0, 4);
        var month = date.substring(5, 7);
        var day = date.substring(8, 10);

        //var m_date = date.substring(0, 10);

        var m_time = date.substring(11, date.length);

        mailListModel.append({
                        ID: id,
                        sender: from,
                        to: to,
                        subject: subject,
                        readed: isRead,
                        date: day+"/"+month+"/"+year,
                        time: m_time,
                        content: content
                    });
    }


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

        Shortcut {

            sequence: "Ctrl+n"
            onActivated: {
                mailListContainer.state = 'addNewMail'
                mailFromTextInput.forceActiveFocus()
            }
        }



        states: [
            State {
                name: 'addNewMail'


                PropertyChanges {
                    target: addMailBackgroundRectangle
                    opacity: 0.5
                    enabled: true
                }


                PropertyChanges {
                    target: addMailContainer
                    anchors.topMargin: -400

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

                PropertyChanges {
                    target: timeDateButton
                    enabled: true
                    opacity: 1
                }

                PropertyChanges {
                    target: sendMailFooter
                    opacity: 1
                    visible: true

                }
            },
            State {
                name: 'setTimeDate'

                PropertyChanges {
                    target: setTimeDateContainer
                    anchors.topMargin: -420
                }

                PropertyChanges {

                    target: dateLabel
                    color: setTimeDateContainer.state === 'setTime' ? "#546E7A" : 'red'
                }

                PropertyChanges {

                    target: timeLabel
                    color: setTimeDateContainer.state === 'setTime' ? "red" : "#546E7A"
                }

                PropertyChanges {
                    target: setDateTimeBackgroundRectangle
                    opacity: 0.25
                    enabled: true
                }

                PropertyChanges {
                    target: mailFromContainer
                    enabled: false

                }

                PropertyChanges {
                    target: mailToContainer
                    enabled: false

                }

                PropertyChanges {
                    target: addMailBackgroundRectangle
                    opacity: 0.5
                    enabled: true
                }

                PropertyChanges {
                    target: addMailContainer
                    anchors.topMargin: -400

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

                PropertyChanges {
                    target: timeDateButton
                    enabled: true
                    opacity: 1
                }

                PropertyChanges {
                    target: sendMailFooter
                    opacity: 1
                    visible: true

                }


            },
            State {
                name: "setMailsInterval"
                PropertyChanges {
                    target: setMailsIntervalContainer
                    anchors.topMargin: -310
                }

                PropertyChanges {
                    target: addMailBackgroundRectangle
                    opacity: 0.5
                    enabled: true
                }

                PropertyChanges {
                    target: mailListView
                    enabled: false
                }

                PropertyChanges {
                    target: sendMailFooter
                    opacity: 0
                    visible: false

                }
            }
        ]

        transitions: [
            Transition {
                from: ""
                to: "addNewMail"

                ParallelAnimation {

                    NumberAnimation {
                        properties: "anchors.topMargin, rotation"
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

                NumberAnimation {
                    properties: "anchors.topMargin, x, opacity, rotation"
                    easing {type: Easing.OutCurve; overshoot: 100; }
                    duration: 200
                }

                ScaleAnimator {
                    easing {type: Easing.Linear}
                    duration: 200
                }
            },
            Transition {
                from: "addNewMail"
                to: "setTimeDate"

                ParallelAnimation {

                    NumberAnimation {
                        properties: "anchors.topMargin, opacity"
                        easing {type: Easing.OutExpo; overshoot: 100;}
                        duration: 400
                    }


                    ColorAnimation {
                        duration: 200
                    }
                }

            },
            Transition {
                from: "setTimeDate"
                to: "addNewMail"

                ParallelAnimation {

                    NumberAnimation {
                        properties: "anchors.topMargin, opacity"
                        easing {type: Easing.InExpo; overshoot: 100}
                        duration: 400
                    }


                    ColorAnimation {
                        duration: 200
                    }
                }

            },
            Transition {
                from: "setTimeDate"
                to: ""

                NumberAnimation {
                    properties: "anchors.topMargin, x, opacity, rotation"
                    easing {type: Easing.OutCurve; overshoot: 100; }
                    duration: 200
                }

                ScaleAnimator {
                    easing {type: Easing.Linear}
                    duration: 200
                }

                ColorAnimation {
                    duration: 200
                }
            },
            Transition {
                from: ""
                to: "setMailsInterval"

                ParallelAnimation {

                    NumberAnimation {
                        properties: "anchors.topMargin, opacity"
                        easing {type: Easing.OutExpo; overshoot: 100;}
                        duration: 400
                    }


                    ColorAnimation {
                        duration: 200
                    }
                }
            },
            Transition {
                from: "setMailsInterval"
                to: ""

                ParallelAnimation {

                    NumberAnimation {
                        properties: "anchors.topMargin, opacity"
                        easing {type: Easing.InExpo; overshoot: 100;}
                        duration: 400
                    }


                    ColorAnimation {
                        duration: 200
                    }
                }

                onRunningChanged: {
                    if ((mailListContainer.state == "") && (!running)) {
                        setMailsIntervalContainer.state = "firstOfInterval"
                    }
                }
            },
            Transition {
                from: "*"
                to: "addNewMail"

                SequentialAnimation {

                    NumberAnimation {
                        target: setMailsIntervalContainer
                        properties: "anchors.topMargin, opacity"
                        easing {type: Easing.InExpo; overshoot: 100;}
                        duration: 400
                    }
                    NumberAnimation {
                        target: addMailContainer
                        properties: "anchors.topMargin, rotation"
                        easing {type: Easing.OutElastic; overshoot: 1; amplitude: 1; period: 0.7}
                        duration: 600
                    }
                }

                onRunningChanged: {
                    if ((mailListContainer.state == "addNewMail") && (!running)) {
                        setMailsIntervalContainer.state = "firstOfInterval"
                    }
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

                id: mailListModel

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
                    readed: true
                    date: "12/07/17"
                    time: "14:40"
                }

                ListElement {
                    sender: "juanperez@gmail.com"
                    subject: "Ejemplo como siempre"
                    readed: true
                    date: "03/02/16"
                    time: "16:20"
                }
                ListElement {
                    sender: "gabiparrello@gmail.com"
                    subject: "Algo va haciendo esto!"
                    readed: true
                    date: "28/10/17"
                    time: "21:47"
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
                        color: readed ? '#f8f5f5' : '#16aec0'
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
            enabled: false

            MouseArea {
                anchors.fill: parent
                onClicked: mailListContainer.state === "setTimeDate" ? mailListContainer.state = "addNewMail" : mailListContainer.state = ""
            }
        }

        Rectangle {
            id: addMailContainer
            anchors.left: parent.left
            anchors.top: parent.bottom
            width: 348
            height: 510
            enabled: true
            color: "#ffffff"

            Keys.onReturnPressed: {

                if (mailListContainer.state === 'addNewMail') sendMailButton.sendEmail()
            }

            Keys.onEscapePressed: mailListContainer.state = ''

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

                enabled: true

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.IBeamCursor
                }

                CustomBorder {

                    id: mailFromContainerBorder
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
                    KeyNavigation.down: mailToTextInput
                }
            }

            Rectangle {
                id: mailToContainer
                anchors.top: mailFromContainer.bottom
                anchors.topMargin: 1
                width: parent.width
                height: 48
                color: "#ffffff"

                enabled: true

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.IBeamCursor
                }

                CustomBorder {

                    id: mailToContainerBorder
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

                    KeyNavigation.down: subjectTextInput
                    KeyNavigation.up: mailFromTextInput
                }
            }

            Rectangle {
                id: subjectContainer
                anchors.top: mailToContainer.bottom
                anchors.topMargin: 1
                width: parent.width
                height: 48
                color: "#ffffff"

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.IBeamCursor
                }

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

                    KeyNavigation.up: mailToTextInput
                    KeyNavigation.down: mailBodyTextEdit
                }
            }

            MouseArea {
                anchors.fill: mailBodyTextEdit
                cursorShape: Qt.IBeamCursor
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

                KeyNavigation.up: subjectTextInput
            }

            Rectangle {

                id: setDateTimeBackgroundRectangle
                anchors.fill: parent
                color: 'black'
                opacity: 0
                enabled: false

                MouseArea {
                    anchors.fill: parent
                    onClicked: mailListContainer.state = 'addNewMail'
                }
            }

            Rectangle {
                id: setTimeDateContainer
                anchors.left: parent.left
                anchors.top: parent.bottom
                anchors.topMargin: 0
                width: parent.width
                height: 270
                color: "#ffffff"

                Keys.onReturnPressed: {
                    sendMailButton.sendEmail()
                }

                Keys.onEscapePressed: mailListContainer.state = 'addNewMail'

                states: [
                    State {
                        name: "setTime"
                        PropertyChanges {
                            target: setTimeContainer
                            opacity: 1
                            enabled: true
                        }
                    }
                ]

                transitions: [
                    Transition {
                        from: ""
                        to: "setTime"

                        NumberAnimation {
                            id: toSetTimeTransition
                            properties: 'opacity'
                            easing {type: Easing.InExpo; overshoot: 100}
                            duration: 400
                        }
                    },
                    Transition {
                        from: "setTime"
                        to: ""

                        NumberAnimation {
                            id: toAddMailTransition
                            properties: 'opacity'
                            easing {type: Easing.InExpo; overshoot: 100}
                            duration: 350
                        }
                    }
                ]

                CustomBorder {

                    commonBorder: false
                    lBorderwidth: 0
                    rBorderwidth: 0
                    tBorderwidth: 2
                    bBorderwidth: 0
                    borderColor: "#607D8B"
                }

                MouseArea {
                    anchors.fill: parent
                }

                Calendar {
                    id: calendar

                    anchors.fill: parent

                    onClicked: {

                        setTimeDateContainer.state = 'setTime'       //Qt.platform.os === "osx" ?
                        dateLabel.text = Qt.formatDate(calendar.selectedDate, "dd-MM-yyyy")
                        dateLabel.width = 70
                    }

                    style: CalendarStyle {
                        gridVisible: false
                        dayDelegate: Item {
                            readonly property color sameMonthDateTextColor: "#444"
                            readonly property color selectedDateColor: Qt.platform.os === "osx" ? "#26C6DA" : systemPalette.highlight
                            readonly property color selectedDateTextColor: "white"
                            readonly property color differentMonthDateTextColor: "#bbb"
                            readonly property color invalidDatecolor: "#dddddd"

                            Rectangle {
                                id: possibleSelected

                                width: parent.height
                                height: parent.height
                                anchors.centerIn: parent
                                border.color: "transparent"
                                color: styleData.date !== undefined && styleData.selected ? selectedDateColor : "transparent"
                                anchors.margins: styleData.selected ? -1 : 0
                                radius: height/2
                            }


                            Label {
                                id: dayDelegateText
                                text: styleData.date.getDate()
                                anchors.centerIn: parent
                                color: {
                                    var color = invalidDatecolor;
                                    if (styleData.valid) {
                                        // Date is within the valid range.
                                        color = styleData.visibleMonth ? sameMonthDateTextColor : differentMonthDateTextColor;
                                        if (styleData.selected) {
                                            color = selectedDateTextColor;
                                        }
                                    }
                                    color;
                                }
                            }
                        }
                    }
                }

                Rectangle {

                    id: setTimeContainer

                    anchors.fill: parent
                    color: "#26C6DA"

                    opacity: 0
                    enabled: false

                    MouseArea {
                        anchors.fill: parent
                    }

                    Rectangle {

                        width: parent.width
                        height: 45
                        anchors.top: parent.top

                        color: "#10000000"

                        /*CustomBorder {
                            lBorderwidth: 0
                            rBorderwidth: 0
                            tBorderwidth: 0
                            bBorderwidth: 1

                            borderColor: "#80000000"
                        }*/
                    }

                    Text {
                        anchors.top: parent.top
                        anchors.topMargin: 15
                        anchors.horizontalCenter: parent.horizontalCenter
                        color: 'white'

                        text: "HORA"

                        font.pixelSize: 15
                        font.bold: true

                    }


                    Rectangle {

                        anchors.left: parent.left
                        anchors.top: parent.top

                        height: 45
                        width: height

                        color: setTimeBackArrowMouseArea.containsMouse ? "#08000000" : 'transparent'


                        MouseArea {

                            id: setTimeBackArrowMouseArea

                            anchors.fill: parent
                            hoverEnabled: true
                            onClicked: setTimeDateContainer.state = ''
                        }


                        Image {
                            id: setTimeBackArrowImage

                            width: 25
                            height: width
                            smooth: true
                            fillMode: Image.PreserveAspectFit
                            anchors.centerIn:parent
                            source: "qrc:/img/ic_arrow_back_white_24px.svg"
                        }
                    }

                    Rectangle {

                        anchors.top: parent.top
                        anchors.right: parent.right

                        width: 45
                        height: width

                        color: closeSetDateTimeBackArrowMouseArea.containsMouse ? "#08000000" : 'transparent'


                        MouseArea {

                            id: closeSetDateTimeBackArrowMouseArea

                            anchors.fill: parent
                            hoverEnabled: true

                            onClicked: mailListContainer.state = "addNewMail"
                        }


                        Image {
                            id: closeSetDateTimeBackArrowImage
                            smooth: true
                            fillMode: Image.PreserveAspectFit
                            anchors.centerIn: parent
                            width: 25
                            height: width
                            source: "qrc:/img/ic_keyboard_arrow_down_white_24px.svg"
                        }
                    }


                    TimePicker {
                        id: timePicker
                        anchors.centerIn: parent
                        anchors.verticalCenterOffset: 15
                        width: parent.width * 0.8
                        height: parent.height * 0.6

                        linesColor: '#90FFFFFF'
                        selectedItemColor: '#FFFFFF'
                        nonSelectedItemsColor: "#60FFFFFF"
                    }
                }
            }
        }

        Rectangle {
            id: setMailsIntervalContainer

            width: parent.width
            height: 310

            anchors.top: footer.top

            state: "firstOfInterval"

            property date firstOfIntervalDate: new Date()
            property date lastOfIntervalDate: new Date()
            property bool siempreSelected: true

            function getIntDate(date) {
                return date.getFullYear() + date.getMonth() * 10000 + date.getDate() * 1000000;
            }

            function isToday(date) {

                const currentDate = new Date();

                return getIntDate(date) === getIntDate(currentDate);
            }

            function compareDates(date1, date2) {

                /* Esta funcion sirve para comparar fechas
                 *
                 *      Devuelve:
                 *      0 cuando son IGUALES
                 *      1 cuando la primera es MAYOR que la segunda
                 *     -1 cuando la primera es MENOR que la segunda
                 *
                 */

                var result;
                if (date1.getFullYear() === date2.getFullYear()) {
                    if (date1.getMonth() === date2.getMonth()) {
                        if (date1.getDate() === date2.getDate()) result = 0;
                        else if (date1.getDate() > date2.getDate()) result = 1;
                        else result = -1;
                    }
                    else if (date1.getMonth() > date2.getMonth()) result = 1;
                    else result = -1;
                }
                else if (date1.getFullYear() > date2.getFullYear()) result = 1;
                else result = -1;

                return result;
            }

            function setMailsInterval() {
                const firstOfIntervalDay = firstOfIntervalDate.getDate();
                const firstOfIntervalMonth = firstOfIntervalDate.getMonth();
                const firstOfIntervalYear = firstOfIntervalDate.getFullYear();

                const lastOfIntervalDay = lastOfIntervalDate.getDate();
                const lastOfIntervalMonth = lastOfIntervalDate.getMonth();
                const lastOfIntervalYear = lastOfIntervalDate.getFullYear();

                const currentDate = new Date();

                if (isToday(firstOfIntervalDate) && siempreSelected) setSinceToLabel.text = "TODOS";
                else if (compareDates(firstOfIntervalDate, lastOfIntervalDate) === 0) {

                    if (isToday(firstOfIntervalDate)) setSinceToLabel.text = "HOY";
                    else if (firstOfIntervalYear === currentDate.getFullYear()) setSinceToLabel.text = Qt.formatDate(firstOfIntervalDate, "ddd, dd 'de' MMMM");
                    else setSinceToLabel.text = Qt.formatDate(firstOfIntervalDate, "dd 'de' MMMM 'de' yyyy");

                }
                else if (compareDates(firstOfIntervalDate, lastOfIntervalDate) > 0) {

                    if (firstOfIntervalYear === currentDate.getFullYear() && lastOfIntervalYear === currentDate.getFullYear()) {

                        if (isToday(firstOfIntervalDate))
                            setSinceToLabel.text = "Desde HOY" + " hasta el " + Qt.formatDate(lastOfIntervalDate, "dd/MM");
                        else if (siempreSelected)
                            setSinceToLabel.text = "Desde el " + Qt.formatDate(firstOfIntervalDate, "dd/MM") + " hasta SIEMPRE";
                        else
                         setSinceToLabel.text = "Desde el " + Qt.formatDate(firstOfIntervalDate, "dd/MM") + " hasta el " + Qt.formatDate(lastOfIntervalDate, "dd/MM");
                    }
                    else {

                        if (isToday(firstOfIntervalDate))
                            setSinceToLabel.text = "Desde HOY" + " hasta el " + Qt.formatDate(lastOfIntervalDate, "dd/MM/yy");
                        else if (siempreSelected)
                            setSinceToLabel.text = "Desde el " + Qt.formatDate(firstOfIntervalDate, "dd/MM/yy") + " hasta SIEMPRE ";
                        else
                            setSinceToLabel.text = "Desde el " + Qt.formatDate(firstOfIntervalDate, "dd/MM/yy") + " hasta el " + Qt.formatDate(lastOfIntervalDate, "dd/MM/yy");
                    }
                }
                else {

                    if (firstOfIntervalYear === currentDate.getFullYear() && lastOfIntervalYear === currentDate.getFullYear()) {

                        if (siempreSelected)
                            setSinceToLabel.text = "Desde el " + Qt.formatDate(firstOfIntervalDate, "dd/MM") + " hasta SIEMPRE";
                        else if (isToday(firstOfIntervalDate))
                            setSinceToLabel.text = "Desde HOY" + " hasta el " + Qt.formatDate(firstOfIntervalDate, "dd/MM");
                        else
                         setSinceToLabel.text = "Desde el " + Qt.formatDate(lastOfIntervalDate, "dd/MM") + " hasta el " + Qt.formatDate(firstOfIntervalDate, "dd/MM");
                    }
                    else {

                        if (siempreSelected)
                            setSinceToLabel.text = "Desde el " + Qt.formatDate(lastOfIntervalDate, "dd/MM/yy") + " hasta SIEMPRE ";
                        else if (isToday(firstOfIntervalDate))
                            setSinceToLabel.text = "Desde HOY" + " hasta el " + Qt.formatDate(firstOfIntervalDate, "dd/MM/yy");
                        else
                            setSinceToLabel.text = "Desde el " + Qt.formatDate(lastOfIntervalDate, "dd/MM/yy") + " hasta el " + Qt.formatDate(firstOfIntervalDate, "dd/MM/yy");
                    }
                }

            }

            CustomBorder {

                commonBorder: false
                lBorderwidth: 0
                rBorderwidth: 0
                tBorderwidth: 2
                bBorderwidth: 0
                borderColor: "#607D8B"

            }

            MouseArea {
                anchors.fill: parent
            }

            states: [
                State {
                    name: "firstOfInterval"

                    PropertyChanges {
                        target: setMailsIntervalContainerHeaderTitle
                        text: "DESDE"
                    }

                    PropertyChanges {
                        target: setMailsIntervalContainerHeaderButtonText
                        text: "Hoy"
                    }

                    PropertyChanges {
                        target: setIntervalCalendar
                        selectedDate: setMailsIntervalContainer.firstOfIntervalDate
                    }

                    PropertyChanges {
                        target: setMailsIntervalContainerHeaderButton
                        width: 45
                    }
                },
                State {
                    name: "lastOfInterval"

                    PropertyChanges {
                        target: setMailsIntervalContainerHeaderTitle
                        text: "HASTA"
                    }

                    PropertyChanges {
                        target: setMailsIntervalContainerHeaderButtonText
                        text: "Siempre"
                    }

                    PropertyChanges {
                        target: setIntervalCalendar
                        selectedDate: setMailsIntervalContainer.lastOfIntervalDate
                    }

                    PropertyChanges {
                        target: setMailsIntervalContainerHeaderButton
                        width: 75
                    }
                }
            ]

            Rectangle {
                id: setMailsIntervalContainerHeader

                width: parent.width
                height: 40

                color: "white"

                Rectangle {

                    width: parent.width / 3
                    height: parent.height

                    color: "#607D8B"

                    Text {
                        id: setMailsIntervalContainerHeaderTitle

                        width: 60
                        height: 16

                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: 10

                        text: 'DESDE'
                        font.bold: true
                        color: 'white'


                        font.pixelSize: 16
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                    }
                }

                Rectangle {

                    id: closeSetMailsIntervalArrowRectangle

                    anchors.top: parent.top
                    anchors.right: parent.right

                    width: parent.height
                    height: parent.height

                    color: closeSetMailsIntervalArrowMouseArea.containsMouse ? "#08000000" : 'transparent'


                    MouseArea {

                        id: closeSetMailsIntervalArrowMouseArea

                        anchors.fill: parent
                        hoverEnabled: true

                        onClicked: mailListContainer.state = ""
                    }


                    Image {
                        id: closeSetMailsIntervalArrowImage
                        smooth: true
                        fillMode: Image.PreserveAspectFit
                        anchors.centerIn: parent
                        width: 25
                        height: width
                        source: "qrc:/img/ic_keyboard_arrow_down_bluegray_24px.svg"
                    }
                }

                Rectangle {
                    id: setMailsIntervalContainerHeaderButton

                    height: 24
                    width: 30

                    radius: 12

                    anchors.verticalCenter: parent.verticalCenter
                    anchors.right: closeSetMailsIntervalArrowRectangle.left
                    anchors.rightMargin: 10

                    color: {
                        var color = 'transparent';
                        if ((setMailsIntervalContainer.state === "firstOfInterval" && setMailsIntervalContainer.isToday(setMailsIntervalContainer.firstOfIntervalDate))
                                || (setMailsIntervalContainer.state === "lastOfInterval" && setMailsIntervalContainer.siempreSelected))
                            color = "#26C6DA";
                        else {
                            if (setMailsIntervalContainerHeaderButtonMouseArea.containsMouse) color = '#15000000';
                            else color = 'transparent';
                        }
                    }

                    MouseArea {

                        id: setMailsIntervalContainerHeaderButtonMouseArea

                        anchors.fill: parent
                        hoverEnabled: true

                        onClicked: {
                            var currentDate = new Date();

                            if (setMailsIntervalContainer.state === "firstOfInterval") {
                                setIntervalCalendar.selectedDate = currentDate;
                                setMailsIntervalContainer.firstOfIntervalDate = currentDate;
                                setMailsIntervalContainer.state = "lastOfInterval"
                            }
                            else {
                                setMailsIntervalContainer.siempreSelected = true;
                                mailListContainer.state = ""
                            }

                            setMailsIntervalContainer.setMailsInterval();
                        }
                    }

                    Text {

                        id: setMailsIntervalContainerHeaderButtonText

                        text: 'Hoy'
                        color: {
                            var color = '#212121';
                            var currentDate = new Date();
                            if ((setMailsIntervalContainer.state === "firstOfInterval" && setMailsIntervalContainer.isToday(setMailsIntervalContainer.firstOfIntervalDate))
                                    || (setMailsIntervalContainer.state === "lastOfInterval" && setMailsIntervalContainer.siempreSelected))
                                color = "white";
                            else color = '#212121';
                        }

                        font.bold: {
                            var bold = false;
                            var currentDate = new Date();
                            if ((setMailsIntervalContainer.state === "firstOfInterval" && setMailsIntervalContainer.isToday(setMailsIntervalContainer.firstOfIntervalDate))
                                    || (setMailsIntervalContainer.state === "lastOfInterval" && setMailsIntervalContainer.siempreSelected))
                                bold = true
                            else bold = false

                        }

                        height: 15

                        anchors.centerIn: parent

                        font.pixelSize: 15
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                    }
                }

            }

            Calendar {
                id: setIntervalCalendar

                maximumDate: new Date()
                minimumDate: new Date(2000, 0, 1)

                width: parent.width
                height: 270

                anchors.top: setMailsIntervalContainerHeader.bottom

                onClicked: {

                    const day = selectedDate.getDate();
                    const month = selectedDate.getMonth() + 1;
                    const year = selectedDate.getFullYear();

                    if (setMailsIntervalContainer.state === "firstOfInterval") {

                        setMailsIntervalContainer.state = "lastOfInterval"
                        setMailsIntervalContainer.firstOfIntervalDate = date

                    }
                    else {
                        mailListContainer.state = ""
                        setMailsIntervalContainer.lastOfIntervalDate = date
                        setMailsIntervalContainer.siempreSelected = false
                    }

                    setMailsIntervalContainer.setMailsInterval();

                    //setTimeDateContainer.state = 'setTime'       //Qt.platform.os === "osx" ?
                    //dateLabel.text = Qt.formatDate(calendar.selectedDate, "dd-MM-yyyy")
                    //dateLabel.width = 70
                }

                style: CalendarStyle {
                    gridVisible: false
                    dayDelegate: Item {
                        readonly property color sameMonthDateTextColor: "#444"
                        readonly property color selectedDateColor: Qt.platform.os === "osx" ? "#26C6DA" : systemPalette.highlight
                        readonly property color selectedDateTextColor: "white"
                        readonly property color differentMonthDateTextColor: "#bbb"
                        readonly property color invalidDatecolor: "#dddddd"

                        Rectangle {
                            id: setIntervalCalendarPossibleSelected

                            width: parent.height
                            height: parent.height
                            anchors.centerIn: parent
                            border.color: "transparent"
                            color: styleData.date !== undefined && styleData.selected && (setMailsIntervalContainer.state === 'firstOfInterval' || !setMailsIntervalContainer.siempreSelected) ? selectedDateColor : "transparent"
                            anchors.margins: styleData.selected ? -1 : 0
                            radius: height/2
                        }


                        Label {
                            id: setIntervalCalendarDayDelegateText
                            text: styleData.date.getDate()
                            anchors.centerIn: parent
                            color: {
                                var color = invalidDatecolor;
                                if (styleData.valid) {
                                    // Date is within the valid range.
                                    color = styleData.visibleMonth ? sameMonthDateTextColor : differentMonthDateTextColor;
                                    if (styleData.selected && (setMailsIntervalContainer.state === 'firstOfInterval' || !setMailsIntervalContainer.siempreSelected)) {
                                        color = selectedDateTextColor;
                                    }
                                }
                                color;
                            }
                        }
                    }
                }
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
                id:setSinceToButton

                height: parent.height - 20
                width: childrenRect.width + 20

                radius: (parent.height - 20) / 2

                anchors.centerIn: parent

                color: setSinceToButtonMouseArea.containsMouse ? "#15000000" : 'transparent'

                MouseArea {
                    id: setSinceToButtonMouseArea

                    anchors.fill: parent
                    onClicked: mailListContainer.state = (mailListContainer.state === "setMailsInterval" ? "" : "setMailsInterval")
                    cursorShape: Qt.PointingHandCursor
                    hoverEnabled: true
                }

                Text {
                    id: setSinceToLabel

                    height: 18

                    anchors.centerIn: parent

                    text: 'TODOS'
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    color: "#546E7A"
                    font.pixelSize: 15
                }
            }


            Rectangle {

                id: sendMailFooter
                anchors.fill: parent
                color: 'white'
                opacity: 0
                visible: false

                MouseArea {
                    anchors.fill: parent
                }
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

                    cursorShape: Qt.PointingHandCursor

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

                function validateEmail(email) {
                    var re = /^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;
                    return re.test(email);
                }

                function sendEmail() {

                    var currentDate = new Date();

                    if (!sendMailButton.validateEmail(mailFromTextInput.text)) {

                        mailFromContainerBorder.color = 'red';
                        mailFromLabel.color = 'red';
                    }
                    else {
                        mailFromContainerBorder.color = "#bcbcbc";
                        mailFromLabel.color = "#4b4b4b";
                    }

                    if (!sendMailButton.validateEmail(mailToTextInput.text)) {

                        mailToContainerBorder.color = 'red';
                        mailToLabel.color = 'red';
                    }
                    else {

                        mailToContainerBorder.color = "#bcbcbc";
                        mailToLabel.color = "#4b4b4b";
                    }

                    if (sendMailButton.validateEmail(mailFromTextInput.text) && sendMailButton.validateEmail(mailToTextInput.text)) {

                        /*mailListModel.append(
                                    {
                                        sender: mailFromTextInput.text,
                                        subject: subjectTextInput.text === "" ? "(Sin asunto)" : subjectTextInput.text,
                                        readed: false,
                                        date: Qt.formatDate(calendar.selectedDate, "dd/MM/yy"),
                                        time: timeLabel.text === "Hora" ? ('00' + currentDate.getHours()).slice(-2) + ":" + ('00' + currentDate.getMinutes()).slice(-2) : timeLabel.text,
                                        content: mailBodyTextEdit.text
                                    }
                                    )*/

                        var m_date = Qt.formatDate(calendar.selectedDate, "yyyy MM dd")
                        var m_time = timeLabel.text === "Hora" ? ('00' + currentDate.getHours()).slice(-2) + ":" + ('00' + currentDate.getMinutes()).slice(-2) : timeLabel.text;

                        addNewMailSlot(
                                    mailToTextInput.text,
                                    mailFromTextInput.text,
                                    m_date + " " + m_time,
                                    subjectTextInput.text,
                                    mailBodyTextEdit.text,
                                    true);  //sortedByDate

                        //console.log(mailListModel.get(mailListModel.count-1).content);



                        mailListContainer.state = ""

                        mailFromTextInput.text = "";
                        mailToTextInput.text = "";
                        subjectTextInput.text = "";
                        mailBodyTextEdit.text = "";

                        mailFromContainerBorder.color = "#bcbcbc";
                        mailFromLabel.color = "#4b4b4b";
                        mailToContainerBorder.color = "#bcbcbc";
                        mailToLabel.color = "#4b4b4b";

                        timePicker.stringTime = "";
                        dateLabel.text = "Fecha";
                        dateLabel.width = 40


                        calendar.selectedDate = currentDate
                        timePicker.setTime(currentDate.getHours())
                        timePicker.setMinuteTime(currentDate.getMinutes())
                    }
                    else if (mailListContainer.state === "setTimeDate") mailListContainer.state = "addNewMail";
                }

                MouseArea {

                    id: sendMailMouseArea
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor

                    onClicked: sendMailButton.sendEmail()
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

            Rectangle {

                id: timeDateButton
                anchors.centerIn: parent
                enabled: false
                opacity: 0

                width: 100
                height: parent.height


                MouseArea {

                    id: timeDateMouseArea
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor

                    onClicked: {

                       mailListContainer.state = mailListContainer.state === "addNewMail" ? "setTimeDate" : "addNewMail"
                    }
                }

                Text {
                    id: dateLabel
                    width: 40
                    anchors.right: timeDateSeparatorLabel.left
                    anchors.verticalCenter: parent.verticalCenter
                    color: "#546E7A"
                    text: qsTr("Fecha")
                    //text: Qt.formatDate(calendar.selectedDate, "dd/MM/yy")

                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignRight
                    font.pixelSize: 14
                }

                MouseArea {
                    width: dateLabel.width
                    height: parent.height
                    anchors.right: dateLabel.right
                    cursorShape: Qt.PointingHandCursor

                    onClicked: {

                        if (mailListContainer.state === 'setTimeDate' && setTimeDateContainer.state === '') mailListContainer.state = "addNewMail"
                        else {
                            if (mailListContainer.state !== 'setTimeDate') toAddMailTransition.duration = 0

                            setTimeDateContainer.state = ''
                            mailListContainer.state = "setTimeDate"
                            toAddMailTransition.duration = 350
                        }
                    }
                }

                Text {
                    id: timeDateSeparatorLabel
                    width: 15
                    anchors.centerIn: parent
                    color: "#546E7A"
                    text: qsTr(" | ")
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.pixelSize: 14
                }

                Text {
                    id: timeLabel
                    width: 38
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: timeDateSeparatorLabel.right
                    anchors.leftMargin: -3
                    color: "#546E7A"
                    //text: qsTr("Hora")
                    text: timePicker.stringTime === "" ? "Hora" : timePicker.stringTime
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.pixelSize: 14
                }

                MouseArea {
                    width: timeLabel.width
                    height: parent.height
                    anchors.left: timeLabel.left
                    cursorShape: Qt.PointingHandCursor

                    onClicked: {

                        if (mailListContainer.state === 'setTimeDate' && setTimeDateContainer.state === 'setTime') mailListContainer.state = "addNewMail"
                        else {
                            if (mailListContainer.state != 'setTimeDate') toSetTimeTransition.duration = 0

                            setTimeDateContainer.state = 'setTime'
                            mailListContainer.state = "setTimeDate"

                            toSetTimeTransition.duration = 400
                        }
                    }
                }
            }
        }
    }
}


