begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore>
end_include
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|<QtNetwork>
end_include
begin_include
include|#
directive|include
file|"ui_form.h"
end_include
begin_define
DECL|macro|FLIGHTVIEW_URL
define|#
directive|define
name|FLIGHTVIEW_URL
value|"http://mobile.flightview.com/TrackByFlight.aspx"
end_define
begin_define
DECL|macro|FLIGHTVIEW_RANDOM
define|#
directive|define
name|FLIGHTVIEW_RANDOM
value|"http://mobile.flightview.com/TrackSampleFlight.aspx"
end_define
begin_comment
comment|// strips all invalid constructs that might trip QXmlStreamReader
end_comment
begin_function
DECL|function|sanitized
specifier|static
name|QString
name|sanitized
parameter_list|(
specifier|const
name|QString
modifier|&
name|xml
parameter_list|)
block|{
name|QString
name|data
init|=
name|xml
decl_stmt|;
comment|// anything up to the html tag
name|int
name|i
init|=
name|data
operator|.
name|indexOf
argument_list|(
literal|"<html"
argument_list|)
decl_stmt|;
if|if
condition|(
name|i
operator|>
literal|0
condition|)
name|data
operator|.
name|remove
argument_list|(
literal|0
argument_list|,
name|i
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// everything inside the head tag
name|i
operator|=
name|data
operator|.
name|indexOf
argument_list|(
literal|"<head"
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|>
literal|0
condition|)
name|data
operator|.
name|remove
argument_list|(
name|i
argument_list|,
name|data
operator|.
name|indexOf
argument_list|(
literal|"</head>"
argument_list|)
operator|-
name|i
operator|+
literal|7
argument_list|)
expr_stmt|;
comment|// invalid link for JavaScript code
while|while
condition|(
literal|true
condition|)
block|{
name|i
operator|=
name|data
operator|.
name|indexOf
argument_list|(
literal|"onclick=\"gotoUrl("
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|<
literal|0
condition|)
break|break;
name|data
operator|.
name|remove
argument_list|(
name|i
argument_list|,
name|data
operator|.
name|indexOf
argument_list|(
literal|'\"'
argument_list|,
name|i
operator|+
literal|9
argument_list|)
operator|-
name|i
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
comment|// all inline frames
while|while
condition|(
literal|true
condition|)
block|{
name|i
operator|=
name|data
operator|.
name|indexOf
argument_list|(
literal|"<iframe"
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|<
literal|0
condition|)
break|break;
name|data
operator|.
name|remove
argument_list|(
name|i
argument_list|,
name|data
operator|.
name|indexOf
argument_list|(
literal|"</iframe>"
argument_list|)
operator|-
name|i
operator|+
literal|8
argument_list|)
expr_stmt|;
block|}
comment|// entities
name|data
operator|.
name|remove
argument_list|(
literal|"&nbsp;"
argument_list|)
expr_stmt|;
name|data
operator|.
name|remove
argument_list|(
literal|"&copy;"
argument_list|)
expr_stmt|;
return|return
name|data
return|;
block|}
end_function
begin_class
DECL|class|FlightInfo
class|class
name|FlightInfo
super|:
specifier|public
name|QMainWindow
block|{
name|Q_OBJECT
private|private:
DECL|member|ui
name|Ui_Form
name|ui
decl_stmt|;
DECL|member|m_url
name|QUrl
name|m_url
decl_stmt|;
DECL|member|m_searchDate
name|QDate
name|m_searchDate
decl_stmt|;
DECL|member|m_map
name|QPixmap
name|m_map
decl_stmt|;
DECL|member|m_manager
name|QNetworkAccessManager
name|m_manager
decl_stmt|;
DECL|member|mapReplies
name|QList
argument_list|<
name|QNetworkReply
modifier|*
argument_list|>
name|mapReplies
decl_stmt|;
public|public:
DECL|function|FlightInfo
name|FlightInfo
parameter_list|(
name|QMainWindow
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QMainWindow
argument_list|(
name|parent
argument_list|)
block|{
name|QWidget
modifier|*
name|w
init|=
operator|new
name|QWidget
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|ui
operator|.
name|setupUi
argument_list|(
name|w
argument_list|)
expr_stmt|;
name|setCentralWidget
argument_list|(
name|w
argument_list|)
expr_stmt|;
name|ui
operator|.
name|searchBar
operator|->
name|hide
argument_list|()
expr_stmt|;
name|ui
operator|.
name|infoBox
operator|->
name|hide
argument_list|()
expr_stmt|;
name|connect
argument_list|(
name|ui
operator|.
name|searchButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|startSearch
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|ui
operator|.
name|flightEdit
argument_list|,
name|SIGNAL
argument_list|(
name|returnPressed
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|startSearch
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
literal|"Flight Info"
argument_list|)
expr_stmt|;
comment|// Rendered from the public-domain vectorized aircraft
comment|// http://openclipart.org/media/people/Jarno
name|m_map
operator|=
name|QPixmap
argument_list|(
literal|":/aircraft.png"
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|searchTodayAction
init|=
operator|new
name|QAction
argument_list|(
literal|"Today's Flight"
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|searchYesterdayAction
init|=
operator|new
name|QAction
argument_list|(
literal|"Yesterday's Flight"
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|randomAction
init|=
operator|new
name|QAction
argument_list|(
literal|"Random Flight"
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|searchTodayAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|today
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|searchYesterdayAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|yesterday
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|randomAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|randomFlight
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|m_manager
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|(
name|QNetworkReply
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|handleNetworkData
argument_list|(
name|QNetworkReply
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
name|menuBar
argument_list|()
operator|->
name|addAction
argument_list|(
name|searchTodayAction
argument_list|)
expr_stmt|;
name|menuBar
argument_list|()
operator|->
name|addAction
argument_list|(
name|searchYesterdayAction
argument_list|)
expr_stmt|;
name|menuBar
argument_list|()
operator|->
name|addAction
argument_list|(
name|randomAction
argument_list|)
expr_stmt|;
else|#
directive|else
name|addAction
argument_list|(
name|searchTodayAction
argument_list|)
expr_stmt|;
name|addAction
argument_list|(
name|searchYesterdayAction
argument_list|)
expr_stmt|;
name|addAction
argument_list|(
name|randomAction
argument_list|)
expr_stmt|;
name|setContextMenuPolicy
argument_list|(
name|Qt
operator|::
name|ActionsContextMenu
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
private|private
name|slots
private|:
DECL|function|handleNetworkData
name|void
name|handleNetworkData
parameter_list|(
name|QNetworkReply
modifier|*
name|networkReply
parameter_list|)
block|{
if|if
condition|(
operator|!
name|networkReply
operator|->
name|error
argument_list|()
condition|)
block|{
if|if
condition|(
operator|!
name|mapReplies
operator|.
name|contains
argument_list|(
name|networkReply
argument_list|)
condition|)
block|{
comment|// Assume UTF-8 encoded
name|QByteArray
name|data
init|=
name|networkReply
operator|->
name|readAll
argument_list|()
decl_stmt|;
name|QString
name|xml
init|=
name|QString
operator|::
name|fromUtf8
argument_list|(
name|data
argument_list|)
decl_stmt|;
name|digest
argument_list|(
name|xml
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|mapReplies
operator|.
name|removeOne
argument_list|(
name|networkReply
argument_list|)
expr_stmt|;
name|m_map
operator|.
name|loadFromData
argument_list|(
name|networkReply
operator|->
name|readAll
argument_list|()
argument_list|)
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
block|}
name|networkReply
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
block|}
DECL|function|today
name|void
name|today
parameter_list|()
block|{
name|QDateTime
name|timestamp
init|=
name|QDateTime
operator|::
name|currentDateTime
argument_list|()
decl_stmt|;
name|m_searchDate
operator|=
name|timestamp
operator|.
name|date
argument_list|()
expr_stmt|;
name|searchFlight
argument_list|()
expr_stmt|;
block|}
DECL|function|yesterday
name|void
name|yesterday
parameter_list|()
block|{
name|QDateTime
name|timestamp
init|=
name|QDateTime
operator|::
name|currentDateTime
argument_list|()
decl_stmt|;
name|timestamp
operator|=
name|timestamp
operator|.
name|addDays
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
name|m_searchDate
operator|=
name|timestamp
operator|.
name|date
argument_list|()
expr_stmt|;
name|searchFlight
argument_list|()
expr_stmt|;
block|}
DECL|function|searchFlight
name|void
name|searchFlight
parameter_list|()
block|{
name|ui
operator|.
name|searchBar
operator|->
name|show
argument_list|()
expr_stmt|;
name|ui
operator|.
name|infoBox
operator|->
name|hide
argument_list|()
expr_stmt|;
name|ui
operator|.
name|flightStatus
operator|->
name|hide
argument_list|()
expr_stmt|;
name|ui
operator|.
name|flightName
operator|->
name|setText
argument_list|(
literal|"Enter flight number"
argument_list|)
expr_stmt|;
name|ui
operator|.
name|flightEdit
operator|->
name|setFocus
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|QT_KEYPAD_NAVIGATION
name|ui
operator|.
name|flightEdit
operator|->
name|setEditFocus
argument_list|(
literal|true
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|m_map
operator|=
name|QPixmap
argument_list|()
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
DECL|function|startSearch
name|void
name|startSearch
parameter_list|()
block|{
name|ui
operator|.
name|searchBar
operator|->
name|hide
argument_list|()
expr_stmt|;
name|QString
name|flight
init|=
name|ui
operator|.
name|flightEdit
operator|->
name|text
argument_list|()
operator|.
name|simplified
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|flight
operator|.
name|isEmpty
argument_list|()
condition|)
name|request
argument_list|(
name|flight
argument_list|,
name|m_searchDate
argument_list|)
expr_stmt|;
block|}
DECL|function|randomFlight
name|void
name|randomFlight
parameter_list|()
block|{
name|request
argument_list|(
name|QString
argument_list|()
argument_list|,
name|QDate
operator|::
name|currentDate
argument_list|()
argument_list|)
expr_stmt|;
block|}
public|public
name|slots
public|:
DECL|function|request
name|void
name|request
parameter_list|(
specifier|const
name|QString
modifier|&
name|flightCode
parameter_list|,
specifier|const
name|QDate
modifier|&
name|date
parameter_list|)
block|{
name|setWindowTitle
argument_list|(
literal|"Loading..."
argument_list|)
expr_stmt|;
name|QString
name|code
init|=
name|flightCode
operator|.
name|simplified
argument_list|()
decl_stmt|;
name|QString
name|airlineCode
init|=
name|code
operator|.
name|left
argument_list|(
literal|2
argument_list|)
operator|.
name|toUpper
argument_list|()
decl_stmt|;
name|QString
name|flightNumber
init|=
name|code
operator|.
name|mid
argument_list|(
literal|2
argument_list|,
name|code
operator|.
name|length
argument_list|()
argument_list|)
decl_stmt|;
name|ui
operator|.
name|flightName
operator|->
name|setText
argument_list|(
literal|"Searching for "
operator|+
name|code
argument_list|)
expr_stmt|;
name|m_url
operator|=
name|QUrl
argument_list|(
name|FLIGHTVIEW_URL
argument_list|)
expr_stmt|;
name|m_url
operator|.
name|addEncodedQueryItem
argument_list|(
literal|"view"
argument_list|,
literal|"detail"
argument_list|)
expr_stmt|;
name|m_url
operator|.
name|addEncodedQueryItem
argument_list|(
literal|"al"
argument_list|,
name|QUrl
operator|::
name|toPercentEncoding
argument_list|(
name|airlineCode
argument_list|)
argument_list|)
expr_stmt|;
name|m_url
operator|.
name|addEncodedQueryItem
argument_list|(
literal|"fn"
argument_list|,
name|QUrl
operator|::
name|toPercentEncoding
argument_list|(
name|flightNumber
argument_list|)
argument_list|)
expr_stmt|;
name|m_url
operator|.
name|addEncodedQueryItem
argument_list|(
literal|"dpdat"
argument_list|,
name|QUrl
operator|::
name|toPercentEncoding
argument_list|(
name|date
operator|.
name|toString
argument_list|(
literal|"yyyyMMdd"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|code
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|// random flight as sample
name|m_url
operator|=
name|QUrl
argument_list|(
name|FLIGHTVIEW_RANDOM
argument_list|)
expr_stmt|;
name|ui
operator|.
name|flightName
operator|->
name|setText
argument_list|(
literal|"Getting a random flight..."
argument_list|)
expr_stmt|;
block|}
name|m_manager
operator|.
name|get
argument_list|(
name|QNetworkRequest
argument_list|(
name|m_url
argument_list|)
argument_list|)
expr_stmt|;
block|}
private|private:
DECL|function|digest
name|void
name|digest
parameter_list|(
specifier|const
name|QString
modifier|&
name|content
parameter_list|)
block|{
name|setWindowTitle
argument_list|(
literal|"Flight Info"
argument_list|)
expr_stmt|;
name|QString
name|data
init|=
name|sanitized
argument_list|(
name|content
argument_list|)
decl_stmt|;
comment|// do we only get the flight list?
comment|// we grab the first leg in the flight list
comment|// then fetch another URL for the real flight info
name|int
name|i
init|=
name|data
operator|.
name|indexOf
argument_list|(
literal|"a href=\"?view=detail"
argument_list|)
decl_stmt|;
if|if
condition|(
name|i
operator|>
literal|0
condition|)
block|{
name|QString
name|href
init|=
name|data
operator|.
name|mid
argument_list|(
name|i
argument_list|,
name|data
operator|.
name|indexOf
argument_list|(
literal|'\"'
argument_list|,
name|i
operator|+
literal|8
argument_list|)
operator|-
name|i
operator|+
literal|1
argument_list|)
decl_stmt|;
name|QRegExp
name|regex
argument_list|(
literal|"dpap=([A-Za-z0-9]+)"
argument_list|)
decl_stmt|;
name|regex
operator|.
name|indexIn
argument_list|(
name|href
argument_list|)
expr_stmt|;
name|QString
name|airport
init|=
name|regex
operator|.
name|cap
argument_list|(
literal|1
argument_list|)
decl_stmt|;
name|m_url
operator|.
name|addEncodedQueryItem
argument_list|(
literal|"dpap"
argument_list|,
name|QUrl
operator|::
name|toPercentEncoding
argument_list|(
name|airport
argument_list|)
argument_list|)
expr_stmt|;
name|m_manager
operator|.
name|get
argument_list|(
name|QNetworkRequest
argument_list|(
name|m_url
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|QXmlStreamReader
name|xml
argument_list|(
name|data
argument_list|)
decl_stmt|;
name|bool
name|inFlightName
init|=
literal|false
decl_stmt|;
name|bool
name|inFlightStatus
init|=
literal|false
decl_stmt|;
name|bool
name|inFlightMap
init|=
literal|false
decl_stmt|;
name|bool
name|inFieldName
init|=
literal|false
decl_stmt|;
name|bool
name|inFieldValue
init|=
literal|false
decl_stmt|;
name|QString
name|flightName
decl_stmt|;
name|QString
name|flightStatus
decl_stmt|;
name|QStringList
name|fieldNames
decl_stmt|;
name|QStringList
name|fieldValues
decl_stmt|;
while|while
condition|(
operator|!
name|xml
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|xml
operator|.
name|readNext
argument_list|()
expr_stmt|;
if|if
condition|(
name|xml
operator|.
name|tokenType
argument_list|()
operator|==
name|QXmlStreamReader
operator|::
name|StartElement
condition|)
block|{
name|QStringRef
name|className
init|=
name|xml
operator|.
name|attributes
argument_list|()
operator|.
name|value
argument_list|(
literal|"class"
argument_list|)
decl_stmt|;
name|inFlightName
operator||=
name|xml
operator|.
name|name
argument_list|()
operator|==
literal|"h1"
expr_stmt|;
name|inFlightStatus
operator||=
name|className
operator|==
literal|"FlightDetailHeaderStatus"
expr_stmt|;
name|inFlightMap
operator||=
name|className
operator|==
literal|"flightMap"
expr_stmt|;
if|if
condition|(
name|xml
operator|.
name|name
argument_list|()
operator|==
literal|"td"
operator|&&
operator|!
name|className
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QString
name|cn
init|=
name|className
operator|.
name|toString
argument_list|()
decl_stmt|;
if|if
condition|(
name|cn
operator|.
name|contains
argument_list|(
literal|"fieldTitle"
argument_list|)
condition|)
block|{
name|inFieldName
operator|=
literal|true
expr_stmt|;
name|fieldNames
operator|+=
name|QString
argument_list|()
expr_stmt|;
name|fieldValues
operator|+=
name|QString
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|cn
operator|.
name|contains
argument_list|(
literal|"fieldValue"
argument_list|)
condition|)
name|inFieldValue
operator|=
literal|true
expr_stmt|;
block|}
if|if
condition|(
name|xml
operator|.
name|name
argument_list|()
operator|==
literal|"img"
operator|&&
name|inFlightMap
condition|)
block|{
name|QString
name|src
init|=
name|xml
operator|.
name|attributes
argument_list|()
operator|.
name|value
argument_list|(
literal|"src"
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|src
operator|.
name|prepend
argument_list|(
literal|"http://mobile.flightview.com/"
argument_list|)
expr_stmt|;
name|QUrl
name|url
init|=
name|QUrl
operator|::
name|fromPercentEncoding
argument_list|(
name|src
operator|.
name|toAscii
argument_list|()
argument_list|)
decl_stmt|;
name|mapReplies
operator|.
name|append
argument_list|(
name|m_manager
operator|.
name|get
argument_list|(
name|QNetworkRequest
argument_list|(
name|url
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|xml
operator|.
name|tokenType
argument_list|()
operator|==
name|QXmlStreamReader
operator|::
name|EndElement
condition|)
block|{
name|inFlightName
operator|&=
name|xml
operator|.
name|name
argument_list|()
operator|!=
literal|"h1"
expr_stmt|;
name|inFlightStatus
operator|&=
name|xml
operator|.
name|name
argument_list|()
operator|!=
literal|"div"
expr_stmt|;
name|inFlightMap
operator|&=
name|xml
operator|.
name|name
argument_list|()
operator|!=
literal|"div"
expr_stmt|;
name|inFieldName
operator|&=
name|xml
operator|.
name|name
argument_list|()
operator|!=
literal|"td"
expr_stmt|;
name|inFieldValue
operator|&=
name|xml
operator|.
name|name
argument_list|()
operator|!=
literal|"td"
expr_stmt|;
block|}
if|if
condition|(
name|xml
operator|.
name|tokenType
argument_list|()
operator|==
name|QXmlStreamReader
operator|::
name|Characters
condition|)
block|{
if|if
condition|(
name|inFlightName
condition|)
name|flightName
operator|+=
name|xml
operator|.
name|text
argument_list|()
expr_stmt|;
if|if
condition|(
name|inFlightStatus
condition|)
name|flightStatus
operator|+=
name|xml
operator|.
name|text
argument_list|()
expr_stmt|;
if|if
condition|(
name|inFieldName
condition|)
name|fieldNames
operator|.
name|last
argument_list|()
operator|+=
name|xml
operator|.
name|text
argument_list|()
expr_stmt|;
if|if
condition|(
name|inFieldValue
condition|)
name|fieldValues
operator|.
name|last
argument_list|()
operator|+=
name|xml
operator|.
name|text
argument_list|()
expr_stmt|;
block|}
block|}
if|if
condition|(
name|fieldNames
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QString
name|code
init|=
name|ui
operator|.
name|flightEdit
operator|->
name|text
argument_list|()
operator|.
name|simplified
argument_list|()
operator|.
name|left
argument_list|(
literal|10
argument_list|)
decl_stmt|;
name|QString
name|msg
init|=
name|QString
argument_list|(
literal|"Flight %1 is not found"
argument_list|)
operator|.
name|arg
argument_list|(
name|code
argument_list|)
decl_stmt|;
name|ui
operator|.
name|flightName
operator|->
name|setText
argument_list|(
name|msg
argument_list|)
expr_stmt|;
return|return;
block|}
name|ui
operator|.
name|flightName
operator|->
name|setText
argument_list|(
name|flightName
argument_list|)
expr_stmt|;
name|flightStatus
operator|.
name|remove
argument_list|(
literal|"Status: "
argument_list|)
expr_stmt|;
name|ui
operator|.
name|flightStatus
operator|->
name|setText
argument_list|(
name|flightStatus
argument_list|)
expr_stmt|;
name|ui
operator|.
name|flightStatus
operator|->
name|show
argument_list|()
expr_stmt|;
name|QStringList
name|whiteList
decl_stmt|;
name|whiteList
operator|<<
literal|"Departure"
expr_stmt|;
name|whiteList
operator|<<
literal|"Arrival"
expr_stmt|;
name|whiteList
operator|<<
literal|"Scheduled"
expr_stmt|;
name|whiteList
operator|<<
literal|"Takeoff"
expr_stmt|;
name|whiteList
operator|<<
literal|"Estimated"
expr_stmt|;
name|whiteList
operator|<<
literal|"Term-Gate"
expr_stmt|;
name|QString
name|text
decl_stmt|;
name|text
operator|=
name|QString
argument_list|(
literal|"<table width=%1>"
argument_list|)
operator|.
name|arg
argument_list|(
name|width
argument_list|()
operator|-
literal|25
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|fieldNames
operator|.
name|count
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|QString
name|fn
init|=
name|fieldNames
index|[
name|i
index|]
operator|.
name|simplified
argument_list|()
decl_stmt|;
if|if
condition|(
name|fn
operator|.
name|endsWith
argument_list|(
literal|':'
argument_list|)
condition|)
name|fn
operator|=
name|fn
operator|.
name|left
argument_list|(
name|fn
operator|.
name|length
argument_list|()
operator|-
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|whiteList
operator|.
name|contains
argument_list|(
name|fn
argument_list|)
condition|)
continue|continue;
name|QString
name|fv
init|=
name|fieldValues
index|[
name|i
index|]
operator|.
name|simplified
argument_list|()
decl_stmt|;
name|bool
name|special
init|=
literal|false
decl_stmt|;
name|special
operator||=
name|fn
operator|.
name|startsWith
argument_list|(
literal|"Departure"
argument_list|)
expr_stmt|;
name|special
operator||=
name|fn
operator|.
name|startsWith
argument_list|(
literal|"Arrival"
argument_list|)
expr_stmt|;
name|text
operator|+=
literal|"<tr>"
expr_stmt|;
if|if
condition|(
name|special
condition|)
block|{
name|text
operator|+=
literal|"<td align=center colspan=2>"
expr_stmt|;
name|text
operator|+=
literal|"<b><font size=+1>"
operator|+
name|fv
operator|+
literal|"</font></b>"
expr_stmt|;
name|text
operator|+=
literal|"</td>"
expr_stmt|;
block|}
else|else
block|{
name|text
operator|+=
literal|"<td align=right>"
expr_stmt|;
name|text
operator|+=
name|fn
expr_stmt|;
name|text
operator|+=
literal|" : "
expr_stmt|;
name|text
operator|+=
literal|"&nbsp;"
expr_stmt|;
name|text
operator|+=
literal|"</td>"
expr_stmt|;
name|text
operator|+=
literal|"<td>"
expr_stmt|;
name|text
operator|+=
name|fv
expr_stmt|;
name|text
operator|+=
literal|"</td>"
expr_stmt|;
block|}
name|text
operator|+=
literal|"</tr>"
expr_stmt|;
block|}
name|text
operator|+=
literal|"</table>"
expr_stmt|;
name|ui
operator|.
name|detailedInfo
operator|->
name|setText
argument_list|(
name|text
argument_list|)
expr_stmt|;
name|ui
operator|.
name|infoBox
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
DECL|function|resizeEvent
name|void
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|event
argument_list|)
expr_stmt|;
name|ui
operator|.
name|detailedInfo
operator|->
name|setMaximumWidth
argument_list|(
name|width
argument_list|()
operator|-
literal|25
argument_list|)
expr_stmt|;
block|}
DECL|function|paintEvent
name|void
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
name|event
parameter_list|)
block|{
name|QMainWindow
operator|::
name|paintEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
name|QPainter
name|p
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|p
operator|.
name|fillRect
argument_list|(
name|rect
argument_list|()
argument_list|,
name|QColor
argument_list|(
literal|131
argument_list|,
literal|171
argument_list|,
literal|210
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_map
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|int
name|x
init|=
operator|(
name|width
argument_list|()
operator|-
name|m_map
operator|.
name|width
argument_list|()
operator|)
operator|/
literal|2
decl_stmt|;
name|int
name|space
init|=
name|ui
operator|.
name|infoBox
operator|->
name|pos
argument_list|()
operator|.
name|y
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|ui
operator|.
name|infoBox
operator|->
name|isVisible
argument_list|()
condition|)
name|space
operator|=
name|height
argument_list|()
expr_stmt|;
name|int
name|top
init|=
name|ui
operator|.
name|titleBox
operator|->
name|height
argument_list|()
decl_stmt|;
name|int
name|y
init|=
name|qMax
argument_list|(
name|top
argument_list|,
operator|(
name|space
operator|-
name|m_map
operator|.
name|height
argument_list|()
operator|)
operator|/
literal|2
argument_list|)
decl_stmt|;
name|p
operator|.
name|drawPixmap
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|m_map
argument_list|)
expr_stmt|;
block|}
name|p
operator|.
name|end
argument_list|()
expr_stmt|;
block|}
block|}
class|;
end_class
begin_include
include|#
directive|include
file|"flightinfo.moc"
end_include
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|Q_INIT_RESOURCE
argument_list|(
name|flightinfo
argument_list|)
expr_stmt|;
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|FlightInfo
name|w
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
name|w
operator|.
name|showMaximized
argument_list|()
expr_stmt|;
else|#
directive|else
name|w
operator|.
name|resize
argument_list|(
literal|360
argument_list|,
literal|504
argument_list|)
expr_stmt|;
name|w
operator|.
name|show
argument_list|()
expr_stmt|;
endif|#
directive|endif
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
end_unit
