import QtQuick 2.5

Rectangle {
  id: timePicker
  color: "transparent"
  clip: true
  property int numberOfItems: 7
  property string fontFamily
  property string linesColor: '#D0D0D0'
  property string selectedItemColor: 'black'
  property string nonSelectedItemsColor: selectedItemColor
  property string scrollingAnimation: "circular"
  property var time: ({hour: 0, minute: 0})
  property int minute: 1
  property int hour: 1
  property string stringTime


  Rectangle {
    width: parent.width
    height: 1
    y: (parent.height - listView.delegateHeight) / 2
    color: linesColor
  }

  Text {

      text: ":"

      anchors.horizontalCenter: parent.horizontalCenter
      y: (parent.height - listView.delegateHeight) / 2

      height: listView.delegateHeight * 0.8

      font.pixelSize: listView.delegateHeight * 0.8
      font.family: fontFamily
      color: selectedItemColor

      verticalAlignment: Text.AlignVCenter
  }

  Rectangle {
    width: parent.width
    height: 1
    y: (parent.height - listView.delegateHeight) / 2 + listView.delegateHeight
    color: linesColor
  }
  ListView {
    id: listView
    x: 0
    width: parent.width / 2
    y: -parent.height * 0.5
    height: parent.height * 2
    property int delegateHeight: height / numberOfItems
    model: 96000
    spacing: 1
    highlightRangeMode: ListView.StrictlyEnforceRange
    preferredHighlightBegin: (height - delegateHeight) / 2
    preferredHighlightEnd: (height + delegateHeight) / 2


    delegate: Item {
      id: contentItem
      width: listView.width
      height: listView.delegateHeight
      Rectangle {
        anchors.fill: parent
        color: "#3333ee33"
        visible: false
      }
      Text {
        id: innerText
        property int hour: index % 24
        text: leadingZero(hour)
        anchors.centerIn: parent
        font.pixelSize: listView.delegateHeight * 0.8
        font.family: fontFamily
        color: contentItem.ListView.isCurrentItem ? selectedItemColor : nonSelectedItemsColor

        //      --CIRCULAR SCROLLING ANIMATION--
        /*transform: [
            Rotation {
                origin.x: innerText.width / 2
                origin.y: innerText.height / 2
                axis { x: 1; y: 0; z: 0 }
                angle: {
                    var middle = contentItem.ListView.view.contentY - contentItem.y + contentItem.ListView.view.height / 2
                    var calculated = (middle - contentItem.height / 2) / contentItem.height * 40
                    if (calculated < -90)
                        return -90
                    else if (calculated > 90)
                        return 90
                    else
                        return calculated
                }
            },
            Scale {
                origin.x: innerText.width / 2
                origin.y: innerText.height / 2
                xScale: {
                    // scaled 1 in middle position -> 0 when reaching edges
                    var scaled = (contentItem.y - contentItem.ListView.view.contentY + contentItem.height * 0.5) / contentItem.ListView.view.height * 2
                    if (scaled > 1) scaled = 2 - scaled
                    return Math.max(0, scaled)
                }
                yScale: xScale
            },
            Translate {
                y: {
                    var scaled = (contentItem.y - contentItem.ListView.view.contentY + contentItem.height * 0.5) / contentItem.ListView.view.height * 2
                    scaled = Math.max(0, scaled)
                    scaled = 1 - scaled
                    return scaled * scaled * scaled * contentItem.height * 3
                }
            }
        ]*/

        //      --SIMPLE SCROLLING ANIMATION--
        transform: [
            Scale {
                origin.x: innerText.width / 2
                origin.y: innerText.height / 2
                xScale: {
                    // scaled 1 in middle position -> 0 when reaching edges

                    var scaled =  (contentItem.y - contentItem.ListView.view.contentY + contentItem.height * 0.5) / contentItem.ListView.view.height * 2

                    if (scaled > 1) scaled = 2 - scaled
                    if(scaled < 0.92) scaled = 0.8
                    return Math.max(0, scaled)
                }
                yScale: xScale
            },
            Translate {
                y: {
                    var scaled = (contentItem.y - contentItem.ListView.view.contentY + contentItem.height * 0.5) / contentItem.ListView.view.height * 2
                    return scaled
                }
            }
        ]

      }
    }
    Component.onCompleted: {
      // Scrolls to middle of list
      //positionViewAtIndex(model * 0.5 - (listView.numberOfItems > 2 ? 1 : 0), ListView.SnapPosition)
      var currentDate = new Date();
      positionViewAtIndex(model * 0.5 - 1 + currentDate.getHours(), ListView.SnapPosition)

    }
    onMovementEnded: {
        var item = currentIndex % 24
        hour = item
        //console.debug("HOUR IS:", hour )
        timePicker.time = {hour: hour}
        stringTime = leadingZero(hour) + ":" + leadingZero(minute)
    }
  }
  function setTime(newTime) {
    listView.positionViewAtIndex(newTime || 0, ListView.Center)
    timePicker.time = newTime
  }



  ListView {
    id: minuteListView
    x: parent.width / 2
    width: parent.width / 2
    y: -parent.height * 0.5
    height: parent.height * 2
    property int delegateHeight: height / numberOfItems
    model: 96000
    spacing: 1
    highlightRangeMode: ListView.StrictlyEnforceRange
    preferredHighlightBegin: (height - delegateHeight) / 2
    preferredHighlightEnd: (height + delegateHeight) / 2
    delegate: Item {
      id: minuteContentItem
      width: minuteListView.width
      height: minuteListView.delegateHeight
      Rectangle {
        anchors.fill: parent
        color: "#3333ee33"
        visible: false
      }
      Text {
        id: minuteInnerText
        property int minute: (index % 60)
        text: leadingZero(minute)
        anchors.centerIn: parent
        font.pixelSize: minuteListView.delegateHeight * 0.8
        font.family: fontFamily
        color: minuteContentItem.ListView.isCurrentItem ? selectedItemColor : nonSelectedItemsColor

        //      --CIRCULAR SCROLLING ANIMATION--
        /*transform: [
            Rotation {
                origin.x: minuteInnerText.width / 2
                origin.y: minuteInnerText.height / 2
                axis { x: 1; y: 0; z: 0 }
                angle: {
                    var middle = contentItem.ListView.view.contentY - contentItem.y + contentItem.ListView.view.height / 2
                    var calculated = (middle - contentItem.height / 2) / contentItem.height * 40
                    if (calculated < -90)
                        return -90
                    else if (calculated > 90)
                        return 90
                    else
                        return calculated
                }
            },
            Scale {
                origin.x: minuteInnerText.width / 2
                origin.y: minuteInnerText.height / 2
                xScale: {
                    // scaled 1 in middle position -> 0 when reaching edges
                    var scaled = (minuteContentItem.y - minuteContentItem.ListView.view.contentY + minuteContentItem.height * 0.5) / minuteContentItem.ListView.view.height * 2
                    if (scaled > 1) scaled = 2 - scaled
                    return Math.max(0, scaled)
                }
                yScale: xScale
            },
            Translate {
                y: {
                    var scaled = (minuteContentItem.y - minuteContentItem.ListView.view.contentY + minuteContentItem.height * 0.5) / minuteContentItem.ListView.view.height * 2
                    scaled = Math.max(0, scaled)
                    scaled = 1 - scaled
                    return scaled * scaled * scaled * minuteContentItem.height * 3
                }
            }
        ]*/

        //      --SIMPLE SCROLLING ANIMATION--
        transform: [
            Scale {
                origin.x: minuteInnerText.width / 2
                origin.y: minuteInnerText.height / 2
                xScale: {
                    // scaled 1 in middle position -> 0 when reaching edges
                    var scaled = (minuteContentItem.y - minuteContentItem.ListView.view.contentY + minuteContentItem.height * 0.5)
                            / minuteContentItem.ListView.view.height * 2

                    if (scaled > 1) scaled = 2 - scaled
                    if(scaled < 0.92) scaled = 0.8
                    return Math.max(0, scaled)
                }
                yScale: xScale
            },
            Translate {
                y: {
                    var scaled = (minuteContentItem.y - minuteContentItem.ListView.view.contentY + minuteContentItem.height * 0.5) / minuteContentItem.ListView.view.height * 2
                    return scaled
                }
            }
        ]


      }
    }

    Component.onCompleted: {
      // Scrolls to middle of list
      //positionViewAtIndex(model * 0.5 - (minuteListView.numberOfItems > 2 ? 1 : 0), ListView.SnapPosition)
        var currentDate = new Date();
        positionViewAtIndex(model * 0.5 - 1 + currentDate.getMinutes(), ListView.SnapPosition)
    }
    onMovementEnded: {
          var item = currentIndex % 60
          minute = item
          //console.debug("MINUTE IS:", minute)
          timePicker.time = {minute: minute}
          stringTime = leadingZero(hour) + ":" + leadingZero(minute)
    }
  }


  function setMinuteTime(newTime) {
    minuteListView.positionViewAtIndex(newTime || 0, ListView.Center)
    timePicker.time = newTime
  }


  function leadingZero(number) {
    return ('00' + number).slice(-2)
  }


}
